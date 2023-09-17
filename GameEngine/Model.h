#ifndef MODELE_H
#define MODELE_H

#include "Mesh.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Material.h"

class Model {
private:
    Mesh mesh;
    int textureID;
    glm::mat4 modelM;
    Material material;

public:
    Model(Mesh m, int i , Material mat);
    Mesh getMesh();
    void setMesh(Mesh newMesh);
    int getId();
    void setId(int newId);
    glm::mat4 getT();
    void setT(glm::mat4 m);
    Material getMaterial();
};
#endif
