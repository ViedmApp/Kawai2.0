#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
private:
	float yaw = -90.;
	float pitch = 0.0f;
	float field_of_view = 45.;
	float speed;
	float sensitivity;
	float zoom;

	glm::vec3 cameraPosition;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	glm::vec3 cameraRight;

	glm::mat4 projection;
	glm::mat4 view;

public:
	Camera(glm::vec3 cameraPosition, glm::vec3 cameraFront, glm::vec3 cameraUp, float field_of_View, float pitch, float yaw, float width, float height);
	~Camera();

	//setters
	void setFOV(float fov);
	void setPitch(float pitch);
	void setProjection(float width,float height);
	void setOrtho(float width, float height);
	void setCameraPos(glm::vec3 cameraPos);
	void setCameraSpeed(float speed);
	void setView(glm::vec3 cameraPos, glm::vec3 cameraCenter, glm::vec3 cameraUp);

	//getters
	float getFOV();
	float getPitch();
	glm::mat4 getViewMatrix();
	glm::mat4 getPerspectiva();
	glm::vec3 getCameraFront();
	glm::vec3 getCameraPos();
	glm::vec3 getCameraUp();

private:
	void updateCameraVectors();
};
