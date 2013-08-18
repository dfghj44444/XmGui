/*

file : XM_UI_RectItemText.h

*/

#ifndef H_XM_UI_RECTITEMTEXT_H
#define H_XM_UI_RECTITEMTEXT_H

namespace XM
{
	class UI_RectItemText : public UI_RectItem
	{
		XM_RTTI_DECLARE_STATIC

	protected:

		CStringW				m_strTextData;

		fontNode*				m_pFontNode;				
		DWORD					m_dwTextFormat;				

		bool					m_bUseTextShadow;			
		bool					m_bUseTextOutline;			
		int						m_nShadowOffsetX;			
		int						m_nShadowOffsetY;

		bool					m_bTextMarginFirst;
		unsigned int			m_uMarginH;
		unsigned int			m_uMarginV;

		bool					m_bUseBackgroundColor;		
		bool					m_bUseTextureBackground;	
		D3DCOLOR				m_colorBackground;			
		D3DCOLOR				m_colorFont;				
		D3DCOLOR				m_colorShadow;				
		D3DCOLOR				m_colorOutline;				

		bool					m_bNumberCheck;

	protected:
		virtual void			renderItem(IDirect3DDevice9* pDevice);

	public:

		// ctor/dtor
		UI_RectItemText();
		virtual ~UI_RectItemText();

		// serialize
		virtual bool			saveFile(IStream& rStream);
		virtual bool			loadFile(IStream& rStream);

		void					setTextData(const CStringW strTextData);
		void					setTextData(const WCHAR* strTextData);
		void					setTextData(const char* strTextData);

		bool					setFont(const WCHAR* strFontname, int nFontHeight, int nFontWeight, BOOL bItalic);
		void					setFont(fontNode* pFontNode);
		fontNode*				getFont();
		void					setDrawFormat(const DWORD dwFormat);
		DWORD					getDrawFormat();

		void					setUseTextShadow(bool bFlag);
		bool					getUseTextShadow();
		void					setUseTextOutline(bool bFlag);
		bool					getUseTextOutline();
		void					setShadowOffset(int nX, int nY);
		void					getShadowOffset(int& rX, int& rY);

		void					setTextMarginFirst(bool bFlag);
		bool					getTextMarginFirst();
		void					setTextMargin(unsigned int nH, unsigned int nV);
		void					getTextMargin(unsigned int& rH, unsigned int& rV);

		void					setUseBackgroundColor(bool bFlag);
		bool					getUseBackgroundColor();
		void					setUseTextureBackground(bool bFlag);
		bool					getUseTextureBackground();
		void					setBackgroundColor(D3DCOLOR cColor);
		D3DCOLOR				getBackgroundColor();
		void					setFontColor(D3DCOLOR cColor);
		D3DCOLOR				getFontColor();
		void					setShadowColor(D3DCOLOR cColor);
		D3DCOLOR				getShadowColor();
		void					setOutlineColor(D3DCOLOR cColor);
		D3DCOLOR				getOutlineColor();

		void					setFontNumber(const bool& bNumber );

	}; // class UI_RectItemText

} // namespace XM

#endif // H_XM_UI_RectITEMTEXT_H