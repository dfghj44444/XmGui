/***********************************************************************
Copyright:2010-2013 Double One<dfghj77777@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA., or go to http://www.gnu.org/copyleft/lesser.txt

--------------------------------------------------------------------
@File Name:UI_Contorl.cpp
@Describe:This is a part of XM_GUI
@Create Date:2010-10-7 14:01:29
@Version:1.0
@Author：Double One
@Blog： http://onedouble.cnblogs.com
@Modifier: Double One (dfghj77777@gmail.com)
@Modify Date：2013-08-05 14:01:30
@Modify Reason：
***********************************************************************/
#ifndef H_XM_UI_MANAGER_H
#define H_XM_UI_MANAGER_H

namespace XM
{
	typedef VOID (CALLBACK *PCALLBACKSTATUSGUIEVENT) (UINT nEvent, int nControlID, UI_Object* pControl, void* pUserContext);	
	class UI_Manager : public UI_Box
	{
		XM_RTTI_DECLARE_STATIC

	protected:
		static UI_Object*				m_pFocus;		
		UI_Object*						m_pMouseOver;	

		//UI_ToolTip*				m_pToolTip;
		int								m_nDefaultControl;

		PCALLBACKSTATUSGUIEVENT			m_pEventCallback;
		void*							m_pUserContext;

		float							m_fAlpha;
		bool							m_bAlphaCkeck;

        static int						s_SuperID;//开始时000，每多一个manager自增1，以保证各个manageriD不同
	public:
		// ctor/dtor
		UI_Manager();
		virtual ~UI_Manager();
	
		// serialize
		virtual bool			saveFile(IStream& rStream);
		virtual bool			loadFile(IStream& rStream);

		void					clear();

		virtual void			render(IDirect3DDevice9* pd3dDevice);
		virtual void			frameMove( DWORD dwElapsedTime = 0 );

		virtual bool			msgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
		void					onMouseMove(int nMouseX, int nMouseY);

		UI_Object*				GetMouseUpFocus();
		// focus object
		void					clearFocus();
		void					focusDefaultControl();
		void					setFocus(UI_Object* pControl);
		void					setNextFocus();
		void					refresh();
		//   KEY DWON UP
		void					SetAlphaCheck( const bool& bFlag );

		bool*					GetControlComPare();
		// default control id
		void					setDefaultControlID(int nID);
		int						getDefaultControlID();

		// callback function
		void					setEventCallback(PCALLBACKSTATUSGUIEVENT pCallback, void* pUserContext = NULL);
		void					sendEvent(UINT nEvent, bool bTriggeredByUser, UI_Object* pControl);
	}; // class UI_Manager

} // namespace XM

#endif // H_XM_STATUSUI_MANAGER_H