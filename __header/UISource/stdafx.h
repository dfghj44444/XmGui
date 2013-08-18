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
@File Name:stdafx.h
@Describe:This is a part of XM_GUI
@Create Date:2010-10-7 14:01:29
@Version:1.0
@Author£ºDouble One
@Blog£º http://onedouble.cnblogs.com
@Modifier: Double One (dfghj77777@gmail.com)
@Modify Date£º2013-08-05 14:01:30
@Modify Reason£º
***********************************************************************/
#pragma once

// TODO: reference additional headers your program requires here
// Windows Header Files:
#include <windows.h>
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <MMSystem.h>

#pragma warning(disable:4995)
#pragma warning(disable:4819) //The file contains a character that cannot be represented in the current code page
#pragma warning(disable:4996) //This function or variable may be unsafe

#include <windows.h>
#include <TCHAR.h>
#include <winuser.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dxerr.h>
#include <wchar.h>
#include <strsafe.h>
#include <atlstr.h>
#include <map>
#include <hash_map>
#include <vector>
#include <usp10.h>
#include <dimm.h>
#include <string>

// TODO: reference additional headers your program requires here
#include "BaseDef.h"
#include "RTTI.h"
#include "Font.h"
#include "_ASSERT.h"
#include "_Vector.h"
#include "BaseNode.h"
#include "MouseUtil.h"
//#include "XM_VertexTypes.h"
#include "RenderUtil.h"
//#include "XM_UniBuffer.h"
///////////////////////////////////////////////////////////////////////////////
// W/R in binary
#include "StreamFile.h"
#include "StreamUtil.h"
// Timer
#include "Timer.h"

// 
// resource
#include "ResNode.h"
#include "ResMgr.h"
// texture
#include "TextureNode.h"
#include "TextureMgr.h"

// Font
#include "FontCreationParam.h"
#include "FontNode.h"
#include "FontMgr.h"
//UI
#include "EnumTypes.h"
#include "ClassTypes.h"
#include "UI_Base.h"
#include "UI_Rect.h"
#include "UI_RectItem.h"
#include "ui_rectitemtext.h"
#include "UI_Object.h"
#include "UI_Widget.h"
#include "UI_Box.h"
#include "UIManager.h"

//UI
#include "UIButton.h"

#include "Engine.h"