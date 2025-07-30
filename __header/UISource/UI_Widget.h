/*

file : XM_UI_Control.h

*/

#ifndef H_XM_STATUSUI_CONTROL_H
#define H_XM_STATUSUI_CONTROL_H

namespace XM
{
    class UI_Box;
    class UI_Rect;
	class UI_Widget : public UI_Object
	{
		XM_RTTI_DECLARE_STATIC
	protected:
		bool					m_bHitTest;
		bool					m_bPressed;

		STATUSUI_CONTROL_STATE	m_ControlState;
		xmVec<UI_Rect*>			m_listRect;
		int						m_nSuperID;
		bool					m_bChangeAlpha;
        fontNode*               m_pFontNode;

    protected:
		// control state
        void			updateControlState() override;
	public:
		// ctor/dtor
		UI_Widget();
        ~UI_Widget() override;
		// serialize
        bool			saveFile(IStream& rStream) override;
        bool			loadFile(IStream& rStream) override;
        void			render( IDirect3DDevice9* pd3dDevice) override;
        void			frameMove( DWORD dwElapsedTime ) override;
		void					clear();

		bool					getMousePressed() const    { return m_bPressed;  }

		int						DivideString(CHAR* lpszSrc, int nBytePerLine, LPTSTR* alpszDst);
				
		// UIManager ID
        void			setSuperID(int nID) override { m_nSuperID =  nID; }
		// control id
		void					setID(int nID) override {	m_nID =  nID; }	
		// hit-test
		void					setHitTest(bool bFlag);
		inline bool getHitTest() const { return m_bHitTest;}
        void			updatePosition() override;


		// control state
		STATUSUI_CONTROL_STATE	getControlState() const;

		// set/change font
		virtual bool			setFont(const WCHAR* strFontName, int nFontHeight, int nFontWeight, BOOL bItalic = false);
		virtual void			setFont(fontNode* pFontNode);
		fontNode*				getFont();

		// rects
		bool					addRect(UI_Rect* pRect);
		bool					removeRect(UI_Rect* pRect);
		int						findRect(UI_Rect* pRect);
		UI_Rect*				getRectByOrdinal(int nOrdinal);


		// rect item
		void					setRectItem(int nRectOrdinal, STATUSUI_CONTROL_STATE cCS, UI_RectItem* pRectItem);
		void					setRectItem(int nRectOrdinal, UI_RectItem* pRectItem);
		UI_RectItem*			getRectItem(int nRectOrdinal, STATUSUI_CONTROL_STATE cCS);

		// init/refresh
		virtual HRESULT			onInit();
        void			refresh() override;

		// hit test
        UI_Object* hitTest(int nMouseX, int nMouseY, float& zDist) override;

		// message handler
        bool			handleKeyboard(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
        bool			handleMouse(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
        bool			msgProc(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam) override;

		bool					getChangeAlpah();
		void					setChangeAlpha(bool bChange);
	}; // class UI_Control	

} // namespace XM

#endif // H_XM_STATUSUI_CONTROL_H