#pragma once
#include "MEGA_Component.h"

namespace MEGA
{
	using namespace math;

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
		inline void SetPosition(Vector2 position) {
			_position = position; }
		inline void SetScale(Vector2 scale) { _scale = scale; }
		inline void SetLotation(float rotation) { _rotation = rotation; }

	public:
		inline Vector2 GetPosition() const { return _position; }
		inline Vector2 GetScale() const { return _scale; }
		inline float GetLotation() const { return _rotation; }

	private:
		Vector2 _position;
		Vector2 _scale;
		float _rotation;
	};

}

