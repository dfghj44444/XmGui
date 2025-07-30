/***********************************************************************
Copyright:2010-2013 Double One<dfghj77777@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA., or go to http://www.gnu.org/copyleft/lesser.txt

--------------------------------------------------------------------
@File Name:UI_Object.cpp
@Describe:This is a part of XM_GUI
@Create Date:2010-10-7 14:01:29
@Version:1.0
@Author£ºDouble One
@Blog£º http://onedouble.cnblogs.com
@Modifier: Double One (dfghj77777@gmail.com)
@Modify Date£º2013-08-06 14:01:30
@Modify Reason£º
***********************************************************************/

#include "stdafx.h"
 
namespace XM
{
	// RTTI
	XM_RTTI_CREATE_STATIC(UI_Object, L"UI_Object", UI_Base);
	///////////////////////////////////////////////////////////////////////////
	// ctor/dtor
	UI_Object::UI_Object()
	{
		XM_RTTI_INIT_POINTER;

		m_nSuperID		= 0;
		m_nID			= 0;
		m_bVisible		= true;
		m_bEnabled		= true;
		m_bUseMouse		= true;
		m_bUseKeyboard	= true;		

		m_bMouseOver	= false;
		m_bPressed		= false;
		m_bHasFocus		= false;

		// position, size
		m_vPos			= D3DXVECTOR3(0.0f, 0.0f, -0.01f);
		m_vParentPos	= D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	}

	UI_Object::~UI_Object()
	{
	}

	bool UI_Object::saveFile(IStream& rStream)
	{
		ISTREAM_WRITEINT(rStream, m_nID) == false;
		ISTREAM_WRITEBool(rStream, m_bVisible) == false;
		ISTREAM_WRITEBool(rStream, m_bEnabled) == false;
		ISTREAM_WRITEBool(rStream, m_bUseMouse) == false;
		ISTREAM_WRITEBool(rStream, m_bUseKeyboard) == false;
		ISTREAM_WRITEVEC3(rStream, m_vPos) == false;
		ISTREAM_READVEC3(rStream, &m_vParentPos) == false ;

		return true;
	}

	bool UI_Object::loadFile(IStream& rStream)
	{
		ISTREAM_READINT(rStream, &m_nID) ;
		ISTREAM_READBool(rStream, &m_bVisible) ;
		ISTREAM_READBool(rStream, &m_bEnabled) ;
		ISTREAM_READBool(rStream, &m_bUseMouse);
	    ISTREAM_READBool(rStream, &m_bUseKeyboard) ;
		ISTREAM_READVEC3(rStream, &m_vPos) ;
		ISTREAM_READVEC3(rStream, &m_vParentPos) ;
	
		return true;
	}

    void UI_Object::frameMove(DWORD dwElapsedTime)
    {
	  // Update logic here, if needed
      // For example, update position based on elapsed time or other factors
      // Placeholder logic for frame move
      m_vPos.x += 0.01f * dwElapsedTime; // Example: move right over time
      m_vPos.y += 0.01f * dwElapsedTime; // Example: move down over time
    }

    void UI_Object::render(IDirect3DDevice9*)
    {
	  // Render logic here, if needed
      // For example, draw the object at its current position
      // Placeholder logic for rendering
      // This could involve drawing a rectangle or other shape at m_vPos
      // using Direct3D functions, but is left empty for now.
    }

    UI_Object* UI_Object::hitTest(int nMouseX, int nMouseY, float& zDist)
    {
      if (!m_bVisible || !m_bEnabled || !m_bUseMouse)
        return nullptr;
      // Perform hit test logic here
      // For example, check if the mouse coordinates are within the bounds of this object
      // If hit, set zDist to the appropriate value and return this object
      // Placeholder logic for hit test
      if (nMouseX >= m_vPos.x && nMouseX <= m_vPos.x + 100 && // Assuming width of 100
        nMouseY >= m_vPos.y && nMouseY <= m_vPos.y + 50)   // Assuming height of 50
      {
        zDist = m_vPos.z; // Set zDist to object's z position
        return this; // Hit detected, return this object
      }
      return nullptr; // No hit detected
    }

    void UI_Object::setID(int iId)
    {
      m_nID = iId;
    }

    void UI_Object::setSuperID(int nId)
    {
      m_nSuperID = nId;
    }

    bool UI_Object::handleKeyboard(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
      if (!m_bVisible || !m_bEnabled || !m_bUseKeyboard)
        return false;
      if (pDialog == nullptr)
        return false;
      // handle keyboard messages here
      // ...
      return false; // return true if the message was handled
    }

    bool UI_Object::handleMouse(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
      if (!m_bVisible || !m_bEnabled || !m_bUseMouse)
        return false;
      if (pDialog == nullptr)
        return false;
      // handle mouse messages here
      // ...
      return false; // return true if the message was handled
    }

    void UI_Object::refresh()
    {
      m_bMouseOver = false;
      m_bHasFocus = false;
      m_bPressed = false;
      // Reset other states if necessary
    }

    bool UI_Object::msgProc(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
      if (pDialog == nullptr)
        return false;
      // Handle messages here
      switch (uMsg)
      {
      case WM_MOUSEMOVE:
        // Handle mouse move
        break;
      case WM_LBUTTONDOWN:
        // Handle left button down
        break;
      case WM_LBUTTONUP:
        // Handle left button up
        break;
      case WM_RBUTTONDOWN:
        // Handle right button down
        break;
      case WM_RBUTTONUP:
        // Handle right button up
        break;
      default:
        return false; // Not handled
      }
      return true; // Message handled
    }
}
