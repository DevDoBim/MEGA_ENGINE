#pragma once
#include "CommonInclude.h"

namespace MEGA
{
	class Time
	{
	public:
		static void Initailize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return deltaTime; }
		
	private:
		// cpu GHz ¿˙¿Â
		static LARGE_INTEGER cpuFrequency;
		static LARGE_INTEGER startFrequency;
		static LARGE_INTEGER endFrequency;

		static float deltaTime;
	};

}

