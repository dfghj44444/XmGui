/**
 * @file DX9Renderer.cpp
 * @brief DirectX 9渲染器实现
 * @author Double One
 * @version 1.0.0
 * @date 2025-01-09
 */

#include "../include/XmGuiRenderer.h"
#include <d3d9.h>
#include <d3dx9.h>
#include <vector>
#include <stack>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

namespace XM {

//=============================================================================
// DX9纹理实现
//=============================================================================
class DX9Texture : public ITexture {
private:
    IDirect3DTexture9* m_pTexture;
    int m_width, m_height;
    bool m_isValid;

public:
    DX9Texture() : m_pTexture(nullptr), m_width(0), m_height(0), m_isValid(false) {}
    
    virtual ~DX9Texture() {
        if (m_pTexture) {
            m_pTexture->Release();
            m_pTexture = nullptr;
        }
    }

    // ITexture接口实现
    virtual int GetWidth() const override { return m_width; }
    virtual int GetHeight() const override { return m_height; }
    virtual bool IsValid() const override { return m_isValid; }

    virtual bool LoadFromFile(const std::wstring& filename) override {
        IDirect3DDevice9* device = GetDevice();
        if (!device) return false;

        if (m_pTexture) {
            m_pTexture->Release();
            m_pTexture = nullptr;
        }

        HRESULT hr = D3DXCreateTextureFromFileW(device, filename.c_str(), &m_pTexture);
        if (SUCCEEDED(hr)) {
            D3DSURFACE_DESC desc;
            m_pTexture->GetLevelDesc(0, &desc);
            m_width = desc.Width;
            m_height = desc.Height;
            m_isValid = true;
            return true;
        }
        
        m_isValid = false;
        return false;
    }

    virtual bool LoadFromMemory(const void* data, size_t size) override {
        IDirect3DDevice9* device = GetDevice();
        if (!device) return false;

        if (m_pTexture) {
            m_pTexture->Release();
            m_pTexture = nullptr;
        }

        HRESULT hr = D3DXCreateTextureFromFileInMemory(device, data, static_cast<UINT>(size), &m_pTexture);
        if (SUCCEEDED(hr)) {
            D3DSURFACE_DESC desc;
            m_pTexture->GetLevelDesc(0, &desc);
            m_width = desc.Width;
            m_height = desc.Height;
            m_isValid = true;
            return true;
        }
        
        m_isValid = false;
        return false;
    }

    virtual bool CreateEmpty(int width, int height) override {
        IDirect3DDevice9* device = GetDevice();
        if (!device) return false;

        if (m_pTexture) {
            m_pTexture->Release();
            m_pTexture = nullptr;
        }

        HRESULT hr = device->CreateTexture(width, height, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, &m_pTexture, NULL);
        if (SUCCEEDED(hr)) {
            m_width = width;
            m_height = height;
            m_isValid = true;
            return true;
        }
        
        m_isValid = false;
        return false;
    }

    virtual bool UpdateData(const void* data, int width, int height) override {
        if (!m_pTexture || !data) return false;

        D3DLOCKED_RECT lockedRect;
        HRESULT hr = m_pTexture->LockRect(0, &lockedRect, NULL, 0);
        if (SUCCEEDED(hr)) {
            BYTE* dest = static_cast<BYTE*>(lockedRect.pBits);
            const BYTE* src = static_cast<const BYTE*>(data);
            
            int minWidth = std::min(width, m_width);
            int minHeight = std::min(height, m_height);
            
            for (int y = 0; y < minHeight; y++) {
                memcpy(dest + y * lockedRect.Pitch, src + y * width * 4, minWidth * 4);
            }
            
            m_pTexture->UnlockRect(0);
            return true;
        }
        
        return false;
    }

    virtual void* Lock() override {
        if (!m_pTexture) return nullptr;
        
        D3DLOCKED_RECT lockedRect;
        HRESULT hr = m_pTexture->LockRect(0, &lockedRect, NULL, 0);
        return SUCCEEDED(hr) ? lockedRect.pBits : nullptr;
    }

    virtual void Unlock() override {
        if (m_pTexture) {
            m_pTexture->UnlockRect(0);
        }
    }

