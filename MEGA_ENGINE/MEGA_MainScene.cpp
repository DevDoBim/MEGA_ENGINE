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
			// 게임 오브젝트들을 생성하기 전에 Load를 한다.
			_backGround = Object::Instantiate<Player>(e_LayerType::BackGround);
			SpriteRenderer* sprite = _backGround->AddComponent<SpriteRenderer>();

			graphics::Texture* background = Resources::Find<graphics::Texture>(L"Background");
			sprite->SetTexture(background);

			_backGround->AddComponent<PlayerScript>();
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