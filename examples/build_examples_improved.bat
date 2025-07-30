@echo off
echo ======================================
echo    XmGui Example Build Script (Enhanced)
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
set INCLUDE_PATH=../include;../__header;../__header/UISource;../__header/Engine
set LIB_PATH=../lib;../__lib
set LIBS=UILib.lib Engine.lib d3d9.lib d3dx9.lib kernel32.lib user32.lib gdi32.lib

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

REM Check DirectX libraries
echo Checking DirectX SDK: %DXSDK_DIR%
if not exist "%DXSDK_DIR%\Lib\x86\d3d9.lib" (
    echo WARNING: DirectX SDK not found, may cause linking errors
    echo Please ensure DirectX SDK is installed and DXSDK_DIR environment variable is set
    echo.
    REM Try using DirectX libraries from Windows SDK
    if defined WindowsSdkDir (
        echo "Trying Windows SDK: %WindowsSdkDir%"
        set DXSDK_DIR="%WindowsSdkDir%"
        if exist "%WindowsSdkDir%\Lib\x86\d3d9.lib" (
            echo Found DirectX libraries in Windows SDK, will use them
        )
    )
)
REM Create output directory
if not exist "bin" mkdir bin

echo Starting compilation...
echo.

REM Compile BasicExample
echo Compiling BasicExample.cpp...
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

:setup_vs_environment
echo Detecting Visual Studio installation...

REM Check if already in VS environment
where cl >nul 2>nul
if %errorlevel% equ 0 (
    echo Visual Studio environment already set
    exit /b 0
)

REM Try different versions of Visual Studio
set VS_VERSIONS=2022 2019 2017 2015 2013 2012 2010 2008

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
echo 1. Visual Studio not installed or environment variables not set
echo 2. DirectX SDK not installed
echo 3. Library file paths are incorrect
echo 4. Header file paths are incorrect
echo.
echo Solutions:
echo 1. Use Visual Studio Developer Command Prompt
echo 2. Make sure DirectX SDK is installed and DXSDK_DIR is set
echo 3. Check if library files exist in %LIB_PATH%
echo 4. Check if header files exist in %INCLUDE_PATH%
echo.
pause
exit /b 1 