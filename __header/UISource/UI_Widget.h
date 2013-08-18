/*

file : XM_UI_Control.h

*/

#ifndef H_XM_STATUSUI_CONTROL_H
#define H_XM_STATUSUI_CONTROL_H

namespace XM
{
    class UI_Box;
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

	protected:
		// control state
		virtual void			updateControlState();
	public:
		// ctor/dtor
		UI_Widget();
		virtual ~UI_Widget();
		// serialize
		virtual bool			saveFile(IStream& rStream);
		virtual bool			loadFile(IStream& rStream);
		virtual void			render( IDirect3DDevice9* pd3dDevice);
		virtual void			frameMove( DWORD dwElapsedTime );
		void					clear();

		bool					getMousePressed() const    { return m_bPressed;  };

		int						DivideString(CHAR* lpszSrc, int nBytePerLine, LPTSTR* alpszDst);
				
		// UIManager ID
		virtual void			setSuperID(int nID) { m_nSuperID =  nID; };	
		// control id
		void					setID(int nID){	m_nID =  nID; };	
		// hit-test
		void					setHitTest(bool bFlag);
		inline bool	const		getHitTest() const { return m_bHitTest;};
		virtual void			updatePosition();


		// control state
		STATUSUI_CONTROL_STATE	getControlState() const;

		// set/change font
		virtual bool			setFont(const WCHAR* strFontname, int nFontHeight, int nFontWeight, BOOL bItalic = false);
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
		virtual void			refresh();

		// hit test
		virtual UI_Object* hitTest(int nMouseX, int nMouseY, float& zDist);

		// message handler
		virtual bool			handleKeyboard(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam);
		virtual bool			handleMouse(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam);
		virtual bool			msgProc(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam);

		bool					getChangeAlpah();
		void					setChangeAlpha(bool bChange);
	}; // class UI_Control	

} // namespace XM

#endif // H_XM_STATUSUI_CONTROL_H