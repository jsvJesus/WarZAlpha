#pragma once

#if defined(R3D_USE_DX11)

#include <windows.h>

struct ID3D11DeviceContext;
struct ID3D11RenderTargetView;
struct ID3D11DepthStencilView;
struct IDXGISwapChain;

class r3dDX11RenderLayer
{
public:
	r3dDX11RenderLayer();
	~r3dDX11RenderLayer();

	int Init( HWND hWindow, int XRes, int YRes, int BPP, int Flags );
	void Close();
	void Resize( int XRes, int YRes, int BPP, int Flags );
	bool IsInitialized() const;
	
	void SetDeviceContext( ID3D11DeviceContext* context );
	void SetSwapChain( IDXGISwapChain* swapChain );
	void SetBackBufferViews( ID3D11RenderTargetView* renderTargetView, ID3D11DepthStencilView* depthStencilView );
	
	ID3D11DeviceContext* GetDeviceContext() const;
	IDXGISwapChain* GetSwapChain() const;
	ID3D11RenderTargetView* GetBackBufferRTV() const;
	ID3D11DepthStencilView* GetDepthStencilView() const;
	int GetBackBufferWidth() const;
	int GetBackBufferHeight() const;

private:
	bool initialized_;
	HWND hWindow_;
	ID3D11DeviceContext* deviceContext_;
	IDXGISwapChain* swapChain_;
	ID3D11RenderTargetView* backBufferRTV_;
	ID3D11DepthStencilView* depthStencilView_;
	int backBufferWidth_;
	int backBufferHeight_;
};

#endif // defined(R3D_USE_DX11)