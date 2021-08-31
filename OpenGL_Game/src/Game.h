#pragma once
#include "Shader.h"
#include "StateStack.h"
#include "Texture.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "Window.h"

class Game
{
public:
	Game();
	void run();

private:
	void initGLEW();
	void initStates();
	void configureOpenGL();

	void processEvents();
	void update(double dt);
	void render();

	void loadResources(); 

private:
	Window								  m_window;
	StateStack							  m_stateStack;

	ResourceManager<Shader, std::string>  m_shaderManager;
	ResourceManager<Texture, std::string> m_textureManager;

	Renderer*							  m_renderer;
	
};

