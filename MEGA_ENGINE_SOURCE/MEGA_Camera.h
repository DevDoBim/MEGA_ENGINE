#pragma once
#include "MEGA_Component.h"

namespace MEGA
{
	class Camera : public Component
	{
	public:
		Camera();
		~Camera();

	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}


