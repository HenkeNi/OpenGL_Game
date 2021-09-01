#include "pch.h"
#include "GameState.h"
#include "../constants/Constants.h"

#include <GL/glew.h>
//#include <glm/glm.hpp>

//#include <iostream>


GameState::GameState(StateStack& stateStack, SharedContext context)
	: State{ stateStack, context }
{
	m_gameObjects.emplace_back(m_context.m_shaderManager->getResource("default"), m_context.m_textureManager->getResource("player"), glm::vec3{ 0.1f, 0.1f, 0.0f });
}

void GameState::handleEvent()
{

}

void GameState::update(double dt)
{

}

void GameState::draw(Renderer& renderer)
{
	for (const auto& obj : m_gameObjects)
		obj.draw(renderer);
}

void GameState::initGameObjects()
{

}
