#pragma once
#include "MEGA_SceneName.h"
#include "MEGA_GameObject.h"

namespace MEGA
{
	class Scene : public SceneName
	{
	public:
		Scene();
		~Scene();

	public:
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	public:
		void AddGameObject(GameObject* gameObject);

	private:
		std::vector<GameObject*> _gameObjects;
	};
}


