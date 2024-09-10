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
		Player,
		MAX = 10
	};

	enum class e_ComponentType
	{
		TransForm,
		SpriteRenderer,
		Script,
		Camera,
		End,
	};

	enum class e_ResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}