#include "Camera.h"
#include <GLFW/glfw3.h>

Camera::Camera()
{
	position = glm::vec3(0, 0.0, 0);
}

void Camera::move(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		position.z -= 0.001f;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		position.z += 0.001f;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		position.x -= 0.001f;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		position.x += 0.001f;
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		position.y -= 0.001f;
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		position.y += 0.001f;
	}
	/*
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		pitch += 0.05f;
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		pitch -= 0.05f;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		yaw -= 0.05f;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		yaw += 0.05f;
	}
	*/
}

glm::mat4 Camera::getViewMatrix()
{
	glm::mat4 viewMatrix(1.0f);

	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	glm::vec3 Front = glm::normalize(front);
	// also re-calculate the Right and Up vector
	glm::vec3 Right = glm::normalize(glm::cross(Front, glm::vec3(0.0f, 1.0f, 0.0f)));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	glm::vec3 Up = glm::normalize(glm::cross(Right, Front));

	viewMatrix = glm::lookAt(position, position+ glm::vec3(0.0f, 0.0f, -1.0f), Up);
	return viewMatrix;
}




