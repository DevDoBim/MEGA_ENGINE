#include "MEGA_SpriteRenderer.h"
#include "MEGA_Transform.h"
#include "MEGA_GameObject.h"

namespace MEGA
{
	SpriteRenderer::SpriteRenderer()
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
		HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, brush);

		Transform* transform = GetOwner()->GetComponent<Transform>();
		Rectangle(hdc, transform->GetX(), transform->GetY(), 100 + transform->GetX(), 100 + transform->GetY());

		SelectObject(hdc, defaultBrush);

		DeleteObject(brush);
	}
}
