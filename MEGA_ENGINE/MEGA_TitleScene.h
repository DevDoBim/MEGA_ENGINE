#pragma once
#include "..\MEGA_ENGINE_SOURCE\MEGA_Scene.h"


namespace MEGA
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	public:
		void OnEnter() override;
		void OnExit() override;

	private:

	};
}


