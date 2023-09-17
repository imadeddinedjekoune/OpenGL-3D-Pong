#include "Loader.h"


Mesh Loader::loadToVao_PTN(const char* path)
{
    std::vector<glm::vec3> position;
    std::vector<glm::vec2> texture;
    std::vector<glm::vec3> normals;

    loadOBJ(path, position, texture, normals);

    float* positions = reinterpret_cast<float*>(position.data());
    float* texts = reinterpret_cast<float*>(texture.data());
    float* nomarls = reinterpret_cast<float*>(normals.data());


    int sizes[] = { position.size() * 3,texture.size() * 2,normals.size() * 3 };

    return Loader::loadToVao(positions, texts, nomarls, sizes);
}

Mesh Loader::loadToVao(float* positions, float* textures, int *indices,int *sizes)
{
    int VAO = createVAO();

    storeDataInAttributeList(0, positions, 3 , sizes[0]);
    storeDataInAttributeList(1, textures, 2, sizes[1]);
    bindIndicesBuffer(indices,sizes[2]);

    unbindVAO();
    return Mesh(VAO, (sizeof(indices) / sizeof(int))+1 );
}

Mesh Loader::loadToVao(float* positions, float* textures, float* normals, int* sizes)
{
    int VAO = createVAO();

    storeDataInAttributeList(0, positions, 3, sizes[0]);
    storeDataInAttributeList(1, textures, 2, sizes[1]);
    storeDataInAttributeList(2, normals, 3, sizes[2]);


    unbindVAO();
    return Mesh(VAO, sizes[0] / 3);
}

Mesh Loader::loadToVao(float* positions, float* textures, int* sizes)
{
    int VAO = createVAO();

    storeDataInAttributeList(0, positions, 3, sizes[0]);
    storeDataInAttributeList(1, textures, 2, sizes[1]);

    unbindVAO();
    return Mesh(VAO, sizes[0]/3);
}

int Loader::createVAO()
{
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    return VAO;
}

void Loader::unbindVAO()
{
    glBindVertexArray(0);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Loader::storeDataInAttributeList(int index, GLfloat verts[], int size , int len)
{
    GLfloat *vert = (GLfloat*)malloc(sizeof(GLfloat) * len);
    for (int i = 0; i < len; i++)
    {
        vert[i] = verts[i];
    }

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * len, vert, GL_STATIC_DRAW);
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, size * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::bindIndicesBuffer(int* indexes , int len)
{
    int *ind = (int*)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        ind[i] = indexes[i];
    }

    GLuint EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)* len, ind, GL_STATIC_DRAW);
}

int Loader::loadTexture(const char *pathImage , GLenum format)
{
    unsigned int texture1;
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    
    unsigned char* data = stbi_load(pathImage, &width, &height, &nrChannels, 0 );
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    return texture1;
}


