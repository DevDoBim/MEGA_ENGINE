#include "MEGA_APP.h"


namespace MEGA
{
	APP::APP() : 
		_hWnd(nullptr), _hdc(nullptr)
	{
	}

	APP::~APP()
	{
	}

	void APP::Initialize(HWND hWnd)
	{
		_hWnd = hWnd;
		_hdc = GetDC(_hWnd);

	}

	void APP::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void APP::Update()
	{
		_player.Update();
	}

	void APP::LateUpdate()
	{
	}

	void APP::Render()
	{
		_player.Render(_hdc);
	}
}