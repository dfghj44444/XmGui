/**
 * @file BasicExample.cpp
 * @brief XmGui基础使用示例
 * @author Double One
 * @date 2025-01-09
 * 
 * 这个示例展示了如何：
 * 1. 初始化XmGui系统
 * 2. 创建一个简单的窗口
 * 3. 添加按钮控件
 * 4. 处理用户事件
 * 5. 渲染UI
 */

#include "../include/XmGui.h"
#include <iostream>

// 全局变量
HWND                g_hWnd = nullptr;
IDirect3D9*         g_pD3D = nullptr;
IDirect3DDevice9*   g_pD3DDevice = nullptr;
XM::UI_Manager*     g_pUIManager = nullptr;
XM::xmEngine*       g_pEngine = nullptr;

// 应用程序状态
bool g_bApplicationRunning = true;

// 窗口消息处理
LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// DirectX初始化
bool InitializeDirectX(HWND hWnd);
void CleanupDirectX();

// UI事件回调
void CALLBACK OnUIEvent(UINT nEvent, int nControlID, XM::UI_Object* pControl, void* pUserContext);

// 创建UI界面
bool CreateUI();

// 主函数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 注册窗口类
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = L"XmGuiExample";
    wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

    if (!RegisterClassEx(&wc))
    {
        MessageBox(nullptr, L"窗口类注册失败!", L"错误", MB_ICONERROR);
        return -1;
    }

    // 创建窗口
    g_hWnd = CreateWindowEx(
        0,
        L"XmGuiExample",
        L"XmGui 基础示例",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );

    if (!g_hWnd)
    {
        MessageBox(nullptr, L"窗口创建失败!", L"错误", MB_ICONERROR);
        return -1;
    }

    // 初始化DirectX
    if (!InitializeDirectX(g_hWnd))
    {
        MessageBox(nullptr, L"DirectX初始化失败!", L"错误", MB_ICONERROR);
        CleanupDirectX();
        return -1;
    }

    // 初始化XmGui
    if (!XM::InitializeXmGui(g_pD3DDevice, g_hWnd))
    {
        MessageBox(nullptr, L"XmGui初始化失败!", L"错误", MB_ICONERROR);
        CleanupDirectX();
        return -1;
    }

    // 创建UI界面
    if (!CreateUI())
    {
        MessageBox(nullptr, L"UI创建失败!", L"错误", MB_ICONERROR);
        XM::ShutdownXmGui();
        CleanupDirectX();
        return -1;
    }

    // 显示窗口
    ShowWindow(g_hWnd, nCmdShow);
    UpdateWindow(g_hWnd);

    // 主消息循环
    MSG msg = {};
    while (g_bApplicationRunning)
    {
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // 检查设备状态
        if (!XM::IsDeviceValid(g_pD3DDevice))
        {
            // 设备丢失，尝试重置
            if (g_pEngine)
            {
                g_pEngine->onLostDevice();
                HRESULT hr = g_pD3DDevice->Reset(&g_d3dpp);
                if (SUCCEEDED(hr))
                {
                    g_pEngine->onResetDevice(g_pD3DDevice);
                }
            }
            continue;
        }

        // 清除后台缓冲区
        g_pD3DDevice->Clear(0, nullptr, D3DCLEAR_TARGET, 
                           XM::MakeColor(64, 128, 255), 1.0f, 0);

        // 开始渲染
        if (SUCCEEDED(g_pD3DDevice->BeginScene()))
        {
            // 更新UI
            if (g_pUIManager)
            {
                g_pUIManager->frameMove(GetTickCount());
                g_pUIManager->render(g_pD3DDevice);
            }

            // 结束渲染
            g_pD3DDevice->EndScene();
        }

        // 显示渲染结果
        g_pD3DDevice->Present(nullptr, nullptr, nullptr, nullptr);

        // 限制帧率
        Sleep(16); // 约60FPS
    }

    // 清理资源
    XM_SAFE_DELETE(g_pUIManager);
    XM::ShutdownXmGui();
    CleanupDirectX();

    return 0;
}

// 窗口消息处理
LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    // 首先让XmGui处理消息
    bool bHandled = false;
    if (g_pEngine)
    {
        g_pEngine->handleMessage(hWnd, msg, wParam, lParam, &bHandled);
    }

    if (bHandled)
        return 0;

    switch (msg)
    {
    case WM_DESTROY:
        g_bApplicationRunning = false;
        PostQuitMessage(0);
        break;

    case WM_KEYDOWN:
        if (wParam == VK_ESCAPE)
        {
            g_bApplicationRunning = false;
            PostMessage(hWnd, WM_CLOSE, 0, 0);
        }
        break;

    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }

    return 0;
}

