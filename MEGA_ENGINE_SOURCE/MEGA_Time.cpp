#include "MEGA_Time.h"

#define CAST_FLOAT(a) (static_cast<float>(a))

namespace MEGA
{
	LARGE_INTEGER Time::cpuFrequency = {};
	LARGE_INTEGER Time::startFrequency = {};
	LARGE_INTEGER Time::endFrequency = {};

	float Time::deltaTime = 0.0f;

	void Time::Initailize()
	{
		// 고해상도 성능 카운터의 빈도를 반환, 시스템의 고유한 타이머의 주파수
		QueryPerformanceFrequency(&cpuFrequency);

		// 프로그램 시작, 경과된 카운트 저장
		QueryPerformanceCounter(&startFrequency);
	}
	void Time::Update()
	{
		QueryPerformanceCounter(&endFrequency);

		// 행동하기전 카운트 값과, 행동 이후 카운트 값을 차감 -> 행동당 카운트
		// 카운트 / 1초당 카운트, 1초에 몇 번 행동하는지 구할 수 있다.
		float calculationFrequency = CAST_FLOAT(endFrequency.QuadPart - startFrequency.QuadPart);
		deltaTime = calculationFrequency / CAST_FLOAT(cpuFrequency.QuadPart);

		// 행동 카운트 초기화
		startFrequency.QuadPart = endFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;
		time += deltaTime;
		float fps = 1.0f / deltaTime;

		// 유니코드 문자열 저장 버퍼
		// float 타입을 문자열로 변환
		wchar_t str[256] = L"";
		swprintf_s(str, 256, L"fps : %d", static_cast<int>(fps));

		// 문자열의 길이, null 문자를 만나면 해당 위치를 기준으로 반환한다.
		int len = wcsnlen_s(str, 256);
		TextOut(hdc, 50, 50, str, len);

		
	}
}