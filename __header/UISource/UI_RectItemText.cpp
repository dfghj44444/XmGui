/*

file : XM_UI_RectItemText.cpp

*/

#include "stdafx.h"

namespace XM
{
	XM_RTTI_CREATE_STATIC(UI_RectItemText, L"UI_RectItemText", UI_RectItem);
	///////////////////////////////////////////////////////////////////////////
	// ctor/dtor
	UI_RectItemText::UI_RectItemText()
	{
		XM_RTTI_INIT_POINTER;

		m_pFontNode = nullptr;
		if(setFont(_FONT_NAME_, 18, 0, FALSE) == false)
		{
			XM_ASSERT(0);
		}

		m_strTextData			= L"empty";

		m_dwTextFormat			= DT_TOP|DT_LEFT|DT_WORDBREAK;

		// 텍스트 그림자
		m_bUseTextShadow		= false;
		m_bUseTextOutline		= true;
		m_nShadowOffsetX		= 2;
		m_nShadowOffsetY		= 2;

		// 텍스트 마진
		m_uMarginH				= 5;
		m_uMarginV				= 5;
		setTextMarginFirst(false);

		// 컬러
		m_bUseBackgroundColor	= true;
		m_bUseTextureBackground	= true;
		m_colorBackground		= D3DCOLOR_ARGB(255, 255, 255, 0);
		m_colorFont				= D3DCOLOR_ARGB(255, 255, 255, 255);
		m_colorShadow			= D3DCOLOR_ARGB(255, 0, 0, 0);
		m_colorOutline			= D3DCOLOR_ARGB(255, 0, 0, 0);

		m_bNumberCheck			= false;
	}
	UI_RectItemText::~UI_RectItemText()
	{
		_SAFE_DEREF(m_pTexNode);
		_SAFE_DEREF(m_pFontNode);
	}
	// ctor/dtor
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// serialize
	bool UI_RectItemText::saveFile(IStream& rStream)
	{
		if(UI_RectItem::saveFile(rStream) == false) return false;

		ISTREAM_WRITESTRING(rStream, m_strTextData) ;

		bool bTemp = m_pFontNode? true:false;
		ISTREAM_WRITEBool(rStream, bTemp) ;
		if(bTemp == true)
		{
			fontCreateParam* param = m_pFontNode->getCreationParam();
			ISTREAM_WRITESTRING(rStream, m_pFontNode->getResname());
			ISTREAM_WRITEINT(rStream, param);
			ISTREAM_WRITEINT(rStream, param);
			ISTREAM_WRITEBOOL(rStream, param);
		}
		ISTREAM_WRITEULONG(rStream, m_dwTextFormat) ;

		ISTREAM_WRITEBool(rStream, m_bUseTextShadow) ;
		ISTREAM_WRITEBool(rStream, m_bUseTextOutline) ;
		ISTREAM_WRITEINT(rStream, m_nShadowOffsetX) ;
		ISTREAM_WRITEINT(rStream, m_nShadowOffsetY);

		ISTREAM_WRITEBool(rStream, m_bTextMarginFirst) ;
		ISTREAM_WRITEUINT(rStream, m_uMarginH) ;
		ISTREAM_WRITEUINT(rStream, m_uMarginV) ;

		ISTREAM_WRITEBool(rStream, m_bUseBackgroundColor) ;
		ISTREAM_WRITEBool(rStream, m_bUseTextureBackground) ;
		ISTREAM_WRITEULONG(rStream, m_colorBackground) ;
		ISTREAM_WRITEULONG(rStream, m_colorFont) ;
		ISTREAM_WRITEULONG(rStream, m_colorShadow) ;
		ISTREAM_WRITEULONG(rStream, m_colorOutline);

		ISTREAM_WRITEBool(rStream, m_bNumberCheck) ;

		return true;
	}
	bool UI_RectItemText::loadFile(IStream& rStream)
	{
		if(UI_RectItem::loadFile(rStream) == false) return false;

		ISTREAM_READSTRING(rStream, &m_strTextData);

		bool bTemp;
		ISTREAM_READBool(rStream, &bTemp) ;
		if(bTemp == true)
		{
			CStringW strFontName;
			int nFontWeight;
			int nFontHeight;
			BOOL bItalic;
			ISTREAM_READSTRING(rStream, &strFontName);
			ISTREAM_READINT(rStream, &nFontHeight) ;
			ISTREAM_READINT(rStream, &nFontWeight) ;
			ISTREAM_READBOOL(rStream, &bItalic) ;
			if(setFont(strFontName, nFontHeight, nFontWeight, bItalic) == false)
				return false;
		}
		ISTREAM_READULONG(rStream, &m_dwTextFormat) ;
		ISTREAM_READBool(rStream, &m_bUseTextShadow) ;
		ISTREAM_READBool(rStream, &m_bUseTextOutline) ;
		ISTREAM_READINT(rStream, &m_nShadowOffsetX) ;
		ISTREAM_READINT(rStream, &m_nShadowOffsetY) ;

		ISTREAM_READBool(rStream, &m_bTextMarginFirst) ;
		ISTREAM_READUINT(rStream, &m_uMarginH) ;
		ISTREAM_READUINT(rStream, &m_uMarginV);

		ISTREAM_READBool(rStream, &m_bUseBackgroundColor) ;
		ISTREAM_READBool(rStream, &m_bUseTextureBackground) ;
		ISTREAM_READULONG(rStream, &m_colorBackground) ;
		ISTREAM_READULONG(rStream, &m_colorFont) ;
		ISTREAM_READULONG(rStream, &m_colorShadow) ;
		ISTREAM_READULONG(rStream, &m_colorOutline) ;

		ISTREAM_READBool(rStream, &m_bNumberCheck) ;

		return true;
	}
	// serialize
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// render
	void UI_RectItemText::render(IDirect3DDevice9* pDevice)
	{
		XM_ASSERT(pDevice);
		if((pDevice == nullptr))	{return;}

		IDirect3DTexture9* pTexture = nullptr;
		if(m_pTexNode)
			pTexture = m_pTexNode->getTexture();

		if(m_pFontNode == nullptr)
			return;

		CFont* pFont = m_pFontNode->getFont();
		if(pFont == nullptr)
			return;

		RECT rc;
		rc.left = static_cast<int>(m_Vertices[0].x);
		rc.right = static_cast<int>(m_Vertices[1].x);
		rc.top = static_cast<int>(m_Vertices[0].y);
		rc.bottom = static_cast<int>(m_Vertices[3].y);
		if(m_bUseBackgroundColor == true)
		{
			renderRect_VTXTYPE_2D_COLOR(rc, m_colorBackground, m_Vertices[0].z, pDevice);
		}

		if((pTexture)&&(m_bUseTextureBackground == true))
		{
			pDevice->SetTexture(0, pTexture);
			pDevice->SetFVF(VTXTYPE_2D_COLOR_TEX1::FVF);
			pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, m_Vertices,	sizeof(VTXTYPE_2D_COLOR_TEX1));
		}


