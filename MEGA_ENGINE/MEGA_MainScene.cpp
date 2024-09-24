#pragma once
#include "MEGA_MainScene.h"
#include "MEGA_Player.h"
#include "MEGA_PlayerScript.h"
#include "MEGA_Cat.h"
#include "MEGA_CatScript.h"

#include "MEGA_TitleScene.h"

#include "..\MEGA_ENGINE_SOURCE\MEGA_GameObject.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_SpriteRenderer.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Transform.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_SceneManager.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Input.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Object.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Texture.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Resources.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Camera.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Renderer.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Animator.h"

using namespace MEGA::math;

namespace MEGA
{
	MainScene::MainScene() : _player(nullptr)
	{
	}

	MainScene::~MainScene()
	{
	}

	void MainScene::Initialize()
	{	
		{
			GameObject* camera = Object::Instantiate<GameObject>(e_LayerType::None, Vector2(540.0f, 240.0f));
			Camera* cameraComp =  camera->AddComponent<Camera>();

			renderer::mainCamera = cameraComp;
			//camera->AddComponent<PlayerScript>();

			// 게임 오브젝트들을 생성하기 전에 Load를 한다.
			_player = Object::Instantiate<Player>(e_LayerType::Player);
			_player->AddComponent<PlayerScript>();

			graphics::Texture* playerTextures = Resources::Find<graphics::Texture>(L"Player");
			Animator* playerAnimator = _player->AddComponent<Animator>();
			playerAnimator->CreateAnimation(L"Idle", playerTextures, Vector2(2000.0f, 250.0f), Vector2(250.0f ,250.0f), Vector2::zero, 1, 0.1f);
			
			playerAnimator->PlayAnimation(L"Idle", true);

			_player->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
			//_player->GetComponent<Transform>()->SetScale(Vector2(0.7f, 0.7f));
			_player->GetComponent<Transform>()->SetLotation(0.0f);

			//GameObject* _backGround = Object::Instantiate<GameObject>(e_LayerType::Player);
			//SpriteRenderer* spriteBg = _backGround->AddComponent<SpriteRenderer>();

			//graphics::Texture* World = Resources::Find<graphics::Texture>(L"Bubble");
			//spriteBg->SetTexture(World);

			//_backGround->AddComponent<PlayerScript>();
			Cat* cat = Object::Instantiate<Cat>(e_LayerType::Animal);
			cat->AddComponent<CatScript>();

			graphics::Texture* catTextures = Resources::Find<graphics::Texture>(L"Cat");
			Animator* Catanimator = cat->AddComponent<Animator>();
			Catanimator->CreateAnimation(L"DownWalk", catTextures, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
			Catanimator->CreateAnimation(L"RightWalk", catTextures, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
			Catanimator->CreateAnimation(L"UpWalk", catTextures, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
			Catanimator->CreateAnimation(L"LeftWalk", catTextures, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
			Catanimator->CreateAnimation(L"Seat", catTextures, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
			Catanimator->CreateAnimation(L"Grooming", catTextures, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);


			Catanimator->PlayAnimation(L"Seat", true);

			cat->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 200.0f));
			cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
			cat->GetComponent<Transform>()->SetLotation(0.0f);
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
		//wchar_t str[256] = L"Main Scene";
		//int len = wcsnlen_s(str, 256);
		//TextOut(hdc, 100, 100, str, len);
	}

	void MainScene::OnEnter()
	{

	}
	void MainScene::OnExit()
	{
		//Transform* transform = _player->GetComponent<Transform>();
		//transform->SetPosition(Vector2(0, 0));
	}
}