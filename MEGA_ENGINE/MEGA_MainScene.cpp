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
			Player* player = new Player();
			Transform* transform = player->AddComponent<Transform>();

			transform->SetPosition(800, 450);
			transform->SetName(L"Transform");

			SpriteRenderer* spriteRender = player->AddComponent<SpriteRenderer>();
			spriteRender->SetName(L"Renderer");

			AddGameObject(player);
		}

		{
			Player* player = new Player(); 
			Transform* transform = player->AddComponent<Transform>(); 

			transform->SetPosition(100, 200);
			transform->SetName(L"Transform"); 

			SpriteRenderer* spriteRender = player->AddComponent<SpriteRenderer>();
			spriteRender->SetName(L"Renderer");

			AddGameObject(player);
		}

		{
			Player* player = new Player();
			Transform* transform = player->AddComponent<Transform>();

			transform->SetPosition(450, 300);
			transform->SetName(L"Transform");

			SpriteRenderer* spriteRender = player->AddComponent<SpriteRenderer>();
			spriteRender->SetName(L"Renderer");

			AddGameObject(player);
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