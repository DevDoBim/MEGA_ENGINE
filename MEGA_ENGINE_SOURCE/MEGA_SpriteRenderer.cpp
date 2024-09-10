#include "MEGA_SpriteRenderer.h"
#include "MEGA_Transform.h"
#include "MEGA_GameObject.h"
#include "MEGA_Texture.h"

#define Check_BMP (graphics::Texture::e_TextureType::BMP)
#define Check_PNG (graphics::Texture::e_TextureType::PNG)

namespace MEGA
{
	SpriteRenderer::SpriteRenderer() : 
		Component(e_ComponentType::SpriteRenderer), _texture(nullptr), _scale(Vector2::one)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
		assert(_texture != nullptr);

		Transform* transform = GetOwner()->GetComponent<Transform>();
		Vector2 position = transform->GetPosition();

		if (_texture->GetTextureType() == Check_BMP)
		{
			TransparentBlt
			(
				hdc, position._x, position._y, _texture->GetWidth() * _scale._x, _texture->GetHeight() * _scale._y,
				_texture->GetHDC(), 0, 0, _texture->GetWidth(), _texture->GetHeight(), 
				RGB(255, 0, 255)
			);
		}
		else if (_texture->GetTextureType() == Check_PNG)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage
			(
				_texture->GetImage(),
				Gdiplus::Rect(position._x, position._y, _texture->GetWidth() * _scale._x, _texture->GetHeight() * _scale._y)
			);
		}
		
	}

	
}
