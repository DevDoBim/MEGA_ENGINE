#pragma once
#include "MEGA_Component.h"

namespace MEGA
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

	public:
		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:

	};

}

