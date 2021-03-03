#pragma once
#include "VAO.h"
#include "Program.h"
#include "Texture.h"
#include <string>

namespace GL
{
	class Console
	{
	public:
		Console(int width, int height);
		void print(const std::string& text);
		~Console();
	private:
		void drawChar(const unsigned char symbol);
		GL::VAO vao;
		GL::Program shader{ "res\\glsl\\main.vert", "res\\glsl\\main.frag" };
		GL::Texture mLuicidaConsoleFont{ "res\\img\\Luicida Console.bmp" };
	};
};


