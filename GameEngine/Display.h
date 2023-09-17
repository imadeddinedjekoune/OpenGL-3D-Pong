#ifndef DISPLAY_H
#define DISPLAY_H

using namespace std;
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class DisplayManager {
public:
	static GLFWwindow* createDisplay();
	static int windowRequestClose(GLFWwindow* window);
	static void updateDisplay(GLFWwindow* window);
	static void destroyDisplay(GLFWwindow* window);
};

#endif
