#include "Window.h"
#include <stdexcept>
#include <stb/stb_easy_font.h>
#include "../GL/Console.h"

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
	GL::Console console(80, 25);

	while (glfwWindowShouldClose(mWindow) == false)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1, 1, 0, 1);

		console.swap();

		glfwSwapBuffers(mWindow);

		glfwPollEvents();
	}
}

Window::~Window()
{
	glfwDestroyWindow(mWindow);
}