    virtual void* GetNativeHandle() const override {
        return m_pTexture;
    }

private:
    IDirect3DDevice9* GetDevice();
};

//=============================================================================
// DX9着色器实现
//=============================================================================
class DX9Shader : public IShader {
private:
    IDirect3DVertexShader9* m_pVertexShader;
    IDirect3DPixelShader9* m_pPixelShader;
    bool m_isValid;

public:
    DX9Shader() : m_pVertexShader(nullptr), m_pPixelShader(nullptr), m_isValid(false) {}
    
    virtual ~DX9Shader() {
        if (m_pVertexShader) {
            m_pVertexShader->Release();
            m_pVertexShader = nullptr;
        }
        if (m_pPixelShader) {
            m_pPixelShader->Release();
            m_pPixelShader = nullptr;
        }
    }

    virtual bool LoadFromFile(const std::wstring& filename) override {
        // DX9着色器从文件加载（简化实现）
        return false; // 暂不实现
    }

    virtual bool LoadFromSource(const std::string& source) override {
        // DX9着色器从源码编译（简化实现）
        return false; // 暂不实现
    }

    virtual bool IsValid() const override { return m_isValid; }

    virtual void SetFloat(const std::string& name, float value) override {
        // DX9设置float参数
    }

    virtual void SetVector2(const std::string& name, float x, float y) override {
        // DX9设置Vector2参数
    }

    virtual void SetVector3(const std::string& name, float x, float y, float z) override {
        // DX9设置Vector3参数
    }

    virtual void SetVector4(const std::string& name, float x, float y, float z, float w) override {
        // DX9设置Vector4参数
    }

    virtual void SetMatrix(const std::string& name, const float* matrix) override {
        // DX9设置矩阵参数
    }

    virtual void SetTexture(const std::string& name, ITexture* texture) override {
        // DX9设置纹理参数
    }

    virtual void* GetNativeHandle() const override {
        return m_pVertexShader; // 返回顶点着色器句柄
    }
};

//=============================================================================
// DX9渲染器实现
//=============================================================================
class DX9Renderer : public IRenderer {
private:
    IDirect3D9* m_pD3D;
    IDirect3DDevice9* m_pDevice;
    D3DPRESENT_PARAMETERS m_d3dpp;
    HWND m_hWnd;
    bool m_isInitialized;
    bool m_deviceLost;
    
    // 渲染状态
    RenderState m_currentState;
    std::stack<RenderState> m_stateStack;
    
    // 变换矩阵
    D3DXMATRIX m_currentTransform;
    std::stack<D3DXMATRIX> m_transformStack;
    
    // 统计信息
    mutable RenderStats m_stats;
    DWORD m_lastFrameTime;
    
    // 视口
    Viewport m_viewport;

public:
    DX9Renderer() 
        : m_pD3D(nullptr)
        , m_pDevice(nullptr)
        , m_hWnd(nullptr)
        , m_isInitialized(false)
        , m_deviceLost(false)
        , m_lastFrameTime(0)
    {
        ZeroMemory(&m_d3dpp, sizeof(m_d3dpp));
        D3DXMatrixIdentity(&m_currentTransform);
    }

    virtual ~DX9Renderer() {
        Shutdown();
    }

    //=========================================================================
    // 生命周期管理
    //=========================================================================
    virtual bool Initialize(HWND hWnd, int width, int height, bool fullscreen = false) override {
        if (m_isInitialized) {
            Shutdown();
        }

        m_hWnd = hWnd;
        
        // 创建Direct3D对象
        m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
        if (!m_pD3D) {
            return false;
        }

        // 设置D3D设备参数
        ZeroMemory(&m_d3dpp, sizeof(m_d3dpp));
        m_d3dpp.Windowed = !fullscreen;
        m_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
        m_d3dpp.BackBufferFormat = fullscreen ? D3DFMT_X8R8G8B8 : D3DFMT_UNKNOWN;
        m_d3dpp.BackBufferWidth = width;
        m_d3dpp.BackBufferHeight = height;
        m_d3dpp.EnableAutoDepthStencil = TRUE;
        m_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
        m_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

        // 创建D3D设备
        HRESULT hr = m_pD3D->CreateDevice(
            D3DADAPTER_DEFAULT,
            D3DDEVTYPE_HAL,
            hWnd,
            D3DCREATE_SOFTWARE_VERTEXPROCESSING,
            &m_d3dpp,
            &m_pDevice
        );

        if (FAILED(hr)) {
            // 尝试使用参考设备
            hr = m_pD3D->CreateDevice(
                D3DADAPTER_DEFAULT,
                D3DDEVTYPE_REF,
                hWnd,
                D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                &m_d3dpp,
                &m_pDevice
            );
        }

        if (FAILED(hr)) {
            Shutdown();
            return false;
        }

        // 设置初始渲染状态
        InitializeRenderStates();
        
        // 设置视口
        m_viewport = Viewport(0, 0, width, height);
        SetViewport(m_viewport);

        m_isInitialized = true;
        m_deviceLost = false;
        
        return true;
    }

