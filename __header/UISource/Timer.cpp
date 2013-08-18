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
@File Name:Timer.cpp
@Describe:This is a part of XM_GUI
@Create Date:2010-10-7 14:01:29
@Version:1.0
@Author£ºDouble One
@Blog£º http://onedouble.cnblogs.com
@Modifier: Double One (dfghj77777@gmail.com)
@Modify Date£º2013-08-05 14:01:30
@Modify Reason£º
***********************************************************************/
#include "stdafx.h"

namespace XM
{
	xmTimer::xmTimer()
	{
		m_fNow			= 0.0f;
		m_fDelta		= 0.0f;
		m_bTimerInited	= false;
		m_bPaused		= false;
	}
	xmTimer::~xmTimer()
	{
	}

	float xmTimer::getAbsoluteTime()
	{
		updateTimer();
		return m_fNow;
	}

	bool xmTimer::isEnabled()
	{
		return m_bTimerInited;
	}
	float xmTimer::getNow()
	{
		return m_fNow;
	}
	float xmTimer::getElapsedTime()
	{
		return m_fDelta;
	}

	int xmTimer::getNow_Int()
	{
		return (int)(m_fNow * 1000.0f);
	}
	int xmTimer::getElapsedTime_Int()
	{
		return (int)(m_fDelta * 1000.0f);
	}

	void xmTimer::resetTimer()
	{
		m_dwStart   = timeGetTime();
		m_dwCurrent = m_dwStart;
		m_dwDelta   = 0;
		m_fNow      = 0.0f;
		m_fDelta    = 0.0f;
	}
	void xmTimer::updateTimer()
	{
		if(m_bPaused == false)
		{
			DWORD Current = timeGetTime();
			m_dwDelta = Current - m_dwCurrent;
			m_dwCurrent = Current;
			m_fNow = (float)(m_dwCurrent - m_dwStart) * 0.001f;
			m_fDelta = (float)(m_dwDelta) * 0.001f;
		}
	}

	void xmTimer::pauseTimer(bool bPause)
	{
		m_bPaused = bPause;
		if(m_bPaused == false)
			resetTimer();
	}
} // namespace XM