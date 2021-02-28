#include "Console.h"

GL::Console::Console(int width, int height)
{
	glOrtho(0, width, height, 0, -1, 1);

	vao.addVertexBufferObject({
		{ 0.0f, 0.0f, 0.0f },
		{ 1.0f, 0.0f, 0.0f },
		{ 1.0f, 1.0f, 0.0f },
		{ 0.0f, 1.0f, 0.0f }
		});

	vao.addVertexBufferObject({
		{ 1.0f, 0.0f, 0.0f },
		{ 0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f },
		{ 1.0f, 1.0f, 0.0f },
		});

	vao.addIndices({
		0,1,2,
		0,2,3
		});

	shader.bindAttribute(0, "position");
	shader.bindAttribute(1, "color");

	shader.link();
	shader.use();
}

void GL::Console::print(const std::string& e)
{
	vao.draw();
}

GL::Console::~Console()
{
}

void GL::Console::drawChar(const char16_t symbol)
{

}