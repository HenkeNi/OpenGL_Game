#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

//#include <optional>
//#include <string>

/*
*	Class for creating a Shader program	
*/
class Shader
{
public:
	bool loadFromFile(const std::string& vertexPath, const std::string& fragmentPath, const std::string& geometryPath = "");
	void attachShaders(unsigned int vertex, unsigned int fragment, std::optional<unsigned int> geometry);
	void checkCompileErrors(unsigned int object, const std::string& type) const;

	unsigned int compileShader(unsigned int type, const char* src);
	unsigned int getId() const;

	Shader& use();

	void setFloat(const std::string& name, float value, bool useShader = false);
	void setInteger(const std::string& name, int value, bool useShader = false);

	void setVector2f(const std::string& name, float x, float y, bool useShader = false);
	void setVector2f(const std::string& name, const glm::vec2& value, bool useShader = false);

	void setVector3f(const std::string& name, float x, float y, float z, bool useShader = false);
	void setVector3f(const std::string& name, const glm::vec3& value, bool useShader = false);
	
	void setVector4f(const std::string& name, float x, float y, float z, float w, bool useShader = false);
	void setVector4f(const std::string& name, const glm::vec4& value, bool useShader = false);
	void setMatrix4(const std::string& name, const glm::mat4& matrix, bool useShader = false);


private:
	unsigned int m_id;
};

