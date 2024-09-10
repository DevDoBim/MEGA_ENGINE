#include "MEGA_PlayerScript.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Input.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Time.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Transform.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_GameObject.h"

namespace MEGA
{
	PlayerScript::PlayerScript()
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
	{
		if (Input::GetKey(e_KeyCode::Right))
		{
			Transform* transform = GetOwner()->GetComponent<Transform>();
			Vector2 position = transform->GetPosition();

			position._x += Time::DeltaTime() * 100.0f;
			transform->SetPosition(position);
		}

		if (Input::GetKey(e_KeyCode::Left))
		{
			Transform* transform = GetOwner()->GetComponent<Transform>();
			Vector2 position = transform->GetPosition();

			position._x -= Time::DeltaTime() * 100.0f;
			transform->SetPosition(position);
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
}