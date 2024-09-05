#include "MEGA_APP.h"
#include "MEGA_Input.h"
#include "MEGA_Time.h"
#include "MEGA_SceneManager.h"


namespace MEGA
{
	APP::APP() : 
		_hWnd(nullptr), _hdc(nullptr),
		_width(0), _height(0), _rect{},
		_backHdc(NULL), _backBuffer(NULL)
	{

	}

	APP::~APP()
	{
	}

	void APP::Initialize(HWND hWnd, UINT width, UINT height)
	{
		adjustWindowRect(hWnd, width, height);
		createBuffer();
		InitializeEtc();

		SceneManager::Initialize();
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
		SceneManager::Update();
	}

	void APP::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void APP::Render()
	{
		resetRender();

		// 실제로 새로 그려지는건 backHdc에 그리겠다.
		Time::Render(_backHdc);
		SceneManager::Render(_backHdc);
		copyRender();
		//SceneManager::Render(_backHdc);
	}

	void APP::adjustWindowRect(HWND hWnd, UINT width, UINT height)
	{
		_hWnd = hWnd;
		_hdc = GetDC(hWnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		_rect = rect;

		_width = width;
		_height = height;
		//_width = rect.right - rect.left;
		//_height = rect.bottom - rect.top;
	}

	void APP::createBuffer()
	{
		// Bitmap 생성, 메모리 상에 생성된 Bitmap은 별도의 초기화를 하지 않기 때문에 검정색(0)이다.
		_backBuffer = CreateCompatibleBitmap(_hdc, _width, _height);

		// backBuffer를 가리키는 DC 생성
		_backHdc = CreateCompatibleDC(_hdc);

		// DC연결, 생성된 _backHdc의 기존 배경을 삭제하고 _backBuffer를 사용하겠다.
		// 이전의 _backHdc에 있는 bitmap을 변수 bitmap에 저장, _backBuffer bitmap을 반환
		HBITMAP bitmap = (HBITMAP)SelectObject(_backHdc, _backBuffer);
		DeleteObject(bitmap);
	}

	void APP::InitializeEtc()
	{
		// 윈도우 창 영역을 새롭게 수정했으니, 다시 보여준다.
		SetWindowPos(_hWnd, nullptr, 0, 0, _width, _height, 0);
		ShowWindow(_hWnd, true);

		Input::Initailize();
		Time::Initailize();
	}

	void APP::resetRender()
	{
		FillRect(_backHdc, &_rect, (HBRUSH)GetStockObject(WHITE_BRUSH));
	}
	
	void APP::copyRender()
	{
		// _backHdc에 있는 내용을 가져와 덮어씌운다.
		BitBlt(_hdc, 0, 0, _width, _height, _backHdc, 0, 0, SRCCOPY);
	}
}