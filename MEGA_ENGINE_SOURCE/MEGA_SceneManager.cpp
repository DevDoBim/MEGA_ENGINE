#include "MEGA_SceneManager.h"

namespace MEGA
{
	std::map<std::wstring, Scene*> SceneManager::_scene = {};
	Scene* SceneManager::_activeScene = nullptr;

	// 모든 Scene 초기화
	void SceneManager::Initialize()
	{
	}
	// 현재 실행 중인 Scene 업데이트
	void SceneManager::Update()
	{
		_activeScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		_activeScene->LateUpdate();
	}
	void SceneManager::Render(HDC hdc)
	{
		_activeScene->Render(hdc);
	}
}
