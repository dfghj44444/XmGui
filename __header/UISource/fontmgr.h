/*

file : XM_FontMgr.h

*/

#ifndef H_XM_FONTMGRD3D9_H
#define H_XM_FONTMGRD3D9_H

#define FONTCOL_WHITE				D3DCOLOR_ARGB( 255, 255, 255, 255 )
#define FONTCOL_BLACK				D3DCOLOR_ARGB( 255,   0,   0,   0 )
#define FONTCOL_GRAY				D3DCOLOR_ARGB( 255, 192, 192, 192 )
#define FONTCOL_RED					D3DCOLOR_ARGB( 255, 255,   0,   0 )
#define FONTCOL_GREEN				D3DCOLOR_ARGB( 255,   0, 255,   0 )
#define FONTCOL_BLUE				D3DCOLOR_ARGB( 255,   0,   0, 255 )
#define FONTCOL_YELLOW				D3DCOLOR_ARGB( 255, 255, 255,	0 )

namespace XM
{
	class fontMgr : public resMgr
	{
	public:

		fontMgr();
		virtual ~fontMgr();

		fontNode*				getFontNode(WCHAR* filename, fontCreateParam* pParam);
		fontNode*				getFontNode(CStringW filename, fontCreateParam* pParam);

        CFont* create(LPCWSTR pFacename, unsigned int height, unsigned int weight = 0);
        CFont* create(LPCWSTR pFacename, const XM::fontCreateParam* param);
        void remove(CFont* font);

        void init();
        void destroy();

    private:
        typedef stdext::hash_map<std::wstring, CFont*> FontMap;
        FontMap m_FontMap;
	};
}

#endif // H_XM_FONTMGRD3D9_H