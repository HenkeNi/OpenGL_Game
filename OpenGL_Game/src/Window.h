#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window();

	bool		getShouldClose() const;
	GLFWwindow* getWindow(); 

private:
	void initGLFW() const;
	void createWindow();

private:
	GLFWwindow* m_window;

};

