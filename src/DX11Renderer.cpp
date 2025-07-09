/**
 * @file DX11Renderer.cpp
 * @brief DirectX 11渲染器实现
 * @author Double One
 * @version 1.0.0
 * @date 2025-01-09
 */

#include "../include/XmGuiRenderer.h"
#include <d3d11.h>
#include <dxgi.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include <wrl/client.h>
#include <vector>
#include <stack>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

using Microsoft::WRL::ComPtr;
using namespace DirectX;

namespace XM {

//=============================================================================
// DX11纹理实现
//=============================================================================
class DX11Texture : public ITexture {
private:
    ComPtr<ID3D11Texture2D> m_pTexture;
    ComPtr<ID3D11ShaderResourceView> m_pSRV;
    int m_width, m_height;
    bool m_isValid;

public:
    DX11Texture() : m_width(0), m_height(0), m_isValid(false) {}

    virtual int GetWidth() const override { return m_width; }
    virtual int GetHeight() const override { return m_height; }
    virtual bool IsValid() const override { return m_isValid; }

    virtual bool LoadFromFile(const std::wstring& filename) override {
        // 简化实现 - 需要WIC或其他图像加载库
        return false;
    }

    virtual bool LoadFromMemory(const void* data, size_t size) override {
        // 简化实现
        return false;
    }

    virtual bool CreateEmpty(int width, int height) override {
        auto device = GetDevice();
        if (!device) return false;

        D3D11_TEXTURE2D_DESC desc = {};
        desc.Width = width;
        desc.Height = height;
        desc.MipLevels = 1;
        desc.ArraySize = 1;
        desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        desc.SampleDesc.Count = 1;
        desc.Usage = D3D11_USAGE_DEFAULT;
        desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;

        HRESULT hr = device->CreateTexture2D(&desc, nullptr, &m_pTexture);
        if (SUCCEEDED(hr)) {
            hr = device->CreateShaderResourceView(m_pTexture.Get(), nullptr, &m_pSRV);
            if (SUCCEEDED(hr)) {
                m_width = width;
                m_height = height;
                m_isValid = true;
                return true;
            }
        }
        return false;
    }

    virtual bool UpdateData(const void* data, int width, int height) override {
        auto context = GetContext();
        if (!context || !m_pTexture || !data) return false;

        context->UpdateSubresource(m_pTexture.Get(), 0, nullptr, data, width * 4, 0);
        return true;
    }

    virtual void* Lock() override { return nullptr; } // DX11不支持Lock
    virtual void Unlock() override {} // DX11不支持Unlock
    virtual void* GetNativeHandle() const override { return m_pSRV.Get(); }

private:
    ID3D11Device* GetDevice();
    ID3D11DeviceContext* GetContext();
};

//=============================================================================
// DX11渲染器实现
//=============================================================================
class DX11Renderer : public IRenderer {
private:
    ComPtr<ID3D11Device> m_pDevice;
    ComPtr<ID3D11DeviceContext> m_pContext;
    ComPtr<IDXGISwapChain> m_pSwapChain;
    ComPtr<ID3D11RenderTargetView> m_pRTV;
    ComPtr<ID3D11DepthStencilView> m_pDSV;
    
    // 基本着色器
    ComPtr<ID3D11VertexShader> m_pVertexShader;
    ComPtr<ID3D11PixelShader> m_pPixelShader;
    ComPtr<ID3D11InputLayout> m_pInputLayout;
    ComPtr<ID3D11Buffer> m_pVertexBuffer;
    ComPtr<ID3D11Buffer> m_pConstantBuffer;
    
    // 状态对象
    ComPtr<ID3D11BlendState> m_pBlendState;
    ComPtr<ID3D11RasterizerState> m_pRasterizerState;
    ComPtr<ID3D11DepthStencilState> m_pDepthStencilState;
    ComPtr<ID3D11SamplerState> m_pSamplerState;
    
    HWND m_hWnd;
    bool m_isInitialized;
    RenderState m_currentState;
    std::stack<RenderState> m_stateStack;
    Viewport m_viewport;
    mutable RenderStats m_stats;
    DWORD m_lastFrameTime;

public:
    DX11Renderer() : m_hWnd(nullptr), m_isInitialized(false), m_lastFrameTime(0) {}

    virtual ~DX11Renderer() {
        Shutdown();
    }

