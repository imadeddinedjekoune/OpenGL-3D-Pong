#ifndef LIGHT_H
#define LIGHT_H
#include <glm/glm.hpp>

class Light {
private:
    glm::vec3 pos;
    glm::vec3 color;


public:
    Light(glm::vec3 p , glm::vec3 c);
    glm::vec3 getPos();
    glm::vec3 getColor();
};
#endif
