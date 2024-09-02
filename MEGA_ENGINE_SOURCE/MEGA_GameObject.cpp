#include "MEGA_GameObject.h"
#include "MEGA_Input.h"
#include "MEGA_Time.h"

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
			_x -= _speed * Time::DeltaTime();
		}

		if (Input::GetKey(e_KeyCode::D) || Input::GetKey(e_KeyCode::Right))
		{
			_x += _speed * Time::DeltaTime();
		}

		if (Input::GetKey(e_KeyCode::W) || Input::GetKey(e_KeyCode::Up))
		{
			_y -= _speed * Time::DeltaTime();
		}

		if (Input::GetKey(e_KeyCode::S) || Input::GetKey(e_KeyCode::Down))
		{
			_y += _speed * Time::DeltaTime();
		}

	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc) 
	{
		HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, brush);

		Ellipse(hdc, _x, _y, 100 + _x, 100 + _y);
		SelectObject(hdc, defaultBrush);
		DeleteObject(brush);
	}
}
