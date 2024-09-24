#include "MEGA_Input.h"
#include "MEGA_APP.h"

extern MEGA::APP application;

namespace MEGA
{
	std::vector<Input::Key> Input::keys = {};
	math::Vector2 Input::mousePosition = math::Vector2::one;

	int ASCII[keyCounts] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		VK_LBUTTON,VK_RBUTTON
	};

	void Input::Initailize()
	{
		CreateKey();
	}

	void Input::Update()
	{
		UpdateKey();
	}

	

	void Input::CreateKey()
	{
		// Key 초기화
		keys.reserve(keyCounts);

		for (size_t i = 0; i < keyCounts; i++)
		{
			Key key = {};
			key.keyCode = static_cast<e_KeyCode>(i);
			key.state = e_KeyState::None;
			key.bPressed = false;

			keys.push_back(key);
		}
	}

	void Input::UpdateKey()
	{
		if (GetFocus())
		{
			PressKey();
			SetMousePosition();
		}
		else
		{
			KeyClear();
		}

	}

	void Input::PressKey()
	{
		for (size_t i = 0; i < keyCounts; i++)
		{
			// 키 입력 True
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (keys[i].bPressed)
				{
					keys[i].state = e_KeyState::Pressed;
				}
				else
				{
					keys[i].state = e_KeyState::Down;
				}
				keys[i].bPressed = true;
			}
			// 키 입력 False
			else
			{
				if (keys[i].bPressed)
				{
					keys[i].state = e_KeyState::Up;
				}
				else
				{
					keys[i].state = e_KeyState::None;
				}
				keys[i].bPressed = false;
			}
		}
	}

	void Input::SetMousePosition()
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);

		ClientToScreen(application.GetHWND(), &mousePos);

		mousePosition._x = mousePos.x;
		mousePosition._y = mousePos.y;
	}

	void Input::KeyClear()
	{
		for (Key& key : keys)
		{
			if (key.state == e_KeyState::Down || key.state == e_KeyState::Pressed)
			{
				key.state = e_KeyState::Up;
			}
			else if (key.state == e_KeyState::Up)
			{
				key.state = e_KeyState::None;
			}
		}
	}

}