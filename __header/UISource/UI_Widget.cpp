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
@File Name:UI_Contorl.cpp
@Describe:This is a part of XM_GUI
@Create Date:2010-10-7 14:01:29
@Version:1.0
@Author£ºDouble One
@Blog£º http://onedouble.cnblogs.com
@Modifier: Double One (dfghj77777@gmail.com)
@Modify Date£º2013-08-05 14:01:30
@Modify Reason£º
***********************************************************************/

#include "stdafx.h"

namespace XM
{
	// RTTI
	XM_RTTI_CREATE_STATIC(UI_Widget, L"UI_Control", UI_Object);

	///////////////////////////////////////////////////////////////////////////
	// ctor/dtor
	UI_Widget::UI_Widget()
	{
		XM_RTTI_INIT_POINTER;
		// using hit-test
		m_bHitTest		= true;
		// L-Button Pressed
		m_bPressed		= false;
		// mouse over
		m_bMouseOver	= false;
		// focus
		m_bHasFocus		= false;
		// control state
		m_ControlState	= getControlState();

		updateControlState();		
	}

	UI_Widget::~UI_Widget()
	{
		clear();
	}
	// ctor/dtor
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// clear
	void UI_Widget::clear()
	{
		m_bPressed		= false;
		m_bMouseOver	= false;
		m_bHasFocus		= false;
		m_nSuperID	= 0;

		// clear rects
		int nSize = m_listRect.size();
		for(int i = 0; i<nSize; ++i)
		{
			if( m_listRect[i] )
			{
				m_listRect[i]->DelRef();
			}
		}
		m_listRect.clear();		
	}
	// clear
	///////////////////////////////////////////////////////////////////////////

	int UI_Widget::DivideString(CHAR* lpszSrc, int nBytePerLine, LPTSTR* alpszDst)
	{
		if( strlen( lpszSrc ) <= 0 )
			return 1;
		int nSrcPos = 0;			
		int nSrcLen = static_cast<int>( strlen(lpszSrc) );
		//int nDstStart = 0;			
		int nDstLen = 1;			
		int nLineCount = 0;			

		while (TRUE)
		{
			if (0x80 & lpszSrc[nSrcPos])	
			{
				nSrcPos++;
				nDstLen++;
			}


			if (nDstLen > nBytePerLine)
			{
				nSrcPos -= 2;
				nDstLen -= 2;
				nLineCount += 1;
				nDstLen = 0;
			}
			else if (nDstLen >= nBytePerLine)
			{
				nLineCount++;
				nDstLen = 0;
			}

			else if (nSrcPos >= nSrcLen - 1)
			{
				break;
			}
			nSrcPos++;
			nDstLen++;
		}
		nLineCount += 1;
		if( nLineCount > 7 )
			nLineCount += 1;
		return nLineCount;
	}


	// is enabled
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// hit-test
	void UI_Widget::setHitTest(bool bFlag)
	{
		m_bHitTest = bFlag;
	}	
	// hit-test
	///////////////////////////////////////////////////////////////////////////
	void UI_Widget::updatePosition()
	{
		D3DXVECTOR3 vCurrentPos = m_vParentPos + m_vPos;
		int nSize = m_listRect.size();
		for(int i = 0; i<m_listRect.size(); ++i)
		{
			m_listRect[i]->setParentPos(vCurrentPos);
		}
	}
	// position
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// control state
	void UI_Widget::updateControlState()
	{
		STATUSUI_CONTROL_STATE iState = SCT_NORMAL;

		if(m_bVisible == false)
			iState = SCT_INVISIBLE;
		else if(m_bEnabled == false)
			iState = SCT_DISABLED;
		else if( m_bPressed )
			iState = SCT_PUSH;
		else if((!m_bPressed&&m_bMouseOver)|| m_bHasFocus)
			iState = SCT_FOCUSED;

		m_ControlState = iState;

		int nSize = m_listRect.size();
		for(int i = 0; i<nSize; ++i)
			m_listRect[i]->setState(m_ControlState);
	}
	STATUSUI_CONTROL_STATE UI_Widget::getControlState() const
	{
		return m_ControlState;
	}
	// control state
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// rects
	bool UI_Widget::addRect(UI_Rect* pRect)
	{
		XM_ASSERT(pRect);
		if(pRect == 0)
		{
			return false;
		}

		if(findRect(pRect) < 0)
		{
			pRect->setParentPos(m_vPos + m_vParentPos);
			m_listRect.push_back(pRect);
			pRect->AddRef();
			return true;
		}
		return false;
	}

	bool UI_Widget::removeRect(UI_Rect* pRect)
	{
		XM_ASSERT(pRect);
		if(pRect == 0)
		{
			return false;
		}

		int nIndex = findRect(pRect);
		if(nIndex >= 0)
		{
			m_listRect.erase(nIndex);
			pRect->DelRef();
			return true;
		}
		return false;
	}

	int UI_Widget::findRect(UI_Rect* pRect)
	{
		XM_ASSERT(pRect);
		if(pRect == 0)
		{
			return -1;
		}
	
		return m_listRect.find(pRect);
	}

