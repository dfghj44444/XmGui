/**
 * @file VulkanRenderer.cpp
 * @brief Vulkan渲染器实现
 * @author Double One
 * @version 1.0.0
 * @date 2025-01-09
 */

#include "../include/XmGuiRenderer.h"

// 只有在启用Vulkan支持时才编译此文件
#if XMGUI_ENABLE_VULKAN

#ifdef _WIN32
    #define VK_USE_PLATFORM_WIN32_KHR
    #include <windows.h>
#endif

#include <vulkan/vulkan.h>
#include <vector>
#include <memory>
#include <stack>

namespace XM {

//=============================================================================
// Vulkan纹理实现
//=============================================================================
class VulkanTexture : public ITexture {
private:
    VkImage m_image;
    VkDeviceMemory m_imageMemory;
    VkImageView m_imageView;
    VkSampler m_sampler;
    int m_width, m_height;
    bool m_isValid;

public:
    VulkanTexture() : m_image(VK_NULL_HANDLE), m_imageMemory(VK_NULL_HANDLE), 
                      m_imageView(VK_NULL_HANDLE), m_sampler(VK_NULL_HANDLE),
                      m_width(0), m_height(0), m_isValid(false) {}

    virtual ~VulkanTexture() {
        // 清理Vulkan资源
        if (m_imageView != VK_NULL_HANDLE) {
            // vkDestroyImageView(device, m_imageView, nullptr);
        }
        if (m_image != VK_NULL_HANDLE) {
            // vkDestroyImage(device, m_image, nullptr);
        }
        if (m_imageMemory != VK_NULL_HANDLE) {
            // vkFreeMemory(device, m_imageMemory, nullptr);
        }
        if (m_sampler != VK_NULL_HANDLE) {
            // vkDestroySampler(device, m_sampler, nullptr);
        }
    }

    virtual int GetWidth() const override { return m_width; }
    virtual int GetHeight() const override { return m_height; }
    virtual bool IsValid() const override { return m_isValid; }

    virtual bool LoadFromFile(const std::wstring& filename) override {
        // Vulkan纹理加载需要复杂的设置
        // 这里提供简化的框架
        return false;
    }

    virtual bool LoadFromMemory(const void* data, size_t size) override {
        // Vulkan从内存加载纹理
        return false;
    }

    virtual bool CreateEmpty(int width, int height) override {
        // 创建空纹理
        m_width = width;
        m_height = height;
        m_isValid = true;
        return true;
    }

    virtual bool UpdateData(const void* data, int width, int height) override {
        // 更新纹理数据
        return false;
    }

    virtual void* Lock() override { return nullptr; }
    virtual void Unlock() override {}
    virtual void* GetNativeHandle() const override { return (void*)m_imageView; }
};

//=============================================================================
// Vulkan渲染器实现
//=============================================================================
class VulkanRenderer : public IRenderer {
private:
    VkInstance m_instance;
    VkPhysicalDevice m_physicalDevice;
    VkDevice m_device;
    VkQueue m_graphicsQueue;
    VkQueue m_presentQueue;
    VkSurfaceKHR m_surface;
    VkSwapchainKHR m_swapchain;
    
    std::vector<VkImage> m_swapchainImages;
    std::vector<VkImageView> m_swapchainImageViews;
    std::vector<VkFramebuffer> m_swapchainFramebuffers;
    
    VkRenderPass m_renderPass;
    VkPipelineLayout m_pipelineLayout;
    VkPipeline m_graphicsPipeline;
    
    VkCommandPool m_commandPool;
    VkCommandBuffer m_commandBuffer;
    
    VkSemaphore m_imageAvailableSemaphore;
    VkSemaphore m_renderFinishedSemaphore;
    VkFence m_inFlightFence;
    
    HWND m_hWnd;
    bool m_isInitialized;
    RenderState m_currentState;
    std::stack<RenderState> m_stateStack;
    Viewport m_viewport;
    mutable RenderStats m_stats;
    DWORD m_lastFrameTime;
    
