#include "MEGA_GameObject.h"

namespace MEGA
{
	GameObject::GameObject() :
		_x(0.0f), _y(0.0f)
	{
	}
	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			_x -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			_x += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			_y -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			_y += 0.01f;
		}

	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc) 
	{
		Rectangle(hdc, 100 + _x, 100 + _y, 200 + _x, 200 + _y);
	}
}
