#include "Camera.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>



Camera::Camera(glm::vec3 cameraPosition, glm::vec3 cameraFront, glm::vec3 cameraUp, float field_of_view, float pitch, float yaw, float width, float height)
{
	this->cameraPosition = cameraPosition;
	this->cameraFront = cameraFront;
	this->cameraUp = cameraUp;
	this->field_of_view = field_of_view;
	setView(cameraPosition,
			cameraPosition + cameraFront,
			cameraUp);
	//setProjection(width,height);
	setOrtho(width,height);
	updateCameraVectors();
}


Camera::~Camera()
{
}

void Camera::setFOV(float fov)
{
	this->field_of_view = fov;
}

void Camera::setPitch(float pitch)
{
	this->pitch = pitch;
}

void Camera::setView(glm::vec3 cameraPos, glm::vec3 cameraCenter, glm::vec3 cameraUp)
{
	this->view = glm::lookAt(cameraPos,
							cameraCenter,
							cameraUp);
}

void Camera::setProjection(float width,float height)
{
	this->projection = glm::perspective(glm::radians(this->field_of_view),
										(float) width/(float)height,
										0.1f,
										1000.0f);
}

void Camera::setOrtho(float width, float height)
{
	this->projection = glm::ortho(-25.0f,
								25.0f,
								-25.0f,
								25.0f,
								-25.0f,
								25.0f);
}

void Camera::setCameraPos(glm::vec3 cameraPos)
{
	this->cameraPosition = cameraPos;
	setView(cameraPosition,cameraPosition+cameraFront,cameraUp);
	updateCameraVectors();
}
void Camera::setCameraSpeed(float speed)
{
	this->speed = speed;
}

float Camera::getFOV()
{
	return field_of_view;
}

float Camera::getPitch()
{
	return pitch;
}

glm::mat4 Camera::getViewMatrix()
{
	return view;
}
glm::mat4 Camera::getPerspectiva()
{
	return projection;
}

glm::vec3 Camera::getCameraPos()
{
	return cameraPosition;
}

glm::vec3 Camera::getCameraFront()
{
	return cameraFront;
}

glm::vec3 Camera::getCameraUp()
{
	return cameraUp;
}

void Camera::updateCameraVectors()
{
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);
	// Also re-calculate the Right and Up vector
	//cameraRight = glm::normalize(glm::cross(front, up));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	//cameraUp = glm::normalize(glm::cross(Right, Front));
}