    uint32_t m_currentImageIndex;

public:
    VulkanRenderer() : m_instance(VK_NULL_HANDLE), m_physicalDevice(VK_NULL_HANDLE),
                       m_device(VK_NULL_HANDLE), m_graphicsQueue(VK_NULL_HANDLE),
                       m_presentQueue(VK_NULL_HANDLE), m_surface(VK_NULL_HANDLE),
                       m_swapchain(VK_NULL_HANDLE), m_renderPass(VK_NULL_HANDLE),
                       m_pipelineLayout(VK_NULL_HANDLE), m_graphicsPipeline(VK_NULL_HANDLE),
                       m_commandPool(VK_NULL_HANDLE), m_commandBuffer(VK_NULL_HANDLE),
                       m_imageAvailableSemaphore(VK_NULL_HANDLE), m_renderFinishedSemaphore(VK_NULL_HANDLE),
                       m_inFlightFence(VK_NULL_HANDLE), m_hWnd(nullptr), m_isInitialized(false),
                       m_lastFrameTime(0), m_currentImageIndex(0) {}

    virtual ~VulkanRenderer() {
        Shutdown();
    }

    virtual bool Initialize(HWND hWnd, int width, int height, bool fullscreen = false) override {
        m_hWnd = hWnd;
        
        // 初始化Vulkan需要大量代码
        // 这里提供简化的框架
        
        // 1. 创建Vulkan实例
        if (!CreateInstance()) {
            return false;
        }
        
        // 2. 创建窗口表面
        if (!CreateSurface()) {
            return false;
        }
        
        // 3. 选择物理设备
        if (!PickPhysicalDevice()) {
            return false;
        }
        
        // 4. 创建逻辑设备
        if (!CreateLogicalDevice()) {
            return false;
        }
        
        // 5. 创建交换链
        if (!CreateSwapchain(width, height)) {
            return false;
        }
        
        // 6. 创建渲染通道
        if (!CreateRenderPass()) {
            return false;
        }
        
        // 7. 创建图形管线
        if (!CreateGraphicsPipeline()) {
            return false;
        }
        
        // 8. 创建帧缓冲
        if (!CreateFramebuffers()) {
            return false;
        }
        
        // 9. 创建命令缓冲
        if (!CreateCommandBuffers()) {
            return false;
        }
        
        // 10. 创建同步对象
        if (!CreateSyncObjects()) {
            return false;
        }
        
        m_viewport = Viewport(0, 0, width, height);
        m_isInitialized = true;
        
        return true;
    }

    virtual void Shutdown() override {
        if (m_device != VK_NULL_HANDLE) {
            vkDeviceWaitIdle(m_device);
            
            // 清理资源
            if (m_inFlightFence != VK_NULL_HANDLE) {
                vkDestroyFence(m_device, m_inFlightFence, nullptr);
            }
            if (m_renderFinishedSemaphore != VK_NULL_HANDLE) {
                vkDestroySemaphore(m_device, m_renderFinishedSemaphore, nullptr);
            }
            if (m_imageAvailableSemaphore != VK_NULL_HANDLE) {
                vkDestroySemaphore(m_device, m_imageAvailableSemaphore, nullptr);
            }
            if (m_commandPool != VK_NULL_HANDLE) {
                vkDestroyCommandPool(m_device, m_commandPool, nullptr);
            }
            
            for (auto framebuffer : m_swapchainFramebuffers) {
                vkDestroyFramebuffer(m_device, framebuffer, nullptr);
            }
            
            if (m_graphicsPipeline != VK_NULL_HANDLE) {
                vkDestroyPipeline(m_device, m_graphicsPipeline, nullptr);
            }
            if (m_pipelineLayout != VK_NULL_HANDLE) {
                vkDestroyPipelineLayout(m_device, m_pipelineLayout, nullptr);
            }
            if (m_renderPass != VK_NULL_HANDLE) {
                vkDestroyRenderPass(m_device, m_renderPass, nullptr);
            }
            
            for (auto imageView : m_swapchainImageViews) {
                vkDestroyImageView(m_device, imageView, nullptr);
            }
            
            if (m_swapchain != VK_NULL_HANDLE) {
                vkDestroySwapchainKHR(m_device, m_swapchain, nullptr);
            }
            
            vkDestroyDevice(m_device, nullptr);
        }
        
        if (m_surface != VK_NULL_HANDLE) {
            vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
        }
        
        if (m_instance != VK_NULL_HANDLE) {
            vkDestroyInstance(m_instance, nullptr);
        }
        
        m_isInitialized = false;
    }

