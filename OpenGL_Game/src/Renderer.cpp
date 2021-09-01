#include "pch.h"
#include "Renderer.h"
#include "constants/Constants.h"

//Renderer::Renderer(Shader& shader, Texture& texture)
//	: m_shader{ shader }, m_texture{ texture }
//{
//}


void Renderer::draw(Shader& shader, const Texture& texture, glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f);
{
	shader.use();
	texture.bind(0);

	glm::mat4 view		 = glm::mat4(1.f); // intialize to identity matrix
	glm::mat4 projection = glm::mat4(1.f);

	projection = glm::perspective(glm::radians(45.f), static_cast<float>(constants::SCR_WIDTH) / static_cast<float>(constants::SCR_HEIGHT), 0.1f, 100.f);
	view	   = glm::translate(view, glm::vec3(0.f, 0.f, -3.f));

	shader.setMatrix4("projection", projection);
	shader.setMatrix4("view", view);

	glBindVertexArray(VAO);
	glm::mat4 model = glm::mat4(1.f);
	model = glm::translate(model, position);
	
	shader.setMatrix4("model", model);
	glDrawElements(GL_TRIANGLES, numOfIndices, GL_UNSIGNED_INT, 0);

	//glm::mat4 model 



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




void Renderer::initRenderData()
{

}