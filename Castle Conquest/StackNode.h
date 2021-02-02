#ifndef STACKNODE_RXDXFB
#define STACKNODE_RXDXFB
template <class T>
class StackNode
{
protected:
private:
	T data;
	StackNode<T>* link;
public:
	StackNode()
		: link(nullptr)
	{
	}

	T getData() const
	{
		return this->data;
	}
	StackNode<T>* getLink() const
	{
		return this->link;
	}

	void setData(const T& data)
	{
		this->data = data;
		return;
	}
	void setLink(StackNode<T>* link)
	{
		this->link = link;
		return;
	}
};

#endif