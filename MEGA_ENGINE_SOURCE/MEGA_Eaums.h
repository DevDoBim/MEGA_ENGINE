#pragma once

namespace MEGA
{
	enum class e_LayerType
	{
		None,
		BackGround,
		//Objects,
		//Mover,
		//Character,
		Animal,
		Player,
		Particle,
		MAX = 10
	};

	enum class e_ComponentType
	{
		TransForm,
		SpriteRenderer,
		Animator,
		Script,
		Camera,
		End,
	};

	enum class e_ResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};
}