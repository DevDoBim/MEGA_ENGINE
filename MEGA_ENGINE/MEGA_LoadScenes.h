#pragma once
#include "..\MEGA_ENGINE_SOURCE\MEGA_SceneManager.h"
#include "MEGA_MainScene.h"

namespace MEGA
{
	void LoadScenes()
	{
		// Scene 생성
		SceneManager::CreateScene<MainScene>(L"MainScene");
		
		// Scene 호출
		SceneManager::LoadScene(L"MainScene");
	}
}
