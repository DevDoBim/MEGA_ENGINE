#pragma once
#include "..\MEGA_ENGINE_SOURCE\MEGA_Resources.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Texture.h"

namespace MEGA
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"World", L"C:\\Users\\DoBim\\source\\repos\\MAEA_ENGINE\\Resource\\Img\\World_0.png");
		Resources::Load<graphics::Texture>(L"Cat", L"C:\\Users\\DoBim\\source\\repos\\MAEA_ENGINE\\Resource\\Img\\Cat.bmp");
		Resources::Load<graphics::Texture>(L"Bubble", L"C:\\Users\\DoBim\\source\\repos\\MAEA_ENGINE\\Resource\\Img\\Bubble.png");
		Resources::Load<graphics::Texture>(L"Effect", L"C:\\Users\\DoBim\\source\\repos\\MAEA_ENGINE\\Resource\\Img\\effect.png");
	}
}
 