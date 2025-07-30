@echo off
echo 正在编译XmGui项目...

REM 尝试使用MSBuild编译
where msbuild >nul 2>&1
if %errorlevel% equ 0 (
    echo 使用MSBuild编译...
    msbuild XMGUI.sln /p:Configuration=Debug /p:Platform=Win32
    goto :end
)

REM 尝试使用Visual Studio开发者命令提示符
echo 尝试设置Visual Studio环境...
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat" 2>nul
if %errorlevel% equ 0 (
    echo 使用Visual Studio 2019 Community编译...
    msbuild XMGUI.sln /p:Configuration=Debug /p:Platform=Win32
    goto :end
)

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Auxiliary\Build\vcvars32.bat" 2>nul
if %errorlevel% equ 0 (
    echo 使用Visual Studio 2019 Professional编译...
    msbuild XMGUI.sln /p:Configuration=Debug /p:Platform=Win32
    goto :end
)

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\Build\vcvars32.bat" 2>nul
if %errorlevel% equ 0 (
    echo 使用Visual Studio 2019 Enterprise编译...
    msbuild XMGUI.sln /p:Configuration=Debug /p:Platform=Win32
    goto :end
)

call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat" 2>nul
if %errorlevel% equ 0 (
    echo 使用Visual Studio 2022 Community编译...
    msbuild XMGUI.sln /p:Configuration=Debug /p:Platform=Win32
    goto :end
)

call "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Auxiliary\Build\vcvars32.bat" 2>nul
if %errorlevel% equ 0 (
    echo 使用Visual Studio 2022 Professional编译...
    msbuild XMGUI.sln /p:Configuration=Debug /p:Platform=Win32
    goto :end
)

call "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvars32.bat" 2>nul
if %errorlevel% equ 0 (
    echo 使用Visual Studio 2022 Enterprise编译...
    msbuild XMGUI.sln /p:Configuration=Debug /p:Platform=Win32
    goto :end
)

echo 错误：无法找到Visual Studio或MSBuild
echo 请确保已安装Visual Studio，或者手动打开XMGUI.sln进行编译
pause
exit /b 1

:end
echo 编译完成！
pause 