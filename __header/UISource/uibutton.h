/*

file : XM_UI_Button.h

*/

#ifndef H_XM_STATUSUI_BUTTON_H
#define H_XM_STATUSUI_BUTTON_H

namespace XM
{
	class UI_Button : public UI_Widget
	{	
		XM_RTTI_DECLARE_STATIC
	
	protected:

	public:
		// ctor/dtor
		UI_Button();
		virtual ~UI_Button();

		// serialize
		virtual bool			saveFile(IStream& rStream);
		virtual bool			loadFile(IStream& rStream);

		// init/refresh
		virtual HRESULT			onInit();
		virtual void			refresh();

		// render
		virtual void			render(UI_Manager* pDialog, IDirect3DDevice9* pd3dDevice);

		// message handler
		virtual void			onFocusIn(UI_Manager* pDialog);
		virtual void			onFocusOut(UI_Manager* pDialog);
		virtual void			onMouseEnter(UI_Manager* pDialog);
		virtual void			onMouseLeave(UI_Manager* pDialog);
		virtual void			onHotkey(UI_Manager* pDialog);		
		virtual bool			handleMouse(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam);
		virtual bool			msgProc(UI_Manager* pDialog, UINT uMsg, WPARAM wParam, LPARAM lParam);

	}; // class UI_Button

} // namespace XM

#endif // H_XM_STATUSUI_BUTTON_H