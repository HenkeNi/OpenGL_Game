#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct CameraAttributes
{
	glm::vec3 position{ 0.0f, 0.0f, 0.0f };
	glm::vec3 front{ 0.0f, 0.0f, 1.0f };
	glm::vec3 up{ 0.0f, 1.0f, 0.0f };
	glm::vec3 right;
	glm::vec3 worldUp;
};