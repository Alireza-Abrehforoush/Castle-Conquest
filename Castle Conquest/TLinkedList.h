#ifndef TLINKEDLIST_SDFG
#define TLINKEDLIST_SDFG
#include "TNode.h"
template <class D>
class TLinkedList
{
private:
	TNode<D>* head;
	TNode<D>* tail;
public:
	TLinkedList()
	{
		//cout << "TLinkedList Constructor is called!" << endl;
		this->head = nullptr;
		this->tail = nullptr;
		return;
	}
	TLinkedList(const TLinkedList<D>& x)
	{
		//cout << "TLinkedList Copy Constructor is called!" << endl;
		this->setHead(nullptr);
		this->setTail(nullptr);
		TNode<D>* t = x.head;
		while (t)
		{
			this->pushBack(t->getData());
			t = t->getNext();
		}
		return;
	}
	TLinkedList(TLinkedList<D>&& y)
	{
		//cout << "TLinkedList Move Constructor is called!" << endl;
		this->head = y.getHead();
		this->tail = y.getTail();
		y.setHead(nullptr);
		y.setTail(nullptr);
		return;
	}
	void setHead(TNode<D>* head)
	{
		this->head = head;
		return;
	}
	void setTail(TNode<D>* tail)
	{
		this->tail = tail;
		return;
	}
	TNode<D>* getHead()
	{
		return this->head;
	}
	TNode<D>* getTail()
	{
		return this->tail;
	}
	void addFront(D data)
	{
		TNode<D>* t = new TNode<D>(data);
		t->setNext(this->head);
		this->head->setPrev(t);
		this->head = t;
		if (this->tail == nullptr) this->tail = t;
		return;
	}
	void pushBack(D data)
	{
		TNode<D>* t = new TNode<D>(data);
		t->setPrev(this->tail);
		this->tail->setNext(t);
		this->tail = t;
		if (this->head == nullptr) this->head = t;
		return;
	}
	D pop()
	{
		TNode<D> t = *this->head;
		delete this->head;
		this->head = t.getNext();
		return t.getData();
	}
	bool isEmpty()
	{
		if (this->head == nullptr) return true;
		else return false;
	}
	void print()
	{
		TNode<D>* t = this->head;
		cout << "printing TLinkedList" << endl;
		while (t)
		{
			t->print();
			t = t->getNext();
		}
		return;
	}
	~TLinkedList()
	{
		TNode<D>* t = this->head;
		while (t)
		{
			TNode<D>* k = t->getNext();
			delete t;
			t = nullptr;
			t = k;
		}
		this->setHead(nullptr);
	}
};

#endif