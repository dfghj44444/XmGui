/*

file : ANW_StatusUI_Button.cpp

*/


#include "stdafx.h"

namespace ANW
{
	// RTTI 상속
	ANW_RTTI_CREATE_STATIC(StatusUI_Button, L"StatusUI_Button", StatusUI_Control);

	///////////////////////////////////////////////////////////////////////////
	// ctor/dtor
	StatusUI_Button::StatusUI_Button()
	{
		// RTTI 클래스포인터 저장
		ANW_RTTI_INIT_POINTER;

		// control type
		m_ControlType	= SCT_BUTTON;

		// 버튼 생성
		StatusUI_Rect* pRect;
		ANW_NEW(pRect, StatusUI_Rect);
		if(addRect(pRect) == false)
		{
			ANW_ASSERT(0);
		}
	}

	StatusUI_Button::~StatusUI_Button()
	{
		clear();
	}
	// ctor/dtor
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// serialize
	bool StatusUI_Button::saveFile(IStream& rStream)
	{
		if( false == StatusUI_Control::saveFile(rStream) )	return false;

		return true;
	}
	bool StatusUI_Button::loadFile(IStream& rStream)
	{
		if( false == StatusUI_Control::loadFile(rStream) )	return false;
		
		return true;
	}
	// serialize
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// init/refresh
	HRESULT StatusUI_Button::onInit()
	{
		return S_OK;
	}
	void StatusUI_Button::refresh()
	{
		m_bMouseOver = false;
		m_bHasFocus = false;
	}
	// init/refresh
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// render
	void StatusUI_Button::render(StatusUI_Manager* pDialog, IDirect3DDevice9* pd3dDevice)
	{
		if(m_bVisible == false)
		{
			return;
		}
		
		int nSize = m_listRect.size();
		for(int i = 0; i<nSize; ++i)
		{
			m_listRect[i]->render(pd3dDevice);
		}

	}
	// render
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// message handler
	void StatusUI_Button::onFocusIn(StatusUI_Manager* pDialog)
	{
		m_bHasFocus = true;
		updateControlState();
	}
	void StatusUI_Button::onFocusOut(StatusUI_Manager* pDialog)
	{
		m_bHasFocus = false;
		updateControlState();
	}
	void StatusUI_Button::onMouseEnter(StatusUI_Manager* pDialog)
	{
		m_bMouseOver = true;
		updateControlState();
	}
	void StatusUI_Button::onMouseLeave(StatusUI_Manager* pDialog)
	{
		m_bMouseOver = false;
		//  [8/7/2007 조을형]
		m_bPressed = false;
		updateControlState();		

		//pDialog->sendEvent(SET_CHAT_BG_HIDE,true,this);
	}
	void StatusUI_Button::onHotkey(StatusUI_Manager* pDialog)
	{
		if(pDialog)
		{
			pDialog->setFocus(this);
			pDialog->sendEvent(SET_BUTTON_CLICKED, true, this );			
		}		
	}
	bool StatusUI_Button::handleMouse(StatusUI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		if((m_bVisible == false)||(m_bEnabled == false)||(pDialog == 0))
		{
			return false;
		}

		if(pDialog == 0)
		{
			return false;
		}

		HWND hWnd = g_pStaticEngine->getHwnd();
		if(hWnd == 0)
		{
			return false;
		}

		float fDist;
		int mouseX, mouseY;
		g_pStaticMouseUtil->getMousePos(&mouseX, &mouseY);

		switch(uMsg)
		{
		case WM_RBUTTONDOWN:
		case WM_LBUTTONDOWN:
		case WM_LBUTTONDBLCLK:
			if(hitTest(mouseX, mouseY, fDist))
			{
				m_bPressed = true;
				SetCapture(hWnd);
				pDialog->setFocus(this);
				
				//  [8/7/2007 조을형]
				updateControlState();

				return true;
			}
			break;

		case WM_LBUTTONUP:
			if(m_bPressed == true)
			{
				m_bPressed = false;				
				ReleaseCapture();		

				if(pDialog->getUseKeyboard() == false)
				{
					pDialog->clearFocus();
				}

				if(hitTest(mouseX, mouseY, fDist))
				{
					updateControlState();
					pDialog->sendEvent(SET_BUTTON_CLICKED, true, this);					
				}
				else
				{
					m_bHasFocus = false;
					updateControlState();
				}
				return true;
			}
		case WM_RBUTTONUP:
			{
				if(m_bPressed == true) 
				{
					m_bPressed = false;				
					ReleaseCapture();		

					if(pDialog->getUseKeyboard() == false)
					{
						pDialog->clearFocus();
					}

					if(hitTest(mouseX, mouseY, fDist))
					{
						updateControlState();
						pDialog->sendEvent(SET_BUTTON_R_CLECK, true, this);					
					}
					else
					{
						m_bHasFocus = false;
						updateControlState();
					}
					return true;
				}
			}		
		}

		return false;
	}
	bool StatusUI_Button::msgProc(StatusUI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		return false;
	}
	///////////////////////////////////////////////////////////////////////////

} // namespace ANW