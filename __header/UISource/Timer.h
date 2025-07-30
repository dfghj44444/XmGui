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
@Author��Double One
@Blog�� http://onedouble.cnblogs.com
@Modifier: Double One (dfghj77777@gmail.com)
@Modify Date��2013-08-05 14:01:30
@Modify Reason��
***********************************************************************/

#ifndef H_XM_CLOCK_H
#define H_XM_CLOCK_H
#include <chrono>

namespace XM
{
	class xmTimer
	{
	protected:
		bool					m_bTimerInited;
		bool					m_bPaused;
		float					m_fNow;
		float					m_fDelta;

        std::chrono::steady_clock::time_point m_dwStart;
		std::chrono::steady_clock::time_point m_dwCurrent;
		std::chrono::steady_clock::duration m_dwDelta;

	public:
		xmTimer();
		virtual ~xmTimer();

		void					updateTimer();
		void					resetTimer();
		void					pauseTimer(bool bPause);
		bool					isEnabled();

		float					getAbsoluteTime();

		float					getNow();
		float					getElapsedTime();

		int						GetNowInt();
		int						GetElapsedTimeInt();
	}; // class xmTimer

} // namespace XM

#endif // H_XM_CLOCK_H