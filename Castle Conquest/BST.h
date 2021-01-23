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
	BSTNode<T>* search(const T& key) const//contains errors
	{
		BSTNode<T>* temp = this->root;
		while (temp)
		{
			if (temp->getData() == key)
			{
				return temp;
			}
			else if (temp->getData() > key)
			{
				temp = temp->getLeft();
			}
			else
			{
				temp = temp->getRight();
			}
		}
	}

	~BST()
	{
	}
};

#endif