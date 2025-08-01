/*

file : XM_UI_EnumTypes.h

*/

#ifndef H_XM_STATUSUI_ENUMTYPES_H
#define H_XM_STATUSUI_ENUMTYPES_H

namespace XM
{
	enum STATUSUI_CONTROL_STATE
	{
		SCT_INVISIBLE,
		SCT_DISABLED,
		SCT_FOCUSED,
		SCT_NORMAL,	
		SCT_PUSH,
		SCT_TIP,
		SCT_STATUS_COUNT,
		SCT_TIP_FOCUSED,
		SCT_TIP_NORMAL,
		SCT_TIP_PUSH,

	}; // enum STATUSUI_CONTROL_STATE


	enum STATUSUI_EVENT_TYPE
	{
		SET_BUTTON_CLICKED,
        SET_BUTTON_R_CLICKED,
		SET_CHECKBOX_CHANGED,
		SET_RADIOBUTTON_CHANGED,
		SET_SLIDER_CHANGED,
		SET_EDITBOX_CHANGED,
		SET_EDITBOX_STRING,
		SET_IMEEDITBOX_CHANGED,
		SET_IMEEDITBOX_STRING,
		SET_LISTBOX_SELECTION,
		SET_LISTBOX_DOUBLECLICK,
		SET_COMBOBOX_CHANGE,
		SET_PROGRESSBAR_CLICKED,
		SET_TEXTBUTTON_CLICKED,
		SET_TOOLTIP_OVER,		
	}; // enum STATUSUI_EVENT_TYPE

	enum STATUSUI_POSITION
	{
		SPT_UPPERLEFT,
		SPT_UPPERMIDDLE,
		SPT_UPPERRIGHT,
		SPT_LEFT,
		SPT_MIDDLE,
		SPT_RIGHT,
		SPT_LOWERLEFT,
		SPT_LOWERMIDDLE,
		SPT_LOWERRIGHT,
	}; // enum STATUSUI_POSITION

	enum KEYBOARD_KEY
	{
		VK_0	=	0x30,
		VK_1	=	0x31,
		VK_2	=	0x32,
		VK_3	=	0x33,
		VK_4	=	0x34,
		VK_5	=	0x35,
		VK_6	=	0x36,
		VK_7	=	0x37,
		VK_8	=	0x38,
		VK_9	=	0x39,

		VK_A	=	0x41,
		VK_B	=	0x42,
		VK_C	=	0x43,
		VK_D	=	0x44,
		VK_E	=	0x45,
		VK_F	=	0x46,
		VK_G	=	0x47,
		VK_H	=	0x48,
		VK_I	=	0x49,
		VK_J	=	0x4A,
		VK_K	=	0x4B,
		VK_L	=	0x4C,
		VK_M	=	0x4D,
		VK_N	=	0x4E,
		VK_O	=	0x4F,
		VK_P	=	0x50,
		VK_Q	=	0x51,
		VK_R	=	0x52,
		VK_S	=	0x53,
		VK_T	=	0x54,
		VK_U	=	0x55,
		VK_V	=	0x56,
		VK_W	=	0x57,
		VK_X	=	0x58,
		VK_Y	=	0x59,
		VK_Z	=	0x5A,
	};
} // namespace XM

#endif // H_XM_STATUSUI_ENUMTYPES_H