    virtual void Shutdown() override {
        if (m_pDevice) {
            m_pDevice->Release();
            m_pDevice = nullptr;
        }
        
        if (m_pD3D) {
            m_pD3D->Release();
            m_pD3D = nullptr;
        }
        
        m_isInitialized = false;
        m_deviceLost = false;
    }

    virtual bool IsInitialized() const override {
        return m_isInitialized;
    }

    //=========================================================================
    // 设备管理
    //=========================================================================
    virtual bool OnDeviceLost() override {
        m_deviceLost = true;
        return true;
    }

    virtual bool OnDeviceReset() override {
        if (!m_pDevice) return false;
        
        HRESULT hr = m_pDevice->Reset(&m_d3dpp);
        if (SUCCEEDED(hr)) {
            InitializeRenderStates();
            SetViewport(m_viewport);
            m_deviceLost = false;
            return true;
        }
        
        return false;
    }

    virtual void OnResize(int width, int height) override {
        if (!m_pDevice) return;
        
        m_d3dpp.BackBufferWidth = width;
        m_d3dpp.BackBufferHeight = height;
        
        OnDeviceReset();
        
        m_viewport.width = width;
        m_viewport.height = height;
        SetViewport(m_viewport);
    }

    //=========================================================================
    // 渲染控制
    //=========================================================================
    virtual void BeginFrame() override {
        if (!m_pDevice || m_deviceLost) return;
        
        // 检查设备状态
        HRESULT hr = m_pDevice->TestCooperativeLevel();
        if (hr == D3DERR_DEVICELOST) {
            OnDeviceLost();
            return;
        } else if (hr == D3DERR_DEVICENOTRESET) {
            OnDeviceReset();
        }
        
        m_stats.Reset();
        m_lastFrameTime = GetTickCount();
    }

    virtual void EndFrame() override {
        if (!m_pDevice || m_deviceLost) return;
        
        // 更新统计信息
        DWORD currentTime = GetTickCount();
        m_stats.frameTime = (currentTime - m_lastFrameTime) / 1000.0f;
        m_stats.fps = m_stats.frameTime > 0 ? 1.0f / m_stats.frameTime : 0.0f;
        m_stats.frameCount++;
    }

    virtual void Present() override {
        if (!m_pDevice || m_deviceLost) return;
        
        HRESULT hr = m_pDevice->Present(NULL, NULL, NULL, NULL);
        if (hr == D3DERR_DEVICELOST) {
            OnDeviceLost();
        }
    }

    virtual void Clear(const Color& color) override {
        if (!m_pDevice || m_deviceLost) return;
        
        DWORD d3dColor = D3DCOLOR_COLORVALUE(color.r, color.g, color.b, color.a);
        m_pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, d3dColor, 1.0f, 0);
    }

    virtual void SetViewport(const Viewport& viewport) override {
        if (!m_pDevice || m_deviceLost) return;
        
        D3DVIEWPORT9 d3dViewport;
        d3dViewport.X = viewport.x;
        d3dViewport.Y = viewport.y;
        d3dViewport.Width = viewport.width;
        d3dViewport.Height = viewport.height;
        d3dViewport.MinZ = viewport.minDepth;
        d3dViewport.MaxZ = viewport.maxDepth;
        
        m_pDevice->SetViewport(&d3dViewport);
        m_viewport = viewport;
    }

    virtual Viewport GetViewport() const override {
        return m_viewport;
    }

