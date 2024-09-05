#include "MEGA_TitleScene.h"
#include "MEGA_MainScene.h"

#include "..\MEGA_ENGINE_SOURCE\MEGA_SceneManager.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Input.h"

namespace MEGA
{
	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
		Scene::Initialize();
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(e_KeyCode::K))
		{
			SceneManager::LoadScene(L"MainScene");
		}
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[256] = L"Title Scene";
		int len = wcsnlen_s(str, 256);
		TextOut(hdc, 100, 100, str, len);
	}
	void TitleScene::OnEnter()
	{
	}
	void TitleScene::OnExit()
	{
	}
}

