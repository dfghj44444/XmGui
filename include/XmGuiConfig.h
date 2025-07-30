/**
 * @file XmGuiConfig.h
 * @brief XmGui配置文件 - 集中管理所有可配置的参数
 * @author Double One
 * @version 1.0.0
 * @date 2025-01-09
 * 
 * 这个文件包含了XmGui库的所有配置选项，通过修改这些值可以定制库的行为。
 * 建议在编译时通过预处理器宏定义来覆盖这些默认值。
 */

#ifndef XMGUI_CONFIG_H
#define XMGUI_CONFIG_H

//=============================================================================
// 版本配置
//=============================================================================
#define XMGUI_VERSION_MAJOR         1
#define XMGUI_VERSION_MINOR         0
#define XMGUI_VERSION_PATCH         0
#define XMGUI_VERSION_BUILD         0

//=============================================================================
// 平台配置
//=============================================================================
#ifndef XMGUI_PLATFORM_WINDOWS
#define XMGUI_PLATFORM_WINDOWS      1
#endif

#ifndef XMGUI_DIRECTX_VERSION
#define XMGUI_DIRECTX_VERSION       9
#endif

//=============================================================================
// 渲染器配置
//=============================================================================
// 启用DirectX 9支持
#ifndef XMGUI_ENABLE_DX9
#define XMGUI_ENABLE_DX9            1
#endif

// 启用DirectX 11支持
#ifndef XMGUI_ENABLE_DX11
#define XMGUI_ENABLE_DX11           1
#endif

// 启用Vulkan支持（需要安装Vulkan SDK）
#ifndef XMGUI_ENABLE_VULKAN
#define XMGUI_ENABLE_VULKAN         0
#endif

//=============================================================================
// 显示配置
//=============================================================================
// 默认屏幕分辨率（可以在运行时修改）
#ifndef XMGUI_DEFAULT_SCREEN_WIDTH
#define XMGUI_DEFAULT_SCREEN_WIDTH  1024
#endif

#ifndef XMGUI_DEFAULT_SCREEN_HEIGHT
#define XMGUI_DEFAULT_SCREEN_HEIGHT 768
#endif

#ifndef XMGUI_DEFAULT_SCREEN_BPP
#define XMGUI_DEFAULT_SCREEN_BPP    32
#endif

// 最小和最大分辨率限制
#ifndef XMGUI_MIN_SCREEN_WIDTH
#define XMGUI_MIN_SCREEN_WIDTH      320
#endif

#ifndef XMGUI_MIN_SCREEN_HEIGHT
#define XMGUI_MIN_SCREEN_HEIGHT     240
#endif

#ifndef XMGUI_MAX_SCREEN_WIDTH
#define XMGUI_MAX_SCREEN_WIDTH      7680  // 8K width
#endif

#ifndef XMGUI_MAX_SCREEN_HEIGHT
#define XMGUI_MAX_SCREEN_HEIGHT     4320  // 8K height
#endif

//=============================================================================
// 字体配置
//=============================================================================
// 字体纹理大小
#ifndef XMGUI_FONT_TEXTURE_SIZE
#define XMGUI_FONT_TEXTURE_SIZE     256
#endif

// 最大批处理字符数
#ifndef XMGUI_MAX_BATCH_COUNT
#define XMGUI_MAX_BATCH_COUNT       1024
#endif

// 默认字体名称
#ifndef XMGUI_DEFAULT_FONT_NAME
#define XMGUI_DEFAULT_FONT_NAME     L"微软雅黑"
#endif

// 默认字体大小
#ifndef XMGUI_DEFAULT_FONT_SIZE
#define XMGUI_DEFAULT_FONT_SIZE     12
#endif

// 字体缓存大小
#ifndef XMGUI_FONT_CACHE_SIZE
#define XMGUI_FONT_CACHE_SIZE       256
#endif

//=============================================================================
// 内存配置
//=============================================================================
// 基础向量大小
#ifndef XMGUI_VECTOR_BASE_SIZE
#define XMGUI_VECTOR_BASE_SIZE      8
#endif

// 内存泄漏检查文件名长度
#ifndef XMGUI_LEAK_CHECK_NAME_LENGTH
#define XMGUI_LEAK_CHECK_NAME_LENGTH 256
#endif

// 撤销级别
#ifndef XMGUI_UNDO_LEVEL_DEFAULT
#define XMGUI_UNDO_LEVEL_DEFAULT    4096
#endif

