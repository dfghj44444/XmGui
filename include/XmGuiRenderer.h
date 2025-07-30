/**
 * @file XmGuiRenderer.h
 * @brief XmGui渲染抽象层 - 支持多图形API的统一渲染接口
 * @author Double One
 * @version 1.0.0
 * @date 2025-01-09
 * 
 * 这个文件定义了XmGui的渲染抽象层，支持DirectX 9/11和Vulkan等多种图形API。
 * 通过抽象接口，可以在不同的图形后端之间无缝切换。
 * 
 * 支持的渲染后端：
 * - DirectX 9 (Windows)
 * - DirectX 11 (Windows)
 * - Vulkan (Windows/Linux/macOS)
 * 
 * 使用示例：
 * @code
 * // 创建渲染器
 * auto renderer = XM::CreateRenderer(XM::RendererType::DX11, hWnd);
 * 
 * // 初始化
 * renderer->Initialize();
 * 
 * // 渲染循环
 * renderer->BeginFrame();
 * renderer->Clear(XM::Color::Blue);
 * // ... 渲染UI元素
 * renderer->EndFrame();
 * renderer->Present();
 * @endcode
 */

#ifndef XMGUI_RENDERER_H
#define XMGUI_RENDERER_H

#include "XmGuiConfig.h"
#include <memory>
#include <string>
#include <vector>
#include <functional>

// 前向声明
struct HWND__;
typedef HWND__* HWND;

namespace XM {

//=============================================================================
// 渲染器类型枚举
//=============================================================================
enum class RendererType {
    Auto,       // 自动选择最佳渲染器
    DX9,        // DirectX 9
    DX11,       // DirectX 11
    DX12,       // DirectX 12 (保留)
    Vulkan,     // Vulkan
    OpenGL,     // OpenGL (保留)
    Metal       // Metal (保留)
};

//=============================================================================
// 渲染特性支持
//=============================================================================
struct RendererCapabilities {
    bool supportsMultisampling;
    bool supportsHDR;
    bool supportsComputeShaders;
    bool supportsGeometryShaders;
    bool supportsInstancing;
    int maxTextureSize;
    int maxRenderTargets;
    int maxVertexAttributes;
    std::string version;
    std::string deviceName;
};

//=============================================================================
// 颜色结构
//=============================================================================
struct Color {
    float r, g, b, a;
    
    Color() : r(0), g(0), b(0), a(1) {}
    Color(float r, float g, float b, float a = 1.0f) : r(r), g(g), b(b), a(a) {}
    
    // 预定义颜色
    static const Color Black;
    static const Color White;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
    static const Color Yellow;
    static const Color Cyan;
    static const Color Magenta;
    static const Color Transparent;
    
    // 从ARGB创建
    static Color FromARGB(uint32_t argb);
    // 转换为ARGB
    uint32_t ToARGB() const;
};

//=============================================================================
// 顶点结构
//=============================================================================
struct Vertex {
    float x, y, z;          // 位置
    float u, v;             // 纹理坐标
    uint32_t color;         // 颜色 (ARGB)
    
    Vertex() : x(0), y(0), z(0), u(0), v(0), color(0xFFFFFFFF) {}
    Vertex(float x, float y, float z = 0, float u = 0, float v = 0, uint32_t color = 0xFFFFFFFF)
        : x(x), y(y), z(z), u(u), v(v), color(color) {}
};

//=============================================================================
// 矩形结构
//=============================================================================
struct Rectangle {
    float x, y, width, height;
    
    Rectangle() : x(0), y(0), width(0), height(0) {}
    Rectangle(float x, float y, float w, float h) : x(x), y(y), width(w), height(h) {}
    
    float Left() const { return x; }
    float Right() const { return x + width; }
    float Top() const { return y; }
    float Bottom() const { return y + height; }
};

//=============================================================================
// 视口结构
//=============================================================================
struct Viewport {
    int x, y, width, height;
    float minDepth, maxDepth;
    
    Viewport() : x(0), y(0), width(0), height(0), minDepth(0.0f), maxDepth(1.0f) {}
    Viewport(int x, int y, int w, int h, float minZ = 0.0f, float maxZ = 1.0f)
        : x(x), y(y), width(w), height(h), minDepth(minZ), maxDepth(maxZ) {}
};

//=============================================================================
// 纹理接口
//=============================================================================
class ITexture {
public:
    virtual ~ITexture() = default;
    
