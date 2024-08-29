#include "MEGA_GameObject.h"
#include "MEGA_Input.h"

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
		if (Input::GetKey(e_KeyCode::A) || Input::GetKey(e_KeyCode::Left))
		{
			_x -= 0.01f;
		}

		if (Input::GetKey(e_KeyCode::D) || Input::GetKey(e_KeyCode::Right))
		{
			_x += 0.01f;
		}

		if (Input::GetKey(e_KeyCode::W) || Input::GetKey(e_KeyCode::Up))
		{
			_y -= 0.01f;
		}

		if (Input::GetKey(e_KeyCode::S) || Input::GetKey(e_KeyCode::Down))
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
