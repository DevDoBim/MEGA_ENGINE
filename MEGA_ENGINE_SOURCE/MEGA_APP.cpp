#include "MEGA_APP.h"
#include "MEGA_Input.h"
#include "MEGA_Time.h"


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

		Input::Initailize();
		Time::Initailize();

	}

	void APP::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void APP::Update()
	{
		Input::Update();
		Time::Update();

		_player.Update();
	}

	void APP::LateUpdate()
	{
	}

	void APP::Render()
	{
		Time::Render(_hdc);
		_player.Render(_hdc);
	}
}