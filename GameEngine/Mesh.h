#ifndef MESH_H
#define MESH_H

class Mesh {
private:
    int vaoID;
    int vertexCount;

public:
    Mesh(int id, int nb);
    int getVaoID();
    int getVertexCount();
}; 
#endif
