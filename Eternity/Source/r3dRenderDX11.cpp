#include "r3dPCH.h"
#include "r3d.h"

#if defined(R3D_USE_DX11)
#include "r3dRenderDX11.h"

r3dDX11RenderLayer::r3dDX11RenderLayer()
: initialized_( false )
, hWindow_( NULL )
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
	initialized_ = true;
	return TRUE;
}

void r3dDX11RenderLayer::Close()
{
	initialized_ = false;
	hWindow_ = NULL;
}

void r3dDX11RenderLayer::Resize( int XRes, int YRes, int BPP, int Flags )
{
	R3D_UNUSED( XRes );
	R3D_UNUSED( YRes );
	R3D_UNUSED( BPP );
	R3D_UNUSED( Flags );
}

bool r3dDX11RenderLayer::IsInitialized() const
{
	return initialized_;
}

#endif // defined(R3D_USE_DX11)