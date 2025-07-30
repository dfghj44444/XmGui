# Vulkan支持设置指南

## 问题描述
如果您遇到以下编译错误：
```
Cannot open include file: 'vulkan/vulkan.h': No such file or directory
```

这是因为项目默认禁用了Vulkan支持，以避免在没有安装Vulkan SDK的系统上编译失败。

## 解决方案

### 方案1：禁用Vulkan支持（推荐，如果不需要Vulkan）
项目已经配置为默认禁用Vulkan支持，您可以直接编译项目，无需安装Vulkan SDK。

### 方案2：启用Vulkan支持（需要安装Vulkan SDK）

#### 步骤1：安装Vulkan SDK
1. 访问 [LunarG Vulkan SDK](https://vulkan.lunarg.com/sdk/home)
2. 下载并安装适合您系统的Vulkan SDK
3. 确保安装后`vulkan-1.dll`在系统PATH中可用

#### 步骤2：修改项目配置
有两种方式启用Vulkan支持：

**方式A：修改项目文件**
编辑 `XmGuiRenderer.vcxproj` 文件，将以下行：
```xml
<PreprocessorDefinitions>WIN32;_DEBUG;_LIB;NOMINMAX;XMGUI_ENABLE_VULKAN=0;%(PreprocessorDefinitions)</PreprocessorDefinitions>
```
改为：
```xml
<PreprocessorDefinitions>WIN32;_DEBUG;_LIB;NOMINMAX;XMGUI_ENABLE_VULKAN=1;%(PreprocessorDefinitions)</PreprocessorDefinitions>
```

**方式B：修改配置文件**
编辑 `include/XmGuiConfig.h` 文件，将以下行：
```cpp
#define XMGUI_ENABLE_VULKAN         0
```
改为：
```cpp
#define XMGUI_ENABLE_VULKAN         1
```

#### 步骤3：添加Vulkan SDK路径
在 `XmGuiRenderer.vcxproj` 文件中，找到 `AdditionalIncludeDirectories` 行，添加Vulkan SDK的包含路径：
```xml
<AdditionalIncludeDirectories>include;__header;__header/UISource;__header/Engine;src;%DXSDK_DIR%\Include;$(VULKAN_SDK)\Include;%(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>
```

#### 步骤4：添加Vulkan库路径
在 `XmGuiRenderer.vcxproj` 文件中，找到 `AdditionalLibraryDirectories` 行（如果没有则添加），添加Vulkan SDK的库路径：
```xml
<AdditionalLibraryDirectories>$(VULKAN_SDK)\Lib;%(AdditionalLibraryDirectories)</AdditionalLibraryDirectories>
```

#### 步骤5：链接Vulkan库
在 `XmGuiRenderer.vcxproj` 文件中，找到 `AdditionalDependencies` 行（如果没有则添加），添加Vulkan库：
```xml
<AdditionalDependencies>vulkan-1.lib;%(AdditionalDependencies)</AdditionalDependencies>
```

## 编译项目

### 使用批处理文件
运行项目根目录下的 `build.bat` 文件：
```cmd
build.bat
```

### 使用Visual Studio
1. 打开 `XMGUI.sln` 解决方案文件
2. 选择 `Debug` 或 `Release` 配置
3. 选择 `Win32` 平台
4. 点击 `生成` -> `生成解决方案`

## 验证Vulkan支持

编译成功后，您可以通过以下方式验证Vulkan支持：

```cpp
#include "include/XmGuiRenderer.h"

// 检查Vulkan是否可用
if (XM::RendererFactory::IsRendererSupported(XM::RendererType::Vulkan)) {
    // Vulkan可用
    auto renderer = XM::RendererFactory::CreateRenderer(XM::RendererType::Vulkan);
} else {
    // Vulkan不可用
}
```

## 故障排除

### 问题1：找不到vulkan-1.dll
- 确保Vulkan SDK已正确安装
- 检查系统PATH中是否包含Vulkan SDK的bin目录
- 重启Visual Studio或命令提示符

### 问题2：链接错误
- 确保已正确添加Vulkan库路径和依赖项
- 检查Vulkan SDK版本是否与项目兼容

### 问题3：运行时错误
- 确保系统支持Vulkan
- 检查显卡驱动程序是否支持Vulkan

## 注意事项

1. Vulkan支持是可选的，项目可以在没有Vulkan的情况下正常工作
2. 如果不需要Vulkan功能，建议保持默认的禁用状态
3. 启用Vulkan支持会增加项目的复杂性和依赖项
4. 在生产环境中，建议根据目标平台的需求来决定是否启用Vulkan支持 