	UI_Rect* UI_Widget::getRectByOrdinal(int nOrdinal)
	{
		int nSize = m_listRect.size();
		if(nSize > 0)
		{
			if((nOrdinal >= 0)&&(nOrdinal < nSize)) 
			{
				return m_listRect[nOrdinal];
			}
		}
		return 0;
	}
	// rects
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// rect item
	void UI_Widget::setRectItem(int nRectOrdinal, STATUSUI_CONTROL_STATE cCS, UI_RectItem* pRectItem)
	{
		UI_Rect* pRect = getRectByOrdinal(nRectOrdinal);
		if(pRect)
		{
			pRect->setItem(cCS, pRectItem);
		}
	}
	void UI_Widget::setRectItem(int nRectOrdinal, UI_RectItem* pRectItem)
	{
		UI_Rect* pRect = getRectByOrdinal(nRectOrdinal);
		if(pRect)
		{
			for(int i = 0; i<SCT_STATUS_COUNT; ++i)
			{
				pRect->setItem((STATUSUI_CONTROL_STATE)i, pRectItem);
			}
		}
	}
	UI_RectItem* UI_Widget::getRectItem(int nRectOrdinal, STATUSUI_CONTROL_STATE cCS)
	{
		UI_Rect* pRect = getRectByOrdinal(nRectOrdinal);
		if(pRect)
		{
			return pRect->getItem(cCS);
		}
		return 0;
	}	
	// rect item
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// serialize
	bool UI_Widget::saveFile(IStream& rStream)
	{
		ISTREAM_WRITEBool(rStream, m_bHitTest);

		ISTREAM_WRITEINT(rStream, m_ControlState) ;

		int nSize = m_listRect.size();
		ISTREAM_WRITEINT(rStream, nSize) ;
		for(int i = 0; i<nSize; ++i)
		{
			if(m_listRect[i]->saveFile(rStream) == false) return false;
		}

		return true;
	}
	bool UI_Widget::loadFile(IStream& rStream)
	{
		clear();		// clear all
		ISTREAM_READBool(rStream, &m_bHitTest) ;
		ISTREAM_READINT(rStream, &m_ControlState);

		bool bTemp;
		ISTREAM_READBool(rStream, &bTemp) ;
		if(bTemp == true)
		{
			CStringW strFontName;
			int nFontWeight;
			int nFontHeight;
			BOOL bItalic;
			ISTREAM_READSTRING(rStream, &strFontName) ;
			ISTREAM_READINT(rStream, &nFontHeight) ;
			ISTREAM_READINT(rStream, &nFontWeight) ;
			ISTREAM_READBOOL(rStream, &bItalic) ;
			if(setFont(strFontName, nFontHeight, nFontWeight, bItalic) == false)
			{
				return false;
			}
		}

		int nSize;
		UI_Rect* pRect;
		ISTREAM_READINT(rStream, &nSize) ;
		for(int i = 0; i<nSize; ++i)
		{
			_NEW(pRect, UI_Rect);
			if(pRect == NULL)
				return false;

			if(pRect->loadFile(rStream) == false) return false;
			m_listRect.push_back(pRect);
			pRect->AddRef();
		}

		updatePosition();
		updateControlState();

		return true;
	}
	// serialize
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// init/refresh
	HRESULT UI_Widget::onInit()
	{
		return S_OK;
	}
	void UI_Widget::refresh()
	{
		m_bMouseOver = false;
		m_bHasFocus = false;
	}
	// init/refresh
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// hit test
	UI_Object* UI_Widget::hitTest(int nMouseX, int nMouseY,OUT float& pZOut)
	{
		if (!m_bVisible || !m_bEnabled || !m_bHitTest)
			return NULL;

		int nSize = m_listRect.size();
		for(int i = 0; i<nSize; ++i)
		{
			if(m_listRect[i]->hitTest(nMouseX, nMouseY, pZOut))
				return this;
		}

		return NULL;
	}
	// hit test
	///////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// framemove
	void UI_Widget::frameMove( DWORD dwElapsedTime )
	{
        updatePosition();
	}
	//////////////////////////////////////////////////////////////////////////()

	void UI_Widget::render( IDirect3DDevice9* pd3dDevice)
	{
		for (int i =0;i < SCT_STATUS_COUNT;i++)
		{
			m_listRect[i]->render(pd3dDevice);
		}
	}
	// render
	///////////////////////////////////////////////////////////////////////////

	bool UI_Widget::handleKeyboard(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		return false;
	}
	bool UI_Widget::handleMouse(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		return false;
	}
	bool UI_Widget::msgProc(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		return false;
	}

	void UI_Widget::setChangeAlpha(bool bChange)
	{
		m_bChangeAlpha = bChange;
	}

	bool UI_Widget::getChangeAlpah()
	{
		return m_bChangeAlpha;
	}

	///////////////////////////////////////////////////////////////////////////
	
} // namespace XM