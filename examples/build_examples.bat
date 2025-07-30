@echo off
echo ======================================
echo       XmGui Example Build Script
echo ======================================
echo.

REM Set compilation environment2
set INCLUDE_PATH=../include;../__header;../__header/UISource;../__header/Engine
set LIB_PATH=../lib;../__lib
set LIBS=UILib.lib Engine.lib d3d9.lib d3dx9.lib kernel32.lib user32.lib gdi32.lib

REM Check compiler
where cl >nul 2>nul
if %errorlevel% neq 0 (
    echo ERROR: Visual Studio compiler not found!
    echo Please make sure Visual Studio is installed and vcvars32.bat is executed
    pause
    exit /b 1
)

REM Check DirectX libraries
if not exist "%DXSDK_DIR%\Lib\x86\d3d9.lib" (
    echo WARNING: DirectX SDK not found, may cause linking errors
    echo Please make sure DirectX SDK is installed and DXSDK_DIR environment variable is set
    echo.
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
echo 1. Run Visual Studio Command Prompt
echo 2. Make sure DirectX SDK is installed and DXSDK_DIR is set
echo 3. Check if library files exist in %LIB_PATH%
echo 4. Check if header files exist in %INCLUDE_PATH%
echo.
pause
exit /b 1 