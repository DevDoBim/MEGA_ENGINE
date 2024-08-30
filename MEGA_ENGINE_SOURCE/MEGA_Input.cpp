#include "MEGA_Input.h"

namespace MEGA
{
	std::vector<Input::Key> Input::keys = {};

	int ASCII[keyCounts] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
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

}