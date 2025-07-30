@echo off
echo ======================================
echo  XmGui Example Build Script (Fixed)
echo ======================================
echo.

REM Auto-detect and setup Visual Studio environment
call :setup_vs_environment
if %errorlevel% neq 0 (
    echo ERROR: Unable to setup Visual Studio environment
    pause
    exit /b 1
)

REM Set compilation environment
set "INCLUDE_PATH=../include;../__header;../__header/UISource;../__header/Engine"
set "LIB_PATH=../lib;../__lib"
set "LIBS=UILib.lib Engine.lib d3d9.lib d3dx9.lib kernel32.lib user32.lib gdi32.lib"

REM Verify compiler is available
where cl >nul 2>nul
if %errorlevel% neq 0 (
    echo ERROR: Visual Studio compiler is still not available
    echo Please ensure Visual Studio is properly installed
    pause
    exit /b 1
)

echo Visual Studio environment setup successful
echo Compiler path: 
where cl

REM Check and setup DirectX SDK paths
call :setup_directx_paths

REM Create output directory
if not exist "bin" mkdir bin

echo Starting compilation...
echo.

REM Compile BasicExample
echo Compiling BasicExample.cpp...

REM Build the compile command with all necessary paths
echo Using DirectX Include: "%DX_INCLUDE_PATH%"
echo Using DirectX Lib: "%DX_LIB_PATH%"
echo.

cl /nologo /EHsc /W3 /MD ^
   /I"%INCLUDE_PATH%" ^
   /I"%DX_INCLUDE_PATH%" ^
   BasicExample.cpp ^
   /Fe"bin\BasicExample.exe" ^
   /link ^
   %LIBS% ^
   /LIBPATH:"%LIB_PATH%" ^
   /LIBPATH:"%DX_LIB_PATH%" ^
   /SUBSYSTEM:WINDOWS

if %errorlevel% equ 0 (
    echo SUCCESS: BasicExample.exe compiled successfully
) else (
    echo FAILED: BasicExample.exe compilation failed
    goto :error
)

echo.
echo ======================================
echo       Compilation Complete!
echo ======================================
echo.
echo Generated files:
dir /b bin\*.exe
echo.
echo Usage:
echo   cd bin
echo   BasicExample.exe
echo.
pause
exit /b 0

:setup_directx_paths
echo.
echo Setting up DirectX SDK paths...

REM Try to find DirectX SDK
if defined DXSDK_DIR (
    echo Found DXSDK_DIR: "%DXSDK_DIR%"
    set "DX_INCLUDE_PATH=%DXSDK_DIR%\Include"
    set "DX_LIB_PATH=%DXSDK_DIR%\Lib\x86"
    
    REM Verify DirectX files exist
    if exist "%DX_INCLUDE_PATH%\d3d9.h" (
        echo ✓ DirectX headers found
    ) else (
        echo ✗ DirectX headers NOT found in: "%DX_INCLUDE_PATH%"
        goto :try_windows_sdk
    )
    
    if exist "%DX_LIB_PATH%\d3d9.lib" (
        echo ✓ DirectX libraries found
        goto :directx_ok
    ) else (
        echo ✗ DirectX libraries NOT found in: "%DX_LIB_PATH%"
        goto :try_windows_sdk
    )
) else (
    echo DXSDK_DIR not set, trying Windows SDK...
    goto :try_windows_sdk
)

:try_windows_sdk
echo Trying Windows SDK...
REM Try different Windows SDK versions
for %%v in (10.0 8.1 8.0) do (
    if exist "%ProgramFiles(x86)%\Windows Kits\%%v\Include\um\d3d9.h" (
        echo Found Windows SDK %%v
        set "DX_INCLUDE_PATH=%ProgramFiles(x86)%\Windows Kits\%%v\Include\um"
        set "DX_LIB_PATH=%ProgramFiles(x86)%\Windows Kits\%%v\Lib\winv6.3\um\x86"
        goto :directx_ok
    )
)

REM Try Windows SDK with different structure
if exist "%ProgramFiles(x86)%\Microsoft SDKs\Windows\v7.1A\Include\d3d9.h" (
    echo Found Windows SDK 7.1A
    set "DX_INCLUDE_PATH=%ProgramFiles(x86)%\Microsoft SDKs\Windows\v7.1A\Include"
    set "DX_LIB_PATH=%ProgramFiles(x86)%\Microsoft SDKs\Windows\v7.1A\Lib"
    goto :directx_ok
)

