#pragma once

#include "d3dx12.h"
#include "d3dx12widget.h"
#include <private/qwidget_p.h>



class D3DX12WidgetPrivate final : public QWidgetPrivate
{
    Q_DECLARE_PUBLIC(D3DX12Widget)

public:
    explicit D3DX12WidgetPrivate(D3DX12Widget *parent);
    ~D3DX12WidgetPrivate();

private:
    // Init DirectX12 3D.
    void Initialize();

    // DirectX12 3D Render.
    void Render();

    // Helper function for resolving the full path of assets.
    QString GetAssetFullPath(const QString& assetName) const { return m_assetsPath + assetName; }

    // Helper function for acquiring the first available hardware adapter that supports Direct3D 12.
    // If no such adapter can be found, *ppAdapter will be set to nullptr.
    void GetHardwareAdapter(_In_ IDXGIFactory1* pFactory, _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter, bool requestHighPerformanceAdapter = false);

    // Specific initialization process.
    D3DX12WidgetPrivate* InitViewport();
    D3DX12WidgetPrivate* LoadPipeline();
    D3DX12WidgetPrivate* LoadAssets();

    // Specific render process.
    D3DX12WidgetPrivate* OnUpdate();
    D3DX12WidgetPrivate* OnRender();

    // Record all the commands we need to render the scene into the command list.
    D3DX12WidgetPrivate* PopulateCommandList();

    // WAITING FOR THE FRAME TO COMPLETE BEFORE CONTINUING IS NOT BEST PRACTICE.
    D3DX12WidgetPrivate* WaitForPreviousFrame();

    // Viewport aspect ratio.
    float m_aspectRatio;

    // TODO: Now it is false.
    bool m_useWarpDevice;

    // Root assets path.
    QString m_assetsPath;

    // Total frame number of swap chain.
    static const UINT FrameCount = 2;

    // TODO
    struct Vertex
    {
        XMFLOAT3 position;
        XMFLOAT4 color;
    };

    // Pipeline objects.
    CD3DX12_VIEWPORT m_viewport;
    CD3DX12_RECT m_scissorRect;
    ComPtr<IDXGISwapChain3> m_swapChain;
    ComPtr<ID3D12Device> m_device;
    ComPtr<ID3D12Resource> m_renderTargets[FrameCount];
    ComPtr<ID3D12CommandAllocator> m_commandAllocator;
    ComPtr<ID3D12CommandQueue> m_commandQueue;
    ComPtr<ID3D12RootSignature> m_rootSignature;
    ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
    ComPtr<ID3D12PipelineState> m_pipelineState;
    ComPtr<ID3D12GraphicsCommandList> m_commandList;
    UINT m_rtvDescriptorSize;

    // App resources.
    ComPtr<ID3D12Resource> m_vertexBuffer;
    D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;

    // Synchronization objects.
    UINT m_frameIndex;
    HANDLE m_fenceEvent;
    ComPtr<ID3D12Fence> m_fence;
    UINT64 m_fenceValue;
};

