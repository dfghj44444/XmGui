/**
 * @file XmGuiRenderer.cpp
 * @brief XmGui渲染抽象层实现
 * @author Double One
 * @version 1.0.0
 * @date 2025-01-09
 */

#include "../include/XmGuiRenderer.h"
#include <stdexcept>
#include <algorithm>

namespace XM {

//=============================================================================
// 颜色预定义实现
//=============================================================================
const Color Color::Black(0.0f, 0.0f, 0.0f, 1.0f);
const Color Color::White(1.0f, 1.0f, 1.0f, 1.0f);
const Color Color::Red(1.0f, 0.0f, 0.0f, 1.0f);
const Color Color::Green(0.0f, 1.0f, 0.0f, 1.0f);
const Color Color::Blue(0.0f, 0.0f, 1.0f, 1.0f);
const Color Color::Yellow(1.0f, 1.0f, 0.0f, 1.0f);
const Color Color::Cyan(0.0f, 1.0f, 1.0f, 1.0f);
const Color Color::Magenta(1.0f, 0.0f, 1.0f, 1.0f);
const Color Color::Transparent(0.0f, 0.0f, 0.0f, 0.0f);

Color Color::FromARGB(uint32_t argb) {
    float a = ((argb >> 24) & 0xFF) / 255.0f;
    float r = ((argb >> 16) & 0xFF) / 255.0f;
    float g = ((argb >> 8) & 0xFF) / 255.0f;
    float b = (argb & 0xFF) / 255.0f;
    return Color(r, g, b, a);
}

uint32_t Color::ToARGB() const {
    uint32_t a = static_cast<uint32_t>(std::clamp(this->a, 0.0f, 1.0f) * 255);
    uint32_t r = static_cast<uint32_t>(std::clamp(this->r, 0.0f, 1.0f) * 255);
    uint32_t g = static_cast<uint32_t>(std::clamp(this->g, 0.0f, 1.0f) * 255);
    uint32_t b = static_cast<uint32_t>(std::clamp(this->b, 0.0f, 1.0f) * 255);
    return (a << 24) | (r << 16) | (g << 8) | b;
}

//=============================================================================
// 前向声明具体渲染器类
//=============================================================================
class DX9Renderer;
class DX11Renderer;
class VulkanRenderer;

// 创建函数声明
std::unique_ptr<IRenderer> CreateDX9Renderer();
std::unique_ptr<IRenderer> CreateDX11Renderer();
std::unique_ptr<IRenderer> CreateVulkanRenderer();

//=============================================================================
// 渲染器工厂实现
//=============================================================================
std::unique_ptr<IRenderer> RendererFactory::CreateRenderer(RendererType type) {
    switch (type) {
    case RendererType::DX9:
        return CreateDX9Renderer();
    
    case RendererType::DX11:
        return CreateDX11Renderer();
    
    case RendererType::Vulkan:
        return CreateVulkanRenderer();
    
    case RendererType::Auto:
        return CreateBestRenderer();
    
    default:
        throw std::invalid_argument("Unsupported renderer type");
    }
}

std::unique_ptr<IRenderer> RendererFactory::CreateBestRenderer() {
    // 优先级顺序：DX11 > DX9 > Vulkan
    auto supportedRenderers = GetSupportedRenderers();
    
    // 检查DX11支持
    if (std::find(supportedRenderers.begin(), supportedRenderers.end(), RendererType::DX11) != supportedRenderers.end()) {
        return CreateDX11Renderer();
    }
    
    // 检查DX9支持
    if (std::find(supportedRenderers.begin(), supportedRenderers.end(), RendererType::DX9) != supportedRenderers.end()) {
        return CreateDX9Renderer();
    }
    
    // 检查Vulkan支持
    if (std::find(supportedRenderers.begin(), supportedRenderers.end(), RendererType::Vulkan) != supportedRenderers.end()) {
        return CreateVulkanRenderer();
    }
    
    throw std::runtime_error("No supported renderer found");
}

std::vector<RendererType> RendererFactory::GetSupportedRenderers() {
    std::vector<RendererType> supported;
    
    // 检查各个渲染器的支持情况
    if (IsRendererSupported(RendererType::DX9)) {
        supported.push_back(RendererType::DX9);
    }
    
    if (IsRendererSupported(RendererType::DX11)) {
        supported.push_back(RendererType::DX11);
    }
    
    if (IsRendererSupported(RendererType::Vulkan)) {
        supported.push_back(RendererType::Vulkan);
    }
    
    return supported;
}

bool RendererFactory::IsRendererSupported(RendererType type) {
    switch (type) {
    case RendererType::DX9:
        {
            // 检查DX9支持
            #ifdef _WIN32
            // 检查d3d9.dll是否可用
            HMODULE d3d9Module = LoadLibraryA("d3d9.dll");
            if (d3d9Module) {
                FreeLibrary(d3d9Module);
                return true;
            }
            #endif
            return false;
        }
    
    case RendererType::DX11:
        {
            // 检查DX11支持
            #ifdef _WIN32
            // 检查d3d11.dll是否可用
            HMODULE d3d11Module = LoadLibraryA("d3d11.dll");
            if (d3d11Module) {
                FreeLibrary(d3d11Module);
                return true;
            }
            #endif
            return false;
        }
    
    case RendererType::Vulkan:
        {
            // 检查Vulkan支持
            #ifdef _WIN32
            // 检查vulkan-1.dll是否可用
            HMODULE vulkanModule = LoadLibraryA("vulkan-1.dll");
            if (vulkanModule) {
                FreeLibrary(vulkanModule);
                return true;
            }
            #endif
            return false;
        }
    
    default:
        return false;
    }
}

RendererType RendererFactory::GetDefaultRendererType() {
    // 根据配置或系统能力返回默认渲染器类型
    auto supportedRenderers = GetSupportedRenderers();
    
    if (!supportedRenderers.empty()) {
        // 返回第一个支持的渲染器（按CreateBestRenderer的优先级）
        if (std::find(supportedRenderers.begin(), supportedRenderers.end(), RendererType::DX11) != supportedRenderers.end()) {
            return RendererType::DX11;
        }
        if (std::find(supportedRenderers.begin(), supportedRenderers.end(), RendererType::DX9) != supportedRenderers.end()) {
            return RendererType::DX9;
        }
        if (std::find(supportedRenderers.begin(), supportedRenderers.end(), RendererType::Vulkan) != supportedRenderers.end()) {
            return RendererType::Vulkan;
        }
    }
    
    return RendererType::DX9; // 默认回退到DX9
}

std::string RendererFactory::RendererTypeToString(RendererType type) {
    switch (type) {
    case RendererType::Auto:    return "Auto";
    case RendererType::DX9:     return "DirectX 9";
    case RendererType::DX11:    return "DirectX 11";
    case RendererType::DX12:    return "DirectX 12";
    case RendererType::Vulkan:  return "Vulkan";
    case RendererType::OpenGL:  return "OpenGL";
    case RendererType::Metal:   return "Metal";
    default:                    return "Unknown";
    }
}

RendererType RendererFactory::StringToRendererType(const std::string& str) {
    if (str == "Auto") return RendererType::Auto;
    if (str == "DirectX 9" || str == "DX9") return RendererType::DX9;
    if (str == "DirectX 11" || str == "DX11") return RendererType::DX11;
    if (str == "DirectX 12" || str == "DX12") return RendererType::DX12;
    if (str == "Vulkan") return RendererType::Vulkan;
    if (str == "OpenGL") return RendererType::OpenGL;
    if (str == "Metal") return RendererType::Metal;
    
    throw std::invalid_argument("Unknown renderer type: " + str);
}

} // namespace XM 