/**
 * @file XmGuiConfig.cpp
 * @brief XmGui配置系统实现
 * @author Double One
 * @version 1.0.0
 * @date 2025-01-09
 */

#include "../include/XmGuiConfig.h"
#include <fstream>
#include <sstream>
#include <iostream>

namespace XM {

    // 全局配置实例
    static RuntimeConfig g_runtimeConfig;
    
    /**
     * @brief 获取运行时配置
     * @return 运行时配置的引用
     */
    RuntimeConfig& GetRuntimeConfig() {
        return g_runtimeConfig;
    }
    
    /**
     * @brief 从文件加载配置
     * @param filename 配置文件名
     * @return 成功返回true
     */
    bool LoadConfigFromFile(const wchar_t* filename) {
        std::wifstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        
        std::wstring line;
        while (std::getline(file, line)) {
            // 跳过注释和空行
            if (line.empty() || line[0] == L'#' || line[0] == L';') {
                continue;
            }
            
            // 查找等号
            size_t pos = line.find(L'=');
            if (pos == std::wstring::npos) {
                continue;
            }
            
            std::wstring key = line.substr(0, pos);
            std::wstring value = line.substr(pos + 1);
            
            // 移除空格
            key.erase(0, key.find_first_not_of(L" \t"));
            key.erase(key.find_last_not_of(L" \t") + 1);
            value.erase(0, value.find_first_not_of(L" \t"));
            value.erase(value.find_last_not_of(L" \t") + 1);
            
            // 解析配置项
            if (key == L"screenWidth") {
                g_runtimeConfig.screenWidth = _wtoi(value.c_str());
            } else if (key == L"screenHeight") {
                g_runtimeConfig.screenHeight = _wtoi(value.c_str());
            } else if (key == L"screenBPP") {
                g_runtimeConfig.screenBPP = _wtoi(value.c_str());
            } else if (key == L"fontSize") {
                g_runtimeConfig.fontSize = _wtoi(value.c_str());
            } else if (key == L"fontName") {
                // 移除引号
                if (!value.empty() && value[0] == L'"' && value.back() == L'"') {
                    value = value.substr(1, value.length() - 2);
                }
                // 注意：这里需要确保字符串生存期
                static std::wstring fontNameStorage = value;
                g_runtimeConfig.fontName = fontNameStorage.c_str();
            } else if (key == L"maxRenderObjects") {
                g_runtimeConfig.maxRenderObjects = _wtoi(value.c_str());
            } else if (key == L"textureCacheSize") {
                g_runtimeConfig.textureCacheSize = _wtoi(value.c_str());
            } else if (key == L"enableVSync") {
                g_runtimeConfig.enableVSync = (value == L"true" || value == L"1");
            } else if (key == L"enableDebugOutput") {
                g_runtimeConfig.enableDebugOutput = (value == L"true" || value == L"1");
            } else if (key == L"enableMemoryLeakDetection") {
                g_runtimeConfig.enableMemoryLeakDetection = (value == L"true" || value == L"1");
            } else if (key == L"enablePerformanceStats") {
                g_runtimeConfig.enablePerformanceStats = (value == L"true" || value == L"1");
            }
        }
        
        file.close();
        return true;
    }
    
    /**
     * @brief 保存配置到文件
     * @param filename 配置文件名
     * @return 成功返回true
     */
    bool SaveConfigToFile(const wchar_t* filename) {
        std::wofstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        
        // 写入文件头
        file << L"# XmGui Configuration File" << std::endl;
        file << L"# Generated automatically - do not edit manually" << std::endl;
        file << L"# Values can be modified to customize XmGui behavior" << std::endl;
        file << std::endl;
        
        // 显示配置
        file << L"[Display]" << std::endl;
        file << L"screenWidth = " << g_runtimeConfig.screenWidth << std::endl;
        file << L"screenHeight = " << g_runtimeConfig.screenHeight << std::endl;
        file << L"screenBPP = " << g_runtimeConfig.screenBPP << std::endl;
        file << std::endl;
        
        // 字体配置
        file << L"[Font]" << std::endl;
        file << L"fontSize = " << g_runtimeConfig.fontSize << std::endl;
        file << L"fontName = \"" << g_runtimeConfig.fontName << L"\"" << std::endl;
        file << std::endl;
        
        // 性能配置
        file << L"[Performance]" << std::endl;
        file << L"maxRenderObjects = " << g_runtimeConfig.maxRenderObjects << std::endl;
        file << L"textureCacheSize = " << g_runtimeConfig.textureCacheSize << std::endl;
        file << L"enableVSync = " << (g_runtimeConfig.enableVSync ? L"true" : L"false") << std::endl;
        file << std::endl;
        
        // 调试配置
        file << L"[Debug]" << std::endl;
        file << L"enableDebugOutput = " << (g_runtimeConfig.enableDebugOutput ? L"true" : L"false") << std::endl;
        file << L"enableMemoryLeakDetection = " << (g_runtimeConfig.enableMemoryLeakDetection ? L"true" : L"false") << std::endl;
        file << L"enablePerformanceStats = " << (g_runtimeConfig.enablePerformanceStats ? L"true" : L"false") << std::endl;
        file << std::endl;
        
        file.close();
        return true;
    }
    
