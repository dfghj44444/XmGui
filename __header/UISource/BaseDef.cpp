#include "stdafx.h"
namespace XM{
void makeStandard(wchar_t* name)
{
  _wcsupr(name);
	for(int i = 0; name[i]; ++i)
	{
		if(name[i] == L'/')
			name[i] = L'\\';
	}
}
}