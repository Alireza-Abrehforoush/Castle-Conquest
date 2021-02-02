#ifndef MYQUEUE_NOOJCNELN
#define MYQUEUE_NOOJCNELN
#include "QueueNode.h"
template <class T>
class MyQueue
{
protected:
private:
	QueueNode<T>* front;
	QueueNode<T>* rear;
public:
	MyQueue()
		: front(nullptr)
		, rear(nullptr)
	{
	}
	void enQueue(const T& x)
	{
		QueueNode<T>* temp = new QueueNode<T>(x);
		if (this->rear == nullptr)
		{
			this->front = temp;
			this->rear = temp;
		}
		else
		{
			this->rear->setNext(temp);
			this->rear = temp;
		}
		return;
	}
	void deQueue()
	{
		if (this->front == nullptr)
		{
			return;
		}
		else
		{
			QueueNode<T>* temp = this->front;
			this->front = this->front->getNext();
			if (this->front == nullptr)
			{
				this->rear = nullptr;
			}
			delete (temp);
			temp = nullptr;
			return;
		}
	}
	~MyQueue()
	{
		while (this->rear != nullptr)
		{
			this->deQueue();
		}
	}
};

#endif