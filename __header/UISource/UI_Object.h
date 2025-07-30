/*

file : XM_UI_Base.h

*/

#ifndef H_XM_UI_OBJECT_H
#define H_XM_UI_OBJECT_H

namespace XM
{
    class UI_Manager;

    class UI_Object : public baseNode
    {
        XM_RTTI_DECLARE_STATIC

    protected:
        // ctor/dtor
        UI_Object();

        int m_nID;
        int m_nSuperID;
        bool m_bEnabled;
        bool m_bVisible;

        bool m_bMouseOver;
        bool m_bPressed;
        bool m_bHasFocus;

        bool m_bUseMouse;
        bool m_bUseKeyboard;

        D3DXVECTOR3 m_vPos;
        D3DXVECTOR3 m_vParentPos;

    public:
        ~UI_Object() override;
        virtual bool saveFile(IStream& rStream);
        virtual bool loadFile(IStream& rStream);
        virtual void frameMove(DWORD dwElapsedTime);
        virtual void render(IDirect3DDevice9*);

        virtual UI_Object* hitTest(int nMouseX, int nMouseY, float& zDist);

        // is enabled
        void setEnabled(bool bEnabled) { m_bEnabled = bEnabled; };
        bool getEnabled() const { return m_bEnabled; };

        // visibility
        void setVisible(bool bVisible) { m_bVisible = bVisible; }
        bool getVisible() const { return m_bVisible; }

        void setUseKeyboard(bool bFlag) { m_bUseKeyboard = bFlag; }
        bool getUseKeyboard() const { return m_bUseKeyboard; }
        void setUseMouse(bool bFlag) { m_bUseMouse = bFlag; }
        bool getUseMouse() const { return m_bUseMouse; }

        int getID() const { return m_nID; }
        virtual void setID(int iId);
        int getSuperID() const { return m_nSuperID; }
        virtual void setSuperID(int nId);

        // position, size
        void setParentPos(const D3DXVECTOR3& vPos)
        {
            setParentPos(vPos.x, vPos.y, vPos.z);
        }

        virtual void setParentPos(float x, float y, float z)
        {
            m_vPos = D3DXVECTOR3(x, y, z);
            updatePosition();
        }
        const D3DXVECTOR3& getParentPos() const { return m_vParentPos; };

        void setPosition(const D3DXVECTOR3& vPos)
        {
            this->setPosition(vPos.x, vPos.y, vPos.z);
        }

        virtual void setPosition(float x, float y, float z)
        {
            m_vParentPos = D3DXVECTOR3(x, y, z);
            updatePosition();
        }
        const D3DXVECTOR3& getPosition() const { return m_vPos; };

        virtual void updatePosition()
        {
        }

        // message handler
        virtual void onFocusIn()
        {
            m_bHasFocus = true;
            updateControlState();
        }

        virtual void onFocusOut()
        {
            m_bHasFocus = false;
            updateControlState();
        }

        virtual void onMouseEnter()
        {
            m_bMouseOver = true;
            updateControlState();
        }

        virtual void onMouseLeave()
        {
            m_bMouseOver = false;
            updateControlState();
        }

        virtual void updateControlState()
        {
        }
        virtual bool handleKeyboard(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam);
        virtual bool handleMouse(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam);

        virtual void refresh();
        virtual bool msgProc(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam);
    };
}
#endif
