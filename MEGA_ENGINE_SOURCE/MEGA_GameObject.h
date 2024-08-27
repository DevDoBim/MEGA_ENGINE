#pragma once
#include "CommonInclude.h"

namespace MEGA
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

	public:
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	public:
		int GetPostionX() { return _x; }
		int GetPostionY() { return _y; }

	private:
		float _x;
		float _y;
	};
}

