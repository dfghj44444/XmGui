/*
file : XM_ResourceMgr.cpp
*/


#include "stdafx.h"

namespace XM
{
	resMgr::resMgr()
	{

	}

	resMgr::~resMgr()
	{
		clear();
	}

	void resMgr::clear()
	{
		int nSize = m_listResources.size();
		int nIndex = 0;
		while(nSize > 0)
		{
			if(nIndex >= nSize)
			{
				break;
			}

			m_listResources[nIndex]->DelRef();
			m_listResources.erase(nIndex);

			nSize = m_listResources.size();
		}
	}

} // namespace XM