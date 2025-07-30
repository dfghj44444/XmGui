/*
file : XM_RTTI.cpp
*/


#include "stdafx.h"

namespace XM
{
	RTTIClass::RTTIClass()
	{
		m_pSuper		= nullptr;
		setName("XM basetype");
	}
	RTTIClass::RTTIClass(const WCHAR* strName, RTTIClass* pSuper)
	{
		XM_ASSERT(strName);
		XM_ASSERT(pSuper);
		m_pSuper = pSuper;
		setName(strName);
	}
	RTTIClass::~RTTIClass()
	{
	}

	// name
	void RTTIClass::setName(const WCHAR* strName)
	{
		XM_ASSERT(strName);
		m_strName = strName;
	}
	void RTTIClass::setName(const CStringW strName)
	{
		m_strName = strName;
	}
	const WCHAR* RTTIClass::getName()
	{
		return m_strName.GetBuffer();
	}

	RTTIClass* RTTIClass::getSuper()
	{
		return m_pSuper;
	}

	// type checking
	bool RTTIClass::isA(RTTIClass* pRTTI)
	{
		XM_ASSERT(pRTTI);
		if(pRTTI == this)
		{
			return true;
		}
		return false;
	}
	bool RTTIClass::isAKindOf(RTTIClass* pRTTI)
	{
		XM_ASSERT(pRTTI);
		RTTIClass* pStartType = this;

		while(pStartType)
		{
			if(pStartType == pRTTI)
			{
				return true;
			}
			else
			{
				pStartType = pStartType->getSuper();
			}
		}
		return false;
	}
} // namespace XM
