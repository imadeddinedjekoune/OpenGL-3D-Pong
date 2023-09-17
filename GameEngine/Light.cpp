#include "Light.h"

Light::Light(glm::vec3 p, glm::vec3 c)
{
	pos = p;
	color = c;
}

glm::vec3 Light::getPos()
{
	return pos;
}

glm::vec3 Light::getColor()
{
	return color;
}
