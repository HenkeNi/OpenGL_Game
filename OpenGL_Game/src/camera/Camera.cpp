#include "pch.h"
#include "Camera.h"

Camera::Camera(glm::vec3 position)
	: m_attributes{ position, { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }
{
	//m_attributes.position = position;
}


Camera::Camera(const CameraAttributes& attrib, const CameraOptions& opt, const EulerAngles& ang)
	: m_attributes{ attrib }, m_options{ opt }, m_angles{ ang }
{
	updateCameraVectors();
}



glm::mat4 Camera::getViewMatrix() const
{
	return glm::lookAt(m_attributes.position, m_attributes.position + m_attributes.front, m_attributes.up);
}

void Camera::processKeyboard(CamerMovement direction, float dt)
{
	float velocity = m_options.movementSpeed * dt;

	if (direction == FORWARD)
		m_attributes.position += m_attributes.front * velocity;
	if (direction == BACKWARD)
		m_attributes.position -= m_attributes.front * velocity;
	if (direction == LEFT)
		m_attributes.position -= m_attributes.right * velocity;
	if (direction == RIGHT)
		m_attributes.position += m_attributes.right * velocity;
}


void Camera::processMouseMovement(float xoffset, float yoffset, bool constrainPitch)
{
	xoffset *= m_options.mouseSensitivity;
	yoffset *= m_options.mouseSensitivity;

	m_angles.yaw   += xoffset;
	m_angles.pitch += yoffset;

	if (constrainPitch)
	{
		if (m_angles.pitch > 89.0f)
			m_angles.pitch = 89.0f;
		if (m_angles.pitch < -89.0f)
			m_angles.pitch = -89.0f;
	}

	updateCameraVectors();
}


void Camera::processMouseScroll(float yoffset)
{
	m_options.zoom -= yoffset;

	if (m_options.zoom < 1.0f)
		m_options.zoom = 1.0f;
	if (m_options.zoom > 45.0f)
		m_options.zoom = 45.0f;
}


void Camera::updateCameraVectors()
{
	// calculate new front vector
	glm::vec3 front;
	front.x = cos(glm::radians(m_angles.yaw)) * cos(glm::radians(m_angles.pitch));
	front.y = sin(glm::radians(m_angles.pitch));
	front.z = sin(glm::radians(m_angles.yaw)) * cos(glm::radians(m_angles.pitch));
	
	m_attributes.front = glm::normalize(front);
	
	// re-calculate right and up vector
	m_attributes.right = glm::normalize(glm::cross(m_attributes.front, m_attributes.worldUp));
	m_attributes.up    = glm::normalize(glm::cross(m_attributes.right, m_attributes.front));
}