		if(m_bTextMarginFirst == false)
		{
			int nRectWidth = static_cast<int>(m_vSize.x);
			int nRectHeight = static_cast<int>(m_vSize.y);
			rc.bottom = rc.top + nRectHeight;
			int nTextWidth = m_pFontNode->getCreationParam()->Width;
			int nTextHeight= m_pFontNode->getCreationParam()->Height;

			unsigned int nDeltaH = (nRectWidth - nTextWidth)/2;
			int hMargin = nDeltaH>m_uMarginH ? m_uMarginH:nDeltaH;

			unsigned int nDeltaV = (nRectHeight - nTextHeight)/2;
			int vMargin = nDeltaV>m_uMarginV ? m_uMarginV:nDeltaV;

			rc.left		+= hMargin;
			rc.right	-= hMargin;
			if(nRectHeight > nTextHeight)
			{
				rc.top		+= vMargin;
				rc.bottom	-= vMargin;
			}
		}
		else
		{
			rc.left		= m_uMarginH;
			rc.right	= rc.left + static_cast<int>(m_vSize.x);
			rc.top		= m_uMarginV;
			rc.bottom	= rc.top + static_cast<int>(m_vSize.y);
		}

		//pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
		//pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);


        bool cache = g_FontRenderBatcher->BeginCache(pFont);

