#ifndef MATERIAL_H
#define MATERIAL_H

class Material {
private :
	float shineDampness;
	float reflexivity;
public:
	Material(float shine , float ref );
	float getShineDampness();
	float getReflexivity();
};

#endif