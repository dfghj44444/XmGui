/**
 * @file MultiRendererExample.cpp
 * @brief 多渲染器示例程序 - 演示如何使用DX9、DX11和Vulkan渲染器
 * @author Double One
 * @version 1.0.0
 * @date 2025-01-09
 * 
 * 这个示例程序演示了如何：
 * 1. 检测系统支持的渲染器
 * 2. 在不同的渲染器之间切换
 * 3. 使用统一的渲染接口绘制UI
 * 4. 显示渲染性能统计信息
 * 
 * 编译命令：
 * cl /EHsc /I"../include" MultiRendererExample.cpp ../src/XmGuiRenderer.cpp ../src/DX9Renderer.cpp ../src/DX11Renderer.cpp ../src/VulkanRenderer.cpp user32.lib gdi32.lib d3d9.lib d3d11.lib dxgi.lib vulkan-1.lib
 */

#include <XmGui.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>

// 窗口相关
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE L"XmGui多渲染器演示"

// 控件ID
#define ID_BUTTON_DX9       1001
#define ID_BUTTON_DX11      1002
#define ID_BUTTON_VULKAN    1003
#define ID_BUTTON_AUTO      1004
#define ID_BUTTON_INFO      1005
#define ID_BUTTON_EXIT      1006

// 全局变量
HWND g_hWnd = nullptr;
bool g_bRunning = true;
std::unique_ptr<XM::IRenderer> g_pRenderer = nullptr;
XM::RendererType g_currentRendererType = XM::RendererType::Auto;

// 性能统计
struct PerformanceStats {
    float frameTime = 0.0f;
    float fps = 0.0f;
    uint32_t drawCalls = 0;
    uint32_t vertexCount = 0;
    uint32_t triangleCount = 0;
    
    void Reset() {
        frameTime = 0.0f;
        fps = 0.0f;
        drawCalls = 0;
        vertexCount = 0;
        triangleCount = 0;
    }
    
    void Update(const XM::RenderStats& stats) {
        frameTime = stats.frameTime;
        fps = stats.fps;
        drawCalls = stats.drawCalls;
        vertexCount = stats.vertexCount;
        triangleCount = stats.triangleCount;
    }
};

PerformanceStats g_perfStats;

// 前向声明
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
bool InitializeWindow();
void ShutdownWindow();
bool SwitchRenderer(XM::RendererType type);
void UpdateUI();
void RenderFrame();
void RenderUI();
void RenderPerformanceInfo();
void ShowRendererInfo();
std::wstring Utf8ToWide(const std::string& utf8);

//=============================================================================
// 主函数
//=============================================================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 设置控制台输出（用于调试）
    AllocConsole();
    FILE* pCout;
    freopen_s(&pCout, "CONOUT$", "w", stdout);
    
    std::wcout << L"=== XmGui多渲染器演示程序 ===" << std::endl;
    std::wcout << L"版本: " << XMGUI_VERSION_STRING << std::endl;
    std::wcout << L"作者: Double One" << std::endl;
    std::wcout << L"日期: 2025-01-09" << std::endl;
    std::wcout << L"===============================" << std::endl;
    
    try {
        // 初始化窗口
        if (!InitializeWindow()) {
            std::wcerr << L"错误: 无法初始化窗口" << std::endl;
            return -1;
        }
        
        // 检测支持的渲染器
        auto supportedRenderers = XM::GetSupportedRenderers();
        std::wcout << L"\n支持的渲染器:" << std::endl;
        for (auto type : supportedRenderers) {
            std::wcout << L"  - " << Utf8ToWide(XM::RendererTypeToString(type)) << std::endl;
        }
        
        if (supportedRenderers.empty()) {
            std::wcerr << L"错误: 没有找到支持的渲染器" << std::endl;
            ShutdownWindow();
            return -1;
        }
        
        // 创建默认渲染器
        XM::RendererType defaultType = XM::GetDefaultRendererType();
        std::wcout << L"\n默认渲染器: " << Utf8ToWide(XM::RendererTypeToString(defaultType)) << std::endl;
        
        if (!SwitchRenderer(defaultType)) {
            std::wcerr << L"错误: 无法初始化默认渲染器" << std::endl;
            ShutdownWindow();
            return -1;
        }
        
        // 主消息循环
        MSG msg = {};
        auto lastTime = std::chrono::high_resolution_clock::now();
        
        std::wcout << L"\n开始渲染循环..." << std::endl;
        std::wcout << L"使用以下按键切换渲染器:" << std::endl;
        std::wcout << L"  1 - DirectX 9" << std::endl;
        std::wcout << L"  2 - DirectX 11" << std::endl;
        std::wcout << L"  3 - Vulkan" << std::endl;
        std::wcout << L"  A - 自动选择" << std::endl;
        std::wcout << L"  I - 显示渲染器信息" << std::endl;
        std::wcout << L"  ESC - 退出程序" << std::endl;
        
        while (g_bRunning) {
            // 处理消息
            while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
                
                if (msg.message == WM_QUIT) {
                    g_bRunning = false;
                }
            }
            
            // 计算帧时间
            auto currentTime = std::chrono::high_resolution_clock::now();
            auto deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();
            lastTime = currentTime;
            
            // 更新UI
            UpdateUI();
            
            // 渲染帧
            RenderFrame();
            
            // 限制帧率（可选）
            Sleep(1);
        }
        
        std::wcout << L"程序正常退出" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "异常: " << e.what() << std::endl;
    }
    
    // 清理资源
    g_pRenderer.reset();
    ShutdownWindow();
    
    // 关闭控制台
    if (pCout) {
        fclose(pCout);
    }
    FreeConsole();
    
    return 0;
}

