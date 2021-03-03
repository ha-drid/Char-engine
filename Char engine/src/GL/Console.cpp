#include "Console.h"

GL::Console::Console(int width, int height)
{
	vao.addVertexBufferObject({
		{  0.0f, -1.0f,  0.0f  },
		{  1.0f, -1.0f,  0.0f  },
		{  1.0f,  0.0f,  0.0f  },
		{  0.0f,  0.0f,  0.0f  }
		});

	vao.addVertexBufferObject({
		{ 0.0f, 1.0f },
		{ 1.0f, 1.0f },
		{ 1.0f, 0.0f },
		{ 0.0f, 0.0f },
		});

	vao.addIndices({
		0,1,2,
		0,2,3
		});

	shader.bindAttribute(0, "position");
	shader.bindAttribute(1, "uv");

	shader.link();

	shader.use();

	shader.setFloat("width", width);
	shader.setFloat("height", height);
}

void GL::Console::print(const std::string& text)
{
	//for (int i = 0; i < text.length(); ++i)
	shader.use();

	glActiveTexture(GL_TEXTURE0);

	mLuicidaConsoleFont.bind();

	shader.setInt("mTexture", 0);

	drawChar('Q');
}

GL::Console::~Console()
{
}

const float SYMBOL_WIDTH = 1.0f / 16.0f;
void GL::Console::drawChar(const unsigned char symbol)
{
	shader.setInt("mTexture", 0);

	uint32_t y = symbol >> 4;
	uint32_t x = symbol & 0b1111;

	struct { float top, left, right, bottom; } rct;

	rct.top = (float)y * SYMBOL_WIDTH;
	rct.bottom = rct.top + SYMBOL_WIDTH;
	rct.left = (float)x * SYMBOL_WIDTH;
	rct.right = rct.left + SYMBOL_WIDTH;
	
	vao.remixVertexBufferObject2({
		rct.left,rct.bottom,
		rct.right,rct.bottom,
		rct.right,rct.top,
		rct.left,rct.top,
		});

	vao.draw();
}