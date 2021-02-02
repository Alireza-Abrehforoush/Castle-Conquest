#ifndef TSTACK_DFGH
#define TSTACK_DFGH
using namespace std;
#include "TNode.h"
#include "TLinkedList.h"
template <class S>
class TStack
{
private:
	TLinkedList<S> data;
public:
	TStack()
	{
		cout << "TStack Constructor is called!" << endl;
		return;
	}
	TStack(const TStack<S>& x)
	{
		cout << "TStack Copy Constructor is called!" << endl;
		data.setHead(nullptr);
		data.setTail(nullptr);
		TLinkedList<S> k = x.data;
		TNode<S>* t = k.getHead();
		while (t)
		{
			this->data.pushBack(t->getData());
			t = t->getNext();
		}
		return;
	}
	TStack(TStack<S>&& y)
	{
		cout << "TStack Move Constructor is called!" << endl;
		this->setData(move(y.getData()));
		return;
	}
	TLinkedList<S> getData()
	{
		return this->data;
	}
	void setData(TLinkedList<S> data)
	{
		this->data.setHead(data.getHead());
		this->data.setTail(data.getTail());
		return;
	}
	void push(S data)
	{
		this->data.addFront(data);
		return;
	}
	S pop()
	{
		return data.pop();
	}
	void print()
	{
		cout << "printing stack" << endl;
		this->data.print();
		return;
	}
	~TStack()
	{
		return;
	}
	friend int sumLnk(TStack x);
};

#endif