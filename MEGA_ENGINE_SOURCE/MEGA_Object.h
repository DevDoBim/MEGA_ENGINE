#pragma once
#include "MEGA_Component.h"
#include "MEGA_GameObject.h"
#include "MEGA_Layer.h"
#include "MEGA_Scene.h"
#include "MEGA_SceneManager.h"
#include "MEGA_Transform.h"

namespace MEGA::Object
{
	template<typename T>
	static T* Instantiate(e_LayerType Type)
	{
		T* gameObj = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(Type);
		layer->AddGameObject(gameObj);

		return gameObj;
	}

	template<typename T>
	static T* Instantiate(e_LayerType Type, math::Vector2 position)
	{
		T* gameObj = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(Type);
		layer->AddGameObject(gameObj);

		Transform* transform = gameObj->GetComponent<Transform>();
		transform->SetPosition(position);

		return gameObj;
	}
}