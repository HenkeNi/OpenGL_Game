#pragma once

#include "../Shader.h"
#include "../Texture.h"

// include clear screen...

class Renderer
{
public:
	Renderer() = default;
	//Renderer(Shader& shader, Texture& texture);

	//void draw(glm::vec2 position, glm::vec2 size, float rotation, glm::vec3 color = glm::vec3{ 1.f });
	void draw(Shader& shader, const Texture& texture, glm::vec3 position, glm::vec3 size = glm::vec3(10.f, 10.f, 10.f), float rotate = 0.0f);

	//void draw(Shader& shader, Texture& texture, int numOfIndices, unsigned int VAO, const glm::vec3& position); // Take in VAO, EBO?? -- take in a Material instead of a Shader?? (Material = shader + uniforms??)


	void		clearScreen();

private:
	void initRenderData();

private:
	unsigned m_VAO;
	unsigned m_numOfIndices;
	//Shader& m_shader;
	//Texture& m_texture;
};

