#pragma once
#include "..\MEGA_ENGINE_SOURCE\MEGA_Resources.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Texture.h"

namespace MEGA
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Background", L"C:\\Users\\DoBim\\source\\repos\\MAEA_ENGINE\\Resource\\CloudOcean.png");
	}
}