    virtual bool Initialize(HWND hWnd, int width, int height, bool fullscreen = false) override {
        m_hWnd = hWnd;

        // 创建设备和交换链
        DXGI_SWAP_CHAIN_DESC scd = {};
        scd.BufferCount = 1;
        scd.BufferDesc.Width = width;
        scd.BufferDesc.Height = height;
        scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        scd.BufferDesc.RefreshRate.Numerator = 60;
        scd.BufferDesc.RefreshRate.Denominator = 1;
        scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        scd.OutputWindow = hWnd;
        scd.SampleDesc.Count = 1;
        scd.SampleDesc.Quality = 0;
        scd.Windowed = !fullscreen;

        D3D_FEATURE_LEVEL featureLevel;
        HRESULT hr = D3D11CreateDeviceAndSwapChain(
            nullptr,
            D3D_DRIVER_TYPE_HARDWARE,
            nullptr,
            0,
            nullptr,
            0,
            D3D11_SDK_VERSION,
            &scd,
            &m_pSwapChain,
            &m_pDevice,
            &featureLevel,
            &m_pContext
        );

        if (FAILED(hr)) return false;

        // 创建渲染目标视图
        ComPtr<ID3D11Texture2D> pBackBuffer;
        hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer);
        if (FAILED(hr)) return false;

        hr = m_pDevice->CreateRenderTargetView(pBackBuffer.Get(), nullptr, &m_pRTV);
        if (FAILED(hr)) return false;

        // 创建深度缓冲
        D3D11_TEXTURE2D_DESC dsd = {};
        dsd.Width = width;
        dsd.Height = height;
        dsd.MipLevels = 1;
        dsd.ArraySize = 1;
        dsd.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
        dsd.SampleDesc.Count = 1;
        dsd.Usage = D3D11_USAGE_DEFAULT;
        dsd.BindFlags = D3D11_BIND_DEPTH_STENCIL;

        ComPtr<ID3D11Texture2D> pDepthBuffer;
        hr = m_pDevice->CreateTexture2D(&dsd, nullptr, &pDepthBuffer);
        if (FAILED(hr)) return false;

        hr = m_pDevice->CreateDepthStencilView(pDepthBuffer.Get(), nullptr, &m_pDSV);
        if (FAILED(hr)) return false;

        // 设置渲染目标
        m_pContext->OMSetRenderTargets(1, m_pRTV.GetAddressOf(), m_pDSV.Get());

        // 创建基本着色器
        if (!CreateShaders()) return false;

        // 创建状态对象
        CreateStates();

        // 设置视口
        m_viewport = Viewport(0, 0, width, height);
        SetViewport(m_viewport);

        m_isInitialized = true;
        return true;
    }

    virtual void Shutdown() override {
        m_pDevice.Reset();
        m_pContext.Reset();
        m_pSwapChain.Reset();
        m_pRTV.Reset();
        m_pDSV.Reset();
        m_isInitialized = false;
    }

    virtual bool IsInitialized() const override { return m_isInitialized; }

    virtual bool OnDeviceLost() override { return true; }
    virtual bool OnDeviceReset() override { return true; }
    virtual void OnResize(int width, int height) override {
        if (!m_pSwapChain) return;
        
        m_pContext->OMSetRenderTargets(0, nullptr, nullptr);
        m_pRTV.Reset();
        m_pDSV.Reset();
        
        m_pSwapChain->ResizeBuffers(0, width, height, DXGI_FORMAT_UNKNOWN, 0);
        
        // 重新创建RTV和DSV
        ComPtr<ID3D11Texture2D> pBackBuffer;
        m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer);
        m_pDevice->CreateRenderTargetView(pBackBuffer.Get(), nullptr, &m_pRTV);
        
        m_pContext->OMSetRenderTargets(1, m_pRTV.GetAddressOf(), m_pDSV.Get());
        
