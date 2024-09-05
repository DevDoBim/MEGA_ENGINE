#pragma once
#include "MEGA_Component.h"

namespace MEGA
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

	public:
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	template<typename T>
	T* AddComponent()
	{
		T* component = new T();
		component->Initialize();
		component->SetOwner(this);
		_components.push_back(component);

		return component;
	}

	template<typename T>
	T* GetComponent()
	{
		T* returnComponent = nullptr;

		for (Component* component : _components)
		{
			// 기본 클래스의 포인터를 파생 클래스의 포인터로 변환
			// 객체가 실제로 변환하려는 파생 클래스의 인스턴스인지 판별, 유효하지 않으면 nullptr 반환
			returnComponent = dynamic_cast<T*>(component);
			if (returnComponent)
			{
				break;
			}
		}
		return returnComponent;
	}

	private:
		void InitializTransform();

	private:
		std::vector<Component*> _components;
	};
}

