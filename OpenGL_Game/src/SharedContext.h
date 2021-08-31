#pragma once

#include "Shader.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Window.h"

#include <string>

struct SharedContext
{
	Window* window;
	ResourceManager<Shader, std::string>*  m_shaderManager;
	ResourceManager<Texture, std::string>* m_textureManager;
};