#pragma once

//#include "Shader.h"
#include "Texture.h"
#include "Renderer.h"
#include "Vertex.h"

//#include <vector>

class Mesh
{
public:
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned> indices, std::vector<Texture> textures);

	void draw(Shader& shader);
	//void draw(Renderer& renderer);

private:
	void setupMesh();

private:
	std::vector<Texture>  m_textures;
	std::vector<Vertex>   m_vertices;
	std::vector<unsigned> m_indices;
	unsigned int		  m_VAO, m_VBO, m_EBO;


};