    //=========================================================================
    // 渲染状态
    //=========================================================================
    virtual void SetRenderState(const RenderState& state) override {
        if (!m_pDevice || m_deviceLost) return;
        
        // 设置混合状态
        switch (state.blendMode) {
        case BlendMode::None:
            m_pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
            break;
        case BlendMode::Alpha:
            m_pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
            m_pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
            m_pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
            break;
        case BlendMode::Additive:
            m_pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
            m_pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
            m_pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
            break;
        }
        
        // 设置过滤模式
        D3DTEXTUREFILTERTYPE filter = D3DTEXF_POINT;
        switch (state.filterMode) {
        case FilterMode::Point:     filter = D3DTEXF_POINT; break;
        case FilterMode::Linear:    filter = D3DTEXF_LINEAR; break;
        case FilterMode::Anisotropic: filter = D3DTEXF_ANISOTROPIC; break;
        }
        
        m_pDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, filter);
        m_pDevice->SetSamplerState(0, D3DSAMP_MINFILTER, filter);
        
        // 设置深度测试
        m_pDevice->SetRenderState(D3DRS_ZENABLE, state.depthTest ? D3DZB_TRUE : D3DZB_FALSE);
        m_pDevice->SetRenderState(D3DRS_ZWRITEENABLE, state.depthWrite ? TRUE : FALSE);
        
        // 设置背面剔除
        m_pDevice->SetRenderState(D3DRS_CULLMODE, state.cullBackFace ? D3DCULL_CW : D3DCULL_NONE);
        
        // 设置线框模式
        m_pDevice->SetRenderState(D3DRS_FILLMODE, state.wireframe ? D3DFILL_WIREFRAME : D3DFILL_SOLID);
        
