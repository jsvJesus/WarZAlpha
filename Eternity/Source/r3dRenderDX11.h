#pragma once

#if defined(R3D_USE_DX11)

#include <windows.h>

class r3dDX11RenderLayer
{
public:
	r3dDX11RenderLayer();
	~r3dDX11RenderLayer();

	int Init( HWND hWindow, int XRes, int YRes, int BPP, int Flags );
	void Close();
	void Resize( int XRes, int YRes, int BPP, int Flags );
	bool IsInitialized() const;

private:
	bool initialized_;
	HWND hWindow_;
};

#endif // defined(R3D_USE_DX11)