#include "pch.h"
#include "Shader.h"
#include "../FileHandler.h"

#include <GL/glew.h>
//#include <glm/glm.hpp>


//#include <fstream>
//#include <iostream>
//#include <optional>
//#include <sstream>



bool Shader::loadFromFile(const std::string& vertexPath, const std::string& fragmentPath, const std::string& geometryPath)
{
	unsigned int vertex, fragment;
	std::optional<unsigned int> geometry;

	vertex = compileShader(GL_VERTEX_SHADER, file_handler::getContentFromFile(vertexPath).c_str());
	fragment = compileShader(GL_FRAGMENT_SHADER, file_handler::getContentFromFile(fragmentPath).c_str());

	if (!geometryPath.empty())
		geometry.value() = compileShader(GL_GEOMETRY_SHADER, file_handler::getContentFromFile(geometryPath).c_str());

	if (vertex == 0 || fragment == 0)
		return false;

	m_id = glCreateProgram();
	attachShaders(vertex, fragment, geometry);

	return true; // TODO: FIX return false if failed
}


void Shader::attachShaders(unsigned int vertex, unsigned int fragment, std::optional<unsigned int> geometry)
{
	glAttachShader(m_id, vertex);
	glAttachShader(m_id, fragment);

	if (geometry)
		glAttachShader(m_id, geometry.value());

	glLinkProgram(m_id);
	checkCompileErrors(m_id, "PROGRAM");

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	if (geometry)
		glDeleteShader(geometry.value());
}


void Shader::checkCompileErrors(unsigned int object, const std::string& type) const
{
	int success;
	char infoLog[1024];

	type == "PROGRAM" ? glGetProgramiv(object, GL_LINK_STATUS, &success) : glGetShaderiv(object, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		type == "PROGRAM" ? glGetProgramInfoLog(object, 1024, nullptr, infoLog) : glGetShaderInfoLog(object, 1024, nullptr, infoLog);
		std::cout << "ERROR::" << (type == "PROGRAM" ? "PROGRAM" : "SHADER");
	}
}


unsigned int Shader::compileShader(unsigned int type, const char* src)
{
	unsigned int shaderId = glCreateShader(type);
	glShaderSource(shaderId, 1, &src, nullptr);
	glCompileShader(shaderId);

	auto shaderType{ type == GL_VERTEX_SHADER ? "VERTEX" : type == GL_FRAGMENT_SHADER ? "FRAGMENT" : "GEOMETRY" };
	checkCompileErrors(shaderId, shaderType);

	return shaderId;
}


unsigned int Shader::getId() const
{
	return m_id;
}


Shader& Shader::use()
{
	glUseProgram(m_id);
	return *this;
}


void Shader::setFloat(const std::string& name, float value, bool useShader)
{
	if (useShader)
		use();

	glUniform1f(glGetUniformLocation(m_id, name.c_str()), value);
}

void Shader::setInteger(const std::string& name, int value, bool useShader)
{
	if (useShader)
		use();

	glUniform1i(glGetUniformLocation(m_id, name.c_str()), value);
}

void Shader::setVector2f(const std::string& name, float x, float y, bool useShader)
{
	if (useShader)
		use();

	glUniform2f(glGetUniformLocation(m_id, name.c_str()), x, y);
}

void Shader::setVector2f(const std::string& name, const glm::vec2& value, bool useShader)
{
	if (useShader)
		use();

	glUniform2f(glGetUniformLocation(m_id, name.c_str()), value.x, value.y);
}

void Shader::setVector3f(const std::string& name, float x, float y, float z, bool useShader)
{
	if (useShader)
		use();

	glUniform3f(glGetUniformLocation(m_id, name.c_str()), x, y, z);
}

void Shader::setVector3f(const std::string& name, const glm::vec3& value, bool useShader)
{
	if (useShader)
		use();

	glUniform3f(glGetUniformLocation(m_id, name.c_str()), value.x, value.y, value.z);
}

void Shader::setVector4f(const std::string& name, float x, float y, float z, float w, bool useShader)
{
	if (useShader)
		use();

	glUniform4f(glGetUniformLocation(m_id, name.c_str()), x, y, z, w);
}

void Shader::setVector4f(const std::string& name, const glm::vec4& value, bool useShader)
{
	if (useShader)
		use();

	glUniform4f(glGetUniformLocation(m_id, name.c_str()), value.x, value.y, value.z, value.w);
}

void Shader::setMatrix4(const std::string& name, const glm::mat4& matrix, bool useShader)
{
	if (useShader)
		use();

	glUniformMatrix4fv(glGetUniformLocation(m_id, name.c_str()), 1, false, glm::value_ptr(matrix));
}
