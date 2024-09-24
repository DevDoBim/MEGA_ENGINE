#pragma once
#include "CommonInclude.h"

namespace MEGA
{
	enum class e_KeyState
	{
		Down,
		Pressed,
		Up,
		None,
		End
	};

	enum class e_KeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		LButton, RButton,
		End
	};

	constexpr int keyCounts = static_cast<UINT>(e_KeyCode::End);

	class Input
	{
	public:
		struct Key
		{
			e_KeyCode keyCode;
			e_KeyState state;
			bool bPressed;
		};

	public:
		static void Initailize();
		static void Update();

	public:
		static bool GetKeyDown(e_KeyCode code) { return keys[static_cast<UINT>(code)].state == e_KeyState::Down; }
		static bool GetKeyUp(e_KeyCode code) { return keys[static_cast<UINT>(code)].state == e_KeyState::Up; }
		static bool GetKey(e_KeyCode code) { return keys[static_cast<UINT>(code)].state == e_KeyState::Pressed; }
		static math::Vector2 GetMosuePosition() { return mousePosition; }

	private:
		Input() = default;
		~Input() = default;

	private:
		static void CreateKey();
		static void UpdateKey();
		static void PressKey();
		static void SetMousePosition();
		static void KeyClear();

	private:
		static std::vector<Key> keys;
		static math::Vector2 mousePosition;
	};
}


