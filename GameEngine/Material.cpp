#include "Material.h"

Material::Material(float shine, float ref)
{
	shineDampness = shine;
	reflexivity = ref;
}

float Material::getShineDampness()
{
	return shineDampness;
}

float Material::getReflexivity()
{
	return reflexivity;
}
