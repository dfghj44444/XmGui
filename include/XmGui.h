/**
 * @file XmGui.h
 * @brief 主要的XmGui头文件 - 包含所有必要的UI组件
 * @author Double One (dfghj77777@gmail.com)
 * @version 1.0.0
 * @date 2025-01-09
 * 
 * XmGui - 基于DirectX 9的轻量级游戏UI库
 * 
 * 特性：
 * - 高性能DirectX 9渲染
 * - 完整的UI控件系统
 * - 事件处理机制
 * - 资源管理
 * - RTTI支持
 * - Unicode字符支持
 * 
 * 使用示例：
 * @code
 * #include "XmGui.h"
 * 
 * // 初始化引擎
 * XM::xmEngine* pEngine = XM::xmEngine::getInstance();
 * pEngine->onCreateDevice(pD3DDevice);
 * 
 * // 创建UI管理器
 * XM::UI_Manager* pManager = new XM::UI_Manager();
 * pEngine->addStatusUIManager(pManager);
 * 
 * // 创建按钮
 * XM::UI_Button* pButton = new XM::UI_Button();
 * pButton->setID(100);
 * pButton->setPosition(100, 100, 0);
 * pManager->addChild(pButton);
 * @endcode
 * 
 * @note 本库采用LGPL v2.1许可证
 */

#ifndef XMGUI_H
#define XMGUI_H
// Unicode和字符集支持
#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#include <d3d9.h>

// 版本信息
#define XMGUI_VERSION_MAJOR 1
#define XMGUI_VERSION_MINOR 0
#define XMGUI_VERSION_PATCH 0
#define XMGUI_VERSION_STRING L"1.0.0"

// 平台检测
#if !defined(_WIN32) && !defined(_WIN64)
#error "XmGui only supports Windows platform"
#endif

// 编译器检测
#if defined(_MSC_VER)
    #if _MSC_VER < 1400  // Visual Studio 2005
        #error "XmGui requires Visual Studio 2005 or later"
    #endif
#endif

// DirectX版本检测
#ifndef D3D_SDK_VERSION
#error "DirectX SDK is required to compile XmGui"
#endif

// 配置选项
#ifndef XMGUI_CONFIG_UNICODE
#define XMGUI_CONFIG_UNICODE 1  // 默认启用Unicode支持
#endif

#ifndef XMGUI_CONFIG_DEBUG_MEMORY
#ifdef _DEBUG
#define XMGUI_CONFIG_DEBUG_MEMORY 1  // 调试模式下启用内存检测
#else
#define XMGUI_CONFIG_DEBUG_MEMORY 0
#endif
#endif

// Windows和DirectX头文件
#ifndef WINVER
#define WINVER 0x0500
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif

#include <windows.h>
#include <tchar.h>
#include <wchar.h>
#include <d3dx9.h>

// 标准C++头文件
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <algorithm>
#include <functional>
#include <iostream>
// 兼容性定义
#if XMGUI_CONFIG_UNICODE
    typedef std::wstring XmString;
    typedef wchar_t XmChar;
    #define XM_TEXT(x) L##x
#else
    typedef std::string XmString;
    typedef char XmChar;
    #define XM_TEXT(x) x
#endif

// 前向声明
namespace XM {
    class baseNode;
    class UI_Base;
    class UI_Object;
    class UI_Widget;
    class UI_Manager;
    class UI_Button;
    class UI_Box;
    class xmEngine;
    class RTTIClass;
    class fontNode;
    class texNode;
    class UI_RectItem;
}


// 包含核心头文件（保持向后兼容）
#include "../__header/UISource/BaseDef.h"
#include "../__header/UISource/EnumTypes.h"
#include "../__header/UISource/RTTI.h"
#include "../__header/UISource/_Vector.h"
#include "../__header/UISource/BaseNode.h"
#include "../__header/UISource/ResNode.h"
#include "../__header/UISource/ResMgr.h"
#include "../__header/UISource/ui_base.h"
#include "../__header/UISource/UI_Object.h"
#include "../__header/UISource/MouseUtil.h"
#include "../__header/UISource/UI_Widget.h"
#include "../__header/UISource/uibutton.h"
#include "../__header/UISource/UI_Box.h"
#include "../__header/UISource/uimanager.h"
#include "../__header/UISource/timer.h"
#include "../__header/UISource/UI_Rect.h"
#include "../__header/UISource/UI_RectItem.h"
#include "../__header/UISource/UI_RectItemText.h"
#include "../__header/UISource/font.h"
#include "../__header/UISource/fontmgr.h"
#include "../__header/UISource/TextureNode.h"
#include "../__header/UISource/texturemgr.h"
#include "../__header/UISource/engine.h"
// 新的渲染抽象层
#include "XmGuiRenderer.h"

// 便利宏定义
#define XM_ENGINE_INSTANCE          XM::xmEngine::getInstance()
#define XM_TEXTURE_MANAGER          XM_ENGINE_INSTANCE->getTexManager()
#define XM_FONT_MANAGER             XM_ENGINE_INSTANCE->getFontManager()
#define XM_TIMER                    XM_ENGINE_INSTANCE->getTimer()
#define XM_DEVICE                   XM_ENGINE_INSTANCE->getDevice()

// 安全释放宏
#define XM_SAFE_RELEASE(p) \
    do { \
        if (p) { \
            (p)->Release(); \
            (p) = nullptr; \
        } \
    } while(0)

#define XM_SAFE_DELETE(p) \
    do { \
        if (p) { \
            delete (p); \
            (p) = nullptr; \
        } \
    } while(0)

