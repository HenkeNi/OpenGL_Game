#pragma once

#include "Texture.h"
#include "Renderer.h"

class GameObject
{
public:
	void draw(Renderer& renderer) const;

	void setPosition(glm::vec3 position);
	void setSize(glm::vec3 size);
	void setVelocity(glm::vec3 velocity);
	void setRotation(float rotation);

private:
	Shader&		m_shader;
	Texture&	m_texture;
	glm::vec3   m_position{ 0.f, 0.f, 0.f }, m_size{ 1.f, 1.f, 1.f }, m_velocity{ 0.f, 0.f, 0.f };
	float		m_rotation{ 0.f };
};

