#include "MEGA_GameObject.h"
#include "MEGA_Input.h"
#include "MEGA_Time.h"
#include "MEGA_Transform.h"

namespace MEGA
{
	GameObject::GameObject() 
	{
		InitializTransform();
	}
	GameObject::~GameObject()
	{
		for (Component* comp : _components)
		{
			if (comp != nullptr)
			{
				delete comp;
				comp = nullptr;
			}
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : _components)
		{
			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : _components)
		{
			comp->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : _components)
		{
			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc) 
	{
		for (Component* comp : _components)
		{
			comp->Render(hdc);
		}
	}

	void GameObject::InitializTransform()
	{
		AddComponent<Transform>();
	}
}
