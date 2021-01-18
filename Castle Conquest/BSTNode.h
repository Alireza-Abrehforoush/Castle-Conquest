#ifndef BSTNODE_BHUHGYFBD
#define BSTNODE_BHUHGYFBD

template <class T>
class BSTNode
{
protected:
private:
	T data;
	BSTNode<T>* parent;
	BSTNode<T>* left;
	BSTNode<T>* right;
	int height;

public:
	BSTNode(const T& data, BSTNode<T>* parent = nullptr, BSTNode<T>* left = nullptr, BSTNode<T>* right = nullptr, const int& height = 0)
		:data(data)
		, parent(parent)
		, left(left)
		, right(right)
		, height(height)
	{
	}

	void setData(const T& data)
	{
		this->data = data;
		return;
	}
	void setParent(BSTNode<T>* parent)
	{
		this->parent = parent;
		return;
	}
	void setLeft(BSTNode<T>* left)
	{
		this->left = left;
		return;
	}
	void setRight(BSTNode<T>* right)
	{
		this->right = right;
		return;
	}
	void setHeight(const int& height)
	{
		if (height >= 0) this->height = height;
		else throw "Height must not be negative!";
		return;
	}

	T getData() const
	{
		return this->data;
	}
	BSTNode<T>* getParent() const
	{
		return this->parent;
	}
	BSTNode<T>* getLeft() const
	{
		return this->left;
	}
	BSTNode<T>* getRight() const
	{
		return this->right;
	}
	int getHeight() const
	{
		return this->height;
	}

	int bf() const
	{
		if (this->left != nullptr && this->right != nullptr)
		{
			return this->left->getHeight() - this->right->getHeight();
		}
		else if (this->left != nullptr && this->right == nullptr)
		{
			return this->left->getHeight() - (-1);
		}
		else if (this->left == nullptr && this->right != nullptr)
		{
			return -1 - this->right->getHeight();
		}
		else
		{
			return 0;
		}
	}
};

#endif