//=============================================================================
// 窗口过程函数
//=============================================================================
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_KEYDOWN:
        {
            switch (wParam) {
            case '1':
                if (XM::IsRendererSupported(XM::RendererType::DX9)) {
                    SwitchRenderer(XM::RendererType::DX9);
                }
                break;
            case '2':
                if (XM::IsRendererSupported(XM::RendererType::DX11)) {
                    SwitchRenderer(XM::RendererType::DX11);
                }
                break;
            case '3':
                if (XM::IsRendererSupported(XM::RendererType::Vulkan)) {
                    SwitchRenderer(XM::RendererType::Vulkan);
                }
                break;
            case 'A':
            case 'a':
                SwitchRenderer(XM::RendererType::Auto);
                break;
            case 'I':
            case 'i':
                ShowRendererInfo();
                break;
            case VK_ESCAPE:
                g_bRunning = false;
                break;
            }
        }
        break;
        
    case WM_SIZE:
        {
            if (g_pRenderer && g_pRenderer->IsInitialized()) {
                RECT rect;
                GetClientRect(hWnd, &rect);
                int width = rect.right - rect.left;
                int height = rect.bottom - rect.top;
                g_pRenderer->OnResize(width, height);
            }
        }
        break;
        
    case WM_CLOSE:
        g_bRunning = false;
        break;
        
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
        
    default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    
    return 0;
}

//=============================================================================
// 窗口管理函数
//=============================================================================
bool InitializeWindow() {
    // 注册窗口类
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = L"XmGuiMultiRenderer";
    wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
    
    if (!RegisterClassEx(&wc)) {
        return false;
    }
    
    // 创建窗口
    g_hWnd = CreateWindowEx(
        WS_EX_APPWINDOW,
        L"XmGuiMultiRenderer",
        WINDOW_TITLE,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        nullptr, nullptr,
        GetModuleHandle(nullptr),
        nullptr
    );
    
    if (!g_hWnd) {
        return false;
    }
    
    ShowWindow(g_hWnd, SW_SHOW);
    UpdateWindow(g_hWnd);
    
    return true;
}

void ShutdownWindow() {
    if (g_hWnd) {
        DestroyWindow(g_hWnd);
        g_hWnd = nullptr;
    }
    
    UnregisterClass(L"XmGuiMultiRenderer", GetModuleHandle(nullptr));
}

