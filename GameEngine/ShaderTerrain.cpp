#include "ShaderTerrain.h"


ShaderTerrain::ShaderTerrain(const char* vertexPath, const char* fragmentPath)
{

	std::string s1 = Utils::readFile(vertexPath);
	std::string s2 = Utils::readFile(fragmentPath);

	const char* vertex = s1.c_str();
	const char* fragment = s2.c_str();


	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderID, 1, &vertex, NULL);
	glCompileShader(vertexShaderID);

	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID, 1, &fragment, NULL);
	glCompileShader(fragmentShaderID);

	programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}

void ShaderTerrain::start()
{
	glUseProgram(programID);
}

void ShaderTerrain::stop()
{
	glUseProgram(0);
}

void ShaderTerrain::setInt(const char* name, int value)
{
	glUniform1i(glGetUniformLocation(programID, name), value);
}

void ShaderTerrain::setFloat(const char* name, float value)
{
	glUniform1f(glGetUniformLocation(programID, name), value);
}

void ShaderTerrain::setVec3(const char* name, glm::vec3 value)
{
	glUniform3fv(glGetUniformLocation(programID, name), 1, glm::value_ptr(value));
}

void ShaderTerrain::setMat4(const char* name, glm::mat4 value)
{
	glUniformMatrix4fv(glGetUniformLocation(programID, name), 1, GL_FALSE, glm::value_ptr(value));
}


void ShaderTerrain::initProjection()
{
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(90.0f), 1.0f, 0.1f, 10000.0f);
	start();
	setMat4("projection", projection);
	stop();
}

void ShaderTerrain::setLight(Light l)
{
	start();
	setVec3("lightPos", l.getPos());
	setVec3("lightColor", l.getColor());
	stop();
}

void ShaderTerrain::initMaterial(Material m)
{
	start();
	setFloat("shineDamper", m.getShineDampness());
	setFloat("reflexivity", m.getReflexivity());
	stop();
}