    virtual bool IsInitialized() const override { return m_isInitialized; }

    virtual bool OnDeviceLost() override { return true; }
    virtual bool OnDeviceReset() override { return true; }
    virtual void OnResize(int width, int height) override {
        // Vulkan窗口大小改变处理
        vkDeviceWaitIdle(m_device);
        
        // 重建交换链
        CreateSwapchain(width, height);
        CreateFramebuffers();
        
        m_viewport.width = width;
        m_viewport.height = height;
    }

    virtual void BeginFrame() override {
        if (!m_isInitialized) return;
        
        m_stats.Reset();
        m_lastFrameTime = GetTickCount();
        
        // 等待上一帧完成
        vkWaitForFences(m_device, 1, &m_inFlightFence, VK_TRUE, UINT64_MAX);
        vkResetFences(m_device, 1, &m_inFlightFence);
        
        // 获取下一个图像
        vkAcquireNextImageKHR(m_device, m_swapchain, UINT64_MAX, 
                             m_imageAvailableSemaphore, VK_NULL_HANDLE, &m_currentImageIndex);
        
        // 重置命令缓冲
        vkResetCommandBuffer(m_commandBuffer, 0);
        
        // 开始记录命令
        VkCommandBufferBeginInfo beginInfo = {};
        beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        beginInfo.flags = 0;
        beginInfo.pInheritanceInfo = nullptr;
        
        vkBeginCommandBuffer(m_commandBuffer, &beginInfo);
    }

    virtual void EndFrame() override {
        if (!m_isInitialized) return;
        
        // 结束命令缓冲记录
        vkEndCommandBuffer(m_commandBuffer);
        
        // 更新统计信息
        DWORD currentTime = GetTickCount();
        m_stats.frameTime = (currentTime - m_lastFrameTime) / 1000.0f;
        m_stats.fps = m_stats.frameTime > 0 ? 1.0f / m_stats.frameTime : 0.0f;
        m_stats.frameCount++;
    }

    virtual void Present() override {
        if (!m_isInitialized) return;
        
        // 提交命令缓冲
        VkSubmitInfo submitInfo = {};
        submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        
        VkSemaphore waitSemaphores[] = {m_imageAvailableSemaphore};
        VkPipelineStageFlags waitStages[] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
        submitInfo.waitSemaphoreCount = 1;
        submitInfo.pWaitSemaphores = waitSemaphores;
        submitInfo.pWaitDstStageMask = waitStages;
        
        submitInfo.commandBufferCount = 1;
        submitInfo.pCommandBuffers = &m_commandBuffer;
        
        VkSemaphore signalSemaphores[] = {m_renderFinishedSemaphore};
        submitInfo.signalSemaphoreCount = 1;
        submitInfo.pSignalSemaphores = signalSemaphores;
        
        vkQueueSubmit(m_graphicsQueue, 1, &submitInfo, m_inFlightFence);
        
        // 呈现图像
        VkPresentInfoKHR presentInfo = {};
        presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
        presentInfo.waitSemaphoreCount = 1;
        presentInfo.pWaitSemaphores = signalSemaphores;
        
        VkSwapchainKHR swapchains[] = {m_swapchain};
        presentInfo.swapchainCount = 1;
        presentInfo.pSwapchains = swapchains;
        presentInfo.pImageIndices = &m_currentImageIndex;
        presentInfo.pResults = nullptr;
        
        vkQueuePresentKHR(m_presentQueue, &presentInfo);
    }

    virtual void Clear(const Color& color) override {
        if (!m_isInitialized) return;
        
        VkRenderPassBeginInfo renderPassInfo = {};
        renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        renderPassInfo.renderPass = m_renderPass;
        renderPassInfo.framebuffer = m_swapchainFramebuffers[m_currentImageIndex];
        renderPassInfo.renderArea.offset = {0, 0};
        renderPassInfo.renderArea.extent = {(uint32_t)m_viewport.width, (uint32_t)m_viewport.height};
        
        VkClearValue clearColor = {{{color.r, color.g, color.b, color.a}}};
        renderPassInfo.clearValueCount = 1;
        renderPassInfo.pClearValues = &clearColor;
        
        vkCmdBeginRenderPass(m_commandBuffer, &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);
    }

