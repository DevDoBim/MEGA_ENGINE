#pragma once
#include "MEGA_GameObject.h"

namespace MEGA
{
	class APP
	{
	public:
		APP();
		~APP();

	public:
		void Initialize(HWND hWnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	public:

	private:
		HWND _hWnd;
		HDC _hdc;

		MEGA::GameObject _player;
	};
}

