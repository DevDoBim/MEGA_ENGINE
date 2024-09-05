#pragma once

namespace MEGA::math
{
	struct Vector2
	{
	public:
		Vector2(): _x(0.0f), _y(0.0f) {};
		Vector2(float x, float y): _x(x), _y(y) {};
		~Vector2() = default;

	public:
		float _x;
		float _y;

		
	};
}

