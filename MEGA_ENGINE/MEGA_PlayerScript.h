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
			Walk,
			Seat,
			Grooming,
			Sleep,
			WakeUp
		};

	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void seat();
		void move();

	private:
		e_State _state;
		class Animator* _animator;
	};
}


