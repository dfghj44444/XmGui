/*
file : XM_ASSERT.h
*/

#ifndef H_XM_ASSERT_H
#define H_XM_ASSERT_H

#if defined(_DEBUG)||defined(DEBUG)
#define XM_ASSERT(x)				if(!(x)) {__asm {int 0x03}}
#else
#define XM_ASSERT(x)
#endif

#define _SAFE_DELETE(x)			if(x) {delete x; x = 0;}
#define _SAFE_DELETE_ARRAY(x)	if(x) {delete[] x; x = 0;}
#define _SAFE_REF(x)				if(x) {x->AddRef();}
#define _SAFE_DEREF(x)			if(x) {x->DelRef(); x = 0;}
#define _SAFE_RELEASE(x)			if(x) {(x)->Release(); (x) = 0;}

#if defined(_DEBUG)||defined(DEBUG)
#define _NEW(x, y)				{x = new y; XM_ASSERT(x); XM::addPtrMap(x, __FILE__, __LINE__);}
#define _MAN_NEW(x, y, z)		{x = new y; XM_ASSERT(x); XM::addPtrMap(x, __FILE__, __LINE__, z);}
#define _NEW_ARRAY(x, y, z)		{x = new y[z]; XM_ASSERT(x); XM::addPtrMap(x, __FILE__, __LINE__);}
#define _DEL(x)					{XM::removePtrMap(x); _SAFE_DELETE(x);}
#define _DEL_ARRAY(x)			{XM::removePtrMap(x); _SAFE_DELETE_ARRAY(x);}
#else
#define _NEW(x, y)				{x = new y;}
#define _MAN_NEW(x, y, z)		{x = new y;}
#define _NEW_ARRAY(x, y, z)		{x = new y[z];}
#define _DEL(x)					{_SAFE_DELETE(x);}
#define _DEL_ARRAY(x)			{_SAFE_DELETE_ARRAY(x);}
#endif

// pointer table
#if defined(_DEBUG)||defined(DEBUG)
namespace XM
{
	void							addPtrMap(void* pPtr, CStringW strCreationInfo, long lineNum);
	void							addPtrMap(void* pPtr, CStringW strCreationInfo, long lineNum, CStringW strSaveFilename );
	void							removePtrMap(void* pPtr);
	void							printCurrentPtrList(WCHAR* filename);
} // namespace XM
#endif

#endif // H_XM_ASSERT_H