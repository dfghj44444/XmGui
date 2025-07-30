/*

file : XM_UI_Manager.cpp

*/
#include "stdafx.h"

namespace XM
{
	XM_RTTI_CREATE_STATIC(UI_Manager, L"UI_Manager", UI_Box);
	int UI_Manager::s_SuperID = 100;
	UI_Object* UI_Manager::m_pFocus = nullptr;
	///////////////////////////////////////////////////////////////////////////
	// ctor/dtor
	UI_Manager::UI_Manager()
	{
		XM_RTTI_INIT_POINTER;

		m_nDefaultControl	= 0;
		m_pEventCallback	= nullptr;
		m_pUserContext		= nullptr;
		m_nSuperID		= s_SuperID++;
		m_pMouseOver		= nullptr;
		m_bAlphaCkeck		= false;
		//////////////////////////////////////////////////////////////////////////
		g_pStaticEngine->addStatusUIManager(this);
	}

	UI_Manager::~UI_Manager()
	{
		clear();
		g_pStaticEngine->removeStatusUIManager(this);	
	}
	///////////////////////////////////////////////////////////////////////////
	// default control id
	void UI_Manager::setDefaultControlID(int nID)
	{
		m_nDefaultControl = nID;
	}
	int UI_Manager::getDefaultControlID()
	{
		return m_nDefaultControl;
	}
	// default control id
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	// serialize
	bool UI_Manager::saveFile(IStream& rStream)
	{		
		if (!UI_Box::saveFile(rStream))
			return false;
		// write classes
		int nSize = m_listControls.size();
		ISTREAM_WRITEINT(rStream, nSize) ;
		for(int i = 0; i<nSize; ++i)
		{
			// write class string
			ISTREAM_WRITESTRING(rStream, m_listControls[i]->getRTTI()->getName());
			// write class
			if(m_listControls[i]->saveFile(rStream) == false) return false;
		}

		// write default control id
		ISTREAM_WRITEINT(rStream, m_nDefaultControl);

		return true;
	}
	bool UI_Manager::loadFile(IStream& rStream)
	{		
		clear();	

		if (!UI_Box::loadFile(rStream))
			return false;

		// read classes
		int nSize;
		ISTREAM_READINT(rStream, &nSize);

		for(int i = 0 ; i < nSize ; ++i)
		{
			// read class string
			CStringW strClassName;
			ISTREAM_READSTRING(rStream, &strClassName) ;

			// create class instance
            UI_Widget* pControl = createControl(strClassName);
			if(pControl == nullptr)
				return false;

			// load class
			if(pControl->loadFile(rStream) == false) 
                return false;

            pControl->setSuperID(m_nSuperID);

			// add to list
			if(addControl(pControl) == false) 
                return false;
		}
		
		// read default control id
		ISTREAM_READINT(rStream, &m_nDefaultControl);

		_SAFE_DEREF(m_pFocus);
		_SAFE_DEREF(m_pMouseOver);

		return true;
	}
	// serialize
	///////////////////////////////////////////////////////////////////////////
	void UI_Manager::clear()
	{
		_SAFE_DEREF(m_pFocus);
		_SAFE_DEREF(m_pMouseOver);	

		int nSize = m_listControls.size();
		for(int i = 0; i<nSize; ++i)
		{
			m_listControls[i]->DelRef();
		}
		m_listControls.clear();
	}

	// skill receiver
	///////////////////////////////////////////////////////////////////////////
	UI_Object* UI_Manager::GetMouseUpFocus()
	{
			return m_pFocus;
	}

