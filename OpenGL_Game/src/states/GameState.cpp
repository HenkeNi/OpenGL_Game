#include "pch.h"
#include "GameState.h"
#include "../constants/Constants.h"

#include <GL/glew.h>
//#include <glm/glm.hpp>

//#include <iostream>


GameState::GameState(StateStack& stateStack, SharedContext context)
	: State{ stateStack, context }
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

	//float vertices[]
	//{
	//	// positions          // colors           // texture coords
	// -0.5f, -0.5f,  0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left - front
	// -0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f, // top left    
	//  0.5f,  0.5f,  0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right   
	//  0.5f, -0.5f,  0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right

	// -0.5f, -0.5f,  -0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
	// -0.5f,  0.5f,  -0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f, // top left 
	//  0.5f,  0.5f,  -0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
	//  0.5f, -0.5f,  -0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
	//};

	//unsigned int indices[] = {
	//  0, 1, 2, // FRONT
	//  2, 3, 0,

	//  4, 5, 6, // BACK
	//  6, 7, 4,

	//  4, 5, 1, // LEFT
	//  1, 0, 4,

	//  3, 2, 6, // RIGHT
	//  6, 7, 3,

	//  1, 5, 6, // TOP
	//  6, 2, 1,

	//  0, 4, 7, // DOWN
	//  7, 3, 0

	//};



	//unsigned int VBO, EBO;
	//glGenVertexArrays(1, &m_VAO);
	//glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);

	//glBindVertexArray(m_VAO);

	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//// position attrib
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(0);

	//// color attrib
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	//glEnableVertexAttribArray(1);
	//// texture coord attribute
	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	//glEnableVertexAttribArray(2);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);



}

void GameState::handleEvent()
{

}

void GameState::update(double dt)
{

}

void GameState::draw(Renderer& renderer)
{
	m_context.m_shaderManager->getResource("default").setInteger("texture1", 0);


	m_context.m_textureManager->getResource("player").bind(GL_TEXTURE0);
	m_context.m_shaderManager->getResource("default").use();



	



	//// create transformations
	//glm::mat4 view = glm::mat4(1.0f); // identity matrix
	//glm::mat4 projection = glm::mat4(1.0f);
	//projection = glm::perspective(glm::radians(45.f), (float)constants::SCR_WIDTH / (float)constants::SCR_HEIGHT, 0.1f, 100.f);
	//view = glm::translate(view, glm::vec3(0.f, 0.f, -1.f));

	//m_context.m_shaderManager->getResource("default").setMatrix4("projection", projection);
	//m_context.m_shaderManager->getResource("default").setMatrix4("view", view);

	//// render boxes
	//glBindVertexArray(m_VAO);
	//
	//
	//glm::mat4 model = glm::mat4(1.f);
	//model = glm::translate(model, glm::vec3{ 0.f, 0.f, 0.f });
	//m_context.m_shaderManager->getResource("default").setMatrix4("model", model);
	//glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	//



	//renderer.draw(m_context.m_shaderManager->getResource("default")); // TEST....
}

void GameState::initGameObjects()
{

}
