#pragma once
#include "..\MEGA_ENGINE_SOURCE\MEGA_Resources.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Texture.h"

namespace MEGA
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"World", L"C:\\Users\\DoBim\\source\\repos\\MAEA_ENGINE\\Resource\\Img\\World_0.png");
		Resources::Load<graphics::Texture>(L"Mario", L"C:\\Users\\DoBim\\source\\repos\\MAEA_ENGINE\\Resource\\Img\\Mario_0.bmp");
	}
}
 