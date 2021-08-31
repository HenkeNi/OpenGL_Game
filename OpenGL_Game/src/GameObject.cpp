#include "pch.h"
#include "GameObject.h"





void GameObject::draw(Renderer& renderer) const
{
	//renderer.draw()
}



void GameObject::setPosition(glm::vec3 position)
{
	m_position = position;
}

void GameObject::setSize(glm::vec3 size)
{
	m_size = size;
}

void GameObject::setVelocity(glm::vec3 velocity)
{
	m_velocity = velocity;
}

void GameObject::setRotation(float rotation)
{
	m_rotation = rotation;
}