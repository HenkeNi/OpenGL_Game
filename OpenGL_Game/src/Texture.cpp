#include "pch.h"
#include "Texture.h"
#include "stb_image/stb_image.h"



bool Texture::loadFromFile(const std::string& filename, bool alpha)
{
	if (alpha)
	{
		m_internalFormat = GL_RGBA;
		m_imageFormat    = GL_RGBA;
	}


	// load image
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);

	if (!data)
		return false;

	// generate texture
	generate(width, height, data);

	// free image data
	stbi_image_free(data);
	
	return true;
}


void Texture::bind(int unit) const
{
	glActiveTexture(GL_TEXTURE + unit);
	glBindTexture(GL_TEXTURE_2D, m_id);
}

void Texture::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::generate(unsigned int width, unsigned int height, unsigned char* data)
{
	// create texture
	glGenTextures(1, &m_id);
	glBindTexture(GL_TEXTURE_2D, m_id);

	// set texture wrap and filter modes
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, m_internalFormat, width, height, 0, m_imageFormat, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	unbind();
}


