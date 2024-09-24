#include "MEGA_CatScript.h"

#include "..\MEGA_ENGINE_SOURCE\MEGA_Input.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Time.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Transform.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_GameObject.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_Animator.h"


namespace MEGA
{
	CatScript::CatScript()
		: _state(CatScript::e_State::Seat), _direction(CatScript::e_Direction::Right)
		, _animator(nullptr)
		, _time(0.0f)
	{
	}
	CatScript::~CatScript()
	{
	}
	void CatScript::Initialize()
	{

	}
	void CatScript::Update()
	{
		if (_animator == nullptr)
		{
			_animator = GetOwner()->GetComponent<Animator>();
		}
		switch (_state)
		{
		case MEGA::CatScript::e_State::Walk:
			move();
			break;

		case MEGA::CatScript::e_State::Seat:
			seat();
			break;

		case MEGA::CatScript::e_State::Grooming:
			break;

		case MEGA::CatScript::e_State::Sleep:
			break;

		case MEGA::CatScript::e_State::WakeUp:
			break;

		default:
			break;
		}

	}
	void CatScript::LateUpdate()
	{
	}
	void CatScript::Render(HDC hdc)
	{
	}
	void CatScript::seat()
	{
		_time += Time::DeltaTime();

		if (_time >= 2.0f)
		{
			_state = CatScript::e_State::Walk;
			_direction = static_cast<e_Direction>(rand() % 4);

			direction();
			_time = 0.0f;
		}
		
	}
	void CatScript::move()
	{
		_time += Time::DeltaTime();

		if (_time >= 2.0f)
		{
			_state = CatScript::e_State::Seat;
			_animator->PlayAnimation(L"Seat", true);
			_time = 0.0f;
		}

		Transform* transform = GetOwner()->GetComponent<Transform>();

		translate(transform);
	}
	void CatScript::direction()
	{
		Transform* transform = GetOwner()->GetComponent<Transform>();
		Vector2 position = transform->GetPosition();

		switch (_direction)
		{
		case MEGA::CatScript::e_Direction::Up:
			_animator->PlayAnimation(L"UpWalk", true);
			break;

		case MEGA::CatScript::e_Direction::Down:
			_animator->PlayAnimation(L"DownWalk", true);
			break;

		case MEGA::CatScript::e_Direction::Left:
			_animator->PlayAnimation(L"LeftWalk", true);
			break;

		case MEGA::CatScript::e_Direction::Right:
			_animator->PlayAnimation(L"RightWalk", true);
			break;

		default:
			assert(static_cast<int>(_direction) > 3);
			break;
		}
	}

	void CatScript::translate(Transform* transform)
	{
		Vector2 position = transform->GetPosition();

		switch (_direction)
		{
		case MEGA::CatScript::e_Direction::Up:
			position._y -= 100.0f * Time::DeltaTime();
			break;

		case MEGA::CatScript::e_Direction::Down:
			position._y += 100.0f * Time::DeltaTime();
			break;

		case MEGA::CatScript::e_Direction::Left:
			position._x -= 100.0f * Time::DeltaTime();
			break;

		case MEGA::CatScript::e_Direction::Right:
			position._x += 100.0f * Time::DeltaTime();
			break;

		default:
			break;
		}
		transform->SetPosition(position);
	}

}