#define XM_SAFE_DELETE_ARRAY(p) \
    do { \
        if (p) { \
            delete[] (p); \
            (p) = nullptr; \
        } \
    } while(0)

// 调试宏
#if XMGUI_CONFIG_DEBUG_MEMORY
#define XM_DEBUG_MEMORY_LEAK_CHECK() \
    do { \
        XM_ENGINE_INSTANCE->printPtrList(); \
    } while(0)
#else
#define XM_DEBUG_MEMORY_LEAK_CHECK() ((void)0)
#endif

// 事件回调类型定义
namespace XM {
    /**
     * @brief UI事件回调函数类型
     * @param nEvent 事件类型
     * @param nControlID 控件ID
     * @param pControl 控件指针
     * @param pUserContext 用户上下文
     */
    typedef void (CALLBACK *UIEventCallback)(
        UINT nEvent, 
        int nControlID, 
        UI_Object* pControl, 
        void* pUserContext
    );

    /**
     * @brief 创建UI控件的工厂函数类型
     * @param strTypeName 控件类型名称
     * @return 创建的控件指针
     */
    typedef UI_Widget* (*CreateControlFunc)(const XmString& strTypeName);
}

// 实用工具函数
namespace XM {
    /**
     * @brief 获取XmGui版本字符串
     * @return 版本字符串
     */
    inline const XmChar* GetVersionString() {
        return XMGUI_VERSION_STRING;
    }

    /**
     * @brief 检查DirectX设备是否有效
     * @param pDevice DirectX设备指针
     * @return 如果设备有效返回true
     */
    inline bool IsDeviceValid(IDirect3DDevice9* pDevice) {
        return pDevice && SUCCEEDED(pDevice->TestCooperativeLevel());
    }

    /**
     * @brief 颜色值转换工具
     * @param r 红色分量 (0-255)
     * @param g 绿色分量 (0-255)
     * @param b 蓝色分量 (0-255)
     * @param a 透明度分量 (0-255)
     * @return D3DCOLOR格式的颜色值
     */
    inline D3DCOLOR MakeColor(BYTE r, BYTE g, BYTE b, BYTE a = 255) {
        return D3DCOLOR_ARGB(a, r, g, b);
    }

    /**
     * @brief 矩形区域检测
     * @param x 点的X坐标
     * @param y 点的Y坐标
     * @param rect 矩形区域
     * @return 如果点在矩形内返回true
     */
    inline bool PointInRect(int x, int y, const RECT& rect) {
        return x >= rect.left && x <= rect.right && 
               y >= rect.top && y <= rect.bottom;
    }
}

// 初始化和清理函数
namespace XM {
    /**
     * @brief 初始化XmGui系统
     * @param pDevice DirectX设备指针
     * @param hWnd 窗口句柄
     * @return 成功返回true
     */
    inline bool InitializeXmGui(IDirect3DDevice9* pDevice, HWND hWnd) {
        xmEngine* pEngine = xmEngine::getInstance();
        if (!pEngine) return false;
        
        pEngine->setHwnd(hWnd);
        return pEngine->onCreateDevice(pDevice);
    }

    /**
     * @brief 清理XmGui系统
     */
    inline void ShutdownXmGui() {
        xmEngine* pEngine = xmEngine::getInstance();
        if (pEngine) {
            pEngine->onDestroyDevice();
        }
    }

    //=========================================================================
    // 新的渲染器抽象层便利函数
    //=========================================================================
    
    /**
     * @brief 获取支持的渲染器列表
     * @return 支持的渲染器类型列表
     */
    inline std::vector<RendererType> GetSupportedRenderers() {
        return RendererFactory::GetSupportedRenderers();
    }
    
    /**
     * @brief 创建并初始化渲染器
     * @param type 渲染器类型，可以是Auto、DX9、DX11、Vulkan等
     * @param hWnd 窗口句柄
     * @param width 渲染宽度
     * @param height 渲染高度
     * @param fullscreen 是否全屏
     * @return 初始化成功的渲染器指针，失败返回nullptr
     */
    inline std::unique_ptr<IRenderer> CreateRenderer(
        RendererType type, HWND hWnd, int width, int height, bool fullscreen = false) {
        return CreateAndInitializeRenderer(type, hWnd, width, height, fullscreen);
    }
    
    /**
     * @brief 自动创建最佳渲染器
     * @param hWnd 窗口句柄
     * @param width 渲染宽度
     * @param height 渲染高度
     * @param fullscreen 是否全屏
     * @return 初始化成功的渲染器指针，失败返回nullptr
     */
    //inline std::unique_ptr<IRenderer> CreateBestRenderer(
    //    HWND hWnd, int width, int height, bool fullscreen = false) {
    //    return XM::CreateBestRenderer(hWnd, width, height, fullscreen);
    //}
    
    /**
     * @brief 检查渲染器是否支持
     * @param type 渲染器类型
     * @return 支持返回true，否则返回false
     */
    inline bool IsRendererSupported(RendererType type) {
        return RendererFactory::IsRendererSupported(type);
    }
    
    /**
     * @brief 渲染器类型转字符串
     * @param type 渲染器类型
     * @return 渲染器类型的字符串表示
     */
    inline std::string RendererTypeToString(RendererType type) {
        return RendererFactory::RendererTypeToString(type);
    }
    
    /**
     * @brief 获取默认渲染器类型
     * @return 系统推荐的默认渲染器类型
     */
    inline RendererType GetDefaultRendererType() {
        return RendererFactory::GetDefaultRendererType();
    }
}

#endif // XMGUI_H 