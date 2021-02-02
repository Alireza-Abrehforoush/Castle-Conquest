#ifndef MYSTACK_BICHBEVIYKEB
#define MYSTACK_BICHBEVIYKEB
#include "StackNode.h"
template <class T>
class MyStack
{
protected:
private:
	StackNode<T>* top;
public:
	void push(const T& data)
	{
		StackNode<T>* temp;
		temp = new StackNode<T>();
		if (!temp)
		{
			throw "exception";
			exit(1);
		}
		else
		{
			temp->setData(data);
			temp->setLink(this->top);
			this->top = temp;
		}
	}
};

#endif