# 1. Transition to D3DX11:
1. Refactor DirectX types and functions:
	- Added DirectXMath helper utilities to centralize XM load/store, transpose/inverse, and scaling operations for DX9 rendering code.
	- Updated DX9 SSAO constants/history matrices and rendering paths to use XMFLOAT/XMMatrix operations instead of D3DX math types and functions.
	- Migrated DX9 shadow setup math in OldRenderDX9 to DirectXMath matrix creation, multiply, and transpose helpers with XMFLOAT types.
2. Refactor ProbeMaster to use XMFLOAT:
	- Swapped probe vector storage to DirectX::XMFLOAT3/4 and added a packing assertion for shader compatibility.
	- Reworked probe math to use XMVector helpers for transforms and dot products in SH projection paths.
