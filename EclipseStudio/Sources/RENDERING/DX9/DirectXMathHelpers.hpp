#pragma once

#include <DirectXMath.h>

namespace r3dDX9
{
	inline DirectX::XMMATRIX ToXM(const DirectX::XMFLOAT4X4& matrix)
	{
		return DirectX::XMLoadFloat4x4(&matrix);
	}

	template <typename T>
	inline DirectX::XMMATRIX ToXMMatrix(const T& matrix)
	{
		return DirectX::XMLoadFloat4x4(reinterpret_cast<const DirectX::XMFLOAT4X4*>(&matrix));
	}

	inline void StoreMatrix(DirectX::XMFLOAT4X4* out, DirectX::CXMMATRIX matrix)
	{
		DirectX::XMStoreFloat4x4(out, matrix);
	}

	inline DirectX::XMFLOAT4X4 IdentityMatrix()
	{
		DirectX::XMFLOAT4X4 out;
		DirectX::XMStoreFloat4x4(&out, DirectX::XMMatrixIdentity());
		return out;
	}

	inline DirectX::XMFLOAT4X4 Multiply(const DirectX::XMFLOAT4X4& a, const DirectX::XMFLOAT4X4& b)
	{
		DirectX::XMFLOAT4X4 out;
		DirectX::XMStoreFloat4x4(&out, DirectX::XMMatrixMultiply(ToXM(a), ToXM(b)));
		return out;
	}

	inline DirectX::XMFLOAT4X4 Transpose(const DirectX::XMFLOAT4X4& matrix)
	{
		DirectX::XMFLOAT4X4 out;
		DirectX::XMStoreFloat4x4(&out, DirectX::XMMatrixTranspose(ToXM(matrix)));
		return out;
	}

	inline DirectX::XMFLOAT4X4 Inverse(const DirectX::XMFLOAT4X4& matrix)
	{
		DirectX::XMFLOAT4X4 out;
		DirectX::XMVECTOR det;
		DirectX::XMStoreFloat4x4(&out, DirectX::XMMatrixInverse(&det, ToXM(matrix)));
		return out;
	}

	inline DirectX::XMFLOAT3 Normalize(const DirectX::XMFLOAT3& v)
	{
		DirectX::XMFLOAT3 out;
		DirectX::XMStoreFloat3(&out, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(&v)));
		return out;
	}

	inline DirectX::XMFLOAT4 Transform(const DirectX::XMFLOAT4& v, const DirectX::XMFLOAT4X4& m)
	{
		DirectX::XMFLOAT4 out;
		DirectX::XMStoreFloat4(&out, DirectX::XMVector4Transform(DirectX::XMLoadFloat4(&v), ToXM(m)));
		return out;
	}

	inline void Scale(DirectX::XMFLOAT4* v, float scale)
	{
		v->x *= scale;
		v->y *= scale;
		v->z *= scale;
		v->w *= scale;
	}
}