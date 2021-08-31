#include "pch.h"
#include "Game.h"
#include "states/GameState.h"



//#include <iostream>
//#include <memory>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);


Game::Game()
	: m_window{}, m_renderer{ new Renderer }
{
	initGLEW();
	initStates();

	glfwSetKeyCallback(m_window.getWindow(), key_callback);
	glfwSetFramebufferSizeCallback(m_window.getWindow(), framebuffer_size_callback);

	configureOpenGL();

	loadResources(); // Load resources before initStates()??
}


void Game::run()
{
	//double previousTimeSinceLastUpdate{ 0.0 }, currentTimeSinceLastUpdate{ 0.0 }, deltaTime{ 0.0 };
	double deltaTime = 0.0, lastFrame = 0.0, currentFrame = 0.0;

	while (!m_window.getShouldClose())
	{
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		m_renderer->clearScreen();
		//m_window.clearScreen(); - put in Renderer??

		glfwPollEvents();

		processEvents();
		update(deltaTime);
		render();

		glfwSwapBuffers(m_window.getWindow());
	}

	glfwTerminate();
}


void Game::initGLEW()
{
	if (glewInit() != GLEW_OK)
		std::cerr << "Error initializing glew\n";
}

void Game::initStates()
{
	m_stateStack.pushState(std::make_unique<GameState>(m_stateStack, SharedContext{ &m_window, &m_shaderManager, &m_textureManager }));
}

void Game::configureOpenGL()
{
	glEnable(GL_DEPTH_TEST);
	/*glDepthFunc(GL_LESS);
	glEnable(GL_STENCIL_TEST);
	glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);*/
}

void Game::processEvents()
{

}

void Game::update(double dt)
{
	m_stateStack.update(dt);
}

void Game::render()
{
	m_stateStack.draw(*m_renderer);
}


void Game::loadResources()
{
	// shaders
	m_shaderManager.load("default", "src/assets/shaders/basic.vert", "src/assets/shaders/basic.frag");

	// textures
	m_textureManager.load("player", "src/assets/textures/pirate.png", true);
}










void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// Called every time the window is resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}