        m_currentState = state;
    }

    virtual RenderState GetRenderState() const override {
        return m_currentState;
    }

    virtual void PushRenderState() override {
        m_stateStack.push(m_currentState);
    }

    virtual void PopRenderState() override {
        if (!m_stateStack.empty()) {
            SetRenderState(m_stateStack.top());
            m_stateStack.pop();
        }
    }

    //=========================================================================
    // 绘制操作
    //=========================================================================
    virtual void DrawVertices(const Vertex* vertices, int count, ITexture* texture = nullptr) override {
        if (!m_pDevice || m_deviceLost || !vertices || count == 0) return;
        
        // 设置纹理
        if (texture) {
            IDirect3DTexture9* d3dTexture = static_cast<IDirect3DTexture9*>(texture->GetNativeHandle());
            m_pDevice->SetTexture(0, d3dTexture);
        } else {
            m_pDevice->SetTexture(0, NULL);
        }
        
        // 设置顶点格式
        m_pDevice->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);
        
        // 绘制
        m_pDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, count / 3, vertices, sizeof(Vertex));
        
        // 更新统计
        m_stats.drawCalls++;
        m_stats.vertexCount += count;
        m_stats.triangleCount += count / 3;
    }

    virtual void DrawIndexed(const Vertex* vertices, int vertexCount, 
                           const uint16_t* indices, int indexCount, ITexture* texture = nullptr) override {
        if (!m_pDevice || m_deviceLost || !vertices || !indices || vertexCount == 0 || indexCount == 0) return;
        
        // 设置纹理
        if (texture) {
            IDirect3DTexture9* d3dTexture = static_cast<IDirect3DTexture9*>(texture->GetNativeHandle());
            m_pDevice->SetTexture(0, d3dTexture);
        } else {
            m_pDevice->SetTexture(0, NULL);
        }
        
        // 设置顶点格式
        m_pDevice->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);
        
        // 绘制（简化实现，使用DrawIndexedPrimitiveUP）
        m_pDevice->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, vertexCount, indexCount / 3, 
                                         indices, D3DFMT_INDEX16, vertices, sizeof(Vertex));
        
        // 更新统计
        m_stats.drawCalls++;
        m_stats.vertexCount += vertexCount;
        m_stats.triangleCount += indexCount / 3;
    }

    virtual void DrawRectangle(const Rectangle& rect, const Color& color) override {
        Vertex vertices[6] = {
            Vertex(rect.x, rect.y, 0, 0, 0, color.ToARGB()),
            Vertex(rect.x + rect.width, rect.y, 0, 1, 0, color.ToARGB()),
            Vertex(rect.x, rect.y + rect.height, 0, 0, 1, color.ToARGB()),
            Vertex(rect.x + rect.width, rect.y, 0, 1, 0, color.ToARGB()),
            Vertex(rect.x + rect.width, rect.y + rect.height, 0, 1, 1, color.ToARGB()),
            Vertex(rect.x, rect.y + rect.height, 0, 0, 1, color.ToARGB())
        };
        
        DrawVertices(vertices, 6, nullptr);
    }

    virtual void DrawRectangle(const Rectangle& rect, ITexture* texture, 
                             const Rectangle* sourceRect = nullptr) override {
        if (!texture) return;
        
        float u1 = 0, v1 = 0, u2 = 1, v2 = 1;
        if (sourceRect) {
            u1 = sourceRect->x / texture->GetWidth();
            v1 = sourceRect->y / texture->GetHeight();
            u2 = (sourceRect->x + sourceRect->width) / texture->GetWidth();
            v2 = (sourceRect->y + sourceRect->height) / texture->GetHeight();
        }
        
        Vertex vertices[6] = {
            Vertex(rect.x, rect.y, 0, u1, v1, 0xFFFFFFFF),
            Vertex(rect.x + rect.width, rect.y, 0, u2, v1, 0xFFFFFFFF),
            Vertex(rect.x, rect.y + rect.height, 0, u1, v2, 0xFFFFFFFF),
            Vertex(rect.x + rect.width, rect.y, 0, u2, v1, 0xFFFFFFFF),
            Vertex(rect.x + rect.width, rect.y + rect.height, 0, u2, v2, 0xFFFFFFFF),
            Vertex(rect.x, rect.y + rect.height, 0, u1, v2, 0xFFFFFFFF)
        };
        
        DrawVertices(vertices, 6, texture);
    }

    void DrawLine(float x1, float y1, float x2, float y2, const Color& color, float width = 1.0f) override {
        // 简化的线条绘制（使用矩形模拟）
        float dx = x2 - x1;
        float dy = y2 - y1;
        float length = sqrtf(dx * dx + dy * dy);
        
        if (length > 0) {
            dx /= length;
            dy /= length;
            
            float nx = -dy * width * 0.5f;
            float ny = dx * width * 0.5f;
            
            Vertex vertices[6] = {
                Vertex(x1 + nx, y1 + ny, 0, 0, 0, color.ToARGB()),
                Vertex(x1 - nx, y1 - ny, 0, 0, 0, color.ToARGB()),
                Vertex(x2 + nx, y2 + ny, 0, 0, 0, color.ToARGB()),
                Vertex(x1 - nx, y1 - ny, 0, 0, 0, color.ToARGB()),
                Vertex(x2 - nx, y2 - ny, 0, 0, 0, color.ToARGB()),
                Vertex(x2 + nx, y2 + ny, 0, 0, 0, color.ToARGB())
            };
            
            DrawVertices(vertices, 6, nullptr);
        }
    }

    void DrawTxt(const std::wstring& text, float x, float y, const XM::Color& color, ITexture* fontTexture = nullptr) override {
        // 文本绘制需要字体系统支持，这里只是占位实现
        // 实际实现需要与现有的字体系统集成
    }

    //=========================================================================
    // 资源管理
    //=========================================================================
    virtual std::shared_ptr<ITexture> CreateTexture() override {
        return std::make_shared<DX9Texture>();
    }

    virtual std::shared_ptr<ITexture> LoadTexture(const std::wstring& filename) override {
        auto texture = std::make_shared<DX9Texture>();
        if (texture->LoadFromFile(filename)) {
            return texture;
        }
        return nullptr;
    }

    virtual std::shared_ptr<IShader> CreateShader() override {
        return std::make_shared<DX9Shader>();
    }

    virtual std::shared_ptr<IShader> LoadShader(const std::wstring& filename) override {
        auto shader = std::make_shared<DX9Shader>();
        if (shader->LoadFromFile(filename)) {
            return shader;
        }
        return nullptr;
    }

    //=========================================================================
    // 信息查询
    //=========================================================================
    virtual RendererType GetType() const override {
        return RendererType::DX9;
    }

    virtual RendererCapabilities GetCapabilities() const override {
        RendererCapabilities caps = {};
        
        if (m_pD3D && m_pDevice) {
            D3DCAPS9 d3dCaps;
            m_pDevice->GetDeviceCaps(&d3dCaps);
            
            caps.supportsMultisampling = true;
            caps.supportsHDR = false;
            caps.supportsComputeShaders = false;
            caps.supportsGeometryShaders = false;
            caps.supportsInstancing = false;
            caps.maxTextureSize = std::min(d3dCaps.MaxTextureWidth, d3dCaps.MaxTextureHeight);
            caps.maxRenderTargets = d3dCaps.NumSimultaneousRTs;
            caps.maxVertexAttributes = 16;
            caps.version = "DirectX 9.0c";
            
            D3DADAPTER_IDENTIFIER9 identifier;
            m_pD3D->GetAdapterIdentifier(D3DADAPTER_DEFAULT, 0, &identifier);
            caps.deviceName = identifier.Description;
        }
        
        return caps;
    }

    virtual RenderStats GetStats() const override {
        return m_stats;
    }

    virtual std::string GetName() const override {
        return "DirectX 9 Renderer";
    }

    //=========================================================================
    // 高级功能
    //=========================================================================
    virtual void SetTransform(const float* matrix) override {
        if (!m_pDevice || m_deviceLost || !matrix) return;
        
        memcpy(&m_currentTransform, matrix, sizeof(D3DXMATRIX));
        m_pDevice->SetTransform(D3DTS_WORLD, &m_currentTransform);
    }

    virtual void PushTransform() override {
        m_transformStack.push(m_currentTransform);
    }

    virtual void PopTransform() override {
        if (!m_transformStack.empty()) {
            m_currentTransform = m_transformStack.top();
            m_transformStack.pop();
            if (m_pDevice && !m_deviceLost) {
                m_pDevice->SetTransform(D3DTS_WORLD, &m_currentTransform);
            }
        }
    }

    virtual void SetScissorRect(const Rectangle& rect) override {
        if (!m_pDevice || m_deviceLost) return;
        
        RECT scissorRect;
        scissorRect.left = static_cast<LONG>(rect.x);
        scissorRect.top = static_cast<LONG>(rect.y);
        scissorRect.right = static_cast<LONG>(rect.x + rect.width);
        scissorRect.bottom = static_cast<LONG>(rect.y + rect.height);
        
        m_pDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, TRUE);
        m_pDevice->SetScissorRect(&scissorRect);
    }

    virtual void DisableScissorRect() override {
        if (!m_pDevice || m_deviceLost) return;
        
        m_pDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
    }

    //=========================================================================
    // 调试功能
    //=========================================================================
    virtual void SetDebugName(const std::string& name) override {
        // DX9没有直接的调试名称支持
    }

    virtual void BeginDebugGroup(const std::string& name) override {
        // DX9没有调试组支持
    }

    virtual void EndDebugGroup() override {
        // DX9没有调试组支持
    }

    virtual void InsertDebugMarker(const std::string& name) override {
        // DX9没有调试标记支持
    }

    //=========================================================================
    // 内部方法
    //=========================================================================
    IDirect3DDevice9* GetDevice() const {
        return m_pDevice;
    }

