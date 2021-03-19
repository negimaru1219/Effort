#pragma once

namespace Effort
{
	class Vector2;
	class Vector3;
	class Vector4;
	class Quaternion;
	class Matrix44;

	class Vector2 : public DirectX::XMFLOAT2
	{
	public:
		Vector2(float _x, float _y)
		{
			x = _x;
			y = _y;
		}
	};

	class Vector3 : public DirectX::XMFLOAT3 
	{

	};

	class Vector4 : public DirectX::XMFLOAT4
	{

	};

	class Quaternion : public DirectX::XMFLOAT4
	{

	};

	class Matrix44 : public DirectX::XMFLOAT4X4
	{

	};
}