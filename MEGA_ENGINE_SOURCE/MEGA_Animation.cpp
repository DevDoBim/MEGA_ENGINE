#include "MEGA_Animation.h"
#include "MEGA_Time.h"
#include "MEGA_Transform.h"
#include "MEGA_GameObject.h"
#include "MEGA_Animator.h"
#include "MEGA_Renderer.h"

namespace MEGA
{
	Animation::Animation()
		: Resource(e_ResourceType::Animation), 
		_animator(nullptr), _texture(nullptr), _animationSheet{},
		_index(-1), _time(0.0f), _bComplete(false)
	{
	}
	Animation::~Animation()
	{
	}
	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	void Animation::Update()
	{
		if (_bComplete) { return; }
		_time += Time::DeltaTime();

		if (_animationSheet[_index].duration < _time)
		{
			if (_index < _animationSheet.size())
			{
				_index++;
			}
			else
			{
				_bComplete = true;
			}
		}
	}
	void Animation::Render(HDC hdc)
	{
		if (_texture == nullptr)
		{
			return;
		}

		GameObject* gameObj = _animator->GetOwner();
		Transform* transform = gameObj->GetComponent<Transform>();

		math::Vector2 position = transform->GetPosition();

		if (renderer::mainCamera)
		{
			position = renderer::mainCamera->CalculatePosition(position);
		}

		//AlphaBlend(.)
	}
	void Animation::CreateAnimation(const std::wstring name, graphics::Texture* spriteSheet, math::Vector2 leftTop, math::Vector2 size, math::Vector2 offset, UINT spriteLength, float duration)
	{
		_texture = spriteSheet;
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.leftTop._x = leftTop._x + size._x * i;
			sprite.leftTop._y = leftTop._y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;
		}
	}
	void Animation::Reset()
	{
		_time = 0.0f;
		_index = 0;
		_bComplete = false;
	}
}