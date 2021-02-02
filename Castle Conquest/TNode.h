#ifndef TNODE_ASDF
#define TNODE_ASDF
#include <iostream>
using namespace std;
template <class K>
class TNode
{
private:
	TNode<K>* prev;
	K data;
	TNode<K>* next;
public:
	TNode(K data=0, TNode<K>* prev = nullptr, TNode<K>* next = nullptr)
	{
		this->data = data;
		this->prev = prev;
		this->next = next;
		return;
	}
	TNode(const TNode<K>& x)
	{
		this->setData(x.data);
		this->setPrev(x.prev);
		this->setNext(x.next);
		return;
	}
	TNode(TNode<K>&& y)
	{
		this->prev(y.getPrev());
		this->data(y.getData());
		this->next(y.getNext());
		y.setPrev(nullptr);
		y.setNext(nullptr);
		return;
	}
	void setPrev(TNode<K>* prev)
	{
		if(this!=nullptr)this->prev = prev;
		return;
	}
	void setData(K data)
	{
		this->data = data;
		return;
	}
	void setNext(TNode<K>* next)
	{
		if (this != nullptr)this->next = next;
		return;
	}
	TNode<K>* getPrev()
	{
		return this->prev;
	}
	K getData()
	{
		return this->data;
	}
	TNode<K>* getNext()
	{
		return this->next;
	}
	void print()
	{
		cout << "\tprinting TNode data" << endl;
		cout << "\t\t" << this->getData() << endl;
		return;
	}
	~TNode()
	{
		return;
	}
};

#endif