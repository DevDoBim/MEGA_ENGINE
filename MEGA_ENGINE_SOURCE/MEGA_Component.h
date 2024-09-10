#pragma once
#include "MEGA_SceneName.h"

namespace MEGA
{
	class GameObject;
	class Component :public SceneName
	{
	public:
		Component(e_ComponentType type);
		~Component();

	public:
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	public:
		inline void SetOwner(GameObject* owner) { _owner = owner; }
		inline GameObject* GetOwner() const { return _owner; }
		inline e_ComponentType GetType() const { return _type; }
		
	private:
		GameObject* _owner;
		e_ComponentType _type;
	};
}