    virtual void SetViewport(const Viewport& viewport) override {
        m_viewport = viewport;
        
        if (m_commandBuffer != VK_NULL_HANDLE) {
            VkViewport vkViewport = {};
            vkViewport.x = (float)viewport.x;
            vkViewport.y = (float)viewport.y;
            vkViewport.width = (float)viewport.width;
            vkViewport.height = (float)viewport.height;
            vkViewport.minDepth = viewport.minDepth;
            vkViewport.maxDepth = viewport.maxDepth;
            
            vkCmdSetViewport(m_commandBuffer, 0, 1, &vkViewport);
        }
    }

    virtual Viewport GetViewport() const override { return m_viewport; }

    virtual void SetRenderState(const RenderState& state) override {
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

    // 简化的绘制函数
    virtual void DrawVertices(const Vertex* vertices, int count, ITexture* texture = nullptr) override {
        if (!m_isInitialized || !vertices || count == 0) return;
        
        // Vulkan绘制需要顶点缓冲等复杂设置
        // 这里只是占位实现
        m_stats.drawCalls++;
        m_stats.vertexCount += count;
        m_stats.triangleCount += count / 3;
    }

    virtual void DrawIndexed(const Vertex* vertices, int vertexCount, 
                           const uint16_t* indices, int indexCount, ITexture* texture = nullptr) override {
        // 索引绘制实现
    }

    virtual void DrawRectangle(const Rectangle& rect, const Color& color) override {
        // 矩形绘制实现
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
        return std::make_shared<VulkanTexture>();
    }

    virtual std::shared_ptr<ITexture> LoadTexture(const std::wstring& filename) override {
        auto texture = std::make_shared<VulkanTexture>();
        if (texture->LoadFromFile(filename)) {
            return texture;
        }
        return nullptr;
    }

    virtual std::shared_ptr<IShader> CreateShader() override { return nullptr; }
    virtual std::shared_ptr<IShader> LoadShader(const std::wstring& filename) override { return nullptr; }

    virtual RendererType GetType() const override { return RendererType::Vulkan; }
    virtual RendererCapabilities GetCapabilities() const override {
        RendererCapabilities caps = {};
        caps.supportsMultisampling = true;
        caps.supportsHDR = true;
        caps.supportsComputeShaders = true;
        caps.supportsGeometryShaders = true;
        caps.supportsInstancing = true;
        caps.maxTextureSize = 32768;
        caps.maxRenderTargets = 16;
        caps.maxVertexAttributes = 64;
        caps.version = "Vulkan 1.0";
        caps.deviceName = "Vulkan Device";
        return caps;
    }
    virtual RenderStats GetStats() const override { return m_stats; }
    virtual std::string GetName() const override { return "Vulkan Renderer"; }

    virtual void SetTransform(const float* matrix) override {}
    virtual void PushTransform() override {}
    virtual void PopTransform() override {}
    virtual void SetScissorRect(const Rectangle& rect) override {}
    virtual void DisableScissorRect() override {}

    virtual void SetDebugName(const std::string& name) override {}
    virtual void BeginDebugGroup(const std::string& name) override {}
    virtual void EndDebugGroup() override {}
    virtual void InsertDebugMarker(const std::string& name) override {}

private:
    bool CreateInstance() {
        // 创建Vulkan实例的简化实现
        VkApplicationInfo appInfo = {};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "XmGui";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "XmGui Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        // 启用必要的扩展
        std::vector<const char*> extensions = {
            VK_KHR_SURFACE_EXTENSION_NAME,
#ifdef _WIN32
            VK_KHR_WIN32_SURFACE_EXTENSION_NAME
#endif
        };

        createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
        createInfo.ppEnabledExtensionNames = extensions.data();
        createInfo.enabledLayerCount = 0;

        VkResult result = vkCreateInstance(&createInfo, nullptr, &m_instance);
        return result == VK_SUCCESS;
    }

    bool CreateSurface() {
#ifdef _WIN32
        VkWin32SurfaceCreateInfoKHR createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
        createInfo.hwnd = m_hWnd;
        createInfo.hinstance = GetModuleHandle(nullptr);

        VkResult result = vkCreateWin32SurfaceKHR(m_instance, &createInfo, nullptr, &m_surface);
        return result == VK_SUCCESS;
#else
        return false;
#endif
    }

    bool PickPhysicalDevice() {
        uint32_t deviceCount = 0;
        vkEnumeratePhysicalDevices(m_instance, &deviceCount, nullptr);

        if (deviceCount == 0) {
            return false;
        }

        std::vector<VkPhysicalDevice> devices(deviceCount);
        vkEnumeratePhysicalDevices(m_instance, &deviceCount, devices.data());

        // 选择第一个可用的设备
        for (const auto& device : devices) {
            if (IsDeviceSuitable(device)) {
                m_physicalDevice = device;
                break;
            }
        }

        return m_physicalDevice != VK_NULL_HANDLE;
    }

    bool IsDeviceSuitable(VkPhysicalDevice device) {
        // 简化的设备适用性检查
        return true;
    }

    bool CreateLogicalDevice() {
        // 简化的逻辑设备创建
        VkDeviceQueueCreateInfo queueCreateInfo = {};
        queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo.queueFamilyIndex = 0; // 简化假设
        queueCreateInfo.queueCount = 1;

        float queuePriority = 1.0f;
        queueCreateInfo.pQueuePriorities = &queuePriority;

        VkPhysicalDeviceFeatures deviceFeatures = {};

        VkDeviceCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        createInfo.pQueueCreateInfos = &queueCreateInfo;
        createInfo.queueCreateInfoCount = 1;
        createInfo.pEnabledFeatures = &deviceFeatures;

        std::vector<const char*> deviceExtensions = {
            VK_KHR_SWAPCHAIN_EXTENSION_NAME
        };

        createInfo.enabledExtensionCount = static_cast<uint32_t>(deviceExtensions.size());
        createInfo.ppEnabledExtensionNames = deviceExtensions.data();

        VkResult result = vkCreateDevice(m_physicalDevice, &createInfo, nullptr, &m_device);
        if (result == VK_SUCCESS) {
            vkGetDeviceQueue(m_device, 0, 0, &m_graphicsQueue);
            vkGetDeviceQueue(m_device, 0, 0, &m_presentQueue);
            return true;
        }
        return false;
    }

    bool CreateSwapchain(int width, int height) {
        // 简化的交换链创建
        VkSwapchainCreateInfoKHR createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
        createInfo.surface = m_surface;
        createInfo.minImageCount = 2;
        createInfo.imageFormat = VK_FORMAT_B8G8R8A8_UNORM;
        createInfo.imageColorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
        createInfo.imageExtent = {static_cast<uint32_t>(width), static_cast<uint32_t>(height)};
        createInfo.imageArrayLayers = 1;
        createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
        createInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
        createInfo.preTransform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
        createInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
        createInfo.presentMode = VK_PRESENT_MODE_FIFO_KHR;
        createInfo.clipped = VK_TRUE;
        createInfo.oldSwapchain = VK_NULL_HANDLE;

        VkResult result = vkCreateSwapchainKHR(m_device, &createInfo, nullptr, &m_swapchain);
        if (result != VK_SUCCESS) {
            return false;
        }

        // 获取交换链图像
        uint32_t imageCount;
        vkGetSwapchainImagesKHR(m_device, m_swapchain, &imageCount, nullptr);
        m_swapchainImages.resize(imageCount);
        vkGetSwapchainImagesKHR(m_device, m_swapchain, &imageCount, m_swapchainImages.data());

        // 创建图像视图
        m_swapchainImageViews.resize(m_swapchainImages.size());
        for (size_t i = 0; i < m_swapchainImages.size(); i++) {
            VkImageViewCreateInfo viewInfo = {};
            viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
            viewInfo.image = m_swapchainImages[i];
            viewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
            viewInfo.format = VK_FORMAT_B8G8R8A8_UNORM;
            viewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
            viewInfo.subresourceRange.baseMipLevel = 0;
            viewInfo.subresourceRange.levelCount = 1;
            viewInfo.subresourceRange.baseArrayLayer = 0;
            viewInfo.subresourceRange.layerCount = 1;

            vkCreateImageView(m_device, &viewInfo, nullptr, &m_swapchainImageViews[i]);
        }

        return true;
    }

    bool CreateRenderPass() {
        // 简化的渲染通道创建
        VkAttachmentDescription colorAttachment = {};
        colorAttachment.format = VK_FORMAT_B8G8R8A8_UNORM;
        colorAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
        colorAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
        colorAttachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
        colorAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
        colorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
        colorAttachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        colorAttachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

        VkAttachmentReference colorAttachmentRef = {};
        colorAttachmentRef.attachment = 0;
        colorAttachmentRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

        VkSubpassDescription subpass = {};
        subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
        subpass.colorAttachmentCount = 1;
        subpass.pColorAttachments = &colorAttachmentRef;

        VkRenderPassCreateInfo renderPassInfo = {};
        renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
        renderPassInfo.attachmentCount = 1;
        renderPassInfo.pAttachments = &colorAttachment;
        renderPassInfo.subpassCount = 1;
        renderPassInfo.pSubpasses = &subpass;

        VkResult result = vkCreateRenderPass(m_device, &renderPassInfo, nullptr, &m_renderPass);
        return result == VK_SUCCESS;
    }

    bool CreateGraphicsPipeline() {
        // 简化的图形管线创建
        VkPipelineLayoutCreateInfo pipelineLayoutInfo = {};
        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount = 0;
        pipelineLayoutInfo.pushConstantRangeCount = 0;

        VkResult result = vkCreatePipelineLayout(m_device, &pipelineLayoutInfo, nullptr, &m_pipelineLayout);
        return result == VK_SUCCESS;
    }

    bool CreateFramebuffers() {
        // 创建帧缓冲
        m_swapchainFramebuffers.resize(m_swapchainImageViews.size());

        for (size_t i = 0; i < m_swapchainImageViews.size(); i++) {
            VkImageView attachments[] = {
                m_swapchainImageViews[i]
            };

            VkFramebufferCreateInfo framebufferInfo = {};
            framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
            framebufferInfo.renderPass = m_renderPass;
            framebufferInfo.attachmentCount = 1;
            framebufferInfo.pAttachments = attachments;
            framebufferInfo.width = m_viewport.width;
            framebufferInfo.height = m_viewport.height;
            framebufferInfo.layers = 1;

            vkCreateFramebuffer(m_device, &framebufferInfo, nullptr, &m_swapchainFramebuffers[i]);
        }
        return true;
    }

    bool CreateCommandBuffers() {
        // 创建命令池
        VkCommandPoolCreateInfo poolInfo = {};
        poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        poolInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
        poolInfo.queueFamilyIndex = 0;

        VkResult result = vkCreateCommandPool(m_device, &poolInfo, nullptr, &m_commandPool);
        if (result != VK_SUCCESS) {
            return false;
        }

        // 创建命令缓冲
        VkCommandBufferAllocateInfo allocInfo = {};
        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.commandPool = m_commandPool;
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandBufferCount = 1;

        result = vkAllocateCommandBuffers(m_device, &allocInfo, &m_commandBuffer);
        return result == VK_SUCCESS;
    }

    bool CreateSyncObjects() {
        // 创建同步对象
        VkSemaphoreCreateInfo semaphoreInfo = {};
        semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

        VkFenceCreateInfo fenceInfo = {};
        fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

        VkResult result = vkCreateSemaphore(m_device, &semaphoreInfo, nullptr, &m_imageAvailableSemaphore);
        if (result != VK_SUCCESS) return false;

        result = vkCreateSemaphore(m_device, &semaphoreInfo, nullptr, &m_renderFinishedSemaphore);
        if (result != VK_SUCCESS) return false;

        result = vkCreateFence(m_device, &fenceInfo, nullptr, &m_inFlightFence);
        return result == VK_SUCCESS;
    }
};

VulkanRenderer* g_pVulkanRenderer = nullptr;

std::unique_ptr<IRenderer> CreateVulkanRenderer() {
    auto renderer = std::make_unique<VulkanRenderer>();
    g_pVulkanRenderer = renderer.get();
    return std::move(renderer);
}

} // namespace XM

#endif // XMGUI_ENABLE_VULKAN 