    // 基本属性
    virtual int GetWidth() const = 0;
    virtual int GetHeight() const = 0;
    virtual bool IsValid() const = 0;
    
    // 纹理操作
    virtual bool LoadFromFile(const std::wstring& filename) = 0;
    virtual bool LoadFromMemory(const void* data, size_t size) = 0;
    virtual bool CreateEmpty(int width, int height) = 0;
    
    // 数据访问
    virtual bool UpdateData(const void* data, int width, int height) = 0;
    virtual void* Lock() = 0;
    virtual void Unlock() = 0;
    
    // 内部句柄（用于渲染器特定操作）
    virtual void* GetNativeHandle() const = 0;
};

//=============================================================================
// 着色器接口
//=============================================================================
class IShader {
public:
    virtual ~IShader() = default;
    
    // 着色器编译和加载
    virtual bool LoadFromFile(const std::wstring& filename) = 0;
    virtual bool LoadFromSource(const std::string& source) = 0;
    virtual bool IsValid() const = 0;
    
    // 参数设置
    virtual void SetFloat(const std::string& name, float value) = 0;
    virtual void SetVector2(const std::string& name, float x, float y) = 0;
    virtual void SetVector3(const std::string& name, float x, float y, float z) = 0;
    virtual void SetVector4(const std::string& name, float x, float y, float z, float w) = 0;
    virtual void SetMatrix(const std::string& name, const float* matrix) = 0;
    virtual void SetTexture(const std::string& name, ITexture* texture) = 0;
    
    // 内部句柄
    virtual void* GetNativeHandle() const = 0;
};

//=============================================================================
// 渲染状态
//=============================================================================
enum class BlendMode {
    None,           // 不混合
    Alpha,          // 标准alpha混合
    Additive,       // 加法混合
    Multiply,       // 乘法混合
    Premultiplied   // 预乘alpha
};

enum class FilterMode {
    Point,          // 点过滤
    Linear,         // 线性过滤
    Anisotropic     // 各向异性过滤
};

struct RenderState {
    BlendMode blendMode = BlendMode::Alpha;
    FilterMode filterMode = FilterMode::Linear;
    bool depthTest = false;
    bool depthWrite = false;
    bool cullBackFace = false;
    bool wireframe = false;
};

//=============================================================================
// 渲染统计信息
//=============================================================================
struct RenderStats {
    uint32_t frameCount = 0;
    uint32_t drawCalls = 0;
    uint32_t vertexCount = 0;
    uint32_t triangleCount = 0;
    float frameTime = 0.0f;
    float fps = 0.0f;
    
    void Reset() {
        drawCalls = 0;
        vertexCount = 0;
        triangleCount = 0;
    }
};

//=============================================================================
// 主要渲染器接口
//=============================================================================
class IRenderer {
public:
    virtual ~IRenderer() = default;
    
    //=========================================================================
    // 生命周期管理
    //=========================================================================
    virtual bool Initialize(HWND hWnd, int width, int height, bool fullscreen = false) = 0;
    virtual void Shutdown() = 0;
    virtual bool IsInitialized() const = 0;
    
    //=========================================================================
    // 设备管理
    //=========================================================================
    virtual bool OnDeviceLost() = 0;
    virtual bool OnDeviceReset() = 0;
    virtual void OnResize(int width, int height) = 0;
    
    //=========================================================================
    // 渲染控制
    //=========================================================================
    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;
    virtual void Present() = 0;
    virtual void Clear(const Color& color) = 0;
    virtual void SetViewport(const Viewport& viewport) = 0;
    virtual Viewport GetViewport() const = 0;
    
    //=========================================================================
    // 渲染状态
    //=========================================================================
    virtual void SetRenderState(const RenderState& state) = 0;
    virtual RenderState GetRenderState() const = 0;
    virtual void PushRenderState() = 0;
    virtual void PopRenderState() = 0;
    