// 对象池初始大小
#ifndef XMGUI_OBJECT_POOL_SIZE
#define XMGUI_OBJECT_POOL_SIZE      128
#endif

//=============================================================================
// 渲染配置
//=============================================================================
// 最大渲染对象数
#ifndef XMGUI_MAX_RENDER_OBJECTS
#define XMGUI_MAX_RENDER_OBJECTS    1000
#endif

// 纹理缓存大小
#ifndef XMGUI_TEXTURE_CACHE_SIZE
#define XMGUI_TEXTURE_CACHE_SIZE    64
#endif

// 默认Z-order步长
#ifndef XMGUI_DEFAULT_Z_STEP
#define XMGUI_DEFAULT_Z_STEP        0.1f
#endif

// 最大Z-order值
#ifndef XMGUI_MAX_Z_ORDER
#define XMGUI_MAX_Z_ORDER           1000.0f
#endif

//=============================================================================
// 事件配置
//=============================================================================
// 最大事件队列大小
#ifndef XMGUI_MAX_EVENT_QUEUE_SIZE
#define XMGUI_MAX_EVENT_QUEUE_SIZE  256
#endif

// 双击间隔时间（毫秒）
#ifndef XMGUI_DOUBLE_CLICK_TIME
#define XMGUI_DOUBLE_CLICK_TIME     500
#endif

// 鼠标悬停延迟（毫秒）
#ifndef XMGUI_HOVER_DELAY
#define XMGUI_HOVER_DELAY           1000
#endif

//=============================================================================
// 动画配置
//=============================================================================
// 默认动画时长（毫秒）
#ifndef XMGUI_DEFAULT_ANIMATION_DURATION
#define XMGUI_DEFAULT_ANIMATION_DURATION 200
#endif

// 动画帧率
#ifndef XMGUI_ANIMATION_FPS
#define XMGUI_ANIMATION_FPS         60
#endif

// 最大同时动画数
#ifndef XMGUI_MAX_CONCURRENT_ANIMATIONS
#define XMGUI_MAX_CONCURRENT_ANIMATIONS 32
#endif

//=============================================================================
// 调试配置
//=============================================================================
// 启用调试输出
#ifndef XMGUI_ENABLE_DEBUG_OUTPUT
#ifdef _DEBUG
#define XMGUI_ENABLE_DEBUG_OUTPUT   1
#else
#define XMGUI_ENABLE_DEBUG_OUTPUT   0
#endif
#endif

// 启用内存泄漏检测
#ifndef XMGUI_ENABLE_MEMORY_LEAK_DETECTION
#ifdef _DEBUG
#define XMGUI_ENABLE_MEMORY_LEAK_DETECTION 1
#else
#define XMGUI_ENABLE_MEMORY_LEAK_DETECTION 0
#endif
#endif

// 启用性能统计
#ifndef XMGUI_ENABLE_PERFORMANCE_STATS
#define XMGUI_ENABLE_PERFORMANCE_STATS 0
#endif

//=============================================================================
// 文件配置
//=============================================================================
// 最大文件路径长度
#ifndef XMGUI_MAX_PATH_LENGTH
#define XMGUI_MAX_PATH_LENGTH       260
#endif

// 配置文件名
#ifndef XMGUI_CONFIG_FILE_NAME
#define XMGUI_CONFIG_FILE_NAME      L"xmgui.cfg"
#endif

// 资源文件扩展名
#ifndef XMGUI_RESOURCE_FILE_EXTENSION
#define XMGUI_RESOURCE_FILE_EXTENSION L".xmres"
#endif

//=============================================================================
// 本地化配置
//=============================================================================
// 默认语言
#ifndef XMGUI_DEFAULT_LANGUAGE
#define XMGUI_DEFAULT_LANGUAGE      "zh-CN"
#endif

// 字符编码
#ifndef XMGUI_DEFAULT_CODEPAGE
#define XMGUI_DEFAULT_CODEPAGE      936  // 简体中文
#endif

//=============================================================================
// 网络配置（为将来的网络功能预留）
//=============================================================================
// 最大连接数
#ifndef XMGUI_MAX_CONNECTIONS
#define XMGUI_MAX_CONNECTIONS       16
#endif

// 网络缓冲区大小
#ifndef XMGUI_NETWORK_BUFFER_SIZE
#define XMGUI_NETWORK_BUFFER_SIZE   4096
#endif

