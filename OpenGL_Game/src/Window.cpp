#include "pch.h"
#include "Window.h"
#include "constants/Constants.h"


//#include <iostream>

Window::Window()
{
	initGLFW();
	createWindow();
}

bool Window::getShouldClose() const
{ 
	return glfwWindowShouldClose(m_window);
}

GLFWwindow* Window::getWindow()
{
	return m_window;
}

void Window::initGLFW() const
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, constants::GL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, constants::GL_VERSION_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif // __APPLE__

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x MSAA (each pixel consist of 4 subsamples
}


void Window::createWindow()
{
	m_window = glfwCreateWindow(constants::SCR_WIDTH, constants::SCR_HEIGHT, constants::title, nullptr, nullptr);
	if (!m_window)
	{
		std::cout << "Failed to create a GLFW Window\n";
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(m_window);
}
