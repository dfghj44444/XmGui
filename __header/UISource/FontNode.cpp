/*
file : XM_FontNode.cpp
*/


#include "stdafx.h"

namespace XM
{
    fontCreateParam::~fontCreateParam()
    {
    }

	// ctor/dtor
	fontNode::fontNode()
	{
		m_pDevice			= nullptr;
		m_pFont				= nullptr;
		m_pFontCreationParam= nullptr;

		fontCreateParam* param;
		_NEW(param,fontCreateParam);
		setCreationParam(param);
		XM_ASSERT(m_pFontCreationParam);
	}
	fontNode::fontNode(fontCreateParam* pParam)
	{
		XM_RTTI_INIT_POINTER;

		m_pDevice			= nullptr;
		m_pFont				= nullptr;
		m_pFontCreationParam= nullptr;

		setCreationParam(pParam);
		XM_ASSERT(m_pFontCreationParam);
	}
	fontNode::~fontNode()
	{
		_SAFE_DEREF(m_pFontCreationParam);
		onDestroyDevice();
	}

	bool fontNode::setCreationParam(fontCreateParam* pParam)
	{
		_SAFE_DEREF(m_pFontCreationParam);
		m_pFontCreationParam = pParam;
		_SAFE_REF(m_pFontCreationParam);

		if((m_pDevice)&&(m_pFontCreationParam))
		{
			return onCreateDevice(m_pDevice);
		}

		return true;
	}
	fontCreateParam* fontNode::getCreationParam()
	{
		return m_pFontCreationParam;
	}

	// create/release/get IDirect3DTexture9
	bool fontNode::createFont()
	{		
		// check param
		XM_ASSERT(m_pDevice);
		XM_ASSERT(m_pFontCreationParam);
		XM_ASSERT(m_strResname.GetLength() > 0);
		if((m_pDevice == nullptr)||(m_pFontCreationParam == nullptr)||(m_strResname.GetLength() <= 0))
		{
			return false;
		}

        m_pFont = g_pStaticFontMgr->create(m_strResname, m_pFontCreationParam);

		if(m_pFont == nullptr)
		{
			return false;
		}

		return true;
	}
	CFont* fontNode::getFont()
	{
		return m_pFont;
	}
	void fontNode::releaseFont()
	{
		_SAFE_RELEASE(m_pFont);
	}

	// on create/reset/lost/destroy
	bool fontNode::onCreateDevice(IDirect3DDevice9* pDevice)
	{
		onDestroyDevice();

		m_pDevice = pDevice;

		if((m_pDevice)&&(m_strResname.GetLength() > 0))
		{
			return createFont();
		}

		return true;
	}
	bool fontNode::onResetDevice(IDirect3DDevice9* pDevice)
	{
		XM_ASSERT(pDevice);
		if(pDevice == nullptr)
		{
			return false;
		}

		if(m_pFont)
		{
			m_pFont->OnResetDevice();
		}

		return true;
	}
	void fontNode::onLostDevice()
	{
		if(m_pFont)
		{
			m_pFont->OnLostDevice();
		}
	}
	void fontNode::onDestroyDevice()
	{
		_SAFE_RELEASE(m_pFont);
		m_pDevice = nullptr;
	}

} // namespace XM