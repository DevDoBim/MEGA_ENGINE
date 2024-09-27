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

			Events* events = FindEvents(_activeAnimation->GetName());

			if (_activeAnimation->IsComplete() == true)
			{
				if (events) events->completeEvent();

				if (_bLoop == true) _activeAnimation->Reset();
			}
		}
	}
	void Animator::LateUpdate()
	{
	}
	void Animator::Render(HDC hdc)
	{
		if (_activeAnimation) _activeAnimation->Render(hdc);
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
		if (animation == nullptr)
		{
			return;
		}

		animation = new Animation();
		animation->SetName(name);

		animation->CreateAnimation(name, spriteSheet, leftTop, size, offset, spriteLength, duration);
		animation->SetAnimator(this);

		Events* events = new Events();
		_events.insert(std::make_pair(name, events));

		_animations.insert(std::make_pair(name, animation));

	}
	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		auto iter = _animations.find(name);
		if(iter == _animations.end());
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

		Events* currentEvent = FindEvents(_activeAnimation->GetName());
		if(currentEvent) currentEvent->endEvent();

		Events* nextEvent = FindEvents(_activeAnimation->GetName());
		if(nextEvent) nextEvent->startEvent();

		_activeAnimation = animation;
		_activeAnimation->Reset();
		_bLoop = loop;
	}
	Animator::Events* Animator::FindEvents(const std::wstring& name) const
	{
		auto iter = _events.find(name);
		if (iter == _events.end()) return nullptr;

		return iter->second;
	}
	std::function<void()>& Animator::GetStartEvent(const std::wstring& name) const
	{
		Events* events = FindEvents(name);
		return events->startEvent._event;
	}
	std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name) const
	{
		Events* events = FindEvents(name);
		return events->completeEvent._event;
	}
	std::function<void()>& Animator::GetEndEvent(const std::wstring& name) const
	{
		Events* events = FindEvents(name);
		return events->endEvent._event;
	}
}