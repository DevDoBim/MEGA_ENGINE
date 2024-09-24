#pragma once
#include "..\MEGA_ENGINE_SOURCE\MEGA_Resources.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Texture.h"

namespace MEGA
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Cat", L"C:\\Users\\DoBim\\source\\repos\\MAEA_ENGINE\\Resource\\Img\\Cat.bmp");
		Resources::Load<graphics::Texture>(L"Effect", L"C:\\Users\\DoBim\\source\\repos\\MAEA_ENGINE\\Resource\\Img\\effect.png");
		Resources::Load<graphics::Texture>(L"Player", L"C:\\Users\\DoBim\\source\\repos\\MAEA_ENGINE\\Resource\\Img\\Player.bmp");
	}
}
 