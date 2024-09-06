#pragma once
#include "MEGA_Resource.h"

namespace MEGA
{
	class Resources
	{
	public:
		template<typename T>
		static Resource* Find(const std::wstring& key)
		{
			std::map<std::wstring, Resource*>::iterator iter;
			iter = _Resources.find(key);

			// iter는 부모의 포인터 변수, dynamic_cast를 통해 다운 캐스팅 
			// -> 자식의 포인터, 이 경우 Resource 종류의 포인터가 된다.
			assert(iter != _Resources.end());
			return dynamic_cast<T*>(iter->second);
		}

		template<typename T>
		static Resource* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = Resources::Find<T>(key);
			if (resource) { return resource; }
			
			resource = new T();
			assert(FAILED(resource->Load(path)) && "Image Load Fail");
			
			if (FAILED(resource->Load(path)))
			{
				MessageBox(nullptr, L"Image Load Fail", L"Error", MB_OK);
				return nullptr;
			}

		}

	private:
		static std::map<std::wstring, Resource*> _Resources;

	};
}