		if(m_bUseTextOutline == true)
		{
			renderString_Outline(pFont, m_strTextData, -1, rc, m_dwTextFormat, m_colorOutline);
		}
		else if(m_bUseTextShadow == true)
		{
			renderString_Shadow(pFont, m_strTextData, -1, rc, m_dwTextFormat, m_colorShadow, m_nShadowOffsetX, m_nShadowOffsetY);
		}
		pFont->DrawTextW(nullptr, m_strTextData, -1, &rc, m_dwTextFormat, m_colorFont);

        if (cache)
            g_FontRenderBatcher->EndCache();
	}
	// render
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	void UI_RectItemText::setTextData(const CStringW strTextData)
	{
		CStringW strCharInsert = strTextData;
        if(m_strTextData == strCharInsert)
            return;
		
		if( true == m_bNumberCheck )
		{
			int nInsertIndex = strCharInsert.GetLength();
			int nCommaCount = nInsertIndex/3;
			for(int i = 0; i<nCommaCount; i++)
			{
				nInsertIndex -= 3;
				if(nInsertIndex > 0)	{strCharInsert.Insert(nInsertIndex, L",");}
			}
		}

		m_strTextData = strCharInsert;
	}
	void UI_RectItemText::setTextData(const WCHAR* strTextData)
	{
		CStringW strCharInsert = strTextData;
        if(strCharInsert == m_strTextData)
            return;

		if( true == m_bNumberCheck )
		{
			int nInsertIndex = strCharInsert.GetLength();
			int nCommaCount = nInsertIndex/3;
			for(int i = 0; i<nCommaCount; i++)
			{
				nInsertIndex -= 3;
				if(nInsertIndex > 0)	{strCharInsert.Insert(nInsertIndex, L",");}
			}
		}

		m_strTextData = strCharInsert;
	}
	void UI_RectItemText::setTextData(const char* strTextData)
	{
		CStringW strCharInsert = strTextData;
        if(m_strTextData == strCharInsert)
            return;

		if( true == m_bNumberCheck )
		{
			int nInsertIndex = strCharInsert.GetLength();
			int nCommaCount = nInsertIndex/3;
			for(int i = 0; i<nCommaCount; i++)
			{
				nInsertIndex -= 3;
				if(nInsertIndex > 0)	{strCharInsert.Insert(nInsertIndex, L",");}
			}
		}

		m_strTextData = strCharInsert;
	}
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	void UI_RectItemText::setFontNumber(const bool& bNumber )
	{
		m_bNumberCheck = bNumber;
	}
	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	bool UI_RectItemText::setFont(const WCHAR* strFontName, int nFontHeight, int nFontWeight, BOOL bItalic)
	{
		_SAFE_DEREF(m_pFontNode);

		XM::fontCreateParam* pFontParam;
		_NEW(pFontParam, XM::fontCreateParam);
		if(pFontParam == nullptr)
		{
			return false;
		}
		pFontParam->Height = nFontHeight;
		pFontParam->Weight = nFontWeight;
		pFontParam->Italic = bItalic;

		m_pFontNode	= g_pStaticFontMgr->getFontNode(strFontName, pFontParam);

		if(m_pFontNode == nullptr)
		{
			_DEL(pFontParam);
			return false;
		}

		m_pFontNode->AddRef();

		return true;
	}
	void UI_RectItemText::setFont(fontNode* pFontNode)
	{
		_SAFE_DEREF(m_pFontNode);
		m_pFontNode = pFontNode;
		_SAFE_REF(m_pFontNode);
	}
	fontNode* UI_RectItemText::getFont()
	{
		return m_pFontNode;
	}
	void UI_RectItemText::setDrawFormat(const DWORD dwFormat)
	{
        if(m_dwTextFormat != dwFormat)
        {
		    m_dwTextFormat = dwFormat;
        }
	}
	DWORD UI_RectItemText::getDrawFormat()
	{
		return m_dwTextFormat;
	}
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	void UI_RectItemText::setUseTextShadow(bool bFlag)
	{
        if(m_bUseTextShadow && bFlag)
            return;

        if(!m_bUseTextShadow && !bFlag)
            return;

		m_bUseTextShadow = bFlag;
	}
	bool UI_RectItemText::getUseTextShadow()
	{
		return m_bUseTextShadow;
	}
	void UI_RectItemText::setUseTextOutline(bool bFlag)
	{
        if( m_bUseTextOutline && bFlag )
            return;

        if( !m_bUseTextOutline && !bFlag )
            return;

		m_bUseTextOutline = bFlag;
	}
	bool UI_RectItemText::getUseTextOutline()
	{
		return m_bUseTextOutline;
	}
	void UI_RectItemText::setShadowOffset(int nX, int nY)
	{
        if(m_nShadowOffsetX != nX || m_nShadowOffsetY != nY)
        {
		    m_nShadowOffsetX = nX;
		    m_nShadowOffsetY = nY;
        }
	}
	void UI_RectItemText::getShadowOffset(int& rX, int& rY)
	{
		rX = m_nShadowOffsetX;
		rY = m_nShadowOffsetY;
	}
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	void UI_RectItemText::setTextMarginFirst(bool bFlag)
	{
        if( m_bTextMarginFirst && bFlag )
            return;

        if( !m_bTextMarginFirst && !bFlag )
            return;

		m_bTextMarginFirst = bFlag;
	}
	bool UI_RectItemText::getTextMarginFirst()
	{
		return m_bTextMarginFirst;
	}
	void UI_RectItemText::setTextMargin(unsigned int nH, unsigned int nV)
	{
        if( m_uMarginH != nH || m_uMarginV != nV )
        {
		    m_uMarginH = nH;
		    m_uMarginV = nV;
        }
	}
	void UI_RectItemText::getTextMargin(unsigned int& rH, unsigned int& rV)
	{
		rH = m_uMarginH;
		rV = m_uMarginV;
	}
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	void UI_RectItemText::setUseBackgroundColor(bool bFlag)
	{
        if( m_bUseBackgroundColor && bFlag )
            return;

        if( !m_bUseBackgroundColor && !bFlag )
            return;

		m_bUseBackgroundColor = bFlag;
	}
	bool UI_RectItemText::getUseBackgroundColor()
	{
		return m_bUseBackgroundColor;
	}
	void UI_RectItemText::setUseTextureBackground(bool bFlag)
	{
        if( m_bUseTextureBackground && bFlag )
            return;

        if( !m_bUseTextureBackground && !bFlag )
            return;

		m_bUseTextureBackground = bFlag;
	}
	bool UI_RectItemText::getUseTextureBackground()
	{
		return m_bUseTextureBackground;
	}
	void UI_RectItemText::setBackgroundColor(D3DCOLOR cColor)
	{
        if( m_colorBackground != cColor )
        {
		    m_colorBackground = cColor;
        }
	}
	D3DCOLOR UI_RectItemText::getBackgroundColor()
	{
		return m_colorBackground;
	}
	void UI_RectItemText::setFontColor(D3DCOLOR cColor)
	{
        if(m_colorFont != cColor)
        {
		    m_colorFont = cColor;
        }
	}
	D3DCOLOR UI_RectItemText::getFontColor()
	{
		return m_colorFont;
	}
	void UI_RectItemText::setShadowColor(D3DCOLOR cColor)
	{
        if( m_colorShadow != cColor )
        {
		    m_colorShadow = cColor;
        }
	}
	D3DCOLOR UI_RectItemText::getShadowColor()
	{
		return m_colorShadow;
	}
	void  UI_RectItemText::setOutlineColor(D3DCOLOR cColor)
	{
        if( m_colorOutline != cColor )
        {
		    m_colorOutline = cColor;
        }
	}
	D3DCOLOR UI_RectItemText::getOutlineColor()
	{
		return m_colorOutline;
	}
	///////////////////////////////////////////////////////////////////////////

} // namespace XM