#pragma once
#include "MEGA_Component.h"

namespace MEGA
{
	class Script : public Component
	{
	public:
		Script();
		~Script();

	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		

	private:

	};

}

