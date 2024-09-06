#pragma once
#include "MEGA_SceneName.h"

namespace MEGA
{
	class Resource : public SceneName
	{
	public:
		Resource() = delete;
		Resource(e_ResourceType type);
		virtual ~Resource();

	public:
		// HRESULT, 윈도우 관련 함수의 BOOL 반환 값, True 1, False 0
		virtual HRESULT Load(const std::wstring& path) = 0;
		const std::wstring& GetPath() { return _path; }
		void SetPath(std::wstring& path) { _path = path; }

	private:
		const e_ResourceType _type;
		std::wstring _path;
	};
}


