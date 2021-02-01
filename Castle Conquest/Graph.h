#ifndef GRAPH_OMMJHBHDWBB
#define GRAPH_OMMJHBHDWBB
#include <map>
#include "MyVector.h"
#include "Edge.h"
template <class T>
class Graph
{
protected:
private:
	MyVector<MyVector<Edge<T>*>> adjacency_matrix;
	map<Vertex<T>*, int> indices_map;
public:
	Graph(const MyVector<Vertex>& vertices)
	{
		for (int i = 0; i < vertices.getSize(); i++)
		{
			Vertex<T>* t = new Vertex<T>(vertices[i].getData());
			indices_map.insert(pair<Vertex<T>*, int>(t, i));
		}
		MyVector<Edge<T>*> k;
		for (int i = 0; i < vertices.getSize(); i++)
		{
			k.push(nullptr);
		}
		for (int i = 0; i < vertices.getSize(); i++)
		{
			adjacency_matrix.push(k);
		}
	}
};

#endif