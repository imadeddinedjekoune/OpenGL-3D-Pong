#include "Display.h"

GLFWwindow* DisplayManager::createDisplay()
{
	// initialiser GLFW //
	glfwInit();

	// initialiser les parametres //
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	// creer la fenetre principale //
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Test OPENGL", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to Open Window" << std::endl;
		glfwTerminate();
	}

	// fenetre comme contexte pour opengl //
	glfwMakeContextCurrent(window);

	// init opengl //
	gladLoadGL();

	glViewport(0, 0, 1280, 720);

	return window;
}

int DisplayManager::windowRequestClose(GLFWwindow* window)
{
	return glfwWindowShouldClose(window);
}

void DisplayManager::updateDisplay(GLFWwindow* window)
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void DisplayManager::destroyDisplay(GLFWwindow* window)
{
	glfwDestroyWindow(window);
	glfwTerminate();
}