private:
    void InitializeRenderStates() {
        if (!m_pDevice) return;
        
        // 设置基本渲染状态
        m_pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
        m_pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
        m_pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
        m_pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
        m_pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
        m_pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
        
        // 设置纹理状态
        m_pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
        m_pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
        m_pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
        m_pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
        m_pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
        m_pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
        
        // 设置投影矩阵为2D正交投影
        D3DXMATRIX matProj;
        D3DXMatrixOrthoOffCenterLH(&matProj, 0, (float)m_viewport.width, (float)m_viewport.height, 0, 0.0f, 1.0f);
        m_pDevice->SetTransform(D3DTS_PROJECTION, &matProj);
        
        // 设置视图矩阵为单位矩阵
        D3DXMATRIX matView;
        D3DXMatrixIdentity(&matView);
        m_pDevice->SetTransform(D3DTS_VIEW, &matView);
        
        // 设置世界矩阵为单位矩阵
        D3DXMatrixIdentity(&m_currentTransform);
        m_pDevice->SetTransform(D3DTS_WORLD, &m_currentTransform);
    }
};

// DX9纹理的GetDevice方法实现
IDirect3DDevice9* DX9Texture::GetDevice() {
    // 这里需要从全局或某种方式获取设备指针
    // 为了简化，假设有一个全局的DX9渲染器实例
    extern DX9Renderer* g_pDX9Renderer;
    return g_pDX9Renderer ? g_pDX9Renderer->GetDevice() : nullptr;
}

// 全局DX9渲染器指针（用于纹理访问设备）
DX9Renderer* g_pDX9Renderer = nullptr;

//=============================================================================
// 创建函数实现
//=============================================================================
std::unique_ptr<IRenderer> CreateDX9Renderer() {
    auto renderer = std::make_unique<DX9Renderer>();
    g_pDX9Renderer = renderer.get(); // 设置全局指针
    return std::move(renderer);
}

} // namespace XM 