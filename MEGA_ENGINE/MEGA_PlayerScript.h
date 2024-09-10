#pragma once
#include "..\MEGA_ENGINE_SOURCE\MEGA_Script.h"

namespace MEGA
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};
}


