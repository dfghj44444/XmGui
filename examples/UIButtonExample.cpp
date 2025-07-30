/**
 * @file UIButtonExample.cpp
 * @brief UIButton使用示例
 * @author Double One
 * @version 1.0.0
 * @date 2025-01-09
 */

#include "../include/XmGuiRenderer.h"
#include "../include/UIButton.h"
#include <iostream>
#include <memory>

using namespace XM;

int main() {
    // 创建窗口（这里需要实际的窗口创建代码）
    HWND hWnd = nullptr; // 实际使用时需要创建窗口
    
    // 创建渲染器
    auto renderer = CreateRenderer(RendererType::DX11, hWnd, 800, 600);
    if (!renderer) {
        std::cout << "无法创建渲染器" << std::endl;
        return -1;
    }
    
    // 初始化渲染器
    if (!renderer->Initialize(hWnd, 800, 600)) {
        std::cout << "渲染器初始化失败" << std::endl;
        return -1;
    }
    
    // 创建UI按钮
    auto button1 = CreateUIButton(renderer.get());
    button1->SetPosition(100, 100);
    button1->SetSize(200, 50);
    button1->SetText(L"点击我");
    button1->SetTextColor(Color::White);
    button1->SetNormalColor(Color(0.2f, 0.2f, 0.8f, 1.0f));
    button1->SetHoverColor(Color(0.3f, 0.3f, 0.9f, 1.0f));
    button1->SetPressedColor(Color(0.1f, 0.1f, 0.7f, 1.0f));
    
    // 设置点击事件
    button1->SetOnClick([]() {
        std::cout << "按钮被点击了！" << std::endl;
    });
    
    // 创建第二个按钮
    auto button2 = CreateUIButton(renderer.get());
    button2->SetPosition(100, 200);
    button2->SetSize(200, 50);
    button2->SetText(L"禁用按钮");
    button2->SetEnabled(false);
    
    // 主循环
    bool running = true;
    while (running) {
        // 处理输入事件
        // 这里需要实际的输入处理代码
        
        // 开始渲染
        renderer->BeginFrame();
        renderer->Clear(Color::DarkBlue);
        
        // 渲染UI按钮
        button1->Render();
        button2->Render();
        
        // 结束渲染
        renderer->EndFrame();
        renderer->Present();
        
        // 处理鼠标输入（示例）
        // 实际使用时需要从窗口消息中获取鼠标位置和状态
        int mouseX = 0, mouseY = 0;
        bool mouseDown = false;
        int mouseButton = 0;
        
        // 处理按钮的鼠标事件
        button1->HandleMouseMove(mouseX, mouseY);
        button1->HandleMouse(mouseX, mouseY, mouseButton, mouseDown);
        
        button2->HandleMouseMove(mouseX, mouseY);
        button2->HandleMouse(mouseX, mouseY, mouseButton, mouseDown);
    }
    
    // 清理
    renderer->Shutdown();
    
    return 0;
}

//=============================================================================
// 高级使用示例
//=============================================================================
class AdvancedUIExample {
private:
    std::unique_ptr<IRenderer> m_renderer;
    std::vector<std::unique_ptr<UIButton>> m_buttons;
    
public:
    AdvancedUIExample(HWND hWnd) {
        // 创建渲染器
        m_renderer = CreateRenderer(RendererType::Auto, hWnd, 1024, 768);
        if (m_renderer) {
            m_renderer->Initialize(hWnd, 1024, 768);
            CreateUI();
        }
    }
    
    void CreateUI() {
        // 创建多个按钮
        for (int i = 0; i < 5; ++i) {
            auto button = CreateUIButton(m_renderer.get());
            button->SetPosition(50 + i * 120, 50);
            button->SetSize(100, 40);
            button->SetText(L"按钮 " + std::to_wstring(i + 1));
            
            // 设置不同的颜色
            float hue = i * 0.2f;
            button->SetNormalColor(Color(hue, 0.5f, 0.5f, 1.0f));
            button->SetHoverColor(Color(hue, 0.7f, 0.7f, 1.0f));
            button->SetPressedColor(Color(hue, 0.3f, 0.3f, 1.0f));
            
            // 设置点击事件
            int buttonIndex = i;
            button->SetOnClick([this, buttonIndex]() {
                std::cout << "按钮 " << (buttonIndex + 1) << " 被点击" << std::endl;
                // 可以在这里添加更多逻辑
            });
            
            m_buttons.push_back(std::move(button));
        }
    }
    
    void Render() {
        if (!m_renderer) return;
        
        m_renderer->BeginFrame();
        m_renderer->Clear(Color::Black);
        
        // 渲染所有按钮
        for (auto& button : m_buttons) {
            button->Render();
        }
        
        m_renderer->EndFrame();
        m_renderer->Present();
    }
    
    void HandleInput(int mouseX, int mouseY, int mouseButton, bool mouseDown) {
        // 处理所有按钮的输入
        for (auto& button : m_buttons) {
            button->HandleMouseMove(mouseX, mouseY);
            button->HandleMouse(mouseX, mouseY, mouseButton, mouseDown);
        }
    }
    
    ~AdvancedUIExample() {
        if (m_renderer) {
            m_renderer->Shutdown();
        }
    }
}; 