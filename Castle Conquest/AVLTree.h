#ifndef AVLTREE_NCKENKECM
#define AVLTREE_NCKENKECM
#include "BST.h"
#include "MyFuncs.h"
template <class T>
class AVLTree :
	public BST<T>
{
protected:
	int heightOf(BSTNode<T>* t)
	{
		if (t == nullptr) return -1;
		else return t->getHeight();
	}
	
	BSTNode<T>* singleLeftRotate(BSTNode<T>*& x)
	{
		if (x == nullptr)
		{
			return x;
		}
		else
		{
			BSTNode<T>* parent = x->getParent();
			BSTNode<T>* y = x->getRight();
			BSTNode<T>* alpha = x->getLeft();
			BSTNode<T>* beta = y->getLeft();
			BSTNode<T>* gamma = y->getRight();
			
			y->setLeft(x);
			x->setParent(y);
			x->setRight(beta);
			beta->setParent(x);
			y->setParent(parent);
			if (parent == nullptr)
			{
				this->root = y;
			}
			else
			{
				if (x == parent->getLeft())
				{
					parent->setLeft(y);
				}
				else
				{
					parent->setRight(y);
				}
			}

			/*
			x->height = max(height(x->left),
				height(x->right)) + 1;
			y->height = max(height(y->left),
				height(y->right)) + 1;
			*/
			x->setHeight(myfuncs::max(this->heightOf(x->getLeft())), this->heightOf(x->getRight()) + 1);
			y->setHeight(myfuncs::max(this->heightOf(y->getLeft())), this->heightOf(y->getRight()) + 1);
		}
	}
	BSTNode<T>* singleRightRotate(BSTNode<T>*& y)
	{
		if (y == nullptr)
		{
			return y;
		}
		else
		{
			BSTNode<T>* parent = y->getParent();
			BSTNode<T>* x = y->getLeft();
			BSTNode<T>* alpha = x->getLeft();
			BSTNode<T>* beta = x->getRight();
			BSTNode<T>* gamma = y->getRight();

			x->setRight(y);
			y->setParent(x);
			y->setLeft(beta);
			beta->setParent(y);
			x->setParent(parent);

			if (parent == nullptr)
			{
				this->root = x;
			}
			else
			{
				if (y == parent->getLeft())
				{
					parent->setLeft(x);
				}
				else
				{
					parent->setRight(x);
				}
			}

			/*
			y->height = max(height(y->left),
					height(y->right)) + 1;
			x->height = max(height(x->left),
					height(x->right)) + 1;
			*/
			y->setHeight(myfuncs::max(this->heightOf(y->getLeft()), this->heightOf(y->getRight())) + 1);
			x->setHeight(myfuncs::max(this->heightOf(x->getLeft()), this->heightOf(x->getRight())) + 1);
		}
	}
	BSTNode<T>* doubleLeftRotate(BSTNode<T>*& x)
	{
		x->setRight(this->singleRightRotate(x->getRight()));
		return this->singleLeftRotate(x);
	}
	BSTNode<T>* doubleRightRotate(BSTNode<T>*& y)
	{
		y->setLeft(this->singleLeftRotate(y->getLeft()));
		return this->singleRightRotate(y);
	}
	BSTNode<T>* leftRightRotate(BSTNode<T>* x)
	{
		if (x == nullptr)
		{
			return x;
		}
		else
		{
			BSTNode<T>* parent = x->getParent();
			this->singleLeftRotate(x->getLeft());
			this->singleRightRotate(x);
			return parent;
		}
	}
	BSTNode<T>* rightLeftRotate(BSTNode<T>* y)
	{
		if (y == nullptr)
		{
			return y;
		}
		else
		{
			BSTNode<T>* parent = y->getParent();
			this->singleRightRotate(y->getRight());
			this->singleLeftRotate(y);
			return parent;
		}
	}

	

private:
public:
};

#endif