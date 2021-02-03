#ifndef GRAPH_OMMJHBHDWBB
#define GRAPH_OMMJHBHDWBB
#include <map>
#include "MyVector.h"
#include "Edge.h"
template <class T, class U>
class Graph
{
protected:
private:
	MyVector<MyVector<Edge<T, U>*>> adjacency_matrix;
	map<Vertex<T>*, int> indices_map;
public:
	Graph()
	{
	}
	Graph(const MyVector<Vertex<T>>& vertices)
	{
		for (int i = 0; i < vertices.getSize(); i++)
		{
			Vertex<T>* t = new Vertex<T>(vertices[i].getData());
			this->indices_map.insert(pair<Vertex<T>*, int>(t, i));
		}
		MyVector<Edge<U>*> k;
		for (int i = 0; i < vertices.getSize(); i++)
		{
			k.push(nullptr);
		}
		for (int i = 0; i < vertices.getSize(); i++)
		{
			this->adjacency_matrix.push(k);
		}
	}
	void addEdge(const Edge<T, U>& x)
	{
		Vertex<T>* h = x.getHead();
		Vertex<T>* t = x.getTail();
		int ih = indices_map[h];
		int it = indices_map[t];
		this->adjacency_matrix[ih][it] = new Edge<T, U>(x);
		return;
	}
	void addVertex(const T& x)
	{
		Vertex<T>* kemp = new Vertex<T>(x);
		indices_map.insert(pair<Vertex<T>*, int>(kemp, indices_map.size()));
	}
	int getNumberOfVertices() const
	{
		return indices_map.size();
	}
	~Graph()
	{
		for (int i = 0; i < this->adjacency_matrix.getSize(); i++)
		{
			for (int j = 0; j < this->adjacency_matrix[i].getSize(); j++)
			{
				delete adjacency_matrix[i][j];
				adjacency_matrix[i][j] = nullptr;
			}
		}
		for (auto k = indices_map.begin(); k != indices_map.end(); k++)
		{
			delete k->first;
		}
	}
};

#endif