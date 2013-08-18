/*
file : XM_BaseNode.cpp
*/


#include "stdafx.h"

namespace XM
{
	RTTIClass baseNode::RTTI;

	// ctor/dtor
	baseNode::baseNode()
	{
		// RTTI 
		XM_RTTI_INIT_POINTER;

		// reference count
		m_nRefCount	= 0;

		// name table
		m_strName = L"noname";
	}
	baseNode::~baseNode()
	{
	}

	// reference counting
	void baseNode::AddRef()
	{
		m_nRefCount++;
	}
	void baseNode::DelRef()
	{
		m_nRefCount--;
		if( m_nRefCount <= 0 )
		{
			#if defined(_DEBUG)||defined(DEBUG)
			removePtrMap(this);
			#endif
			delete this;
		}
	}
	int baseNode::getRef()
	{
		return m_nRefCount;
	}

	// RTTI
	RTTIClass*	baseNode::getRTTI()
	{
		return m_pRTTI;
	}
} // namespace XM
