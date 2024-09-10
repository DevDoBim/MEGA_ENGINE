#pragma once
#include "..\MEGA_ENGINE_SOURCE\MEGA_Scene.h"

namespace MEGA
{
	class Player;

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

	public:
		void OnEnter() override;
		void OnExit() override;

	private:
		Player* _player;
	};
}


