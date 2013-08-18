/*

file : XM_StatusUI_Base.cpp

*/


#include "stdafx.h"

namespace XM
{
	// RTTI s
	XM_RTTI_CREATE_STATIC(UI_Base, L"UI_Base", baseNode);

	///////////////////////////////////////////////////////////////////////////
	// ctor/dtor
	UI_Base::UI_Base()
	{
		// RTTI
		XM_RTTI_INIT_POINTER;
	}
	UI_Base::~UI_Base()
	{
	}
	// ctor/dtor
	///////////////////////////////////////////////////////////////////////////

} // namespace XM