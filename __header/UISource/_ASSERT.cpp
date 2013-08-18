/*
file : XM_ASSERT.cpp
*/


#include "stdafx.h"

#if defined(_DEBUG)||defined(DEBUG)

namespace XM
{
	void addPtrMap(void* pPtr, CStringW strCreationInfo, long lineNum)
	{
		g_pStaticEngine->addPtr(pPtr, strCreationInfo, lineNum);
	}
	void addPtrMap(void* pPtr, CStringW strCreationInfo, long lineNum, CStringW strSaveFilename )
	{
		g_pStaticEngine->addPtr(pPtr, strCreationInfo, lineNum, strSaveFilename);
	}
	void removePtrMap(void* pPtr)
	{
		g_pStaticEngine->removePtr(pPtr);
	}
	void printCurrentPtrList()
	{
		g_pStaticEngine->printPtrList();
	}
} // namespace XM

#endif 

