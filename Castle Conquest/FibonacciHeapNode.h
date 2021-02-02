#ifndef FIBONACCIHEAPNODE_TGHNJNOBUYVYTCVFG
#define FIBONACCIHEAPNODE_TGHNJNOBUYVYTCVFG
template <class T>
class FibonacciHeapNode
{
protected:
private:
	T data;
	FibonacciHeapNode<T>* parent;
	FibonacciHeapNode<T>* child;
	FibonacciHeapNode<T>* left;
	FibonacciHeapNode<T>* right;
	int degree;
	bool marked;
	bool deleted;
public:
	FibonacciHeapNode()
		: parent(nullptr)
		, child(nullptr)
		, left(nullptr)
		, right(nullptr)
		, degree(0)
		, marked(false)
		, deleted(false)
	{
	}
	FibonacciHeapNode(const T& data, FibonacciHeapNode<T>* parent = nullptr, FibonacciHeapNode<T>* child = nullptr, FibonacciHeapNode<T>* left = nullptr, FibonacciHeapNode<T>* right = nullptr, int degree = 0, bool marked = false, bool deleted = false)
		: data(data)
		, parent(parent)
		, child(child)
		, left(left)
		, right(right)
		, degree(0)
		, marked(marked)
		, deleted(deleted)
	{
	}
	T getData() const
	{
		return this->data;
	}
	FibonacciHeapNode<T>* getParent() const
	{
		return this->parent;
	}
	FibonacciHeapNode<T>* getChild() const
	{
		return this->child;
	}
	FibonacciHeapNode<T>* getLeft() const
	{
		return this->left;
	}
	FibonacciHeapNode<T>* getRight() const
	{
		return this->right;
	}
	bool isMarked() const
	{
		return this->marked;
	}
	int getDegree() const
	{
		return this->degree;
	}
	char isDeleted() const
	{
		return this->deleted;
	}

	void setData(const T& data)
	{
		this->data = data;
		return;
	}
	void setParent(FibonacciHeapNode<T>* parent)
	{
		this->parent = parent;
		return;
	}
	void setChild(FibonacciHeapNode<T>* child)
	{
		if (this->hasChild())
		{
			FibonacciHeapNode<T>* temp = this->getChild()->getLeft();
			temp->setRight(child);
			child->setLeft(temp);
			this->getChild()->setLeft(child);
			child->setRight(this->getChild());
			child->setParent(this);
		}
		else
		{
			this->child = child;
			this->child->setParent(this);
			this->child->setLeft(child);
			this->child->setRight(child);
		}
		this->degree++;
		return;
	}
	void setLeft(FibonacciHeapNode<T>* left)
	{
		this->left = left;
		return;
	}
	void setRight(FibonacciHeapNode<T>* right)
	{
		this->right = right;
		return;
	}
	void setDegree(int degree)
	{
		this->degree = degree;
		return;
	}
	void setMarkStatus(bool mark)
	{
		this->marked = mark;
		return;
	}
	void setDeleteStatus(bool deleted)
	{
		this->deleted = deleted;
		return;
	}
	void unlinkChild(FibonacciHeapNode<T>* x)
	{
		if (x != nullptr)
		{
			if (x->getLeft() == x)
			{
				x->setParent(nullptr);
				this->child = nullptr;
			}
			else
			{
				x->getLeft()->setRight(x->getRight());
				x->getRight()->setLeft(x->getLeft());
				if (x == child)
				{
					this->child = this->child->getRight();
				}
			}
			this->degree--;
			//mark
		}
	}
	

	bool hasChild() const
	{
		if (this->child != nullptr) return true;
		else return false;
	}
	bool hasParent()
	{
		if (this->parent == nullptr) return false;
		else return true;
	}
};

#endif