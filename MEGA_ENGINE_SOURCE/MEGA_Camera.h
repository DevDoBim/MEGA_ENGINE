#pragma once
#include "MEGA_Component.h"
#include "MEGA_GameObject.h"

namespace MEGA
{
	class Camera : public Component
	{
	public:
		math::Vector2 CalculatePosition(math::Vector2 position) { return position - _distance; }

	public:
		Camera();
		~Camera();

	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		//std::vector<GameObject*> _gameObjects;

		math::Vector2 _distance; // 거리
		math::Vector2 _resolution; // 해상도
		math::Vector2 _lookPosition; // 카메라가 바라보는 위치

		GameObject* _target;
		

	};
}