    //=========================================================================
    // 绘制操作
    //=========================================================================
    virtual void DrawVertices(const Vertex* vertices, int count, ITexture* texture = nullptr) = 0;
    virtual void DrawIndexed(const Vertex* vertices, int vertexCount, 
                           const uint16_t* indices, int indexCount, ITexture* texture = nullptr) = 0;
    virtual void DrawRectangle(const Rectangle& rect, const Color& color) = 0;
    virtual void DrawRectangle(const Rectangle& rect, ITexture* texture, 
                             const Rectangle* sourceRect = nullptr) = 0;
    virtual void DrawLine(float x1, float y1, float x2, float y2, const XM::Color& color, float width = 1.0f) = 0;
    virtual void DrawTxt(const std::wstring& text, float x, float y, const XM::Color& color, ITexture* fontTexture = nullptr) = 0;
    
    //=========================================================================
    // 资源管理
    //=========================================================================
    virtual std::shared_ptr<ITexture> CreateTexture() = 0;
    virtual std::shared_ptr<ITexture> LoadTexture(const std::wstring& filename) = 0;
    virtual std::shared_ptr<IShader> CreateShader() = 0;
    virtual std::shared_ptr<IShader> LoadShader(const std::wstring& filename) = 0;
    
    //=========================================================================
    // 信息查询
    //=========================================================================
    virtual RendererType GetType() const = 0;
    virtual RendererCapabilities GetCapabilities() const = 0;
    virtual RenderStats GetStats() const = 0;
    virtual std::string GetName() const = 0;
    
    //=========================================================================
    // 高级功能
    //=========================================================================
    virtual void SetTransform(const float* matrix) = 0;
    virtual void PushTransform() = 0;
    virtual void PopTransform() = 0;
    virtual void SetScissorRect(const Rectangle& rect) = 0;
    virtual void DisableScissorRect() = 0;
    
    //=========================================================================
    // 调试功能
    //=========================================================================
    virtual void SetDebugName(const std::string& name) = 0;
    virtual void BeginDebugGroup(const std::string& name) = 0;
    virtual void EndDebugGroup() = 0;
    virtual void InsertDebugMarker(const std::string& name) = 0;
};

//=============================================================================
// 渲染器工厂
//=============================================================================
class RendererFactory {
public:
    // 创建渲染器
    static std::unique_ptr<IRenderer> CreateRenderer(RendererType type);
    
    // 自动选择最佳渲染器
    static std::unique_ptr<IRenderer> CreateBestRenderer();
    
    // 查询支持的渲染器
    static std::vector<RendererType> GetSupportedRenderers();
    
    // 检查渲染器是否支持
    static bool IsRendererSupported(RendererType type);
    
    // 获取默认渲染器类型
    static RendererType GetDefaultRendererType();
    
    // 渲染器类型转换
    static std::string RendererTypeToString(RendererType type);
    static RendererType StringToRendererType(const std::string& str);
};

//=============================================================================
// 便利函数
//=============================================================================

/**
 * @brief 创建渲染器的便利函数
 * @param type 渲染器类型
 * @param hWnd 窗口句柄
 * @param width 渲染宽度
 * @param height 渲染高度
 * @param fullscreen 是否全屏
 * @return 初始化好的渲染器，失败返回nullptr
 */
inline std::unique_ptr<IRenderer> CreateAndInitializeRenderer(
    RendererType type, HWND hWnd, int width, int height, bool fullscreen = false) {
    
    auto renderer = RendererFactory::CreateRenderer(type);
    if (renderer && renderer->Initialize(hWnd, width, height, fullscreen)) {
        return renderer;
    }
    return nullptr;
}

/**
 * @brief 自动创建最佳渲染器的便利函数
 * @param hWnd 窗口句柄
 * @param width 渲染宽度
 * @param height 渲染高度
 * @param fullscreen 是否全屏
 * @return 初始化好的渲染器，失败返回nullptr
 */
inline std::unique_ptr<IRenderer> CreateBestRenderer(
    HWND hWnd, int width, int height, bool fullscreen = false) {
    
    auto renderer = RendererFactory::CreateBestRenderer();
    if (renderer && renderer->Initialize(hWnd, width, height, fullscreen)) {
        return renderer;
    }
    return nullptr;
}

} // namespace XM

#endif // XMGUI_RENDERER_H 