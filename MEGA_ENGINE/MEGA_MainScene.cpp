#include "MEGA_MainScene.h"
#include "MEGA_Player.h"
#include "MEGA_PlayerScript.h"

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
			_player = Object::Instantiate<Player>(e_LayerType::Particle);
			_player->AddComponent<PlayerScript>();

			graphics::Texture* marioTexture = Resources::Find<graphics::Texture>(L"Cat");
			Animator* animator = _player->AddComponent<Animator>();
			animator->CreateAnimation(L"DownWalk", marioTexture, Vector2(0.0f, 0.0f), Vector2(32.0f ,32.0f), Vector2::zero, 4, 0.1f);
			animator->CreateAnimation(L"RightWalk", marioTexture, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
			animator->CreateAnimation(L"UpWalk", marioTexture, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
			animator->CreateAnimation(L"LeftWalk", marioTexture, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
			animator->CreateAnimation(L"Seat", marioTexture, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
			animator->CreateAnimation(L"Grooming", marioTexture, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
			
			
			animator->PlayAnimation(L"Seat", true);

			_player->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
			_player->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
			_player->GetComponent<Transform>()->SetLotation(0.0f);

			GameObject* _backGround = Object::Instantiate<GameObject>(e_LayerType::Player);
			SpriteRenderer* spriteBg = _backGround->AddComponent<SpriteRenderer>();

			graphics::Texture* World = Resources::Find<graphics::Texture>(L"Bubble");
			spriteBg->SetTexture(World);

			//_backGround->AddComponent<PlayerScript>();
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