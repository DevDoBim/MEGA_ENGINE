#include "MEGA_MainScene.h"
#include "MEGA_Player.h"

#include "..\MEGA_ENGINE_SOURCE\MEGA_GameObject.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_SpriteRenderer.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Transform.h"


namespace MEGA
{
	MainScene::MainScene()
	{
	}

	MainScene::~MainScene()
	{
	}

	void MainScene::Initialize()
	{
		{
			Player* backGround = new Player();
			Transform* transform = backGround->AddComponent<Transform>();
			transform->SetPosition(Vector2(0, 0));
			transform->SetName(L"BackGround");

			SpriteRenderer* sprite = backGround->AddComponent<SpriteRenderer>();
			sprite->SetName(L"Sprite");
			sprite->ImageLoad(L"C:\\Users\\DoBim\\source\\repos\\MAEA_ENGINE\\Resource\\CloudOcean.png");

			AddGameObject(backGround);
		}
	}

	void MEGA::MainScene::Update()
	{
		// 부모 함수 호출
		Scene::Update();

	}

	void MEGA::MainScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void MEGA::MainScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}