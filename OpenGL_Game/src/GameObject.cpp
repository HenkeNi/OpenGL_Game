#include "pch.h"
#include "GameObject.h"




GameObject::GameObject(Shader& shader, Texture& texture, glm::vec3 position)
	: m_shader{ shader }, m_texture{ texture }, m_position{ position }
{
}


void GameObject::draw(Renderer& renderer) const
{
	renderer.draw(m_shader, m_texture, m_position, m_size, m_rotation)
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


void GameObject::initData()
{
	float vertices[] = {
		// positions          // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // top right
		 0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // top left 
	};
	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	unsigned int VBO, EBO;
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}