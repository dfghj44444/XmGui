/*
file : XM_TextureNode.cpp
*/


#include "stdafx.h"

namespace XM
{
	// ctor/dtor
	texNode::texNode()
	{
		m_pDevice			= nullptr;
		m_pTexture			= nullptr;
		m_pTexCreationParam	= nullptr;

		texCreateParam* param;
		_NEW(param,texCreateParam);
		XM_ASSERT(m_pTexCreationParam);
	}

	texNode::texNode(texCreateParam* pParam)
	{
		XM_ASSERT(pParam);

		m_pDevice			= nullptr;
		m_pTexture			= nullptr;
		m_pTexCreationParam	= nullptr;

		setTextureCreationParam(pParam);
		XM_ASSERT(m_pTexCreationParam);
	}

	texNode::~texNode()
	{
		_SAFE_DEREF(m_pTexCreationParam);
		onDestroyDevice();

		g_pStaticEngine->removeTexNode(m_strResname.GetBuffer());
	}

	//--------------------------------------------------------------------------------------
	// 
	//--------------------------------------------------------------------------------------
	bool texNode::setTextureCreationParam(texCreateParam* pParam)
	{
		_SAFE_DEREF(m_pTexCreationParam);
		m_pTexCreationParam = pParam;
		_SAFE_REF(m_pTexCreationParam);

		if((m_pDevice)&&(m_pTexCreationParam))
		{
			return onCreateDevice(m_pDevice);
		}

		return true;
	}
	texCreateParam* texNode::getTextureCreationParam()
	{
		return m_pTexCreationParam;
	}

	//--------------------------------------------------------------------------------------
	// create/release/get IDirect3DTexture9
	//--------------------------------------------------------------------------------------
	bool texNode::createTexture()
	{
		// check param
		XM_ASSERT(m_pDevice);
		XM_ASSERT(m_pTexCreationParam);
		XM_ASSERT(m_strResname.GetLength() > 0);
		if((m_pDevice == nullptr)||(m_pTexCreationParam == nullptr)||(m_strResname.GetLength() <= 0))
		{
			return false;
		}

		_SAFE_RELEASE(m_pTexture);

//		bool fLock = false;
//		if ( !IS_LOCK_D3DDEVICE() ) { LOCK_D3DDEVICE(); fLock = true; }

		HRESULT hr;

		hr =  D3DXCreateTextureFromFileExW(
			m_pDevice,									
			m_strResname,								
			m_pTexCreationParam->Width,
			m_pTexCreationParam->Height,
			m_pTexCreationParam->MipLevels,				
			m_pTexCreationParam->Usage,
			m_pTexCreationParam->Format,
			m_pTexCreationParam->Pool,
			m_pTexCreationParam->Filter,				
			m_pTexCreationParam->MipFilter,				
			m_pTexCreationParam->ColorKey,				
			&m_texInfo,
            nullptr,
			&m_pTexture);								

//		if ( fLock ) UNLOCK_D3DDEVICE();

		if(FAILED(hr))
		{
			xmVec<CStringW>* pathList = g_pStaticEngine->getPathList();
			if(pathList)
			{
				int nSize = pathList->size();
				for(int i = 0; i<nSize; ++i)
				{
					CStringW strComplete = (*pathList)[i] + '\\' + m_strResname;
					hr =  D3DXCreateTextureFromFileExW(
						m_pDevice, 
						strComplete,
						m_pTexCreationParam->Width,
						m_pTexCreationParam->Height,
						m_pTexCreationParam->MipLevels,
						m_pTexCreationParam->Usage,
						m_pTexCreationParam->Format,
						m_pTexCreationParam->Pool,
						m_pTexCreationParam->Filter,
						m_pTexCreationParam->MipFilter,
						m_pTexCreationParam->ColorKey,
						&m_texInfo,
                        nullptr,
						&m_pTexture);

					if(SUCCEEDED(hr))
						return true;
				}
			}
		}

		return true;
	}
	IDirect3DTexture9* texNode::getTexture()
	{
		return m_pTexture;
	}
	void texNode::releaseTexture()
	{
		_SAFE_RELEASE(m_pTexture);
	}

	//--------------------------------------------------------------------------------------
	// on create/reset/lost/destroy
	//--------------------------------------------------------------------------------------
	bool texNode::onCreateDevice(IDirect3DDevice9* pDevice)
	{
		onDestroyDevice();

		m_pDevice = pDevice;

		if((m_pDevice)&&(m_strResname.GetLength() > 0))
		{
			return createTexture();
		}

		return true;
	}
	bool texNode::onResetDevice(IDirect3DDevice9* pDevice)
	{
        if(m_pTexCreationParam && m_pTexCreationParam->Pool != D3DPOOL_MANAGED)
        {
		    onCreateDevice(pDevice);
        }
		return true;
	}
	void texNode::onLostDevice()
	{
        if(m_pTexCreationParam && m_pTexCreationParam->Pool != D3DPOOL_MANAGED)
        {
		    _SAFE_RELEASE(m_pTexture);
        }
	}
	void texNode::onDestroyDevice()
	{
		_SAFE_RELEASE(m_pTexture);
		m_pDevice = nullptr;
	}

} // namespace XM