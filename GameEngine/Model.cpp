#include "Model.h"

Model::Model(Mesh m, int i , Material mat) : mesh(m), textureID(i) , material(mat)
{
    modelM = glm::mat4(1.0);

}

Mesh Model::getMesh() { return mesh; }
void Model::setMesh(Mesh newMesh) { mesh = newMesh; }

int Model::getId() { return textureID; }
void Model::setId(int newId) { textureID = newId; }

glm::mat4 Model::getT()
{
    return modelM;
}

void Model::setT(glm::mat4 m)
{
    modelM = m;
}


Material Model::getMaterial()
{
    return material;
}