	void UI_Manager::onMouseMove(int nMouseX, int nMouseY)
	{
	
		if(m_pMouseOver)
		{
			m_pMouseOver->onMouseLeave();
			m_pMouseOver->DelRef();
			m_pMouseOver = nullptr;
		}
		UI_Object* pControl = getMouseObject();
		m_pMouseOver = pControl;		
		
		if(m_pMouseOver)
		{
			m_pMouseOver->AddRef();
			m_pMouseOver->onMouseEnter();		
		}
	}
	// get mouse up
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// focus object
	void UI_Manager::clearFocus()
	{
		if(m_pFocus)
		{
			m_pFocus->onFocusOut();
			m_pFocus->DelRef();
			m_pFocus = nullptr;
		}
	}
	void UI_Manager::focusDefaultControl()
	{
		int nSize = m_listControls.size();
		for(int i = 0; i<nSize; ++i)
		{
			if(m_listControls[i]->getID() == m_nDefaultControl)
			{
				if(m_pFocus == m_listControls[i])
					return;

				if(m_pFocus)
				{
					m_pFocus->onFocusOut();
					m_pFocus->DelRef();
					m_pFocus = nullptr;
				}

				m_pFocus = m_listControls[i];
				m_pFocus->onFocusIn();
				m_pFocus->AddRef();
			}
		}
	}
	void UI_Manager::setFocus(UI_Object* pControl)
	{
		if(m_pFocus == pControl)
			return;

		if(m_pFocus)
		{
			m_pFocus->onFocusOut();
			m_pFocus->DelRef();
			m_pFocus = nullptr;
		}

		if(pControl)
			m_pFocus = pControl;

		if(m_pFocus)
		{
			m_pFocus->onFocusIn();
			m_pFocus->AddRef();
		}
	}
	void UI_Manager::setNextFocus()
	{
		if(m_pFocus == nullptr)
		{
			focusDefaultControl();
			return;
		}

		int nSize = m_listControls.size();
		if(nSize <= 1)
		{
			return;
		}

		int nIndex = m_listControls.find(m_pFocus);
		nIndex++;
		if(nIndex >= nSize)
		{
			nIndex = 0;
		}

		if(m_pFocus)
		{
			m_pFocus->onFocusOut();
			m_pFocus->DelRef();
			m_pFocus = nullptr;
		}

		m_pFocus = m_listControls[nIndex];
		m_pFocus->onFocusIn();
		m_pFocus->AddRef();
	}
	void UI_Manager::refresh()
	{
		if(m_pFocus)
		{
			m_pFocus->onFocusOut();
			m_pFocus->DelRef();
			m_pFocus = nullptr;
		}

		if(m_pMouseOver)
		{
			m_pMouseOver->onMouseLeave();
			m_pMouseOver->DelRef();
			m_pMouseOver = nullptr;
		}

		int nSize = m_listControls.size();
		for(int i = 0; i<nSize; ++i)
		{
			m_listControls[i]->refresh();
		}

		UI_Object* pControl = getMouseObject();
		if(pControl)
		{
			m_pMouseOver = pControl;
			m_pMouseOver->AddRef();
			m_pMouseOver->onMouseEnter();
		}

		if(m_bUseKeyboard == true)
		{
			focusDefaultControl();
		}
	}
	// focus object
	///////////////////////////////////////////////////////////////////////////

	void UI_Manager::SetAlphaCheck(const bool& bFlag)
	{
		m_bAlphaCkeck = bFlag;
		m_fAlpha = 0;
	}

	// frame move
	void UI_Manager::frameMove(DWORD dwElapsedTime)
	{
		if(m_bVisible == false )
		{
			return;
		}

		if( m_bAlphaCkeck == false ) 
		{
			int nSize = m_listControls.size();
			for( int i = 0; i < nSize; ++i )
			{
				if( m_listControls[i] )
				{
					m_listControls[i]->frameMove(dwElapsedTime);
				}
			}
			return;
		}

		int nSize = m_listControls.size();
				
		m_fAlpha += ( static_cast<float>(dwElapsedTime) / 3000.0f ) * 1500.0f;

		for( int i = 0; i < nSize; ++i )
		{
			if( m_listControls[i] )
			{
				m_listControls[i]->frameMove(dwElapsedTime);
				
				if( true == m_bAlphaCkeck )
				{
					//wait to do impliment
					//m_listControls[i]->SetAlpha(m_fAlpha);//内部遍历					
				}				
			}
		}
	}

	
	// frame move
	
