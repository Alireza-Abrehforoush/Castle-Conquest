#ifndef FIBONACCIHEAP_QBSHBDHBBYFEHBUJVHNE
#define FIBONACCIHEAP_QBSHBDHBBYFEHBUJVHNE
#include <iostream>
using namespace std;
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
		if (!this->king_root->hasChild())
		{
			return;
		}
		else
		{
			FibonacciHeapNode<T>** degrees_list = new FibonacciHeapNode<T> * [ceil(log2(this->size_of_heap)) + 1];
			FibonacciHeapNode<T>* next = this->king_root->getChild();
			FibonacciHeapNode<T>* end = next->getLeft();

			for (int i = 0; i < ceil(log2(this->size_of_heap)) + 1; i++)
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
	}
public:
	FibonacciHeap()
	{
	}
	FibonacciHeap(const T& head)
	{
		this->king_root = new FibonacciHeapNode<T>(head);
		this->minimum_element = new FibonacciHeapNode<T>(head);
		this->king_root->setChild(this->minimum_element);
		this->size_of_heap++;
	}
	void insert(const T& data)
	{
		FibonacciHeapNode<T>* x = new FibonacciHeapNode<T>(data);
		if (this->king_root->getChild() == nullptr)
		{
			this->minimum_element = x;
		}
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
				if (min >= it->getData())
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
	void decreaseKey(FibonacciHeapNode<T>* x, const T& y)
	{
		x->setData(y);
		if (x->getParent() == this->king_root)
		{
			if (x->getData() < this->minimum_element->getData())
			{
				this->king_root->getChild() = x;
			}
		}
		if (x->getData() < x->getParent()->getData())
		{
			for (FibonacciHeapNode<T>* temp = x; temp->getParent() != this->king_root; )
			{
				FibonacciHeapNode<T>* kemp = temp->getParent();
				bool mrk = kemp->isMarked();
				kemp->unlinkChild(temp);
				this->king_root->setChild(temp);
				temp->setMarkStatus(false);
				if (mrk == false)
				{
					break;
				}
				else
				{
					kemp->setMarkStatus(true);
					temp = kemp;
				}
			}
		}
	}
	void deleteSubtree(FibonacciHeapNode<T>* x)
	{
		x->setDeleteStatus(true);
		if (x->getChild() != nullptr)
		{
			deleteSubtree(x->getChild());
		}
		if (x->getRight() && x->getRight()->isDeleted() == false)
		{
			deleteSubtree(x->getRight());
		}
		if (x->getParent() != nullptr)
		{
			x->getParent()->unlinkChild(x);
		}
		delete x;
		x = nullptr;
	}
	int display(FibonacciHeapNode<T>* H)
	{
		FibonacciHeapNode<T>* p = H;
		if (p == nullptr)
		{
			cout << "Empty Heap" << endl;
			return 0;
		}
		cout << "Root Nodes: " << endl;

		do {
			cout << p->getData();
			p = p->getRight();
			if (p != H) {
				cout << "-->";
			}
		} while (p != H && p->getRight() != nullptr);
		cout << endl;
	}
	void print()
	{
		display(this->king_root->getChild()->getChild());
	}
	~FibonacciHeap()
	{
		T king_root_data = king_root->getData();
		this->deleteSubtree(this->king_root);
		this->king_root = new FibonacciHeapNode<T>(king_root->getData());
		this->size_of_heap = 0;
	}
};

#endif