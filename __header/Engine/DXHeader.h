#ifndef _DXHEADER_H_
#define _DXHEADER_H_



#include "DXEngine.h"

#ifndef SAFE_DELETE
	#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#endif
#ifndef DELETE_ARRAY
	#define DELETE_ARRAY(p)		 { if(p) { delete[] (p);   (p)=NULL; } }
#endif
#ifndef SAFE_RELEASE
	#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }
#endif
#ifndef SIZE_OF_ELEMENT
	#define SIZE_OF_ELEMENT(p)	 { (sizeof(p) / sizeof((p)[0]) );	   }
#endif

//----------------------------
// Desc : DirectX 
//----------------------------
#define DX_WINDOWS		0x01
#define DX_FULLSCREEN	0x02

#endif