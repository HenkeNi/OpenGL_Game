#pragma once

#include <GL/glew.h>
//#include <string>

class Texture
{
public:	
	bool loadFromFile(const std::string& filename, bool alpha);

	void bind(int unit)   const;
	void unbind() const;
	void generate(unsigned int width, unsigned int height, unsigned char* data);

	inline unsigned int& getId() { return m_id; }

	static unsigned int getNextTextureUnit();

private:
	unsigned int m_id;
	unsigned int m_internalFormat{ GL_RGB }, m_imageFormat{ GL_RGB };
};

