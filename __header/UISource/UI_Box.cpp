#include "stdafx.h"

namespace XM
{

    XM_RTTI_CREATE_STATIC(UI_Box, L"UI_Box", UI_Object);

    UI_Box::UI_Box()
        :m_fOffsetX(0),
		m_Width(0),
		m_Height(0),
		m_vPos(0.0f, 0.0f, -0.01f)
        ,m_fOffsetY(0)
    {
        XM_RTTI_INIT_POINTER;
    }

    UI_Box::~UI_Box()
    {
        int nSize = m_listControls.size();
        for(int i = 0; i < nSize; ++i)
        {
            m_listControls[i]->DelRef();
        }
        m_listControls.clear();
    }

    bool UI_Box::saveFile(IStream& rStream)
    {
        if (!UI_Object::saveFile(rStream))
            return false;

        ISTREAM_WRITEFLOAT(rStream, m_fOffsetX);
        ISTREAM_WRITEFLOAT(rStream, m_fOffsetY);

        // write classes
        int nSize = m_listControls.size();
        ISTREAM_WRITEINT(rStream, nSize);

        for(int i = 0; i < nSize; ++i)
        {
            // write class string
            ISTREAM_WRITESTRING(rStream, m_listControls[i]->getRTTI()->getName()) ;
            // write class
            if (!m_listControls[i]->saveFile(rStream)) 
                return false;
        }
        return true;
    }

    bool UI_Box::loadFile(IStream& rStream)
    {
        if (UI_Object::loadFile(rStream) == false)            return false;

        ISTREAM_READFLOAT(rStream, &m_fOffsetX);
        ISTREAM_READFLOAT(rStream, &m_fOffsetY);

        int nSize;
        ISTREAM_READINT(rStream, &nSize);

        for (int i = 0; i < nSize; ++i)
        {
            // read class string
            CStringW strClassName;
            ISTREAM_READSTRING(rStream, &strClassName);

            // create class instance
            UI_Widget* pControl = createControl(strClassName);
            if(pControl == NULL)          return false;
            // load class
            if(!pControl->loadFile(rStream)) 
                return false;

            // add to list
            if(!addControl(pControl))
                return false;
        }

        return true;
    }

    void UI_Box::setSuperID(int nID)
    {
        for (int i = 0; i < m_listControls.size(); ++i)
            m_listControls[i]->setSuperID(m_nSuperID);
    }

    void UI_Box::setOffset(float x, float y)
    {
        m_fOffsetX = x;
        m_fOffsetY = y;
		updatePosition();
    }

    void UI_Box::frameMove(DWORD dwElapsedTime)
    {
        for( int i = 0; i < (int) m_listControls.size(); ++i )
            m_listControls[i]->frameMove(dwElapsedTime);
    }

    void UI_Box::render(IDirect3DDevice9* pd3dDevice)
    {
        D3DVIEWPORT9 vp;
        vp.MinZ = 0.f;
        vp.MaxZ = 1.f;

        vp.X = static_cast<DWORD>(max(0, getPosX()))+4;
        vp.Y = static_cast<DWORD>(max(0, getPosY()));
        vp.Width = static_cast<DWORD>(getPosX() + (float)m_Width - (float)vp.X);
        vp.Height = static_cast<DWORD>(getPosY() + (float)m_Height - (float)vp.Y);
        pd3dDevice->SetViewport(&vp);

        for (int i = 0; i < m_listControls.size(); ++i)
            m_listControls[i]->render( pd3dDevice);

        vp.X = 0;
        vp.Y = 0;
        vp.Width = _SCREEN_WIDTH;
        vp.Height = _SCREEN_HEIGHT;
        pd3dDevice->SetViewport(&vp);
    }

    UI_Object* UI_Box::hitTest(int nMouseX, int nMouseY, float& zDist)
    {
        float closerDist = 0.f;
        UI_Object* pHitUI = NULL;

        int nSize = m_listControls.size();
        for(int i = 0; i < nSize; ++i)
        {
            UI_Object* pUI = m_listControls[i]->hitTest(nMouseX, nMouseY, zDist);
            if (pUI &&zDist < closerDist)
            {
                pHitUI = pUI;
                closerDist = zDist;
				break;
            }
        }

        zDist = closerDist;
        return pHitUI;
    }

    UI_Object* UI_Box::findControl(int nControlID) const
    {
        int nSize = m_listControls.size();
        for(int i = 0; i<nSize; ++i)
        {
			if(m_listControls[i]->getID() == nControlID)
				return m_listControls[i];

			if (m_listControls[i]->getRTTI()->isAKindOf(&UI_Box::RTTI))
            {
                UI_Object* pControl = static_cast<UI_Box*>(m_listControls[i])->findControl(nControlID);
                if (pControl)
                    return pControl;
            }
        }

        return NULL;
    }

	UI_Object* UI_Box::getMouseObject()
	{
		// get current mouse position
		int mouseX, mouseY;
		g_pStaticMouseUtil->getMousePos(&mouseX, &mouseY);

		float zDist;
		return hitTest(mouseX, mouseY, zDist);
	}


    bool UI_Box::hasControl(UI_Object* pControl) const
    {
        return findControl(pControl->getID()) ? true : false;
    }

    bool UI_Box::addControl(UI_Object* pControl)
    {
        if (!pControl || findControl(pControl->getID()))
        {
            XM_ASSERT(false);
            return false;
        }

        m_listControls.push_back(pControl);
        pControl->AddRef();

        return true;
    }

    void UI_Box::setControlEnabled(int nID, bool bFlag)
    {
        int nSize = m_listControls.size();
        for(int i = 0; i < nSize; ++i)
        {
            if (m_listControls[i]->getID() == nID)
            {
                m_listControls[i]->setEnabled(bFlag);
                return;
            }

			if (m_listControls[i]->getRTTI()->isAKindOf(&UI_Box::RTTI) )
                static_cast<UI_Box*>(m_listControls[i])->setControlEnabled(nID, bFlag);
        }
    }

    int UI_Box::getControlEnabled(int nID, bool& value)
    {
		UI_Object* pUI = findControl(nID);
		if (pUI)
			value = pUI->getEnabled();
		else 
			return -1;

		return 0;
    }

	void UI_Box::updatePosition()
	{
		D3DXVECTOR3 vCurrentPos = m_vParentPos + m_vPos;
		for(int i = 0; i < m_listControls.size(); ++i)
			m_listControls[i]->setParentPos(vCurrentPos + getPosition() + D3DXVECTOR3(m_fOffsetX,m_fOffsetY,0.f));
	}
}