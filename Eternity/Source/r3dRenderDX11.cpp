#include "r3dPCH.h"
#include "r3d.h"

#if defined(R3D_USE_DX11)
#include "r3dRenderDX11.h"

r3dDX11RenderLayer::r3dDX11RenderLayer()
: initialized_( false )
, hWindow_( NULL )
, deviceContext_( NULL )
, swapChain_( NULL )
, backBufferRTV_( NULL )
, depthStencilView_( NULL )
, backBufferWidth_( 0 )
, backBufferHeight_( 0 )
{
}

r3dDX11RenderLayer::~r3dDX11RenderLayer()
{
}

int r3dDX11RenderLayer::Init( HWND hWindow, int XRes, int YRes, int BPP, int Flags )
{
	R3D_UNUSED( XRes );
	R3D_UNUSED( YRes );
	R3D_UNUSED( BPP );
	R3D_UNUSED( Flags );

	hWindow_ = hWindow;
	backBufferWidth_ = XRes;
	backBufferHeight_ = YRes;
	initialized_ = true;
	return TRUE;
}

void r3dDX11RenderLayer::Close()
{
	initialized_ = false;
	hWindow_ = NULL;
	deviceContext_ = NULL;
	swapChain_ = NULL;
	backBufferRTV_ = NULL;
	depthStencilView_ = NULL;
	backBufferWidth_ = 0;
	backBufferHeight_ = 0;
}

void r3dDX11RenderLayer::Resize( int XRes, int YRes, int BPP, int Flags )
{
	R3D_UNUSED( XRes );
	R3D_UNUSED( YRes );
	R3D_UNUSED( BPP );
	R3D_UNUSED( Flags );
	
	backBufferWidth_ = XRes;
	backBufferHeight_ = YRes;
}

bool r3dDX11RenderLayer::IsInitialized() const
{
	return initialized_;
}

void r3dDX11RenderLayer::SetDeviceContext( ID3D11DeviceContext* context )
{
	deviceContext_ = context;
}

void r3dDX11RenderLayer::SetSwapChain( IDXGISwapChain* swapChain )
{
	swapChain_ = swapChain;
}

void r3dDX11RenderLayer::SetBackBufferViews( ID3D11RenderTargetView* renderTargetView, ID3D11DepthStencilView* depthStencilView )
{
	backBufferRTV_ = renderTargetView;
	depthStencilView_ = depthStencilView;
}

ID3D11DeviceContext* r3dDX11RenderLayer::GetDeviceContext() const
{
	return deviceContext_;
}

IDXGISwapChain* r3dDX11RenderLayer::GetSwapChain() const
{
	return swapChain_;
}

ID3D11RenderTargetView* r3dDX11RenderLayer::GetBackBufferRTV() const
{
	return backBufferRTV_;
}

ID3D11DepthStencilView* r3dDX11RenderLayer::GetDepthStencilView() const
{
	return depthStencilView_;
}

int r3dDX11RenderLayer::GetBackBufferWidth() const
{
	return backBufferWidth_;
}

int r3dDX11RenderLayer::GetBackBufferHeight() const
{
	return backBufferHeight_;
}

#endif // defined(R3D_USE_DX11)