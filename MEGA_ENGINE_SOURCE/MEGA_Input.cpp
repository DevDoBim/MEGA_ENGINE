#include "MEGA_Input.h"

namespace MEGA
{
	std::vector<Input::Key> Input::_keys = {};

	int ASCII[static_cast<UINT>(e_KeyCode::End)] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Initailize()
	{
		// Key 초기화
		_keys.reserve(static_cast<UINT>(e_KeyCode::End));

		for (size_t i = 0; i < static_cast<UINT>(e_KeyCode::End); i++)
		{
			Key key = {};
			key.keyCode = static_cast<e_KeyCode>(i);
			key.state = e_KeyState::None;
			key.bPressed = false;

			_keys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < static_cast<UINT>(e_KeyCode::End); i++)
		{
			// 키 입력 True
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (_keys[i].bPressed)
				{
					_keys[i].state = e_KeyState::Pressed;
				}
				else
				{
					_keys[i].state = e_KeyState::Down;
				}
				_keys[i].bPressed = true;
			}
			// 키 입력 False
			else
			{
				if (_keys[i].bPressed)
				{
					_keys[i].state = e_KeyState::Up;
				}
				else
				{
					_keys[i].state = e_KeyState::None;
				}
				_keys[i].bPressed = false;
			}
		}
	}

}