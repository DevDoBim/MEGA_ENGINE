#include "MEGA_Camera.h"
#include "MEGA_Transform.h"
#include "MEGA_APP.h"

extern MEGA::APP application;

namespace MEGA
{
	Camera::Camera()
		: Component(e_ComponentType::Camera),
		_distance(Vector2::zero), _resolution(Vector2::zero), _lookPosition(Vector2::zero), _target(nullptr)
	{
	}
	Camera::~Camera()
	{
	}
	void Camera::Initialize()
	{
		_resolution._x = application.GetWidth();
		_resolution._y = application.GetHeight();
	}
	void Camera::Update()
	{
		if (_target != nullptr)
		{
			Transform* transform = _target->GetComponent<Transform>();
			_lookPosition = transform->GetPosition();
		}
		Transform* cameraTransform = GetOwner()->GetComponent<Transform>();
		_lookPosition = cameraTransform->GetPosition();

		_distance = _lookPosition - (_resolution / 2.0f);
	}
	void Camera::LateUpdate()
	{
	}
	void Camera::Render(HDC hdc)
	{
	}
}
