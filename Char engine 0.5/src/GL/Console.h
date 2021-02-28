#pragma once
#include "VAO.h"
#include "Program.h"
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
		void drawChar(const char16_t symbol);
		GL::VAO vao;
		GL::Program shader{"res\\glsl\\main.vert", "res\\glsl\\main.frag" };
	};
};


