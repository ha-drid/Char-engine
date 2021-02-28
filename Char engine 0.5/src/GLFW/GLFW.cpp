#include "GLFW.h"
#include <stdexcept>
#include <gl.h>

GLFW::GLFW()
{
	if (glfwInit() == false)
		throw std::runtime_error("GLGW init error\n");
}

GLFW::~GLFW()
{
	glfwTerminate();
}
