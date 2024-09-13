#pragma once
#include "MEGA_Resource.h"
#include "MEGA_Texture.h"

namespace MEGA
{
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			math::Vector2 leftTop;
			math::Vector2 size;
			math::Vector2 offset;
			float duration;

			Sprite() 
				: leftTop(math::Vector2::zero), size(math::Vector2::zero), offset(math::Vector2::zero), duration(0.0f)
			{

			}
		};

	public:
		Animation();
		~Animation();

	public:
		HRESULT Load(const std::wstring& path) override;
		void Update();
		void Render(HDC hdc);

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

		void Reset();
		bool IsComplete() const { return _bComplete; }

		void SetAnimator(class Animator* animator) { _animator = animator; }

	private:
		class Animator* _animator;
		graphics::Texture* _texture;

		std::vector<Sprite> _animationSheet;
		int _index;
		float _time;
		bool _bComplete;
	};
}


