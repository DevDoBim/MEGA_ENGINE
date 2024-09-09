#pragma once
#include "MEGA_Component.h"
#include "MEGA_Texture.h"

namespace MEGA
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	public:
		void SetTexture(graphics::Texture* texture) { _texture = texture; }
		void SetSize(math::Vector2 scale) { _scale = scale; }

	private:
		graphics::Texture* _texture;
		math::Vector2 _scale;
	};

}