        m_viewport.width = width;
        m_viewport.height = height;
        SetViewport(m_viewport);
    }

    virtual void BeginFrame() override {
        if (!m_pContext) return;
        m_stats.Reset();
        m_lastFrameTime = GetTickCount();
    }

    virtual void EndFrame() override {
        if (!m_pContext) return;
        DWORD currentTime = GetTickCount();
        m_stats.frameTime = (currentTime - m_lastFrameTime) / 1000.0f;
        m_stats.fps = m_stats.frameTime > 0 ? 1.0f / m_stats.frameTime : 0.0f;
        m_stats.frameCount++;
    }

    virtual void Present() override {
        if (m_pSwapChain) {
            m_pSwapChain->Present(0, 0);
        }
    }

    virtual void Clear(const Color& color) override {
        if (!m_pContext) return;
        float clearColor[4] = { color.r, color.g, color.b, color.a };
        m_pContext->ClearRenderTargetView(m_pRTV.Get(), clearColor);
        m_pContext->ClearDepthStencilView(m_pDSV.Get(), D3D11_CLEAR_DEPTH, 1.0f, 0);
    }

    virtual void SetViewport(const Viewport& viewport) override {
        if (!m_pContext) return;
        
        D3D11_VIEWPORT vp = {};
        vp.TopLeftX = (float)viewport.x;
        vp.TopLeftY = (float)viewport.y;
        vp.Width = (float)viewport.width;
        vp.Height = (float)viewport.height;
        vp.MinDepth = viewport.minDepth;
        vp.MaxDepth = viewport.maxDepth;
        
        m_pContext->RSSetViewports(1, &vp);
        m_viewport = viewport;
    }

    virtual Viewport GetViewport() const override { return m_viewport; }

    virtual void SetRenderState(const RenderState& state) override {
        // 设置混合状态等
        m_currentState = state;
    }

    virtual RenderState GetRenderState() const override { return m_currentState; }
    virtual void PushRenderState() override { m_stateStack.push(m_currentState); }
    virtual void PopRenderState() override {
        if (!m_stateStack.empty()) {
            SetRenderState(m_stateStack.top());
            m_stateStack.pop();
        }
    }

    virtual void DrawVertices(const Vertex* vertices, int count, ITexture* texture = nullptr) override {
        if (!m_pContext || !vertices || count == 0) return;

        // 更新顶点缓冲
        D3D11_MAPPED_SUBRESOURCE mapped;
        if (SUCCEEDED(m_pContext->Map(m_pVertexBuffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped))) {
            memcpy(mapped.pData, vertices, count * sizeof(Vertex));
            m_pContext->Unmap(m_pVertexBuffer.Get(), 0);
        }

        // 设置纹理
        if (texture) {
            ID3D11ShaderResourceView* srv = static_cast<ID3D11ShaderResourceView*>(texture->GetNativeHandle());
            m_pContext->PSSetShaderResources(0, 1, &srv);
        }

        // 绘制
        UINT stride = sizeof(Vertex);
        UINT offset = 0;
        m_pContext->IASetVertexBuffers(0, 1, m_pVertexBuffer.GetAddressOf(), &stride, &offset);
        m_pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        m_pContext->Draw(count, 0);

        m_stats.drawCalls++;
        m_stats.vertexCount += count;
        m_stats.triangleCount += count / 3;
    }

    virtual void DrawIndexed(const Vertex* vertices, int vertexCount, 
                           const uint16_t* indices, int indexCount, ITexture* texture = nullptr) override {
        // 索引绘制实现
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
        // 带纹理的矩形绘制
    }

    virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color, float width = 1.0f) override {
        // 线条绘制
    }

    virtual void DrawText(const std::wstring& text, float x, float y, const Color& color, 
                         ITexture* fontTexture = nullptr) override {
        // 文本绘制
    }

    virtual std::shared_ptr<ITexture> CreateTexture() override {
        return std::make_shared<DX11Texture>();
    }

    virtual std::shared_ptr<ITexture> LoadTexture(const std::wstring& filename) override {
        auto texture = std::make_shared<DX11Texture>();
        if (texture->LoadFromFile(filename)) {
            return texture;
        }
        return nullptr;
    }

    virtual std::shared_ptr<IShader> CreateShader() override { return nullptr; }
    virtual std::shared_ptr<IShader> LoadShader(const std::wstring& filename) override { return nullptr; }

    virtual RendererType GetType() const override { return RendererType::DX11; }
    virtual RendererCapabilities GetCapabilities() const override {
        RendererCapabilities caps = {};
        caps.supportsMultisampling = true;
        caps.supportsHDR = true;
        caps.supportsComputeShaders = true;
        caps.supportsGeometryShaders = true;
        caps.supportsInstancing = true;
        caps.maxTextureSize = 16384;
        caps.maxRenderTargets = 8;
        caps.maxVertexAttributes = 32;
        caps.version = "DirectX 11";
        caps.deviceName = "DirectX 11 Device";
        return caps;
    }
    virtual RenderStats GetStats() const override { return m_stats; }
    virtual std::string GetName() const override { return "DirectX 11 Renderer"; }

    virtual void SetTransform(const float* matrix) override {}
    virtual void PushTransform() override {}
    virtual void PopTransform() override {}
    virtual void SetScissorRect(const Rectangle& rect) override {}
    virtual void DisableScissorRect() override {}

    virtual void SetDebugName(const std::string& name) override {}
    virtual void BeginDebugGroup(const std::string& name) override {}
    virtual void EndDebugGroup() override {}
    virtual void InsertDebugMarker(const std::string& name) override {}

    ID3D11Device* GetDevice() const { return m_pDevice.Get(); }
    ID3D11DeviceContext* GetContext() const { return m_pContext.Get(); }

