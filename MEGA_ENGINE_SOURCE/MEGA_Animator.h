#pragma once
#include "MEGA_Component.h"
#include "MEGA_Animation.h"

namespace MEGA
{
	class Animator : public Component
	{

	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				_event = std::move(func);
			}

			void operator()()
			{
				if (_event)
				{
					_event;
				}
			}

			std::function<void()> _event;
		};

		struct Events
		{
			Event startEvent;
			Event completeEvent;
			Event endEvent;
		};

	public:
		Animator();
		~Animator();

	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	public:
		void CreateAnimation
		(
			const std::wstring& name, 
			graphics::Texture* spriteSheet,
			math::Vector2 leftTop, 
			math::Vector2 size, 
			math::Vector2 offset, 
			UINT spriteLength,
			float duration
		);

		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);

	public:
		Events* FindEvents(const std::wstring& name) const;
		std::function<void()>& GetStartEvent(const std::wstring& name) const;
		std::function<void()>& GetCompleteEvent(const std::wstring& name) const;
		std::function<void()>& GetEndEvent(const std::wstring& name) const;

		bool IsComleteAnim() { return _activeAnimation->IsComplete(); }

	private:
		std::map<std::wstring, Animation*> _animations;
		Animation* _activeAnimation;
		bool _bLoop;

		std::map<std::wstring, Events*> _events;
	};

}


