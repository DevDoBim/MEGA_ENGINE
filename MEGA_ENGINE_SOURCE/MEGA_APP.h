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
		void Initialize(HWND hWnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	public:

	private:
		HWND _hWnd;
		HDC _hdc;

		// DC에는 도화지가 존재하는데, 도화지의 자료형은 BITMAP이다.
		HDC _backHdc;
		HBITMAP _backBuffer;

		UINT _width;
		UINT _height;

		RECT _rect;

		MEGA::GameObject _player;
	};
}

