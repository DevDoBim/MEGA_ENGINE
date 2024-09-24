#pragma once
#include "..\MEGA_ENGINE_SOURCE\MEGA_GameObject.h"

namespace MEGA
{
	class Cat : public GameObject
	{
	public:
		Cat() = default;
		~Cat() = default;

	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}