//=============================================================================
// 配置验证宏
//=============================================================================
// 编译时检查配置的合理性
#if XMGUI_DEFAULT_SCREEN_WIDTH < XMGUI_MIN_SCREEN_WIDTH
#error "XMGUI_DEFAULT_SCREEN_WIDTH cannot be less than XMGUI_MIN_SCREEN_WIDTH"
#endif

#if XMGUI_DEFAULT_SCREEN_HEIGHT < XMGUI_MIN_SCREEN_HEIGHT
#error "XMGUI_DEFAULT_SCREEN_HEIGHT cannot be less than XMGUI_MIN_SCREEN_HEIGHT"
#endif

#if XMGUI_FONT_TEXTURE_SIZE < 64
#error "XMGUI_FONT_TEXTURE_SIZE must be at least 64"
#endif

#if XMGUI_MAX_BATCH_COUNT < 1
#error "XMGUI_MAX_BATCH_COUNT must be at least 1"
#endif

//=============================================================================
// 运行时配置结构
//=============================================================================
namespace XM {
    /**
     * @brief 运行时配置结构
     * 
     * 这个结构包含了可以在运行时修改的配置选项。
     * 通过修改这些值，可以动态调整库的行为。
     */
    struct RuntimeConfig {
        // 显示配置
        int screenWidth;
        int screenHeight;
        int screenBPP;
        
        // 字体配置
        int fontSize;
        const wchar_t* fontName;
        
        // 性能配置
        int maxRenderObjects;
        int textureCacheSize;
        bool enableVSync;
        
        // 调试配置
        bool enableDebugOutput;
        bool enableMemoryLeakDetection;
        bool enablePerformanceStats;
        
        // 默认构造函数
        RuntimeConfig() 
            : screenWidth(XMGUI_DEFAULT_SCREEN_WIDTH)
            , screenHeight(XMGUI_DEFAULT_SCREEN_HEIGHT)
            , screenBPP(XMGUI_DEFAULT_SCREEN_BPP)
            , fontSize(XMGUI_DEFAULT_FONT_SIZE)
            , fontName(XMGUI_DEFAULT_FONT_NAME)
            , maxRenderObjects(XMGUI_MAX_RENDER_OBJECTS)
            , textureCacheSize(XMGUI_TEXTURE_CACHE_SIZE)
            , enableVSync(false)
            , enableDebugOutput(XMGUI_ENABLE_DEBUG_OUTPUT != 0)
            , enableMemoryLeakDetection(XMGUI_ENABLE_MEMORY_LEAK_DETECTION != 0)
            , enablePerformanceStats(XMGUI_ENABLE_PERFORMANCE_STATS != 0)
        {
        }
    };
    
    /**
     * @brief 获取运行时配置
     * @return 运行时配置的引用
     */
    RuntimeConfig& GetRuntimeConfig();
    
    /**
     * @brief 从文件加载配置
     * @param filename 配置文件名
     * @return 成功返回true
     */
    bool LoadConfigFromFile(const wchar_t* filename);
    
    /**
     * @brief 保存配置到文件
     * @param filename 配置文件名
     * @return 成功返回true
     */
    bool SaveConfigToFile(const wchar_t* filename);
    
    /**
     * @brief 重置配置为默认值
     */
    void ResetConfigToDefault();
}

//=============================================================================
// 便利宏
//=============================================================================
// 获取配置值的便利宏
#define XMGUI_GET_CONFIG()              XM::GetRuntimeConfig()
#define XMGUI_GET_SCREEN_WIDTH()        XMGUI_GET_CONFIG().screenWidth
#define XMGUI_GET_SCREEN_HEIGHT()       XMGUI_GET_CONFIG().screenHeight
#define XMGUI_GET_FONT_SIZE()           XMGUI_GET_CONFIG().fontSize
#define XMGUI_GET_FONT_NAME()           XMGUI_GET_CONFIG().fontName

// 设置配置值的便利宏
#define XMGUI_SET_SCREEN_SIZE(w, h)     do { \
    XMGUI_GET_CONFIG().screenWidth = (w); \
    XMGUI_GET_CONFIG().screenHeight = (h); \
} while(0)

#define XMGUI_SET_FONT(name, size)      do { \
    XMGUI_GET_CONFIG().fontName = (name); \
    XMGUI_GET_CONFIG().fontSize = (size); \
} while(0)

#endif // XMGUI_CONFIG_H 