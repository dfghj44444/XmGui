/*
file : XM_TextureMgr.cpp
*/


#include "stdafx.h"

namespace XM
{	
	// ctor/dtor
	texMgr::texMgr()
	{
	}
	texMgr::~texMgr()
	{
		clear();
	}

	texNode* texMgr::getTextureNode(CStringW filename)
	{
		texNode* pExistTexNode = g_pStaticEngine->getTexNode(filename.GetBuffer());
		if(pExistTexNode)
		{
			return pExistTexNode;
		}
#if 0
		xmVec<texNode*>* pTexList = g_pStaticEngine->getTextureList();
		XM_ASSERT(pTexList);
		if(pTexList == 0) return 0;

		int nSize = pTexList->size();
		for(int i = 0; i<nSize; ++i)
		{
			if((*pTexList)[i]->getResname() == filename)
			{
				return (*pTexList)[i];
			}
		}
#endif
		bool bResult;

		texNode* pNode;
		_NEW(pNode, texNode);
		if(pNode == nullptr)
		{
			return nullptr;
		}

		bResult = pNode->setResname(filename);
		if(bResult == false)
		{
			_DEL(pNode);
			return nullptr;
		}

		bResult = pNode->setDevice(g_pStaticEngine->getDevice());
		if(bResult == false)
		{
			_DEL(pNode);
			return nullptr;
		}

		g_pStaticEngine->addTexNode(filename.GetBuffer(), pNode);

		return pNode;
	}	

	texNode* texMgr::getTextureNode(CStringW filename, texCreateParam* pParam)
	{
		texNode* pExistTexNode = g_pStaticEngine->getTexNode(filename.GetBuffer());
		if(pExistTexNode)
		{
			return pExistTexNode;
		}

		bool bResult;

		texNode* pNode;
		_NEW(pNode, texNode(pParam));
		if(pNode == nullptr)
			return nullptr;

		bResult = pNode->setResname(filename);
		if(bResult == false)
		{
			_DEL(pNode);
			return nullptr;
		}

		bResult = pNode->setDevice(g_pStaticEngine->getDevice());
		if(bResult == false)
		{
			_DEL(pNode);
			return nullptr;
		}

		g_pStaticEngine->addTexNode(filename.GetBuffer(), pNode);

		return pNode;
	}
} // namespace XM