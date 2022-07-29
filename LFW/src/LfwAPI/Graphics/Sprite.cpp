#include "LFWpch.h"
#include "Sprite.h"


namespace LFW {

	Sprite::Sprite(glm::vec2 position, glm::vec2 size)
	{
		anchor.Translation.x = position.x;
		anchor.Translation.y = position.y;

		anchor.Scale.x = size.x;
		anchor.Scale.y = size.y;
	}

	void Sprite::SetTexture(std::string path)
	{
		if (path == "")
		{
			std::cout << "Texture path for sprite was invalid\n";
			return;
		}

		if(filePath != "") LoadTexture(texture, filePath.c_str());
		else LoadTexture(texture, path.c_str());
	}

	void Sprite::SetPosition(float x, float y)
	{
		anchor.Translation.x = x;
		anchor.Translation.y = y;
	}

	void Sprite::SetSize(float w, float h)
	{
		anchor.Scale.x = w;
		anchor.Scale.y = h;
	}

	void Sprite::SetRotationX(float rotation)
	{
		anchor.Rotation.x += rotation;
	}

	void Sprite::SetRotationY(float rotation)
	{
		anchor.Rotation.y += rotation;
	}
	void Sprite::SetRotationZ(float rotation)
	{
		anchor.Rotation.z += rotation;
	}
}