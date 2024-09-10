#include "MEGA_GameObject.h"
#include "MEGA_Input.h"
#include "MEGA_Time.h"
#include "MEGA_Transform.h"
#include "MEGA_Script.h"

namespace MEGA
{
	GameObject::GameObject()
	{
		_components.resize(static_cast<UINT>(e_ComponentType::End));
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
			if (comp == nullptr) continue;
			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : _components)
		{
			if (comp == nullptr) continue;
			comp->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : _components)
		{
			if (comp == nullptr) continue;
			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc) 
	{
		for (Component* comp : _components)
		{
			if (comp == nullptr) continue;
			comp->Render(hdc);
		}
	}

	void GameObject::InitializTransform()
	{
		AddComponent<Transform>();
	}
}
