#include "pch.h"
#include "GameObject.h"




GameObject::GameObject(Shader& shader, Texture& texture, glm::vec3 position)
	: m_shader{ shader }, m_texture{ texture }, m_position{ position }
{
	initData();
}


GameObject::~GameObject()
{
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);
	glDeleteBuffers(1, &m_EBO);
}


void GameObject::draw(Renderer& renderer) const
{
	renderer.draw(m_shader, m_texture, m_position, m_size, m_rotation, m_VAO, m_numOfIndices);
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
	float vertices[] 
	{
		// positions          // texture coords
		 0.5f,  0.5f, 0.0f,   //1.0f, 1.0f, // top right
		 0.5f, -0.5f, 0.0f,   //1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f,  // 0.0f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f,  // 0.0f, 1.0f  // top left 
	};

	unsigned int indices[] 
	{
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	//m_numOfIndices = sizeof(indices) / sizeof(indices[0]);

	//glGenVertexArrays(1, &m_VAO);
	//glGenBuffers(1, &m_VBO);
	//glGenBuffers(1, &m_EBO);
	//
	//glBindVertexArray(m_VAO);

	//glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//// position attribute
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(0);

	//// texture coord attribute
	////glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	////glEnableVertexAttribArray(1);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);






	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);
}