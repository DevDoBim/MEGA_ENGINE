#pragma once
#include "CommonInclude.h"

namespace MEGA 
{
	class SceneName
	{
	public:
		SceneName();
		virtual ~SceneName();

		void SetName(const std::wstring& name) { _sceneName = name; }
		std::wstring& GetName() { return _sceneName; }

	private:
		std::wstring _sceneName;
	};
}


