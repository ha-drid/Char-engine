#pragma once
#include <string>

namespace GL
{
	class Texture
	{
	public:
		Texture();
		Texture(const std::string& file);
		void loadImage(const std::string& file);
		~Texture();
		void bind();
	private:
		uint32_t mTextureID;
	};
}

