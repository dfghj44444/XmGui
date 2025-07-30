/*
file : XM_FontMgr.cpp
*/


#include "stdafx.h"

namespace XM
{
	///////////////////////////////////////////////////////////////////////////
	// fontMgr
	// ctor/dtor
	fontMgr::fontMgr()
    = default;

    fontMgr::~fontMgr()
	{
		clear();
	}
	//actually it created a fontnode by the 2 param
	fontNode* fontMgr::getFontNode(WCHAR* filename, fontCreateParam* pParam)
	{
		fontNode* pNode;
		_NEW(pNode, fontNode(pParam));
		if(!pNode )			return nullptr;

		bool bResult = pNode->setResname(filename);
		if(bResult == false){
			_DEL(pNode);
			return nullptr;
		}

		bResult = pNode->setDevice(g_pStaticEngine->getDevice());
		if(bResult == false){
			_DEL(pNode);
			return nullptr;
		}

		return pNode;
	}
	fontNode* fontMgr::getFontNode(CStringW filename, fontCreateParam* pParam)
	{
		return getFontNode(filename.GetBuffer(), pParam);
	}

//----------------------------------------------------------------------------------------------------------------------------
    void fontMgr::init()
    {
        CFont::Init();
    }

    void fontMgr::destroy()
    {
        for(FontMap::const_iterator itr = m_FontMap.begin(); itr != m_FontMap.end(); ++itr)
        {
            XM_ASSERT(itr->second->GetRefCount() == 0);
            delete itr->second;
        }
        m_FontMap.clear();

        CFont::Destroy();
    }


    CFont* fontMgr::create(LPCWSTR pFacename, const XM::fontCreateParam* param)
    {
        CFont* pFont = nullptr;

        int height = param->Height;
        int weight = param->Weight;

        wchar_t fontName[128];
        swprintf(fontName, 128, L"%s_%d_%d", pFacename, height, weight);

        FontMap::const_iterator itr = m_FontMap.find(fontName);
        if(itr == m_FontMap.end())
        {
            HFONT hFont = ::CreateFont(height, 0, 0, 0, weight, FALSE, 0, 0, param->CharSet, OUT_TT_PRECIS, 0, PROOF_QUALITY, 0, pFacename);
            XM_ASSERT(hFont);

            pFont = new CFont(hFont);
            m_FontMap[fontName] = pFont;
        }
        else
        {
            pFont = itr->second;
        }

        pFont->AddRef();
        return pFont;
    }

    CFont* fontMgr::create(LPCWSTR pFacename, unsigned int height, unsigned int weight /*= 0*/)
    {
        fontCreateParam p;
        p.Height = height;
        p.Weight = weight;

        return create(pFacename, &p);
    }

    void fontMgr::remove(CFont* pFont)
    {
        XM_ASSERT(pFont->GetRefCount() == 0);
        //don't destroy the font
    }

} // namespace XM