#include "Window.h"
#include <stdexcept>
#include <stb/stb_easy_font.h>
#include "../GL/Console.h"

void print_string(float x, float y, char* text, float r, float g, float b)
{
	static char buffer[99999]; // ~500 chars
	int num_quads;

	num_quads = stb_easy_font_print(x, y, text, NULL, buffer, sizeof(buffer));

	glColor3f(r, g, b);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 16, buffer);
	glDrawArrays(GL_QUADS, 0, num_quads * 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

Window::Window(int width, int height, const std::string& name)
{
	mWindow = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);

	if (mWindow == NULL)
	{
		throw std::runtime_error("Window create error\n");
	}

	setContexCurrent();

	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		throw std::runtime_error("GLew init error\n");
	}
	
}

void Window::setContexCurrent()
{ 
	glfwMakeContextCurrent(mWindow);
}

void Window::loop()
{
	GL::Console console(20, 20);
	while (glfwWindowShouldClose(mWindow) == false)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1, 0, 0, 1);
		
		console.print("Text");
		glfwSwapBuffers(mWindow);

		glfwPollEvents();
	}
}

Window::~Window()
{
	glfwDestroyWindow(mWindow);
}