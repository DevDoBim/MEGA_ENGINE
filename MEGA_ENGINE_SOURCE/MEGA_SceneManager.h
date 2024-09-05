#pragma once
#include "MEGA_Scene.h"

namespace MEGA
{
	class SceneManager
	{
	public:
		SceneManager() = default;
		~SceneManager() = default;

	public:
		template<typename T>
		static Scene* CreateScene(const std::wstring& sceneName)
		{
			T* scene = new T();
			scene->SetName(sceneName);

			_activeScene = scene;
			scene->Initialize();
			_scene.insert(std::make_pair(sceneName, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& sceneName);
		static Scene* GetActiveScene() { return _activeScene; }
		

	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		// SceneManager는 특정 Scene을 불러와, 해당 Scene을 Update한다.
		static std::map<std::wstring, Scene*> _scene;
		static Scene* _activeScene;
	};
	
}