	///////////////////////////////////////////////////////////////////////////
	// render
	void UI_Manager::render(IDirect3DDevice9* pd3dDevice)
	{
		if(!m_bVisible)
		{
			return;
		}

		// alpha test		
		pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
		pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

		pd3dDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE); 
		pd3dDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);
		pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
		pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
		pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);

		
		int nSize = m_listControls.size();
		bool bRenderFocusedSkill = false;
		for(int i = 0; i<nSize; ++i)
		{
			m_listControls[i]->render( pd3dDevice);
		}

		if( bRenderFocusedSkill == true )
		{
			m_pFocus->render( pd3dDevice);
		}

		if( m_pFocus )
		{
			m_pFocus->render( pd3dDevice );
		}

        pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
        pd3dDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE); 
        pd3dDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
        pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	}
	// render
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// message handler
	bool UI_Manager::msgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		if (!m_bVisible || !m_bEnabled)
			return false;

		if(m_pFocus)
		{
			if(m_pFocus->getEnabled() == true)
			{
				if( m_pFocus->getSuperID() == this->getSuperID() )
				{
					if(m_pFocus->msgProc(this, uMsg, wParam, lParam) == true)
					{
						return true;
					}
				}
			}
		}

		int nMouseX, nMouseY;
		g_pStaticMouseUtil->getMousePos(&nMouseX, &nMouseY);

        if (nMouseX < 0 || nMouseX > _SCREEN_WIDTH)
            uMsg = WM_LBUTTONUP;
        if (nMouseY < 0 || nMouseY > _SCREEN_HEIGHT)
            uMsg = WM_LBUTTONUP;

		UI_Object* pControl = getMouseObject();
		//-----------------------------------------------------------------------------------------------------------------------------
		//[TIP] :
		//-----------------------------------------------------------------------------------------------------------------------------	
		switch(uMsg)
		{
		case WM_LBUTTONDOWN:
			{
				if(pControl != nullptr && pControl->getEnabled() == true)
				{				
					//TODO: 如果按住标题，就可以拖动窗口
				}
			}
		case WM_SIZE:
		case WM_MOVE:
			onMouseMove(-1, -1);
			break;

		case WM_ACTIVATEAPP:
			{
				if(m_pFocus)
				{
					if(m_pFocus->getEnabled() == true)
					{
						if(wParam)
						{
							m_pFocus->onFocusIn();
						}
						else
						{
							m_pFocus->onFocusOut();
						}
					}
				}
			}
			break;
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYUP:
			if(m_pFocus)
			{
				if(m_pFocus->getEnabled() == true && m_pFocus->getVisible() == true)
				{
					if(m_pFocus->handleKeyboard(this, uMsg, wParam, lParam) == true)
					{
						return true;
					}
				}
			}	

			//
			if(uMsg == WM_KEYDOWN)
			{
				if(m_bUseKeyboard == false)
				{
					return false;
				}		

			}
		case WM_MOUSEMOVE:
			{						
				onMouseMove(nMouseX, nMouseY);
			}
		case WM_LBUTTONUP:
		case WM_LBUTTONDBLCLK:
		case WM_RBUTTONDOWN:
		case WM_RBUTTONUP:
		case WM_RBUTTONDBLCLK:
		case WM_MBUTTONDOWN:
		case WM_MBUTTONUP:
		case WM_MBUTTONDBLCLK:
		case WM_MOUSEWHEEL:
			{
				if(m_bUseMouse == false)
				{
					return false;
				}

				UI_Object* pControl = getMouseObject();
				if (m_pFocus  && hasControl(m_pFocus))
				{
                    if(m_pFocus->getEnabled() && m_pFocus->getSuperID() == getSuperID() )
                    {
                        m_pFocus->handleMouse(this, uMsg, wParam, lParam);
                    }
				}				
				
				if( pControl ) 
				{				
					if(pControl->getEnabled() == true)
					{
						setDefaultControlID( pControl->getID() );

						if( pControl->getSuperID() == this->getSuperID() )
						{					
							if(pControl->handleMouse(this, uMsg, wParam, lParam) == true)
							{
								return true;
							}
						}
					}
				}
				else
				{
					if(uMsg == WM_LBUTTONDOWN)
					{
						if(m_pFocus && hasControl(m_pFocus))
						{
							m_pFocus->onFocusOut();
							m_pFocus->DelRef();
							m_pFocus = nullptr;
						}
					}
				}
				break;
			}
		}
		return false;
	}
	// message handler
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// callback function
	void UI_Manager::setEventCallback(PCALLBACKSTATUSGUIEVENT pCallback, void* pUserContext)
	{
		m_pEventCallback = pCallback;
		m_pUserContext = pUserContext;
	}

	void UI_Manager::sendEvent(UINT nEvent, bool bTriggeredByUser, UI_Object* pControl)
	{
		XM_ASSERT(pControl);
		if(pControl == nullptr)			return;
		if(m_pEventCallback == nullptr)			return;

		m_pEventCallback(nEvent, pControl->getID(), pControl, m_pUserContext);
	}
	// callback func
	//////////////////////////////////////	/////////////////////////////////////

	UI_Widget* createControl(const CStringW& name)
	{
		UI_Widget* pControl = nullptr;
		if(name == UI_Widget::RTTI.getName()){
			_NEW(pControl, UI_Widget);
		}else if(name == UI_Button::RTTI.getName()){
			_NEW(pControl, UI_Button);
		}
		//可以改成从engine的NameMap里找名字，并生成新控件
		XM_ASSERT(pControl && "createControl invalid class name");
		return pControl;
	}

} // namespace XM