    /**
     * @brief 重置配置为默认值
     */
    void ResetConfigToDefault() {
        g_runtimeConfig = RuntimeConfig();
    }
    
    /**
     * @brief 验证配置值的有效性
     * @return 如果配置有效返回true
     */
    bool ValidateConfig() {
        bool isValid = true;
        
        // 检查屏幕尺寸
        if (g_runtimeConfig.screenWidth < XMGUI_MIN_SCREEN_WIDTH || 
            g_runtimeConfig.screenWidth > XMGUI_MAX_SCREEN_WIDTH) {
            std::wcout << L"警告：屏幕宽度超出范围，重置为默认值" << std::endl;
            g_runtimeConfig.screenWidth = XMGUI_DEFAULT_SCREEN_WIDTH;
            isValid = false;
        }
        
        if (g_runtimeConfig.screenHeight < XMGUI_MIN_SCREEN_HEIGHT || 
            g_runtimeConfig.screenHeight > XMGUI_MAX_SCREEN_HEIGHT) {
            std::wcout << L"警告：屏幕高度超出范围，重置为默认值" << std::endl;
            g_runtimeConfig.screenHeight = XMGUI_DEFAULT_SCREEN_HEIGHT;
            isValid = false;
        }
        
        // 检查字体大小
        if (g_runtimeConfig.fontSize < 8 || g_runtimeConfig.fontSize > 72) {
            std::wcout << L"警告：字体大小超出范围，重置为默认值" << std::endl;
            g_runtimeConfig.fontSize = XMGUI_DEFAULT_FONT_SIZE;
            isValid = false;
        }
        
        // 检查渲染对象数量
        if (g_runtimeConfig.maxRenderObjects < 10 || g_runtimeConfig.maxRenderObjects > 10000) {
            std::wcout << L"警告：最大渲染对象数量超出范围，重置为默认值" << std::endl;
            g_runtimeConfig.maxRenderObjects = XMGUI_MAX_RENDER_OBJECTS;
            isValid = false;
        }
        
        // 检查纹理缓存大小
        if (g_runtimeConfig.textureCacheSize < 1 || g_runtimeConfig.textureCacheSize > 1024) {
            std::wcout << L"警告：纹理缓存大小超出范围，重置为默认值" << std::endl;
            g_runtimeConfig.textureCacheSize = XMGUI_TEXTURE_CACHE_SIZE;
            isValid = false;
        }
        
        return isValid;
    }
    
    /**
     * @brief 打印当前配置信息
     */
    void PrintConfigInfo() {
        std::wcout << L"=== XmGui 配置信息 ===" << std::endl;
        std::wcout << L"屏幕尺寸: " << g_runtimeConfig.screenWidth << L" x " << g_runtimeConfig.screenHeight << std::endl;
        std::wcout << L"色彩深度: " << g_runtimeConfig.screenBPP << L" bpp" << std::endl;
        std::wcout << L"字体: " << g_runtimeConfig.fontName << L" (" << g_runtimeConfig.fontSize << L"pt)" << std::endl;
        std::wcout << L"最大渲染对象: " << g_runtimeConfig.maxRenderObjects << std::endl;
        std::wcout << L"纹理缓存大小: " << g_runtimeConfig.textureCacheSize << std::endl;
        std::wcout << L"垂直同步: " << (g_runtimeConfig.enableVSync ? L"开启" : L"关闭") << std::endl;
        std::wcout << L"调试输出: " << (g_runtimeConfig.enableDebugOutput ? L"开启" : L"关闭") << std::endl;
        std::wcout << L"内存泄漏检测: " << (g_runtimeConfig.enableMemoryLeakDetection ? L"开启" : L"关闭") << std::endl;
        std::wcout << L"性能统计: " << (g_runtimeConfig.enablePerformanceStats ? L"开启" : L"关闭") << std::endl;
        std::wcout << L"===================" << std::endl;
    }
    
    /**
     * @brief 初始化配置系统
     * @param configFile 配置文件路径，如果为空则使用默认路径
     */
    void InitializeConfigSystem(const wchar_t* configFile = nullptr) {
        // 首先重置为默认值
        ResetConfigToDefault();
        
        // 尝试从文件加载配置
        const wchar_t* filename = configFile ? configFile : XMGUI_CONFIG_FILE_NAME;
        if (LoadConfigFromFile(filename)) {
            std::wcout << L"成功从文件加载配置: " << filename << std::endl;
        } else {
            std::wcout << L"无法加载配置文件，使用默认配置" << std::endl;
        }
        
        // 验证配置
        if (!ValidateConfig()) {
            std::wcout << L"配置验证失败，部分设置已重置为默认值" << std::endl;
        }
        
        // 打印配置信息
        if (g_runtimeConfig.enableDebugOutput) {
            PrintConfigInfo();
        }
    }
    
    /**
     * @brief 关闭配置系统
     */
    void ShutdownConfigSystem() {
        // 保存当前配置到文件
        if (SaveConfigToFile(XMGUI_CONFIG_FILE_NAME)) {
            if (g_runtimeConfig.enableDebugOutput) {
                std::wcout << L"配置已保存到文件: " << XMGUI_CONFIG_FILE_NAME << std::endl;
            }
        }
    }

} // namespace XM 