REM Last resort: try to find DirectX SDK in common locations
echo Searching for DirectX SDK in common locations...
for /d %%d in ("%ProgramFiles(x86)%\Microsoft DirectX SDK*") do (
    echo Checking: "%%d"
    if exist "%%d\Include\d3d9.h" (
        echo Found DirectX SDK at: "%%d"
        set "DX_INCLUDE_PATH=%%d\Include"
        set "DX_LIB_PATH=%%d\Lib\x86"
        goto :directx_ok
    )
)

echo ERROR: Could not find DirectX SDK or Windows SDK
echo Please install DirectX SDK or Windows SDK
pause
exit /b 1

:directx_ok
echo DirectX paths configured successfully
echo Include: "%DX_INCLUDE_PATH%"
echo Lib: "%DX_LIB_PATH%"
exit /b 0

:setup_vs_environment
echo Detecting Visual Studio installation...

REM Check if already in VS environment
where cl >nul 2>nul
if %errorlevel% equ 0 (
    echo Visual Studio environment already set
    exit /b 0
)

REM Try different versions of Visual Studio
set "VS_VERSIONS=2022 2019 2017 2015 2013 2012 2010 2008"

for %%v in (%VS_VERSIONS%) do (
    echo Checking Visual Studio %%v...
    
    REM Check VS 2017+ new path
    if exist "%ProgramFiles%\Microsoft Visual Studio\%%v\Community\VC\Auxiliary\Build\vcvars32.bat" (
        echo Found Visual Studio %%v Community
        call "%ProgramFiles%\Microsoft Visual Studio\%%v\Community\VC\Auxiliary\Build\vcvars32.bat"
        exit /b 0
    )
    
    if exist "%ProgramFiles%\Microsoft Visual Studio\%%v\Professional\VC\Auxiliary\Build\vcvars32.bat" (
        echo Found Visual Studio %%v Professional
        call "%ProgramFiles%\Microsoft Visual Studio\%%v\Professional\VC\Auxiliary\Build\vcvars32.bat"
        exit /b 0
    )
    
    if exist "%ProgramFiles%\Microsoft Visual Studio\%%v\Enterprise\VC\Auxiliary\Build\vcvars32.bat" (
        echo Found Visual Studio %%v Enterprise
        call "%ProgramFiles%\Microsoft Visual Studio\%%v\Enterprise\VC\Auxiliary\Build\vcvars32.bat"
        exit /b 0
    )
    
    REM Check VS 2015 and earlier paths
    if exist "%ProgramFiles%\Microsoft Visual Studio %%v\VC\bin\vcvars32.bat" (
        echo Found Visual Studio %%v
        call "%ProgramFiles%\Microsoft Visual Studio %%v\VC\bin\vcvars32.bat"
        exit /b 0
    )
    
    REM Check x86 path
    if exist "%ProgramFiles(x86)%\Microsoft Visual Studio %%v\VC\bin\vcvars32.bat" (
        echo Found Visual Studio %%v (x86)
        call "%ProgramFiles(x86)%\Microsoft Visual Studio %%v\VC\bin\vcvars32.bat"
        exit /b 0
    )
)

echo Visual Studio installation not found
echo.
echo Please ensure one of the following versions is installed:
echo - Visual Studio 2008 or higher
echo - Visual Studio Community (free version)
echo.
echo Download from: https://visualstudio.microsoft.com/downloads/
exit /b 1

:error
echo.
echo ======================================
echo       Compilation Failed!
echo ======================================
echo.
echo Possible causes:
echo 1. DirectX SDK not found or not properly configured
echo 2. Visual Studio not installed or environment variables not set
echo 3. Library file paths are incorrect
echo 4. Header file paths are incorrect
echo.
echo Current paths:
echo DirectX Include: "%DX_INCLUDE_PATH%"
echo DirectX Lib: "%DX_LIB_PATH%"
echo XmGui Include: "%INCLUDE_PATH%"
echo XmGui Lib: "%LIB_PATH%"
echo.
echo Solutions:
echo 1. Install DirectX SDK June 2010 from Microsoft
echo 2. Or install Windows SDK (contains DirectX headers)
echo 3. Set DXSDK_DIR environment variable manually
echo 4. Use Visual Studio Developer Command Prompt
echo.
pause
exit /b 1 