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
		End
	};

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
		Input() = default;
		~Input() = default;

	public:
		static void Initailize();
		static void Update();


	public:
		void CreateKey();
		void 
		static bool GetKeyDown(e_KeyCode code) { return _keys[static_cast<UINT>(code)].state == e_KeyState::Down; }
		static bool GetKeyUp(e_KeyCode code) { return _keys[static_cast<UINT>(code)].state == e_KeyState::Up; }
		static bool GetKey(e_KeyCode code) { return _keys[static_cast<UINT>(code)].state == e_KeyState::Pressed; }

	private:
		static std::vector<Key> _keys;
	};
}


