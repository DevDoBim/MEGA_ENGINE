#include "MEGA_Player.h"

#include "..\MEGA_ENGINE_SOURCE\MEGA_Input.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Transform.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Time.h"


namespace MEGA
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		if (Input::GetKey(e_KeyCode::Right))
		{
			Transform* transform = GetComponent<Transform>();
			Vector2 position = transform->GetPosition();

			position._x += Time::DeltaTime() * 100.0f;
			transform->SetPosition(position);
		}
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}

