#include "MEGA_Animator.h"


namespace MEGA
{
	Animator::Animator() 
		: Component(e_ComponentType::Animator), _animations{}, _activeAnimation(nullptr), _bLoop(false)
	{
	}
	Animator::~Animator()
	{
	}
	void Animator::Initialize()
	{
	}
	void Animator::Update()
	{
		if (_activeAnimation)
		{
			_activeAnimation->Update();

			if (_activeAnimation->IsComplete() == true && _bLoop == true)
			{
				_activeAnimation->Reset();
			}
		}
	}
	void Animator::LateUpdate()
	{
	}
	void Animator::Render(HDC hdc)
	{
		if (_activeAnimation)
		{
			_activeAnimation->Render(hdc);
		}
	}
	void Animator::CreateAnimation
	(
		const std::wstring& name, 
		graphics::Texture* spriteSheet, 
		math::Vector2 leftTop, 
		math::Vector2 size, 
		math::Vector2 offset, 
		UINT spriteLength, 
		float duration
	)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);

		if (animation != nullptr)
		{
			return;
		}

		animation = new Animation();
		animation->CreateAnimation(name, spriteSheet, leftTop, size, offset, spriteLength, duration);

		animation->SetAnimator(this);
		_animations.insert(std::make_pair(name, animation));

	}
	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		auto iter = _animations.find(name);
		if (iter == _animations.end())
		{
			return nullptr;
		}

		return iter->second;
	}
	void Animator::PlayAnimation(const std::wstring& name, bool loop)
	{
		Animation* animation = FindAnimation(name);
		if (animation == nullptr)
		{
			return;
		}

		_activeAnimation = animation;
		_activeAnimation->Reset();
		_bLoop = loop;
	}
}