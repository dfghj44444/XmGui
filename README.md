# XmGui - 基于DirectX 9的游戏UI库

[![License: LGPL v2.1](https://img.shields.io/badge/License-LGPL%20v2.1-blue.svg)](COPYING)
[![Platform](https://img.shields.io/badge/Platform-Windows-blue.svg)]()
[![DirectX](https://img.shields.io/badge/DirectX-9-green.svg)]()

## 项目简介

XmGui是一个专为游戏开发设计的轻量级UI库，基于DirectX 9技术构建。它提供了完整的UI控件系统、事件处理机制和资源管理功能，适合用于各种2D和3D游戏的用户界面开发。

## 主要特性

### 🎮 多渲染器支持 (新增)
- **DirectX 9**: 兼容性最佳，支持旧硬件和系统
- **DirectX 11**: 现代化特性，高性能渲染
- **Vulkan**: 跨平台，低开销，现代GPU架构
- **智能选择**: 自动检测并选择最佳渲染器
- **统一接口**: 无缝切换不同图形API

### 🚀 高性能渲染
- **优化的GPU管线**: 针对游戏场景的渲染优化
- **批处理支持**: 字体和纹理的批量渲染
- **低内存占用**: 高效的资源管理和对象池机制
- **性能监控**: 实时FPS、绘制调用等统计信息

### 🎨 丰富的UI控件
- **基础控件**: 按钮(Button)、文本框(TextBox)、标签(Label)
- **容器控件**: 面板(Panel)、对话框(Dialog)、窗口(Window)
- **高级控件**: 列表框(ListBox)、下拉框(ComboBox)、进度条(ProgressBar)
- **新体系控件**: 基于渲染器抽象层的现代化UI控件

### 🛠️ 完善的系统架构
- **RTTI系统**: 运行时类型信息支持
- **事件系统**: 完整的鼠标、键盘事件处理
- **序列化**: UI布局的保存和加载
- **国际化**: Unicode字符支持
- **配置系统**: 灵活的配置选项和运行时调整

### 📐 灵活的布局系统
- **相对定位**: 支持相对于父控件的定位
- **自适应布局**: 控件大小自动调整
- **层级管理**: Z-order排序和遮挡处理

## 系统要求

### 最低要求
- **操作系统**: Windows XP SP3 或更高版本
- **DirectX**: DirectX 9.0c
- **编译器**: Visual Studio 2008 或更高版本
- **内存**: 512MB RAM
- **显卡**: 支持DirectX 9的显卡

### 推荐配置
- **操作系统**: Windows 7/8/10/11
- **DirectX**: DirectX 9.0c
- **编译器**: Visual Studio 2019 或更高版本
- **内存**: 2GB RAM 或更多

## 快速开始

### 编译项目

1. **克隆项目**
   ```bash
   git clone https://github.com/your-username/XmGui.git
   cd XmGui
   ```

2. **打开解决方案**
   - 双击 `XMGUI.sln` 文件
   - 或使用 Visual Studio 打开

3. **选择配置**
   - Debug: 用于开发和调试
   - Release: 用于发布

4. **编译**
   - 按 `F7` 或选择 `生成` → `生成解决方案`

### 基础使用示例

```cpp
#include "__header/anw_UIHeader.h"
#include "__header/anw_dxengine.h"

using namespace XM;

// 初始化引擎
xmEngine* pEngine = g_pStaticEngine;
pEngine->onCreateDevice(pD3DDevice);

// 创建UI管理器
UI_Manager* pManager = new UI_Manager();
pEngine->addStatusUIManager(pManager);

// 创建按钮
UI_Button* pButton = new UI_Button();
pButton->setID(100);
pButton->setPosition(100, 100, 0);
pManager->addChild(pButton);

// 设置事件回调
pManager->setEventCallback(OnUIEvent, nullptr);

// 在主循环中调用
pManager->frameMove(dwElapsedTime);
pManager->render(pD3DDevice);
```

### 事件处理

```cpp
void CALLBACK OnUIEvent(UINT nEvent, int nControlID, UI_Object* pControl, void* pUserContext)
{
    switch(nEvent)
    {
    case SET_BUTTON_CLICKED:
        if(nControlID == 100)
        {
            // 处理按钮点击事件
            MessageBox(NULL, L"按钮被点击了!", L"消息", MB_OK);
        }
        break;
    }
}
```

### 多渲染器使用 (新增)

```cpp
#include <XmGui.h>

// 检查支持的渲染器
auto supportedRenderers = XM::GetSupportedRenderers();
for (auto type : supportedRenderers) {
    std::wcout << XM::RendererTypeToString(type) << std::endl;
}

// 创建最佳渲染器
auto renderer = XM::CreateBestRenderer(hWnd, 800, 600);
if (renderer) {
    std::wcout << L"使用渲染器: " << renderer->GetName() << std::endl;
    
    // 渲染循环
    while (running) {
        renderer->BeginFrame();
        renderer->Clear(XM::Color::Blue);
        
        // 绘制UI元素
        XM::Rectangle rect(100, 100, 200, 50);
        renderer->DrawRectangle(rect, XM::Color::Red);
        
        renderer->EndFrame();
        renderer->Present();
    }
}

// 手动选择特定渲染器
if (XM::IsRendererSupported(XM::RendererType::DX11)) {
    auto dx11Renderer = XM::CreateRenderer(XM::RendererType::DX11, hWnd, 800, 600);
    // 使用DX11渲染器...
}
```

## 项目结构

```
XmGui/
├── __header/                   # 头文件目录
│   ├── anw_UIHeader.h         # 主要UI头文件
│   ├── anw_dxengine.h         # DirectX引擎头文件
│   ├── Engine/                # 引擎相关头文件
│   └── UISource/              # UI源码头文件
├── __lib/                     # 库文件目录
│   ├── Engine.lib             # 引擎库(Release)
│   ├── EngineD.lib            # 引擎库(Debug)
│   └── UILib.lib              # UI库
├── _UILibrary/                # UI库源码
├── examples/                  # 使用示例(计划添加)
├── docs/                      # 详细文档(计划添加)
├── COPYING                    # LGPL许可证
├── README.md                  # 项目说明
└── XMGUI.sln                  # Visual Studio解决方案
```

## 核心类层次结构

```
baseNode                       # 基础节点类
├── UI_Base                    # UI基类
    ├── UI_Object              # UI对象基类
        ├── UI_Widget          # UI控件基类
            ├── UI_Button      # 按钮控件
            ├── UI_Box         # 容器控件
            ├── UI_RectItem    # 矩形项目
            └── ...            # 其他控件
        └── UI_Manager         # UI管理器
```

## API文档

### 主要类介绍

#### xmEngine
引擎单例类，负责整个UI系统的初始化和管理。

```cpp
// 获取引擎实例
xmEngine* pEngine = g_pStaticEngine;

// 设备相关
pEngine->onCreateDevice(pD3DDevice);
pEngine->onResetDevice(pD3DDevice);
pEngine->onLostDevice();
pEngine->onDestroyDevice();
```

#### UI_Manager
UI管理器，负责管理所有UI控件的显示和事件处理。

```cpp
UI_Manager* pManager = new UI_Manager();
pManager->setEventCallback(OnUIEvent, pUserContext);
pManager->addChild(pControl);
```

#### UI_Object
所有UI控件的基类，提供基本的位置、可见性和事件处理功能。

```cpp
pControl->setPosition(x, y, z);
pControl->setVisible(true);
pControl->setEnabled(true);
```

### 新体系UI控件

#### UIButton (新)
基于渲染器抽象层的现代化按钮控件，支持多种渲染后端。

```cpp
#include "include/XmGuiRenderer.h"
#include "include/UIButton.h"

// 创建渲染器
auto renderer = XM::CreateRenderer(XM::RendererType::DX11, hWnd, 800, 600);
renderer->Initialize(hWnd, 800, 600);

// 创建按钮
auto button = XM::CreateUIButton(renderer.get());
button->SetPosition(100, 100);
button->SetSize(200, 50);
button->SetText(L"点击我");
button->SetTextColor(XM::Color::White);
button->SetNormalColor(XM::Color(0.2f, 0.2f, 0.8f, 1.0f));
button->SetHoverColor(XM::Color(0.3f, 0.3f, 0.9f, 1.0f));
button->SetPressedColor(XM::Color(0.1f, 0.1f, 0.7f, 1.0f));

// 设置事件回调
button->SetOnClick([]() {
    std::cout << "按钮被点击了！" << std::endl;
});

// 渲染循环
renderer->BeginFrame();
renderer->Clear(XM::Color::DarkBlue);
button->Render();
renderer->EndFrame();
renderer->Present();

// 处理输入
button->HandleMouseMove(mouseX, mouseY);
button->HandleMouse(mouseX, mouseY, mouseButton, mouseDown);
```

## 开发计划

### 已完成功能
- ✅ 基础UI控件系统
- ✅ DirectX 9渲染支持
- ✅ 事件处理机制
- ✅ 字体渲染系统
- ✅ 资源管理器
- ✅ RTTI系统

### 计划中功能
- 🔄 现代C++特性支持
- 🔄 改进的内存管理
- 🔄 更多UI控件类型
- 🔄 主题系统
- 🔄 动画支持
- 🔄 更好的文档和示例

## 贡献指南

我们欢迎任何形式的贡献！请查看以下指南：

1. **报告问题**: 使用GitHub Issues报告bug或提出功能请求
2. **提交代码**: 
   - Fork项目
   - 创建功能分支
   - 提交更改
   - 创建Pull Request

3. **代码规范**: 
   - 使用一致的命名规范
   - 添加适当的注释
   - 遵循现有的代码风格

## 许可证

本项目采用 [GNU Lesser General Public License v2.1](COPYING) 许可证。

## 联系方式

- **作者**: Double One
- **邮箱**: dfghj77777@gmail.com
- **博客**: http://onedouble.cnblogs.com

## 更新日志

### v1.0.0 (当前版本)
- 基础UI系统实现
- DirectX 9渲染支持
- 基本控件集合

---

*这个项目是我的第一个游戏UI库，基于DirectX 9技术。虽然还有许多改进空间，但它已经能够满足基本的游戏UI开发需求。感谢您的使用和反馈！*

