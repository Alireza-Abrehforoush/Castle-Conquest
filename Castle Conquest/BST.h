#ifndef BST_URNFNLDMWOFHJH
#define BST_URNFNLDMWOFHJH

#include "BSTNode.h"

template <class T>
class BST
{
protected:
	BSTNode<T>* root;
private:
public:
	BST(BSTNode<T>* root = nullptr)
		:root(root)
	{
	}
	void setRoot(BSTNode<T>* root)
	{
		this->root = root;
		return;
	}
	BSTNode<T>* getRoot() const
	{
		return this->root;
	}

	
	BSTNode<T>* search(BSTNode<T>* root, const T& key) const
	{
		BSTNode<T>* temp = root;
		if (root == nullptr || temp->getData() == key)
		{
			return temp;
		}
		if (key <= temp->getData())
		{
			return this->search(temp->getLeft(), key);
		}
		else
		{
			return this->search(temp->getRight(), key);
		}
	}
	BSTNode<T>* iterativeSearch(BSTNode<T>* root, const T& key)
	{
		while (root != nullptr && root->getData() != key)
		{
			if (key <= root->getData())
			{
				root = root->getLeft();
			}
			else
			{
				root = root->getRight();
			}
			return root;
		}
	}
	T getMinimum(BSTNode<T>* root) const
	{
		BSTNode<T>* temp = root;
		while (temp->getLeft() != nullptr)
		{
			temp = temp->getLeft();
		}
		return temp->getData();
	}
	T getMaximum(BSTNode<T>* root) const
	{
		BSTNode<T>* temp = root;
		while (temp->getRight() != nullptr)
		{
			temp = temp->getRight();
		}
		return temp->getData();
	}
	T getSuccessorOf(BSTNode<T>* x) const
	{
		if (x->getRight() != nullptr)
		{
			return this->getSuccessorOf(x->getRight());
		}
		BSTNode<T>* y = x->getParent();
		while (y!=nullptr && x == y->getRight())
		{
			x = y;
			y = y->getParent();
		}
	}
	void insert(const T& data)
	{
		if (this->root != nullptr)
		{
			BSTNode<T>* temp = root;
			BSTNode<T>* temp_parent = nullptr;
			while (temp != nullptr)
			{
				temp_parent = temp;
				if (data <= temp->getData())
				{
					temp = temp->getLeft();
				}
				else
				{
					temp = temp->getRight();
				}
			}
			BSTNode<T>* new_node = new BSTNode<T>(data, temp_parent);
			if (data <= temp_parent->getData()) temp_parent->setLeft(new_node);
			else temp_parent->setRight(new_node);
		}
		else
		{
			this->root = new BSTNode<T>(data);
		}
	}

	~BST()
	{
	}
};

#endif