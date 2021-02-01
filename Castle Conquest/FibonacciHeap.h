#ifndef FIBONACCIHEAP_QBSHBDHBBYFEHBUJVHNE
#define FIBONACCIHEAP_QBSHBDHBBYFEHBUJVHNE
#include <cmath>
#include "FibonacciHeapNode.h"
template <class T>
class FibonacciHeap
{
protected:
private:
	FibonacciHeapNode<T>* king_root;
	FibonacciHeapNode<T>* minimum_element;
	int size_of_heap;

	void consolidate()
	{
		FibonacciHeapNode<T>** degrees_list = new FibonacciHeapNode<T> * [ceil(log2(this->size_of_heap))];
		FibonacciHeapNode<T>* next = this->king_root->getChild();
		FibonacciHeapNode<T>* end = next->getLeft();

		for (int i = 0; i < this->size_of_heap; i++)
		{
			degrees_list[i] = nullptr;
		}
		for (FibonacciHeapNode<T>* y = this->king_root->getChild(); ; )
		{
			next = y->getRight();
			while (true)
			{
				if (degrees_list[y->getDegree()] == nullptr)
				{
					degrees_list[y->getDegree()] = y;
					break;
				}
				else
				{
					if (y->getData() > degrees_list[y->getDegree()]->getData())
					{
						this->king_root->unlinkChild(y);
						degrees_list[y->getDegree()]->setChild(y);
						y = y->getParent();
					}
					else
					{
						int degree_of_y = y->getDegree();
						this->king_root->unlinkChild(degrees_list[y->getDegree()]);
						y->setChild(degrees_list[y->getDegree()]);
						degrees_list[degree_of_y] = nullptr;
					}
				}
			}
			y = y->getRight();
			if (y == this->king_root->getChild())
			{
				break;
			}
		}
		delete[] degrees_list;
		degrees_list = nullptr;
	}
public:
	FibonacciHeap()
	{
	}
	FibonacciHeap(const T& head)
	{
		this->king_root = new FibonacciHeapNode<T>(head);
		this->minimum = new FibonacciHeapNode<T>(head);
		this->king_root->setChild(this->minimum_element);
		this->size_of_heap++;
	}
	void insert(const T& data)
	{
		FibonacciHeapNode<T>* x = new FibonacciHeapNode<T>(data);
		this->king_root->setChild(x);
		if (data < this->minimum_element->getData())
		{
			this->minimum_element = x;
		}
		this->size_of_heap++;
	}
	T extractMinimum()
	{
		FibonacciHeapNode<T>* kemp = minimum_element;
		T data = kemp->getData();
		this->king_root->unlinkChild(this->minimum_element);
		while (minimum_element->getChild())
		{
			FibonacciHeapNode<T>* temp = minimum_element->getChild();
			this->minimum_element->unlinkChild(temp);
			king_root->setChild(temp);
		}
		this->setMinimum();
		this->consolidate();
		delete kemp;
		kemp = nullptr;
		this->size_of_heap--;
		return data;
	}
	void setMinimum()
	{
		if (!king_root->hasChild())
		{
			return;
		}
		else
		{
			T min = king_root->getChild()->getData();
			for (FibonacciHeapNode<T>* it = king_root->getChild(); ; it = it->getRight())
			{
				if (min > it->getData())
				{
					minimum_element = it;
					min = it->getData();
				}
				if (it == king_root->getChild()->getLeft())
				{
					break;
				}
			}
		}
		
	}
};

#endif