/*

file : XM_Base.h

*/

#ifndef H_XM_BASEFILES_H
#define H_XM_BASEFILES_H

// 包含配置文件
#include "../../include/XmGuiConfig.h"

// 使用配置文件中的值替代硬编码常量
#define H_DEF_VECTORT_BASESIZE_H			XMGUI_VECTOR_BASE_SIZE
#define H_DEF_LEAKCHECKNAME_LENGTH			XMGUI_LEAK_CHECK_NAME_LENGTH
#define	H_DEF_UNDO_LEVEL_DEFAULT			XMGUI_UNDO_LEVEL_DEFAULT

typedef enum UI_CONTROL_STATE
{
	UIDS_INVISIBLE = 0,
	UIDS_DISABLE ,
	UIDS_PRESSED ,
	UIDS_MOUSEOVER ,
	UIDS_FOCUS ,
	UIDS_NORMAL ,
	UIDS_STATE_COUNT,
}; // typedef enum UI_CONTROL_STATE


#ifndef WINVER
#define WINVER         0x0410
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0410 
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT   0x0500 
#endif

#ifndef WM_XBUTTONDOWN
#define WM_XBUTTONDOWN 0x020B // (not always defined)
#endif

#ifndef WM_XBUTTONUP
#define WM_XBUTTONUP 0x020C // (not always defined)
#endif

#ifndef WM_MOUSEWHEEL
#define WM_MOUSEWHEEL 0x020A // (not always defined)
#endif

#ifndef WHEEL_DELTA
#define WHEEL_DELTA 120 // (not always defined)
#endif

#ifndef WM_XBUTTONDBLCLK
#define WM_XBUTTONDBLCLK 0x020D
#endif

#ifndef SPI_GETWHEELSCROLLLINES
#define SPI_GETWHEELSCROLLLINES 0x0068
#endif

inline float clampf(float x, float min, float max)
{
	return (x < min) ? min : (x > max) ? max : x;
}

// 使用配置文件中的屏幕设置
#define _SCREEN_WIDTH	XMGUI_GET_SCREEN_WIDTH()
#define _SCREEN_HEIGHT	XMGUI_GET_SCREEN_HEIGHT()
#define _SCREEN_BPP     XMGUI_GET_CONFIG().screenBPP

// WCHAR - > char ��ȯ
inline char* WcharToChar(const wchar_t* pwstrSrc)
{
	//XM_ASSERT(pwstrSrc);

	size_t len = (wcslen(pwstrSrc)+1)*2;
	char* pstr = (char*)malloc(sizeof(char)*len);
	WideCharToMultiByte( CP_ACP,0,pwstrSrc,-1,pstr,(int)len,NULL,NULL);
	return pstr;
}

void makeStandard(wchar_t* name)
{
	_wcsupr(name);
	for(int i = 0; name[i]; ++i)
	{
		if(name[i] == L'/')
			name[i] = L'\\';
	}
}
#endif // H_XM_BASEFILES_H
