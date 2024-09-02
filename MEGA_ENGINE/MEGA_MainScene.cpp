#include "MEGA_MainScene.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_GameObject.h"

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
		for (size_t i = 0; i < 100; i++)
		{
			GameObject* obj = new GameObject();
			obj->SetPosition(rand() % 1600, rand() % 900);
			AddGameObject(obj);
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