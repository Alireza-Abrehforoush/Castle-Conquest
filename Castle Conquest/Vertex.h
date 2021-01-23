#ifndef VERTEX_NFEWINEENQ
#define VERTEX_NFEWINEENQ
#include "MyVector.h"
template <class T>
class Vertex
{
protected:
private:
	T data;
	MyVector<Vertex> adjacent_vertices();

public:
	Vertex(int size)
		:adjacent_vertices(size)
	{
	}
};

#endif