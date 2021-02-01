#pragma once
#include "Vertex.h"
template <class T>
class Edge
{
protected:
private:
	T data;
	double weight;
	Vertex<T>* head;
	Vertex<T>* tail;
public:
	Edge()
		:weight(0)
		,head(nullptr)
		,tail(nullptr)
	{
	}
	Edge(const Edge<T>& obj)
	{
		this->data = obj.data;
		this->weight = obj.weight;
		this->head = obj.head;
		this->tail = obj.tail;
	}
	Edge(const T& data, Vertex<T>* head = nullptr, Vertex<T>* tail = nullptr, double weight = 0)
		:data(data)
		,head(head)
		,tail(tail)
		,weight(weight)
	{
	}
	void setData(const T& data)
	{
		this->data = data;
		return;
	}
	void setWeight(double weight = 0)
	{
		this->weight = weight;
		return;
	}
	void setHead(Vertex<T>* head = nullptr)
	{
		this->head = head;
		return;
	}
	void setTail(Vertex<T>* tail = nullptr)
	{
		this->tail = tail;
		return;
	}
	T& getData() const
	{
		return this->data;
	}
	double getWeight() const
	{
		return this->weight;
	}
	Vertex<T>* getHead() const
	{
		return this->head;
	}
	Vertex<T>* getTail() const
	{
		return this->tail;
	}

};

