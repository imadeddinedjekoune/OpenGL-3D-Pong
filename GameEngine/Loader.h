#ifndef LOADER_H
#define LOADER_H

#include <stdio.h>
#include <glad/glad.h>
#include "Mesh.h"
#include <stb/stb_image.h>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include "objload.h"

class Loader {

public:
    static Mesh loadToVao_PTN(const char *path);
    static Mesh loadToVao(float* positions, float* textures, int* indices, int* sizes);
    static Mesh loadToVao(float* positions, float* textures, float* normals, int* sizes);
    static Mesh loadToVao(float* positions, float* textures, int* sizes);

    static int loadTexture(const char* path , GLenum format);

private:
    static int createVAO();
    static void unbindVAO();
    static void storeDataInAttributeList(int index, GLfloat verts[], int size , int len);
    static void bindIndicesBuffer(int* indexs, int len);
    
};

#endif