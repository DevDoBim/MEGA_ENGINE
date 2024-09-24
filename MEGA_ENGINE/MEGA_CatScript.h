#pragma once
#include "..\MEGA_ENGINE_SOURCE\MEGA_Script.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Transform.h"


namespace MEGA
{
	class CatScript : public Script
	{
	public:
		CatScript();
		~CatScript();

	public:
		enum class e_State
		{
			Walk,
			Seat,
			Grooming,
			Sleep,
			WakeUp
		};

		enum class e_Direction
		{
			Up,
			Down,
			Left,
			Right
		};

	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void seat();
		void move();
		void direction();
		void translate(Transform* transform);

	private:
		e_State _state;
		e_Direction _direction;

		class Animator* _animator;
		float _time;
	};
}


