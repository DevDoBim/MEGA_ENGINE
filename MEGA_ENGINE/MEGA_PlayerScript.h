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
		enum class e_State
		{
			Idle,
			Walk,
			GiveWater
		};

	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void idle();
		void move();
		void giveWater();

	private:
		e_State _state;
		class Animator* _animator;

		void(*StartEvent)();
		void(*CompleteEvent)();
		void(*EndEvent)();
	};
}


