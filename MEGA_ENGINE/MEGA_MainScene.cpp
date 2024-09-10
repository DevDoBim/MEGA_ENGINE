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
			SpriteRenderer* sprite = _player->AddComponent<SpriteRenderer>();
			//sprite->SetSize(Vector2(3.0f, 3.0f));
			_player->AddComponent<PlayerScript>();

			graphics::Texture* Mario = Resources::Find<graphics::Texture>(L"Mario");
			sprite->SetTexture(Mario);



			GameObject* _backGround = Object::Instantiate<GameObject>(e_LayerType::BackGround);
			SpriteRenderer* spriteBg = _backGround->AddComponent<SpriteRenderer>();

			graphics::Texture* World = Resources::Find<graphics::Texture>(L"World");
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
		/*Scene::Render(hdc);
		wchar_t str[256] = L"Main Scene";
		int len = wcsnlen_s(str, 256);
		TextOut(hdc, 100, 100, str, len);*/
	}

	void MainScene::OnEnter()
	{
	}
	void MainScene::OnExit()
	{
		Transform* transform = _player->GetComponent<Transform>();
		transform->SetPosition(Vector2(0, 0));
	}
}