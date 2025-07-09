# XmGui 示例程序

本目录包含了XmGui库的使用示例，帮助您快速了解如何使用这个UI库。

## 示例列表

### 1. BasicExample.cpp
**基础示例** - 展示XmGui的基本用法

功能：
- 创建简单的窗口
- 添加按钮控件
- 处理用户事件
- 基础的渲染循环

### 2. 计划中的示例
- **AdvancedExample.cpp** - 高级控件使用示例
- **AnimationExample.cpp** - 动画和过渡效果示例  
- **CustomControlExample.cpp** - 自定义控件示例
- **DialogExample.cpp** - 对话框和模态窗口示例

## 编译要求

### 系统要求
- Windows XP SP3 或更高版本
- Visual Studio 2008 或更高版本
- DirectX 9.0c SDK

### 依赖库
- XmGui库文件（位于 `../lib/` 目录）
- DirectX 9库文件
- Windows系统库

## 编译步骤

### 方法1：使用Visual Studio
1. 打开Visual Studio
2. 创建新的Win32项目
3. 添加示例源文件到项目
4. 配置项目设置：
   - 包含目录：添加 `../include` 和 `../__header`
   - 库目录：添加 `../lib` 和 `../__lib`
   - 链接库：添加 `UILib.lib`, `Engine.lib`, `d3d9.lib`, `d3dx9.lib`
5. 编译运行

### 方法2：使用命令行
```bash
# 编译BasicExample
cl /EHsc /I"../include" /I"../__header" BasicExample.cpp /link UILib.lib Engine.lib d3d9.lib d3dx9.lib /LIBPATH:"../lib" /LIBPATH:"../__lib"
```

### 方法3：使用提供的批处理脚本
```bash
# 运行编译脚本
build_examples.bat
```

## 运行示例

### BasicExample
1. 编译成功后，运行 `BasicExample.exe`
2. 您将看到一个包含三个按钮的窗口
3. 点击按钮测试事件处理
4. 按ESC键或点击退出按钮关闭程序

### 控制说明
- **确定按钮**: 显示确认消息
- **取消按钮**: 显示取消消息
- **退出按钮**: 确认后退出程序
- **ESC键**: 直接退出程序

## 常见问题

### 编译错误
1. **找不到头文件**
   - 确保包含目录设置正确
   - 检查相对路径是否正确

2. **链接错误**
   - 确保库文件路径正确
   - 检查库文件是否存在
   - 确认Debug/Release配置匹配

3. **DirectX相关错误**
   - 确保安装了DirectX SDK
   - 检查DirectX版本兼容性

### 运行错误
1. **DirectX初始化失败**
   - 检查显卡驱动是否支持DirectX 9
   - 尝试使用参考设备

2. **窗口创建失败**
   - 检查窗口类注册是否成功
   - 确认窗口参数设置正确

3. **UI创建失败**
   - 检查XmGui库是否正确初始化
   - 确认D3D设备状态正常

## 调试技巧

### 启用调试输出
在Debug模式下编译，程序会输出详细的调试信息。

### 内存泄漏检测
```cpp
// 在程序结束前调用
XM_DEBUG_MEMORY_LEAK_CHECK();
```

### 设备状态检查
```cpp
// 检查DirectX设备状态
if (!XM::IsDeviceValid(g_pD3DDevice))
{
    // 处理设备丢失
}
```

## 扩展示例

### 添加自定义控件
```cpp
// 创建自定义按钮
XM::UI_Button* pCustomButton = new XM::UI_Button();
pCustomButton->setID(200);
pCustomButton->setPosition(100, 200, 0);
// 设置自定义属性
pUIManager->addChild(pCustomButton);
```

### 处理更多事件
```cpp
void CALLBACK OnUIEvent(UINT nEvent, int nControlID, XM::UI_Object* pControl, void* pUserContext)
{
    switch (nEvent)
    {
    case XM::SET_BUTTON_CLICKED:
        // 处理按钮点击
        break;
    case XM::SET_EDITBOX_CHANGED:
        // 处理文本框改变
        break;
    // 添加更多事件处理...
    }
}
```

## 技术支持

如果您在使用示例时遇到问题，请：

1. 检查上述常见问题部分
2. 查看主项目的README.md文件
3. 访问项目主页获取更多信息
4. 提交Issue报告问题

## 许可证

这些示例程序采用与主项目相同的许可证（LGPL v2.1）。 