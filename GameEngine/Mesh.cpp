#include "Mesh.h"

Mesh::Mesh(int id, int nb)
{
	vaoID = id;
	vertexCount = nb;
}

int Mesh::getVaoID()
{
	return vaoID;
}

int Mesh::getVertexCount()
{
	return vertexCount;
}
