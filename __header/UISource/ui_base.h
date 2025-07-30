/*

file : XM_UI_Base.h

*/

#ifndef H_XM_STATUSUI_BASE_H
#define H_XM_STATUSUI_BASE_H

namespace XM
{
	class UI_Base : public baseNode
	{
		XM_RTTI_DECLARE_STATIC

	protected:
		// ctor/dtor
		UI_Base();

	public:
        ~UI_Base() override;

		// serialize
		virtual bool			saveFile(IStream& rStream) = 0;
		virtual bool			loadFile(IStream& rStream) = 0;

		virtual void			render(IDirect3DDevice9* pDevice) = 0;
		virtual void			frameMove( DWORD dwElapsedTime ) = 0;
	}; // class UI_Base

} // namespace XM

#endif // H_XM_STATUSUI_BASE_H