// DirectX初始化
bool InitializeDirectX(HWND hWnd)
{
    // 创建Direct3D对象
    g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
    if (!g_pD3D)
        return false;

    // 获取适配器信息
    D3DADAPTER_IDENTIFIER9 adapterID;
    g_pD3D->GetAdapterIdentifier(D3DADAPTER_DEFAULT, 0, &adapterID);

    // 设置D3D设备参数
    D3DPRESENT_PARAMETERS d3dpp = {};
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

    // 创建D3D设备
    HRESULT hr = g_pD3D->CreateDevice(
        D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp,
        &g_pD3DDevice
    );

    if (FAILED(hr))
    {
        // 尝试使用参考设备
        hr = g_pD3D->CreateDevice(
            D3DADAPTER_DEFAULT,
            D3DDEVTYPE_REF,
            hWnd,
            D3DCREATE_SOFTWARE_VERTEXPROCESSING,
            &d3dpp,
            &g_pD3DDevice
        );
    }

    return SUCCEEDED(hr);
}

// 清理DirectX
void CleanupDirectX()
{
    XM_SAFE_RELEASE(g_pD3DDevice);
    XM_SAFE_RELEASE(g_pD3D);
}

// UI事件回调
void CALLBACK OnUIEvent(UINT nEvent, int nControlID, XM::UI_Object* pControl, void* pUserContext)
{
    switch (nEvent)
    {
    case XM::SET_BUTTON_CLICKED:
        {
            switch (nControlID)
            {
            case 100: // 确定按钮
                MessageBox(g_hWnd, L"你点击了确定按钮!", L"消息", MB_OK | MB_ICONINFORMATION);
                break;

            case 101: // 取消按钮
                MessageBox(g_hWnd, L"你点击了取消按钮!", L"消息", MB_OK | MB_ICONINFORMATION);
                break;

            case 102: // 退出按钮
                if (MessageBox(g_hWnd, L"确定要退出吗?", L"确认", MB_YESNO | MB_ICONQUESTION) == IDYES)
                {
                    g_bApplicationRunning = false;
                    PostMessage(g_hWnd, WM_CLOSE, 0, 0);
                }
                break;
            }
        }
        break;

    default:
        break;
    }
}

// 创建UI界面
bool CreateUI()
{
    // 获取引擎实例
    g_pEngine = XM_ENGINE_INSTANCE;
    if (!g_pEngine)
        return false;

    // 创建UI管理器
    g_pUIManager = new XM::UI_Manager();
    if (!g_pUIManager)
        return false;

    // 设置UI管理器的位置和大小
    g_pUIManager->setPosition(0, 0, 0);
    
    // 设置事件回调
    g_pUIManager->setEventCallback(OnUIEvent, nullptr);

    // 添加UI管理器到引擎
    g_pEngine->addStatusUIManager(g_pUIManager);

    // 创建标题标签
    // 注意：这里需要根据实际的UI库API来调整
    
    // 创建按钮
    XM::UI_Button* pOkButton = new XM::UI_Button();
    if (pOkButton)
    {
        pOkButton->setID(100);
        pOkButton->setPosition(100, 100, 0);
        // 设置按钮文本（需要根据实际API调整）
        // pOkButton->setText(L"确定");
        g_pUIManager->addChild(pOkButton);
    }

    XM::UI_Button* pCancelButton = new XM::UI_Button();
    if (pCancelButton)
    {
        pCancelButton->setID(101);
        pCancelButton->setPosition(220, 100, 0);
        // pCancelButton->setText(L"取消");
        g_pUIManager->addChild(pCancelButton);
    }

    XM::UI_Button* pExitButton = new XM::UI_Button();
    if (pExitButton)
    {
        pExitButton->setID(102);
        pExitButton->setPosition(340, 100, 0);
        // pExitButton->setText(L"退出");
        g_pUIManager->addChild(pExitButton);
    }

    return true;
}

// 帮助函数：输出调试信息
void OutputDebugInfo()
{
    std::wcout << L"XmGui版本: " << XM::GetVersionString() << std::endl;
    std::wcout << L"DirectX设备状态: " << (XM::IsDeviceValid(g_pD3DDevice) ? L"正常" : L"异常") << std::endl;
    
    // 输出内存使用情况
    XM_DEBUG_MEMORY_LEAK_CHECK();
} 