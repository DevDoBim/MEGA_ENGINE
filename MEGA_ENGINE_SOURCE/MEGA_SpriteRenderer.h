#pragma once
#include "MEGA_Component.h"

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
		void ImageLoad(const std::wstring& path);

	private:
		Gdiplus::Image* _Image;
		UINT _width;
		UINT _height;	
	};

}

