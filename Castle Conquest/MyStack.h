#ifndef MYSTACK_BICHBEVIYKEB
#define MYSTACK_BICHBEVIYKEB
#include <iostream>
#include "StackNode.h"
template <class T>
class MyStack
{
protected:
private:
	StackNode<T>* top;
public:
	MyStack()
	{
	}
	void push(const T& data)
	{
		StackNode<T>* temp;
		temp = new StackNode<T>();
		if (!temp)
		{
			throw "\nHeap Overflow";
		}
		else
		{
			temp->setData(data);
			temp->setLink(this->top);
			this->top = temp;
		}
	}
	bool isEmpty()
	{
		if (this->top == nullptr) return true;
		else return false;
	}
	int peek()
	{
		if (!isEmpty())
		{
			return top->getData();
		}
		else
		{
		}
	}
	void pop()
	{
		StackNode<T>* temp;
		if (top == nullptr)
		{
			throw("\nStack Underflow");
		}
		else
		{
			temp = top;
			top = top->getLink();
			temp->setLink(nullptr);
			delete temp;
			temp = nullptr;
		}
	}
	void display()
	{
		StackNode<T>* temp;
		if (this->top == nullptr)
		{
			throw("\nStack Underflow");
		}
		else
		{
			temp = this->top;
			while (temp != nullptr)
			{
				std::cout << temp->getData() << "-> ";
				temp = temp->getLink();
			}
		}
	}
	~MyStack()
	{
		while (this->isEmpty() == false)
		{
			this->pop();
		}
	}
};

#endif