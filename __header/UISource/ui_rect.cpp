/*

file : XM_UI_Rect.cpp

*/


#include "stdafx.h"

namespace XM
{
	XM_RTTI_CREATE_STATIC(UI_Rect, L"UI_Rect", UI_Base);

	///////////////////////////////////////////////////////////////////////////
	// ctor/dtor
	UI_Rect::UI_Rect()
	{
		XM_RTTI_INIT_POINTER;

		// init control states
		m_controlState = SCT_NORMAL;
		for(int i = 0; i<SCT_STATUS_COUNT; ++i)
		{
			m_Items[i] = nullptr;
		}

		m_uRectID = 0;
	}
	UI_Rect::~UI_Rect()
	{
		// delete control states
		for(int i = 0; i<SCT_STATUS_COUNT; ++i)
		{
			_SAFE_DEREF(m_Items[i]);
		}
	}
	// ctor/dtor
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// serialize
	bool UI_Rect::saveFile(IStream& rStream)
	{
		ISTREAM_WRITEUINT(rStream, m_uRectID) ;

		for(int i = 0; i<SCT_STATUS_COUNT; ++i)
		{
			bool bExist = m_Items[i] ? true : false;
			ISTREAM_WRITEBool(rStream, bExist);

			if(bExist == true)
			{
				ISTREAM_WRITESTRING(rStream, m_Items[i]->getRTTI()->getName());
				if(m_Items[i]->saveFile(rStream) == false) return false;
			}
		}

		return true;
	}
	bool UI_Rect::loadFile(IStream& rStream)
	{
		ISTREAM_READUINT(rStream, &m_uRectID);

		for(int i = 0; i<SCT_STATUS_COUNT; ++i)
		{
			_SAFE_DEREF(m_Items[i]);
		}

		for(int i = 0; i<SCT_STATUS_COUNT; ++i)
		{
			bool bExist;
			ISTREAM_READBool(rStream, &bExist) ;

			if(bExist == true)
			{
				CStringW strClassName;
				ISTREAM_READSTRING(rStream, &strClassName);

				UI_RectItem* pRectItem = nullptr;

				// UI_RectItem
				if(strClassName == UI_RectItem::RTTI.getName())
				{
					_NEW(pRectItem, UI_RectItem);
					if(!pRectItem)
						return false;
				}
				// UI_RectItemText
				else if(strClassName == UI_RectItemText::RTTI.getName())
				{
					_NEW(pRectItem, UI_RectItemText);
					if(!pRectItem )
						return false;
				}
				m_Items[i] = pRectItem;
				pRectItem->AddRef();
			}
		}

		return true;
	}
	// serialize
	///////////////////////////////////////////////////////////////////////////

	
	///////////////////////////////////////////////////////////////////////////
	// alpha
	void UI_Rect::setAlpha( const int& nAl )
	{
		if( m_controlState < SCT_STATUS_COUNT)
		{
			if(m_Items[m_controlState])
			{
				m_Items[m_controlState]->setAlpha( nAl );
			}
		}
	}
	// alpha
	///////////////////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////////////////
	// render
	void UI_Rect::render(IDirect3DDevice9* pDevice)
	{
		XM_ASSERT(pDevice);
		if( m_controlState < SCT_STATUS_COUNT)
		{
			if(m_Items[m_controlState])
			{
				m_Items[m_controlState]->render(pDevice);
				
				if( SCT_FOCUSED == m_controlState )
				{
					if( m_Items[SCT_TIP] )
					{
						m_Items[SCT_TIP]->render( pDevice );
					}
					else if( m_Items[SCT_TIP_FOCUSED] )
					{
						m_Items[SCT_TIP_FOCUSED]->render( pDevice );
					}
				}
				else if( SCT_NORMAL == m_controlState )
				{
					if( m_Items[SCT_NORMAL])
					{
						m_Items[SCT_NORMAL]->render( pDevice );
					}
				}
				else if( SCT_PUSH == m_controlState )
				{
					if( m_Items[SCT_TIP] )
					{
						m_Items[SCT_TIP]->render( pDevice );
					}
					else if( m_Items[SCT_TIP_PUSH] )
					{
						m_Items[SCT_TIP_PUSH]->render( pDevice );
					}
				}
			}
		}
	}

    void UI_Rect::frameMove(DWORD dwElapsedTime)
    {
      for (const auto& item : m_Items)
      {
        if (item)
        {
            item->frameMove(dwElapsedTime);
        }
      }
     // updateControlState();
    }

    // render
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// hit test
	bool UI_Rect::hitTest(int mouseX, int mouseY, float& zOut)
	{
		if(m_controlState < SCT_STATUS_COUNT && m_Items[m_controlState])
			return m_Items[m_controlState]->hitTest(mouseX, mouseY, zOut);

		return false;
	}

    void UI_Rect::setState(STATUSUI_CONTROL_STATE cControlState)
    {
      if (cControlState >= SCT_INVISIBLE && cControlState < SCT_STATUS_COUNT)
      {
        m_controlState = cControlState;
      }
      else
      {
        m_controlState = SCT_NORMAL; // default state
      }
      // update the current item based on the control state
      if (m_Items[m_controlState])
      {
        //todo: m_Items[m_controlState]->setState(m_controlState);
      }
    }

    // hit test
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	// set control rect
	void UI_Rect::setItem(STATUSUI_CONTROL_STATE cCS, UI_RectItem* pRectItem)
	{
		if((cCS >= SCT_INVISIBLE)&&(cCS < SCT_STATUS_COUNT ) )
		{
			_SAFE_DEREF(m_Items[cCS]);
			m_Items[cCS] = pRectItem;
			if(pRectItem)
				pRectItem->AddRef();
		}
	}
	UI_RectItem* UI_Rect::getItem(STATUSUI_CONTROL_STATE cCS)
	{
		return m_Items[cCS];
	}
	UI_RectItem* UI_Rect::getCurrentItem()
	{
		return m_Items[m_controlState];
	}
	// set control rect
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// rect ID
	void UI_Rect::setRectID(unsigned int uRectID)
	{
		m_uRectID = uRectID;
	}
	unsigned int UI_Rect::getRectID()
	{
		return m_uRectID;
	}
	// rect ID
	///////////////////////////////////////////////////////////////////////////


	void UI_Rect::setParentPos(const D3DXVECTOR3& vParent)
	{
		for(int i = 0; i<SCT_STATUS_COUNT; ++i)
		{
			if(m_Items[i])
			{
				m_Items[i]->setParentPos(vParent);
			}
		}
	}

    void UI_Rect::setPos(const D3DXVECTOR3& vPos)
    {
        for(int i = 0; i < SCT_STATUS_COUNT; ++i)
        {
            if(m_Items[i])
            {
                m_Items[i]->setPos(vPos);
            }
        }
    }


} // namespace XM