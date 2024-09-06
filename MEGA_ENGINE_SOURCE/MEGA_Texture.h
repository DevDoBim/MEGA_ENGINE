#pragma once
#include "MEGA_Resource.h"

namespace MEGA::graphics
{
	class Texture : public Resource
	{
	public:
		enum class e_TextureType
		{
			BMP,
			PNG,
			None
		};

	public:
		Texture();
		~Texture();

	public:
		HRESULT Load(const std::wstring& path) override;

	public:
		UINT GetWidth() const { return _width; }
		UINT GetHeight() const { return _height; }
		HDC GetHDC() const { return _hdc; }
		e_TextureType GetTextureType() const { return _type; }
		Gdiplus::Image* GetImage() const { return _Image; }

	private:
		// PNG
		Gdiplus::Image* _Image;

		//BMP
		HBITMAP _bitmap;

		e_TextureType _type;
		HDC _hdc;
		UINT _width;
		UINT _height;
	};

}

