#include "MEGA_PlayerScript.h"

#include "..\MEGA_ENGINE_SOURCE\MEGA_Input.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Time.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Transform.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_GameObject.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Animator.h"


namespace MEGA
{
	PlayerScript::PlayerScript()
		: _state(PlayerScript::e_State::Idle), _animator(nullptr)
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
		if (_animator == nullptr)
		{
			_animator = GetOwner()->GetComponent<Animator>();
		}
		switch (_state)
		{
		case MEGA::PlayerScript::e_State::Idle:
			idle();
			break;

		case MEGA::PlayerScript::e_State::Walk:
			move();
			break;

		case MEGA::PlayerScript::e_State::GiveWater:
			break;


		default:
			break;
		}
		
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::idle()
	{
		if (Input::GetKey(e_KeyCode::LButton))
		{
			_state = PlayerScript::e_State::GiveWater;
			_animator->PlayAnimation(L"RightWalk", true);

			Vector2 mousePosition = Input::GetMosuePosition();

		}

		if (Input::GetKey(e_KeyCode::Right))
		{
			_state = PlayerScript::e_State::Walk;
			_animator->PlayAnimation(L"RightWalk", true);
		}

		if (Input::GetKey(e_KeyCode::Left))
		{
			_state = PlayerScript::e_State::Walk;
			_animator->PlayAnimation(L"LeftWalk", true);
		}

		if (Input::GetKey(e_KeyCode::Up))
		{
			_state = PlayerScript::e_State::Walk;
			_animator->PlayAnimation(L"UpWalk", true);
		}

		if (Input::GetKey(e_KeyCode::Down))
		{
			_state = PlayerScript::e_State::Walk;
			_animator->PlayAnimation(L"DownWalk", true);
		}
	}
	void PlayerScript::move()
	{
		Transform* transform = GetOwner()->GetComponent<Transform>();
		Vector2 position = transform->GetPosition();

		if (Input::GetKey(e_KeyCode::Right))
		{
			position._x += 100.0f * Time::DeltaTime();
		}

		if (Input::GetKey(e_KeyCode::Left))
		{
			position._x -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKey(e_KeyCode::Up))
		{
			position._y -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKey(e_KeyCode::Down))
		{
			position._y += 100.0f * Time::DeltaTime();	
		}

		transform->SetPosition(position);

		if (
			Input::GetKeyUp(e_KeyCode::Right) || 
			Input::GetKeyUp(e_KeyCode::Left) || 
			Input::GetKeyUp(e_KeyCode::Up) ||
			Input::GetKeyUp(e_KeyCode::Down)
			)
		{
			_state = PlayerScript::e_State::Idle;
			_animator->PlayAnimation(L"Idle", false);
		}
	}
}