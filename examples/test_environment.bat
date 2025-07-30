@echo off
echo ======================================
echo        Environment Test Script
echo ======================================
echo.

echo [1] Checking Visual Studio compiler...
where cl >nul 2>nul
if %errorlevel% equ 0 (
    echo ✓ Visual Studio compiler found
    cl 2>&1 | findstr /i "Microsoft"
) else (
    echo ✗ Visual Studio compiler NOT found
    echo.
    echo Please run this script from:
    echo - Visual Studio Developer Command Prompt
    echo - Or use the enhanced build script: build_examples_improved.bat
    echo.
    pause
    exit /b 1
)

echo.
echo [2] Checking DirectX SDK...
if defined DXSDK_DIR (
    echo ✓ DXSDK_DIR is set: "%DXSDK_DIR%"
    if exist "%DXSDK_DIR%\Include\d3d9.h" (
        echo ✓ DirectX headers found
    ) else (
        echo ✗ DirectX headers NOT found
        echo   Checked path: "%DXSDK_DIR%\Include\d3d9.h"
    )
    if exist "%DXSDK_DIR%\Lib\x86\d3d9.lib" (
        echo ✓ DirectX libraries found
    ) else (
        echo ✗ DirectX libraries NOT found
        echo   Checked path: "%DXSDK_DIR%\Lib\x86\d3d9.lib"
    )
) else (
    echo ✗ DXSDK_DIR environment variable not set
    echo   Will try to use Windows SDK DirectX libraries
    if defined WindowsSdkDir (
        echo   Windows SDK Dir: "%WindowsSdkDir%"
        if exist "%WindowsSdkDir%\Include\d3d9.h" (
            echo ✓ Windows SDK DirectX headers found
        )
        if exist "%WindowsSdkDir%\Lib\x86\d3d9.lib" (
            echo ✓ Windows SDK DirectX libraries found
        )
    )
)

echo.
echo [3] Checking XmGui libraries...
if exist "../__lib/UILib.lib" (
    echo ✓ UILib.lib found
) else (
    echo ✗ UILib.lib NOT found
)

if exist "../__lib/Engine.lib" (
    echo ✓ Engine.lib found
) else (
    echo ✗ Engine.lib NOT found
)

if exist "../__lib/EngineD.lib" (
    echo ✓ EngineD.lib (Debug) found
) else (
    echo ✗ EngineD.lib (Debug) NOT found
)

echo.
echo [4] Checking header files...
if exist "../__header/anw_UIHeader.h" (
    echo ✓ Main UI header found
) else (
    echo ✗ Main UI header NOT found
)

if exist "../include/XmGui.h" (
    echo ✓ New unified header found
) else (
    echo ✗ New unified header NOT found
)

echo.
echo [5] Testing simple compilation...
echo Creating test file...
echo #include ^<windows.h^> > test_compile.cpp
echo int main() { return 0; } >> test_compile.cpp

cl /nologo test_compile.cpp /Fe:test_compile.exe >nul 2>&1
if %errorlevel% equ 0 (
    echo ✓ Simple compilation test PASSED
    del test_compile.cpp test_compile.exe >nul 2>&1
) else (
    echo ✗ Simple compilation test FAILED
    del test_compile.cpp >nul 2>&1
)

echo.
echo ======================================
echo           Test Complete
echo ======================================
echo.
echo If all tests passed, you can run:
echo   build_examples.bat
echo   OR
echo   build_examples_improved.bat
echo.
pause 