/*

file : XM_UI_Rect.h

*/

#ifndef H_XM_UI_Rect_H
#define H_XM_UI_Rect_H

namespace XM
{
    class UI_RectItem;

    class UI_Rect : public UI_Base
    {
        XM_RTTI_DECLARE_STATIC

    protected:
        STATUSUI_CONTROL_STATE m_controlState;
        // control states
        UI_RectItem* m_Items[SCT_STATUS_COUNT];

        unsigned int m_uRectID;

    public:
        // ctor/dtor
        UI_Rect();
        ~UI_Rect() override;

        // serialize
        bool saveFile(IStream& rStream) override;
        bool loadFile(IStream& rStream) override;

        void render(IDirect3DDevice9* pDevice) override;
        void frameMove(DWORD dwElapsedTime) override;

        virtual bool hitTest(int mouseX, int mouseY,OUT float& zOut);

        // control states
        void setState(STATUSUI_CONTROL_STATE cControlState);
        STATUSUI_CONTROL_STATE getState();

        // set control rect
        void setItem(STATUSUI_CONTROL_STATE cCS, UI_RectItem* pRectItem);
        UI_RectItem* getItem(STATUSUI_CONTROL_STATE cCS);
        UI_RectItem* getCurrentItem();

        // rect ID
        void setRectID(unsigned int uRectID);
        unsigned int getRectID();

        // alpha
        void setAlpha(const int& nAl = 255);

        // setParentPos
        void setParentPos(const D3DXVECTOR3& vParent);
        void setPos(const D3DXVECTOR3& vPos);
    }; // class UI_Rect

    typedef xmVec<UI_Rect*> listStatusUI2DRect;
} // namespace XM

#endif // H_XM_UI_Rect_H
