#include "MEGA_MainScene.h"
#include "MEGA_Player.h"

#include "MEGA_TitleScene.h"

#include "..\MEGA_ENGINE_SOURCE\MEGA_GameObject.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_SpriteRenderer.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Transform.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_SceneManager.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Input.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Object.h"


namespace MEGA
{
	MainScene::MainScene() : _backGround{}
	{
	}

	MainScene::~MainScene()
	{
	}

	void MainScene::Initialize()
	{
		{
			/*_backGround = new Player();
			Transform* transform = _backGround->AddComponent<Transform>();
			transform->SetPosition(Vector2(0, 0));
			transform->SetName(L"BackGround");

			SpriteRenderer* sprite = _backGround->AddComponent<SpriteRenderer>();
			sprite->SetName(L"Sprite");
			sprite->ImageLoad(L"C:\\Users\\DoBim\\source\\repos\\MAEA_ENGINE\\Resource\\CloudOcean.png");

			AddGameObject(_backGround, e_LayerType::BackGround);*/
			_backGround = Object::Instantiate<Player>(e_LayerType::BackGround, Vector2(100.0f, 100.0f));
			SpriteRenderer* sprite = _backGround->AddComponent<SpriteRenderer>();
			sprite->SetName(L"Sprite"); 
			sprite->ImageLoad(L"C:\\Users\\DoBim\\source\\repos\\MAEA_ENGINE\\Resource\\CloudOcean.png"); 
		}
	}

	void MainScene::Update()
	{
		// 부모 함수 호출
		Scene::Update();

	}

	void MainScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(e_KeyCode::K))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void MainScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[256] = L"Main Scene";
		int len = wcsnlen_s(str, 256);
		TextOut(hdc, 100, 100, str, len);
	}

	void MainScene::OnEnter()
	{
	}
	void MainScene::OnExit()
	{
		Transform* transform = _backGround->GetComponent<Transform>();
		transform->SetPosition(Vector2(0, 0));
	}
}