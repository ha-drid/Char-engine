#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <gl.h>
#include <stdexcept>

GL::Texture::Texture()
{
	glGenTextures(1, &mTextureID);
	bind();
}

GL::Texture::Texture(const std::string& file)
{
	glGenTextures(1, &mTextureID);
	bind();

	loadImage(file);
}

void GL::Texture::loadImage(const std::string& file)
{
	int width, height;
	int color_component;
	unsigned char* data = stbi_load(file.c_str(), &width, &height, &color_component, 0);

	if (data == NULL)
		throw std::runtime_error("file not include");

	bind();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
		0, color_component == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);
}

GL::Texture::~Texture()
{
	glDeleteTextures(1, &mTextureID);
}

void GL::Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindTexture(GL_TEXTURE_2D, mTextureID);
}
