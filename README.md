# 1. Transition to D3DX11:
1. Refactor DirectX types and functions:
	- Added DirectXMath helper utilities to centralize XM load/store, transpose/inverse, and scaling operations for DX9 rendering code.
	- Updated DX9 SSAO constants/history matrices and rendering paths to use XMFLOAT/XMMatrix operations instead of D3DX math types and functions.
	- Migrated DX9 shadow setup math in OldRenderDX9 to DirectXMath matrix creation, multiply, and transpose helpers with XMFLOAT types.
2. Refactor ProbeMaster to use XMFLOAT:
	- Swapped probe vector storage to DirectX::XMFLOAT3/4 and added a packing assertion for shader compatibility.
	- Reworked probe math to use XMVector helpers for transforms and dot products in SH projection paths.
2. Refactor ProbeMaster to use XMFLOAT:
	- Swapped probe vector storage to DirectX::XMFLOAT3/4 and added a packing assertion for shader compatibility.
	- Reworked probe math to use XMVector helpers for transforms and dot products in SH projection paths.
3. Define common matrix/vector type for rendering:
	- Defined shared render matrix/vector types and renderer helpers for shader-matrix conversion to keep layouts consistent across render paths.
	- Updated SSAO/temporal history constants to use unified render vector/matrix types and renderer conversion wrappers for transposed/inverted matrices.
	- Switched DX9 depth effect shader constants to the unified types and renderer matrix transpose helper before shader submission.
4. Update D3D types to DirectX equivalents:
	- Switched camera motion blur matrices to DirectXMath XMFLOAT4X4 storage and updated shader constant setup to use XMFLOAT4 for camera scale values.
	- Reworked the motion matrix calculation to use DirectXMath operations while keeping the explicit transpose before shader upload for MotionBlur matrix order expectations.
	- Updated glow extraction shader constants to use DirectXMath vectors and XMFLOAT4 storage before uploading to the shader.
