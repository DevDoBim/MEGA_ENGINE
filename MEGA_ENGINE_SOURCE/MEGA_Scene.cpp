#include "MEGA_Scene.h"

namespace MEGA
{
	Scene::Scene() :_layers{}
	{
		_layers.resize(static_cast<UINT>(e_LayerType::MAX));
		CreateLayers();
		
	}
	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		for (Layer* layer : _layers)
		{
			assert(layer);
			layer->Initialize();
		}
	}

	void Scene::Update()
	{
		for (Layer* layer : _layers)
		{
			assert(layer);
			layer->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (Layer* layer : _layers)
		{
			assert(layer);
			layer->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : _layers)
		{
			assert(layer);
			layer->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObj, const e_LayerType type)
	{
		_layers[static_cast<UINT>(type)]->AddGameObject(gameObj);
	}

	void Scene::OnEnter()
	{
	}

	void Scene::OnExit()
	{

	}

	void Scene::CreateLayers()
	{
		/*for (size_t i = 0; i < static_cast<UINT>(e_LayerType::End); i++)
		{
			_layers[i] = new Layer();
		}*/

		for (Layer*& layer : _layers)
		{
			layer = new Layer();
		}
	}

}