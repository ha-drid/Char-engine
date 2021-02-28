#include <iostream>
#include <stdexcept>
#include "gl.h"
#include "GLFW/GLFW.h"
#include "GLFW/Window.h"

int main()
{
	try
	{
		GLFW glfw;
		Window window(700, 700, "Char engine");
		window.loop();
	}
	catch (std::runtime_error& e)
	{
		std::cout << "Except:" << e.what() << std::endl;
		return -1;
	}
	catch (std::exception& e)
	{
		std::cout << "Except:" << e.what() << std::endl;
		return -1;
	}

	return 0;
}