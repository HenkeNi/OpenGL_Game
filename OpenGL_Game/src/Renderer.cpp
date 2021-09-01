#include "pch.h"
#include "Renderer.h"
#include "constants/Constants.h"

//Renderer::Renderer(Shader& shader, Texture& texture)
//	: m_shader{ shader }, m_texture{ texture }
//{
//}

Renderer::Renderer()
{
	//initRenderData();
}


void Renderer::draw(Shader& shader, const Texture& texture, glm::vec3 position, glm::vec3 size, float rotate, unsigned VAO, int indices)
{
	shader.use();
	glBindVertexArray(VAO);


	// create transformations
	//glm::mat4 transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	//transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));

	//shader.use();
	//shader.setMatrix4("transform", transform);

	//glm::mat4 view		 = glm::mat4(1.f); // intialize to identity matrix
	//glm::mat4 projection = glm::mat4(1.f);

	//projection = glm::perspective(glm::radians(45.f), static_cast<float>(constants::SCR_WIDTH) / static_cast<float>(constants::SCR_HEIGHT), 0.1f, 100.f);
	//view	   = glm::translate(view, glm::vec3(0.f, 0.f, -3.f));

	//shader.setMatrix4("projection", projection);
	//shader.setMatrix4("view", view);

	//glBindVertexArray(VAO);
	//glm::mat4 model = glm::mat4(1.f);
	//model = glm::translate(model, position);
	
	//shader.setMatrix4("model", model);

	//texture.bind(0);


	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	//glm::mat4 model 
	glBindVertexArray(0);


	// bind shader
	// vao bindr
	// element index bind

	// glDrawElements(GL_TRIANGLES, index.getCount(), GL_UNSIGNED_INT, nullptr);

}


void Renderer::clearScreen()
{
	glClearColor(0.3f, 0.6f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}



//
//void Renderer::initRenderData()
//{
//	unsigned int VBO, EBO;
//
//	float vertices[] = {
//		// pos      // tex
//		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // top right
//		 0.5f, -0.5f, 0.0f,     1.0f, 0.0f, // bottom right
//		-0.5f, -0.5f, 0.0f,     0.0f, 0.0f, // bottom left
//		-0.5f,  0.5f, 0.0f,      0.0f, 1.0f  // top left 
//	};
//
//	unsigned int indices[]
//	{
//		0, 1, 3, // first triangle
//		1, 2, 3  // second triangle
//	};
//
//	m_numOfIndices = sizeof(indices) / sizeof(indices[0]);
//
//	glGenVertexArrays(1, &m_VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//
//	glBindVertexArray(m_VAO);
//	
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//
//}