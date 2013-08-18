/*
file : XM_FontNode.h
*/

#ifndef H_XM_FONTNODE_H
#define H_XM_FONTNODE_H

namespace XM
{
	class fontCreateParam : public baseNode
	{
	public:
		INT						Height;
		UINT					Width;
		UINT					Weight;
		UINT					MipLevels;
		BOOL					Italic;
		DWORD					CharSet;
		DWORD					OutputPrecision;
		DWORD					Quality;
		DWORD					PitchAndFamily;

	public:
		fontCreateParam(){
			setDefault();
		};
		virtual ~fontCreateParam();

		void					setDefault(){
			Height				= 12;
			Width				= 0;
			Weight				= FW_NORMAL;
			MipLevels			= 1;
			Italic				= FALSE;
			CharSet				= DEFAULT_CHARSET;
			OutputPrecision		= OUT_DEFAULT_PRECIS;
			//		Quality				= DEFAULT_QUALITY;
			//		PitchAndFamily		= DEFAULT_PITCH | FF_DONTCARE;
			Quality				= ANTIALIASED_QUALITY;
			PitchAndFamily		= FF_DONTCARE;
		};
	}; // class fontCreateParam

	class fontNode : public resNode
	{
	protected:
		CFont*					m_pFont;
		fontCreateParam*		m_pFontCreationParam;

	public:
		// ctor/dtor
		fontNode();
		fontNode(fontCreateParam* pParam);
		virtual ~fontNode();

		bool					setCreationParam(fontCreateParam* pParam = 0);
		fontCreateParam*		getCreationParam();

		// create/release/get IDirect3DTexture9
		bool					createFont();
		CFont*					getFont();
		void					releaseFont();

		// on create/reset/lost/destroy
		bool					onCreateDevice(IDirect3DDevice9* pDevice);
		bool					onResetDevice(IDirect3DDevice9* pDevice);
		void					onLostDevice();
		void					onDestroyDevice();
	}; // class fontNode

} // namespace XM

#endif // H_XM_FONTNODE_H