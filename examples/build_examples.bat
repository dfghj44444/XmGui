@echo off
echo ======================================
echo       XmGui 示例编译脚本
echo ======================================
echo.

REM 设置编译环境
set INCLUDE_PATH=../include;../__header;../__header/UISource;../__header/Engine
set LIB_PATH=../lib;../__lib
set LIBS=UILib.lib Engine.lib d3d9.lib d3dx9.lib kernel32.lib user32.lib gdi32.lib

REM 检查编译器
where cl >nul 2>nul
if %errorlevel% neq 0 (
    echo 错误：找不到Visual Studio编译器！
    echo 请确保已安装Visual Studio并运行了vcvars32.bat
    pause
    exit /b 1
)

REM 检查DirectX库
if not exist "%DXSDK_DIR%\Lib\x86\d3d9.lib" (
    echo 警告：未找到DirectX SDK，可能会导致链接错误
    echo 请确保已安装DirectX SDK并设置了DXSDK_DIR环境变量
    echo.
)

REM 创建输出目录
if not exist "bin" mkdir bin

echo 开始编译示例...
echo.

REM 编译BasicExample
echo 正在编译 BasicExample.cpp...
cl /nologo /EHsc /W3 /MD ^
   /I"%INCLUDE_PATH%" ^
   /I"%DXSDK_DIR%\Include" ^
   BasicExample.cpp ^
   /Fe"bin\BasicExample.exe" ^
   /link ^
   %LIBS% ^
   /LIBPATH:"%LIB_PATH%" ^
   /LIBPATH:"%DXSDK_DIR%\Lib\x86" ^
   /SUBSYSTEM:WINDOWS

if %errorlevel% equ 0 (
    echo ✓ BasicExample.exe 编译成功
) else (
    echo ✗ BasicExample.exe 编译失败
    goto :error
)

echo.
echo ======================================
echo       编译完成！
echo ======================================
echo.
echo 生成的文件：
dir /b bin\*.exe
echo.
echo 使用方法：
echo   cd bin
echo   BasicExample.exe
echo.
pause
exit /b 0

:error
echo.
echo ======================================
echo       编译失败！
echo ======================================
echo.
echo 可能的原因：
echo 1. 未安装Visual Studio或未设置环境变量
echo 2. 未安装DirectX SDK
echo 3. 库文件路径不正确
echo 4. 头文件路径不正确
echo.
echo 解决方法：
echo 1. 运行Visual Studio命令提示符
echo 2. 确保DirectX SDK已安装并设置DXSDK_DIR
echo 3. 检查库文件是否存在于 %LIB_PATH%
echo 4. 检查头文件是否存在于 %INCLUDE_PATH%
echo.
pause
exit /b 1 