//=============================================================================
// 渲染器管理函数
//=============================================================================
bool SwitchRenderer(XM::RendererType type) {
    std::wcout << L"切换到渲染器: " << Utf8ToWide(XM::RendererTypeToString(type)) << std::endl;
    
    // 关闭当前渲染器
    if (g_pRenderer) {
        g_pRenderer->Shutdown();
        g_pRenderer.reset();
    }
    
    // 获取客户区尺寸
    RECT rect;
    GetClientRect(g_hWnd, &rect);
    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;
    
    // 创建新渲染器
    try {
        g_pRenderer = XM::CreateRenderer(type, g_hWnd, width, height, false);
        if (!g_pRenderer) {
            std::wcerr << L"错误: 无法创建渲染器" << std::endl;
            return false;
        }
        
        g_currentRendererType = g_pRenderer->GetType();
        
        // 显示渲染器信息
        auto caps = g_pRenderer->GetCapabilities();
        std::wcout << L"渲染器创建成功:" << std::endl;
        std::wcout << L"  名称: " << Utf8ToWide(g_pRenderer->GetName()) << std::endl;
        std::wcout << L"  版本: " << Utf8ToWide(caps.version) << std::endl;
        std::wcout << L"  设备: " << Utf8ToWide(caps.deviceName) << std::endl;
        std::wcout << L"  最大纹理尺寸: " << caps.maxTextureSize << std::endl;
        std::wcout << L"  支持多重采样: " << (caps.supportsMultisampling ? L"是" : L"否") << std::endl;
        std::wcout << L"  支持HDR: " << (caps.supportsHDR ? L"是" : L"否") << std::endl;
        
        return true;
        
    } catch (const std::exception& e) {
        std::cerr << "创建渲染器失败: " << e.what() << std::endl;
        return false;
    }
}

//=============================================================================
// 更新和渲染函数
//=============================================================================
void UpdateUI() {
    if (!g_pRenderer || !g_pRenderer->IsInitialized()) {
        return;
    }
    
    // 更新性能统计
    auto stats = g_pRenderer->GetStats();
    g_perfStats.Update(stats);
}

void RenderFrame() {
    if (!g_pRenderer || !g_pRenderer->IsInitialized()) {
        return;
    }
    
    // 开始渲染
    g_pRenderer->BeginFrame();
    
    // 清屏
    XM::Color clearColor(0.2f, 0.3f, 0.4f, 1.0f);
    g_pRenderer->Clear(clearColor);
    
    // 渲染UI
    RenderUI();
    
    // 渲染性能信息
    RenderPerformanceInfo();
    
    // 结束渲染
    g_pRenderer->EndFrame();
    g_pRenderer->Present();
}

void RenderUI() {
    if (!g_pRenderer) return;
    
    // 渲染标题
    std::wstring title = L"XmGui多渲染器演示";
    g_pRenderer->DrawText(title, 20, 20, XM::Color::White);
    
    // 渲染当前渲染器信息
    std::wstring currentRenderer = L"当前渲染器: " + Utf8ToWide(g_pRenderer->GetName());
    g_pRenderer->DrawText(currentRenderer, 20, 50, XM::Color::Yellow);
    
    // 渲染操作提示
    std::wstring instructions = L"按键: 1-DX9, 2-DX11, 3-Vulkan, A-自动, I-信息, ESC-退出";
    g_pRenderer->DrawText(instructions, 20, 80, XM::Color::Cyan);
    
    // 渲染一些基本图形来展示渲染器功能
    float time = GetTickCount() / 1000.0f;
    
    // 绘制彩色矩形
    XM::Rectangle rect1(100, 150, 100, 50);
    XM::Color color1(0.8f, 0.2f, 0.2f, 0.8f);
    g_pRenderer->DrawRectangle(rect1, color1);
    
    XM::Rectangle rect2(220, 150, 100, 50);
    XM::Color color2(0.2f, 0.8f, 0.2f, 0.8f);
    g_pRenderer->DrawRectangle(rect2, color2);
    
    XM::Rectangle rect3(340, 150, 100, 50);
    XM::Color color3(0.2f, 0.2f, 0.8f, 0.8f);
    g_pRenderer->DrawRectangle(rect3, color3);
    
    // 绘制动态线条
    float centerX = 400;
    float centerY = 300;
    float radius = 80;
    
    for (int i = 0; i < 12; i++) {
        float angle = (i * 30.0f + time * 50.0f) * 3.14159f / 180.0f;
        float x1 = centerX + cosf(angle) * radius * 0.5f;
        float y1 = centerY + sinf(angle) * radius * 0.5f;
        float x2 = centerX + cosf(angle) * radius;
        float y2 = centerY + sinf(angle) * radius;
        
        XM::Color lineColor;
        lineColor.r = 0.5f + 0.5f * sinf(time + i * 0.5f);
        lineColor.g = 0.5f + 0.5f * cosf(time + i * 0.3f);
        lineColor.b = 0.5f + 0.5f * sinf(time + i * 0.7f);
        lineColor.a = 1.0f;
        
        g_pRenderer->DrawLine(x1, y1, x2, y2, lineColor, 2.0f);
    }
}

