#pragma once
#include "MEGA_Component.h"
#include "MEGA_Animation.h"

namespace MEGA
{
	class Animator : public Component
	{
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
			const std::wstring name, 
			graphics::Texture* spriteSheet,
			math::Vector2 leftTop, 
			math::Vector2 size, 
			math::Vector2 offset, 
			UINT spriteLength,
			float duration
		);

		Animation* FindAnimation(const std::wstring name);
		void PlayAnimation(const std::wstring name, bool loop = true);

	private:
		std::map<std::wstring, Animation*> _animations;
		Animation* _activeAnimation;
		bool _bLoop;
	};

}


