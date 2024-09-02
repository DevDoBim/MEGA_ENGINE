#pragma once
#include "..\MEGA_ENGINE_SOURCE\MEGA_Scene.h"

namespace MEGA
{
	class MainScene : public Scene
	{
	public:
		MainScene();
		~MainScene();

	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		
	};
}


