#pragma once
#include "MEGA_Component.h"

namespace MEGA
{
	struct position
	{
		int x;
		int y;
	};

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();
		
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	public:
		void SetPosition(int x, int y) { _x = x; _y = y; }
		int GetX() const { return _x; }
		int GetY() const { return _y; }

	private:
		int _x;
		int _y;
	};

}

