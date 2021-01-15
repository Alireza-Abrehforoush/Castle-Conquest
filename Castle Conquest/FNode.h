#ifndef FNODE_BHUHGYFBD
#define FNODE_BHUHGYFBD

template <class T>
class FNode
{
protected:
private:
	T data;
	FNode* parent;
	FNode* left;
	FNode* right;
	int height;
public:
	FNode(const T& data, const FNode* parent = nullptr, const FNode* left = nullptr, const FNode* right = nullptr, const int& height = 0)
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
	void setParent(const FNode* parent)
	{
		this->parent = parent;
		return;
	}
	void setLeft(const FNode* left)
	{
		this->left = left;
		return;
	}
	void setRight(const FNode* right)
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
	FNode* getParent() const
	{
		return this->parent;
	}
	FNode* getLeft() const
	{
		return this->left;
	}
	FNode* getRight() const
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