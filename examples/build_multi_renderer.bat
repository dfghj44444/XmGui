@echo off
setlocal enabledelayedexpansion

echo ===============================================
echo XmGui多渲染器示例编译脚本
echo ===============================================

:: 检查Visual Studio环境
if not defined VCINSTALLDIR (
    echo 正在寻找Visual Studio...
    
    :: 尝试Visual Studio 2019
    if exist "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Auxiliary\Build\vcvars64.bat" (
        call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Auxiliary\Build\vcvars64.bat"
        goto :found_vs
    )
    
    :: 尝试Visual Studio 2019 Community
    if exist "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat" (
        call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
        goto :found_vs
    )
    
    :: 尝试Visual Studio 2017
    if exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvars64.bat" (
        call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvars64.bat"
        goto :found_vs
    )
    
    :: 尝试Visual Studio 2017 Community
    if exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat" (
        call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"
        goto :found_vs
    )
    
    echo 错误: 找不到Visual Studio安装
    echo 请确保安装了Visual Studio 2017或更高版本
    pause
    exit /b 1
)

:found_vs
echo 找到Visual Studio环境: %VCINSTALLDIR%

:: 检查DirectX SDK
echo 正在检查DirectX SDK...
if not exist "%DXSDK_DIR%Include\d3d9.h" (
    echo 警告: DirectX SDK未找到或未正确安装
    echo 请确保安装了DirectX SDK并设置了DXSDK_DIR环境变量
    echo 尝试使用Windows SDK中的DirectX头文件...
)

:: 检查Vulkan SDK
echo 正在检查Vulkan SDK...
if not exist "%VULKAN_SDK%\Include\vulkan\vulkan.h" (
    echo 警告: Vulkan SDK未找到
    echo 如果需要Vulkan支持，请安装Vulkan SDK
    echo 下载地址: https://vulkan.lunarg.com/
    set VULKAN_SUPPORT=0
) else (
    echo 找到Vulkan SDK: %VULKAN_SDK%
    set VULKAN_SUPPORT=1
)

:: 设置编译选项
set CL_OPTIONS=/EHsc /std:c++17 /W3 /O2 /DWIN32 /D_WINDOWS /DUNICODE /D_UNICODE
set INCLUDE_DIRS=/I"../include" /I"../__header/UISource" /I"../__header/Engine"
set LIB_DIRS=/LIBPATH:"../lib" /LIBPATH:"../__lib"

:: 添加DirectX SDK路径
if exist "%DXSDK_DIR%Include" (
    set INCLUDE_DIRS=!INCLUDE_DIRS! /I"%DXSDK_DIR%Include"
    set LIB_DIRS=!LIB_DIRS! /LIBPATH:"%DXSDK_DIR%Lib\x64"
)

:: 添加Vulkan SDK路径
if !VULKAN_SUPPORT! equ 1 (
    set INCLUDE_DIRS=!INCLUDE_DIRS! /I"%VULKAN_SDK%\Include"
    set LIB_DIRS=!LIB_DIRS! /LIBPATH:"%VULKAN_SDK%\Lib"
    set CL_OPTIONS=!CL_OPTIONS! /DVULKAN_SUPPORT=1
)

:: 库文件
set LIBS=user32.lib gdi32.lib kernel32.lib
set LIBS=!LIBS! d3d9.lib d3dx9.lib d3d11.lib dxgi.lib d3dcompiler.lib

:: 如果支持Vulkan，添加Vulkan库
if !VULKAN_SUPPORT! equ 1 (
    set LIBS=!LIBS! vulkan-1.lib
)

:: 源文件
set SOURCE_FILES=MultiRendererExample.cpp
set SOURCE_FILES=!SOURCE_FILES! ../src/XmGuiRenderer.cpp
set SOURCE_FILES=!SOURCE_FILES! ../src/XmGuiConfig.cpp
set SOURCE_FILES=!SOURCE_FILES! ../src/DX9Renderer.cpp
set SOURCE_FILES=!SOURCE_FILES! ../src/DX11Renderer.cpp

:: 如果支持Vulkan，添加Vulkan渲染器
if !VULKAN_SUPPORT! equ 1 (
    set SOURCE_FILES=!SOURCE_FILES! ../src/VulkanRenderer.cpp
)

:: 输出文件
set OUTPUT_FILE=MultiRendererExample.exe

echo.
echo 编译设置:
echo   编译器选项: %CL_OPTIONS%
echo   包含目录: %INCLUDE_DIRS%
echo   库目录: %LIB_DIRS%
echo   链接库: %LIBS%
echo   源文件: %SOURCE_FILES%
echo   输出文件: %OUTPUT_FILE%
echo   Vulkan支持: %VULKAN_SUPPORT%
echo.

:: 开始编译
echo 开始编译...
cl %CL_OPTIONS% %INCLUDE_DIRS% %SOURCE_FILES% /Fe%OUTPUT_FILE% /link %LIB_DIRS% %LIBS%

if %ERRORLEVEL% equ 0 (
    echo.
    echo ===============================================
    echo 编译成功!
    echo ===============================================
    echo.
    echo 生成的文件: %OUTPUT_FILE%
    echo.
    echo 运行说明:
    echo   1. 确保DirectX运行时已安装
    echo   2. 如果使用Vulkan，确保显卡驱动支持Vulkan
    echo   3. 双击运行 %OUTPUT_FILE%
    echo.
    echo 快捷键:
    echo   1 - 切换到DirectX 9
    echo   2 - 切换到DirectX 11
    echo   3 - 切换到Vulkan
    echo   A - 自动选择最佳渲染器
    echo   I - 显示渲染器详细信息
    echo   ESC - 退出程序
    echo.
    
    :: 询问是否立即运行
    set /p RUN_NOW=是否立即运行示例程序? (Y/N): 
    if /i "!RUN_NOW!" equ "Y" (
        echo 正在运行 %OUTPUT_FILE%...
        start %OUTPUT_FILE%
    )
) else (
    echo.
    echo ===============================================
    echo 编译失败!
    echo ===============================================
    echo.
    echo 可能的问题:
    echo   1. Visual Studio环境未正确设置
    echo   2. DirectX SDK未安装或路径不正确
    echo   3. 缺少必要的库文件
    echo   4. 源文件路径错误
    echo.
    echo 请检查以上问题并重试。
    echo.
    
    :: 显示详细的错误信息
    echo 详细编译命令:
    echo cl %CL_OPTIONS% %INCLUDE_DIRS% %SOURCE_FILES% /Fe%OUTPUT_FILE% /link %LIB_DIRS% %LIBS%
)

:: 清理临时文件
if exist "*.obj" del "*.obj"
if exist "*.exp" del "*.exp"
if exist "*.lib" del "*.lib"
if exist "*.pdb" del "*.pdb"
if exist "*.ilk" del "*.ilk"

echo.
pause 