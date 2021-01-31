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
	BSTNode<T>* iterativeSearch(const T& key)
	{
		BSTNode<T>* temp = this->root;
		while (temp != nullptr && temp->getData() != key)
		{
			if (key <= temp->getData())
			{
				temp = temp->getLeft();
			}
			else
			{
				temp = temp->getRight();
			}
			return temp;
		}
	}
	T getMinimum(BSTNode<T>* root) const
	{
		if (root != nullptr)
		{
			BSTNode<T>* temp = root;
			while (temp->getLeft() != nullptr)
			{
				temp = temp->getLeft();
			}
			return temp->getData();
		}
	}
	T getMaximum(BSTNode<T>* root) const
	{
		if (root != nullptr)
		{
			BSTNode<T>* temp = root;
			while (temp->getRight() != nullptr)
			{
				temp = temp->getRight();
			}
			return temp->getData();
		}
	}
	T getSuccessorOf(BSTNode<T>* x) const
	{
		if (x != nullptr)
		{
			if (x->getRight() != nullptr)
			{
				return this->getMinimum(x->getRight());
			}
			BSTNode<T>* y = x->getParent();
			while (y != nullptr && x == y->getRight())
			{
				x = y;
				y = y->getParent();
			}
			return y->getData();
		}
	}
	T getPredecessorOf(BSTNode<T>* x) const
	{
		if (x != nullptr)
		{
			if (x->getLeft() != nullptr)
			{
				return this->getMaximum(x->getLeft());
			}
			BSTNode<T>* y = x->getParent();
			while (y != nullptr && x == y->getLeft())
			{
				x = y;
				y = y->getParent();
			}
			return y->getData();
		}
	}
	BSTNode<T>* insert(const T& data)
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
			return new_node;
		}
		else
		{
			this->root = new BSTNode<T>(data);
			return root;
		}
	}
	void deleteNode(BSTNode<T>* x)
	{
		if (x != nullptr)
		{
			if (x->getLeft() == nullptr && x->getRight() == nullptr)
			{
				if (x->getParent() == nullptr)
				{
					this->root = nullptr;
				}
				else if (x == x->getParent()->getLeft())
				{
					x->getParent()->setLeft(nullptr);
				}
				else
				{
					x->getParent()->setRight(nullptr);
				}
				delete x;
				x = nullptr;
			}
			else if (x->getLeft() == nullptr)
			{
				if (x->getParent() == nullptr)
				{
					this->root = this->root->getRight();
					this->root->setParent(nullptr);
				}
				else if (x == x->getParent()->getLeft())
				{
					x->getParent()->setLeft(x->getRight());
					x->getRight()->setParent(x->getParent());
				}
				else
				{
					x->getParent()->setRight(x->getRight());
					x->getRight()->setParent(x->getParent());
				}
				delete x;
				x = nullptr;
			}
			else if (x->getRight() == nullptr)
			{
				if (x->getParent() == nullptr)
				{
					this->root = this->root->getLeft();
					this->root->setParent(nullptr);
				}
				else if (x == x->getParent()->getLeft())
				{
					x->getParent()->setLeft(x->getLeft());
					x->getLeft()->setParent(x->getParent());
				}
				else
				{
					x->getParent()->setRight(x->getLeft());
					x->getLeft()->setParent(x->getParent());
				}
				delete x;
				x = nullptr;
			}
			else
			{
				BSTNode<T>* suc = iterativeSearch(this->getSuccessorOf(x));
				if (x->getParent() == nullptr)
				{
					if (suc == suc->getParent()->getLeft())
					{
						suc->getParent()->setLeft(nullptr);
					}
					else
					{
						suc->getParent()->setRight(nullptr);
					}
					suc->setParent(nullptr);
					suc->setLeft(x->getLeft());
					suc->setRight(x->getRight());
					this->root = suc;
				}
				else if (x == x->getParent()->getLeft())
				{
					if (suc == suc->getParent()->getLeft())
					{
						suc->getParent()->setLeft(nullptr);
					}
					else
					{
						suc->getParent()->setRight(nullptr);
					}
					suc->setParent(x->getParent());
					suc->setLeft(x->getLeft());
					suc->setRight(x->getRight());
					x->getParent()->setLeft(suc);
				}
				else
				{
					if (suc == suc->getParent()->getLeft())
					{
						suc->getParent()->setLeft(nullptr);
					}
					else
					{
						suc->getParent()->setRight(nullptr);
					}
					suc->setParent(x->getParent());
					suc->setLeft(x->getLeft());
					suc->setRight(x->getRight());
					x->getParent()->setRight(suc);
				}
				delete x;
				x = nullptr;
			}
		}
	}
	void deleteSubtree(BSTNode<T>* x)//bugs not fixed
	{
		//if (x != nullptr)
		//{
		//	if (x->getLeft() == nullptr && x->getRight() == nullptr)
		//	{
		//		delete x;
		//		x = nullptr;
		//	}
		//	else if (x->getLeft() == nullptr)
		//	{
		//		this->deleteSubtree(x->getRight());
		//		this->deleteSubtree(x);
		//	}
		//	else if (x->getRight() == nullptr)
		//	{
		//		this->deleteSubtree(x->getLeft());
		//		this->deleteSubtree(x);
		//	}
		//	else
		//	{
		//		this->deleteSubtree(x->getLeft());
		//		this->deleteSubtree(x->getRight());
		//		this->deleteSubtree(x);
		//	}
		//}

		if (x == nullptr)
		{
			return;
		}
		else
		{
			this->deleteSubtree(x->getLeft());
			this->deleteSubtree(x->getRight());
			delete x;
			x = nullptr;
		}
	}
	~BST()
	{
		this->deleteSubtree(root);
	}
};

#endif