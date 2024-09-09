#pragma once
#include "MEGA_Resource.h"

namespace MEGA
{
	class Resources
	{
	public:
		template<typename T>
		static T* Find(const std::wstring& key)
		{
			//std::map<std::wstring, Resource*>::iterator iter;
			auto iter = _resources.find(key);

			// iter는 부모의 포인터 변수, dynamic_cast를 통해 다운 캐스팅 
			// -> 자식의 포인터, 이 경우 Resource 종류의 포인터가 된다.
			if (iter == _resources.end())
			{
				return nullptr;
			}
			return dynamic_cast<T*>(iter->second);
		}

		template<typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = Resources::Find<T>(key);
			if (resource) { return resource; }
			
			resource = new T();
			if (FAILED(resource->Load(path)))
			{
				MessageBox(nullptr, L"Image Load Fail", L"Error", MB_OK);
				assert(false && "Image Load Fail");
				return nullptr;
			}

			resource->SetName(key);
			resource->SetPath(path);
			_resources.insert(std::make_pair(key, resource));

			return resource;
		}
	private:
		static std::map<std::wstring, Resource*> _resources;

	};
}


