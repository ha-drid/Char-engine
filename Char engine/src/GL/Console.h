#pragma once
#include "VAO.h"
#include "Program.h"
#include "Texture.h"
#include <string>
#include <map>

namespace GL
{
	class Console
	{
	public:
		Console(int width, int height);
		void swap();
		~Console();
	private:
		GL::VAO symbolVAO;
		GL::VAO symbolVAO1;
		GL::Program shader{ "res\\glsl\\main.vert", "res\\glsl\\main.frag" };
		GL::Texture mLuicidaConsoleFont{ "res\\img\\Luicida Console.bmp" };
		int mWidth, mHeight;
	};
};


