#include "MEGA_Layer.h"

namespace MEGA
{
	Layer::Layer() : _Type(), _gameObjects{}
	{
	}

	Layer::~Layer()
	{

	}

	void Layer::Initialize()
	{
		for (GameObject* gameObej : _gameObjects)
		{
			assert(gameObej);
			gameObej->Initialize();
		}
	}

	void Layer::Update()
	{
		for (GameObject* gameObej : _gameObjects)
		{
			assert(gameObej);
			gameObej->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObej : _gameObjects)
		{
			assert(gameObej);
			gameObej->LateUpdate();
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObej : _gameObjects)
		{
			assert(gameObej);
			gameObej->Render(hdc);
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		assert(gameObject);
		_gameObjects.push_back(gameObject);
	}
}