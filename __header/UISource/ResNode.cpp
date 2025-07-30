/*
file : XM_ResourceNode.cpp
*/


#include "stdafx.h"

namespace XM
{
	resNode::resNode()
	{
		m_pDevice	= nullptr;
		m_nGroupID	= 0;

		g_pStaticEngine->addDeviceData(this);
	}

	resNode::~resNode()
	{
		onDestroyDevice();

		g_pStaticEngine->removeDeviceData(this);
	}

	bool resNode::setResname(CStringW strFilename)
	{
		m_strResname = strFilename;				
		return onCreateDevice(m_pDevice);
	}
	CStringW resNode::getResname()
	{
		return m_strResname;
	}

	// group
	void resNode::setGroupID(int nGroupID)
	{
		m_nGroupID = nGroupID;
	}
	int resNode::getGroupID()
	{
		return m_nGroupID;
	}

	bool resNode::setDevice(IDirect3DDevice9* pDevice)
	{
		return onCreateDevice(pDevice);
	}

	// virtual...
	bool resNode::onCreateDevice(IDirect3DDevice9* pDevice)
	{
		XM_ASSERT(pDevice);
		return true;
	}
	bool resNode::onResetDevice(IDirect3DDevice9* pDevice)
	{
		XM_ASSERT(pDevice);
		return true;
	}
	void resNode::onLostDevice()
	{
	}
	void resNode::onDestroyDevice()
	{
	}

} // namespace XM