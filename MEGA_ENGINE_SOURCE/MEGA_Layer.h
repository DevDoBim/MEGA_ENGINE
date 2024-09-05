#pragma once
#include "MEGA_SceneName.h"
#include "CommonInclude.h"
#include "MEGA_GameObject.h"

namespace MEGA
{
	class Layer : public SceneName
	{
	public:
		Layer();
		~Layer();

	public:
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	public:
		void AddGameObject(GameObject* gameObject);

	private:
		e_LayerType _Type;
		std::vector<GameObject*> _gameObjects;
	};
}


