#include "MEGA_SpriteRenderer.h"
#include "MEGA_Transform.h"
#include "MEGA_GameObject.h"

namespace MEGA
{
	SpriteRenderer::SpriteRenderer()
		:_Image(nullptr), 
		_width(0), _height(0)
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
		Transform* transform = GetOwner()->GetComponent<Transform>();
		Vector2 position = transform->GetPosition();

		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(_Image, Gdiplus::Rect(position._x, position._y, _width, _height));
	}
	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		_Image = Gdiplus::Image::FromFile(path.c_str());
		_width = _Image->GetWidth();
		_height = _Image->GetHeight();
	}
}
