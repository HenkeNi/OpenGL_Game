#pragma once
#include <GL/glew.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>

#include "../EulerAngles.h"
#include "CameraAttributes.h"
#include "CameraOptions.h"

class Camera
{
public:
	enum CamerMovement
	{
		FORWARD, BACKWARD, LEFT, RIGHT
	};

public:
	Camera() = default;
	Camera(glm::vec3 position);
	Camera(const CameraAttributes& attrib, const CameraOptions& opt, const EulerAngles& ang);

	glm::mat4 getViewMatrix() const;
	void processKeyboard(CamerMovement direction, float dt);
	void processMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);
	void processMouseScroll(float yoffset);

private:
	void updateCameraVectors();

private:
	CameraAttributes m_attributes;
	CameraOptions	 m_options;
	EulerAngles		 m_angles;


};

