#include "MEGA_Texture.h"
#include "MEGA_APP.h"

extern MEGA::APP application;

namespace MEGA::graphics
{
	// 부모 생성자 호출
	Texture::Texture() : Resource(e_ResourceType::Texture)
	{

	}
	Texture::~Texture()
	{
	}
	HRESULT Texture::Load(const std::wstring& path)
	{
		// BMP와 PNG 각각 따로 처리한다. -> 확장자 확인
		std::wstring ext = path.substr(path.find_last_of(L"." ) + 1);
				
		if (ext == L"png")
		{
			_type = e_TextureType::PNG;
			_Image = Gdiplus::Image::FromFile(path.c_str());

			assert(_Image);

			_width = _Image->GetWidth();
			_height = _Image->GetHeight();
		}
		else if (ext == L"bmp")
		{
			_type = e_TextureType::BMP;
			_bitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			assert(_bitmap);

			BITMAP info = {};
			GetObject(_bitmap, sizeof(BITMAP), &info);

			_width = info.bmWidth;
			_height = info.bmHeight;

			HDC mainDC = application.GetHDC();
			_hdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(_hdc, _bitmap);
			DeleteObject(oldBitmap);
		}


		return 0;
	}
}