void RenderPerformanceInfo() {
    if (!g_pRenderer) return;
    
    // 性能信息背景
    XM::Rectangle bgRect(20, WINDOW_HEIGHT - 150, 300, 120);
    XM::Color bgColor(0.0f, 0.0f, 0.0f, 0.7f);
    g_pRenderer->DrawRectangle(bgRect, bgColor);
    
    // 性能统计文本
    std::wstringstream ss;
    ss << std::fixed << std::setprecision(2);
    ss << L"性能统计:" << std::endl;
    ss << L"FPS: " << g_perfStats.fps << std::endl;
    ss << L"帧时间: " << g_perfStats.frameTime * 1000.0f << L"ms" << std::endl;
    ss << L"绘制调用: " << g_perfStats.drawCalls << std::endl;
    ss << L"顶点数: " << g_perfStats.vertexCount << std::endl;
    ss << L"三角形数: " << g_perfStats.triangleCount << std::endl;
    
    // 由于DrawText函数可能没有完全实现，这里用简化的方式显示
    g_pRenderer->DrawText(L"性能统计", 30, WINDOW_HEIGHT - 140, XM::Color::White);
    
    std::wstring fpsText = L"FPS: " + std::to_wstring((int)g_perfStats.fps);
    g_pRenderer->DrawText(fpsText, 30, WINDOW_HEIGHT - 120, XM::Color::Green);
    
    std::wstring frameTimeText = L"帧时间: " + std::to_wstring((int)(g_perfStats.frameTime * 1000)) + L"ms";
    g_pRenderer->DrawText(frameTimeText, 30, WINDOW_HEIGHT - 100, XM::Color::Yellow);
    
    std::wstring drawCallsText = L"绘制调用: " + std::to_wstring(g_perfStats.drawCalls);
    g_pRenderer->DrawText(drawCallsText, 30, WINDOW_HEIGHT - 80, XM::Color::Cyan);
}

//=============================================================================
// 工具函数
//=============================================================================
void ShowRendererInfo() {
    if (!g_pRenderer) {
        std::wcout << L"没有活动的渲染器" << std::endl;
        return;
    }
    
    auto caps = g_pRenderer->GetCapabilities();
    auto stats = g_pRenderer->GetStats();
    
    std::wcout << L"\n=== 渲染器详细信息 ===" << std::endl;
    std::wcout << L"名称: " << Utf8ToWide(g_pRenderer->GetName()) << std::endl;
    std::wcout << L"类型: " << Utf8ToWide(XM::RendererTypeToString(g_pRenderer->GetType())) << std::endl;
    std::wcout << L"版本: " << Utf8ToWide(caps.version) << std::endl;
    std::wcout << L"设备: " << Utf8ToWide(caps.deviceName) << std::endl;
    std::wcout << L"最大纹理尺寸: " << caps.maxTextureSize << std::endl;
    std::wcout << L"最大渲染目标: " << caps.maxRenderTargets << std::endl;
    std::wcout << L"最大顶点属性: " << caps.maxVertexAttributes << std::endl;
    std::wcout << L"多重采样支持: " << (caps.supportsMultisampling ? L"是" : L"否") << std::endl;
    std::wcout << L"HDR支持: " << (caps.supportsHDR ? L"是" : L"否") << std::endl;
    std::wcout << L"计算着色器支持: " << (caps.supportsComputeShaders ? L"是" : L"否") << std::endl;
    std::wcout << L"几何着色器支持: " << (caps.supportsGeometryShaders ? L"是" : L"否") << std::endl;
    std::wcout << L"实例化支持: " << (caps.supportsInstancing ? L"是" : L"否") << std::endl;
    std::wcout << L"=====================" << std::endl;
}

std::wstring Utf8ToWide(const std::string& utf8) {
    if (utf8.empty()) return L"";
    
    int size = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, nullptr, 0);
    if (size == 0) return L"";
    
    std::wstring wide(size - 1, 0);
    MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, &wide[0], size);
    
    return wide;
} 