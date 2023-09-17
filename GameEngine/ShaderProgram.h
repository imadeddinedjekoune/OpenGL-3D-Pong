#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Utils.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Light.h"
#include "Material.h"

class ShaderProgram {
private:

	int vertexShaderID;
	int fragmentShaderID;
public:
	int programID;
	ShaderProgram(const char *vertex , const char *fragment);
	void start();
	void stop();
	void setInt(const char* name, int value);
	void setFloat(const char* name, float value);
	void setVec3(const char* name, glm::vec3 value);
	void setMat4(const char* name, glm::mat4 value);
	void setLight(Light l);
	void initProjection();
	void initMaterial(Material m);

};

#endif
