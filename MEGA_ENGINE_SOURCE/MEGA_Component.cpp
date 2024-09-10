#include "MEGA_Component.h"

namespace MEGA
{
	Component::Component(e_ComponentType type) 
		: _owner(nullptr), _type(type)
	{
	}

	Component::~Component()
	{
	}

	void Component::Initialize()
	{
	}

	void Component::Update()
	{
	}

	void Component::LateUpdate()
	{
	}

	void Component::Render(HDC hdc)
	{
	}
}

