#pragma once
#include "MEGA_SceneName.h"

namespace MEGA
{
	class GameObject;
	class Component :public SceneName
	{
	public:
		Component();
		~Component();

	public:
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	public:
		inline void SetOwner(GameObject* owner) { _owner = owner; }
		inline GameObject* GetOwner() const { return _owner; }
		
	private:
		GameObject* _owner;
	};
}


