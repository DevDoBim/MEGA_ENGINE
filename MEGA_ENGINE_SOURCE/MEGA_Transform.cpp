#include "MEGA_Transform.h"

MEGA::Transform::Transform() :
	 Component(e_ComponentType::TransForm),
	_position(Vector2::zero), _scale(Vector2::one), _rotation(0.0f)
{
}

MEGA::Transform::~Transform()
{
}

void MEGA::Transform::Initialize()
{

}

void MEGA::Transform::Update()
{

}

void MEGA::Transform::LateUpdate()
{

}

void MEGA::Transform::Render(HDC hdc)
{

}