private:
    bool CreateShaders() {
        // 简单的顶点着色器
        const char* vsSource = R"(
            struct VS_INPUT {
                float3 pos : POSITION;
                float2 tex : TEXCOORD;
                float4 color : COLOR;
            };
            struct VS_OUTPUT {
                float4 pos : SV_POSITION;
                float2 tex : TEXCOORD;
                float4 color : COLOR;
            };
            VS_OUTPUT main(VS_INPUT input) {
                VS_OUTPUT output;
                output.pos = float4(input.pos, 1.0f);
                output.tex = input.tex;
                output.color = input.color;
                return output;
            }
        )";

        // 简单的像素着色器
        const char* psSource = R"(
            struct PS_INPUT {
                float4 pos : SV_POSITION;
                float2 tex : TEXCOORD;
                float4 color : COLOR;
            };
            float4 main(PS_INPUT input) : SV_TARGET {
                return input.color;
            }
        )";

        ComPtr<ID3DBlob> vsBlob, psBlob;
        
        // 编译顶点着色器
        HRESULT hr = D3DCompile(vsSource, strlen(vsSource), nullptr, nullptr, nullptr,
                              "main", "vs_4_0", 0, 0, &vsBlob, nullptr);
        if (FAILED(hr)) return false;

        hr = m_pDevice->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &m_pVertexShader);
        if (FAILED(hr)) return false;

        // 编译像素着色器
        hr = D3DCompile(psSource, strlen(psSource), nullptr, nullptr, nullptr,
                      "main", "ps_4_0", 0, 0, &psBlob, nullptr);
        if (FAILED(hr)) return false;

        hr = m_pDevice->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &m_pPixelShader);
        if (FAILED(hr)) return false;

        // 创建输入布局
        D3D11_INPUT_ELEMENT_DESC layout[] = {
            {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
            {"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0},
            {"COLOR", 0, DXGI_FORMAT_R8G8B8A8_UNORM, 0, 20, D3D11_INPUT_PER_VERTEX_DATA, 0}
        };

        hr = m_pDevice->CreateInputLayout(layout, 3, vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), &m_pInputLayout);
        if (FAILED(hr)) return false;

        // 创建顶点缓冲
        D3D11_BUFFER_DESC bd = {};
        bd.Usage = D3D11_USAGE_DYNAMIC;
        bd.ByteWidth = sizeof(Vertex) * 10000; // 足够的缓冲区
        bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
        bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

        hr = m_pDevice->CreateBuffer(&bd, nullptr, &m_pVertexBuffer);
        if (FAILED(hr)) return false;

        // 设置着色器
        m_pContext->VSSetShader(m_pVertexShader.Get(), nullptr, 0);
        m_pContext->PSSetShader(m_pPixelShader.Get(), nullptr, 0);
        m_pContext->IASetInputLayout(m_pInputLayout.Get());

        return true;
    }

    void CreateStates() {
        // 创建混合状态
        D3D11_BLEND_DESC blendDesc = {};
        blendDesc.RenderTarget[0].BlendEnable = TRUE;
        blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
        blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
        blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
        blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
        blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
        blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
        blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

        m_pDevice->CreateBlendState(&blendDesc, &m_pBlendState);

        // 设置混合状态
        float blendFactor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
        m_pContext->OMSetBlendState(m_pBlendState.Get(), blendFactor, 0xFFFFFFFF);
    }
};

// DX11纹理的GetDevice和GetContext方法实现
DX11Renderer* g_pDX11Renderer = nullptr;

ID3D11Device* DX11Texture::GetDevice() {
    return g_pDX11Renderer ? g_pDX11Renderer->GetDevice() : nullptr;
}

ID3D11DeviceContext* DX11Texture::GetContext() {
    return g_pDX11Renderer ? g_pDX11Renderer->GetContext() : nullptr;
}

std::unique_ptr<IRenderer> CreateDX11Renderer() {
    auto renderer = std::make_unique<DX11Renderer>();
    g_pDX11Renderer = renderer.get();
    return std::move(renderer);
}

} // namespace XM 