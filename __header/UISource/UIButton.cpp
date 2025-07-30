#include "stdafx.h"
#include "uibutton.h"

namespace XM
{
	// RTTI 定义
	XM_RTTI_CREATE_STATIC(UI_Button, L"UI_Button", UI_Widget);

	///////////////////////////////////////////////////////////////////////////
	// ctor/dtor
	UI_Button::UI_Button()
	{
		XM_RTTI_INIT_POINTER;

		// control type
		//m_ControlType	= SCT_BUTTON;

		UI_Rect* pRect;
		_NEW(pRect, UI_Rect);
		if(addRect(pRect) == false)
		{
			XM_ASSERT(0);
		}
	}

	UI_Button::~UI_Button()
	{
		clear();
	}
	// ctor/dtor
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// serialize
	bool UI_Button::saveFile(IStream& rStream)
	{
		if( false == UI_Widget::saveFile(rStream) )	return false;

		return true;
	}
	bool UI_Button::loadFile(IStream& rStream)
	{
		if( false == UI_Widget::loadFile(rStream) )	return false;
		
		return true;
	}
	// serialize
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// init/refresh
	HRESULT UI_Button::onInit()
	{
		return S_OK;
	}
	void UI_Button::refresh()
	{
		m_bMouseOver = false;
		m_bHasFocus = false;
	}
	// init/refresh
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// render
	void UI_Button::render(UI_Manager* pDialog, IDirect3DDevice9* pd3dDevice)
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
	void UI_Button::onFocusIn(UI_Manager* pDialog)
	{
		m_bHasFocus = true;
		updateControlState();
	}
	void UI_Button::onFocusOut(UI_Manager* pDialog)
	{
		m_bHasFocus = false;
		updateControlState();
	}
	void UI_Button::onMouseEnter(UI_Manager* pDialog)
	{
		m_bMouseOver = true;
		updateControlState();
	}
	void UI_Button::onMouseLeave(UI_Manager* pDialog)
	{
		m_bMouseOver = false;
		//  [8/7/2007 ]
		m_bPressed = false;
		updateControlState();		

		//pDialog->sendEvent(SET_CHAT_BG_HIDE,true,this);
	}
	void UI_Button::onHotkey(UI_Manager* pDialog)
	{
		if(pDialog)
		{
			pDialog->setFocus(this);
			pDialog->sendEvent(SET_BUTTON_CLICKED, true, this );			
		}		
	}
	bool UI_Button::handleMouse(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		if((m_bVisible == false)||(m_bEnabled == false)||(pDialog == nullptr))
		{
			return false;
		}

		if(pDialog == nullptr)
		{
			return false;
		}

		HWND hWnd = g_pStaticEngine->getHwnd();
		if(hWnd == nullptr)
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
				
				//  [8/7/2007 ]
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
						pDialog->sendEvent(SET_BUTTON_R_CLICKED, true, this);					
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
	bool UI_Button::msgProc(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		return false;
	}
	///////////////////////////////////////////////////////////////////////////

} // namespace XM