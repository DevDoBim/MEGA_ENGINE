#include "MEGA_Animation.h"
#include "MEGA_Time.h"
#include "MEGA_Transform.h"
#include "MEGA_GameObject.h"
#include "MEGA_Animator.h"
#include "MEGA_Renderer.h"

namespace MEGA
{
	Animation::Animation()
		: Resource(e_ResourceType::Animation), 
		_animator(nullptr), _texture(nullptr), _animationSheet{},
		_index(-1), _time(0.0f), _bComplete(false)
	{
	}
	Animation::~Animation()
	{
	}
	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	void Animation::Update()
	{
		if (_bComplete) { return; }

		_time += Time::DeltaTime();

		if (_animationSheet[_index].duration < _time)
		{
			_time = 0.0f;

			if (_index < _animationSheet.size() -1)
			{
				_index++;
			}
			else
			{
				_bComplete = true;
			}
		}
	}
	void Animation::Render(HDC hdc)
	{
		if (_texture == nullptr)
		{
			return;
		}

		GameObject* gameObj = _animator->GetOwner();
		Transform* transform = gameObj->GetComponent<Transform>();

		Vector2 position = transform->GetPosition();
		Vector2 scale = transform->GetScale();
		float rotation = transform->GetLotation();

		if (renderer::mainCamera)
		{
			//position = renderer::mainCamera->CalculatePosition(position);
		}

		graphics::Texture::e_TextureType type =  _texture->GetTextureType();
		Sprite sprite = _animationSheet[_index];

		if (type == graphics::Texture::e_TextureType::BMP)
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 255; // (0 : 완전투명 transparent) 0 ~ 255 (255 : 불투명 Opaque)

			
			HDC imgHdc = _texture->GetHDC();


			AlphaBlend
			(
				hdc,
				position._x - (sprite.size._x / 2.0f),
				position._y - (sprite.size._y / 2.0f),
				sprite.size._x * scale._x,
				sprite.size._y * scale._y,
				imgHdc,
				sprite.leftTop._x,
				sprite.leftTop._y,
				sprite.size._x,
				sprite.size._y,
				func
			);
		}
		else if (type == graphics::Texture::e_TextureType::PNG)
		{
			// 원하는 픽셀 투명화, 범위 지정
			Gdiplus::ImageAttributes imageAtt = {};
			imageAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(position._x, position._y);
			graphics.RotateTransform(rotation);
			graphics.TranslateTransform(-position._x, -position._y);

			graphics.DrawImage
			(
				_texture->GetImage(), 
				Gdiplus::Rect
				(
					position._x - (sprite.size._x / 2.0f),
					position._y - (sprite.size._y / 2.0f),
					sprite.size._x * scale._x,
					sprite.size._y * scale._y
				),
				sprite.leftTop._x, 
				sprite.leftTop._y, 
				sprite.size._x,
				sprite.size._y,
				Gdiplus::UnitPixel,
				&imageAtt
			);
		}

		

	}
	void Animation::CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet, math::Vector2 leftTop, math::Vector2 size, math::Vector2 offset, UINT spriteLength, float duration)
	{
		_texture = spriteSheet;

		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.leftTop._x = leftTop._x + (size._x * i);
			sprite.leftTop._y = leftTop._y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			_animationSheet.push_back(sprite);
		}
	}
	void Animation::Reset()
	{
		_time = 0.0f;
		_index = 0;
		_bComplete = false;
	}
}