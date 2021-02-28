#pragma once
#include <string>
#include <gl.h>

class Window
{
public:
	Window(int width, int height, const std::string& name);
	~Window();
	void setContexCurrent();
	void loop();
private:
	GLFWwindow* mWindow;
};

