#pragma once

#include "Texture.h"

class GameObject
{
public:

	void setPosition(glm::vec3 position);
	void setSize(glm::vec3 size);

private:
	Texture		m_texture;
	glm::vec3   m_position{ 0.f, 0.f, 0.f }, m_size{ 1.f, 1.f, 1.f }, m_velocity{ 0.f, 0.f, 0.f };
	float		m_rotation{ 0.f };
};

