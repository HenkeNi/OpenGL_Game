#include "pch.h"
#include "GameObject.h"


void GameObject::setPosition(glm::vec3 position)
{
	m_position = position;
}

void GameObject::setSize(glm::vec3 size)
{
	m_size = size;
}