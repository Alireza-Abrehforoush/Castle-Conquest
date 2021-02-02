#ifndef AVLTREE_NCKENKECM
#define AVLTREE_NCKENKECM
#include <iostream>
#include <string>
using namespace std;
#include "BST.h"
#include "MyFuncs.h"
template <class T>
class AVLTree :
	public BST<T>
{
protected:
	BSTNode<T>* singleLeftRotate(BSTNode<T>* x)
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
			if(beta != nullptr) beta->setParent(x);
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
			this->fixHeightOf(x);
			this->fixHeightOf(y);
			this->fixHeightOf(parent);

			return parent;
		}
	}
	BSTNode<T>* singleRightRotate(BSTNode<T>* y)
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
			if(beta != nullptr)beta->setParent(y);
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
			this->fixHeightOf(y);
			this->fixHeightOf(x);
			this->fixHeightOf(parent);

			return parent;
		}
	}
	BSTNode<T>* doubleLeftRotate(BSTNode<T>* x)
	{
		x->setRight(this->singleRightRotate(x->getRight()));
		return this->singleLeftRotate(x);
	}
	BSTNode<T>* doubleRightRotate(BSTNode<T>* y)
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
	
	int getBalance(BSTNode<T>* x)
	{
		if (x == nullptr)
		{
			return 0;
		}
		else
		{
			return this->heightOf(x->getLeft()) - this->heightOf(x->getRight());
		}
	}
	int bf(BSTNode<T>* x)
	{
		if (x == nullptr)
		{
			return 0;
		}
		else
		{
			if (x->getLeft() && x->getRight())
			{
				return x->getLeft()->getHeight() - x->getRight()->getHeight();
			}
			else if (x->getLeft())
			{
				return x->getLeft()->getHeight() + 1;
			}
			else if (x->getRight())
			{
				return -x->getRight()->getHeight() - 1;
			}
			else
			{
				return 0;
			}
		}
	}
	int heightOf(BSTNode<T>* t)
	{
		if (t == nullptr) return -1;
		else return t->getHeight();
	}
	int fixHeightOf(BSTNode<T>* x)
	{
		if (x == nullptr)
		{
			return -1;
		}
		else
		{
			x->setHeight(myfuncs::max(this->heightOf(x->getLeft()), this->heightOf(x->getRight())) + 1);
			return x->getHeight();
		}
	}
	void balance(BSTNode<T>* x)
	{
		BSTNode<T>* temp = x;
		while (temp != nullptr)
		{
			if (bf(temp) > 1)
			{
				if (bf(temp->getLeft()) == -1)
				{
					temp = this->leftRightRotate(temp);
				}
				else
				{
					temp = this->singleRightRotate(temp);
				}
			}
			else if (bf(temp) < -1)
			{
				if (bf(temp->getRight()) == 1)
				{
					temp = this->rightLeftRotate(temp);
				}
				else
				{
					temp = this->singleLeftRotate(temp);
				}
			}
			else
			{
				temp = temp->getParent();
			}
		}
	}

private:
	void display(const string& b_part, const BSTNode<T>* x, bool l)
	{
		if (x != nullptr)
		{
			std::cout << b_part;
			char ch = (char)-60;
			char cr = (char)-61;
			char cl = (char)-64;
			char cu = (char)-77;
			if (l)
			{
				cout << cr << ch << ch;
			}
			else
			{
				cout << cl << ch << ch;
			}
			std::cout << x->getData() << std::endl;
			string temp;
			if (l)
			{
				temp = cu;
				temp.append("   ");
			}
			else
			{
				temp = "    ";
			}
			display(b_part + temp, x->getLeft(), true);
			display(b_part + temp, x->getRight(), false);
		}
	}
public:
	
	void print()
	{
		cout << endl;
		display("", this->root, false);
		cout << endl;
	}
	void insert(const T& x)
	{
		BSTNode<T>* temp = BST<T>::insert(x);
		for (BSTNode<T>* kemp = temp; kemp != nullptr; kemp = kemp->getParent())
		{
			fixHeightOf(kemp);
		}
		this->balance(temp);
	}
	void remove(const T& x)
	{
		BSTNode<T>* temp = this->BST<T>::iterativeSearch(x);
		this->BST<T>::deleteNode(temp);
		return;
	}
	~AVLTree()
	{
		BST<T>::~BST();
	}
};

#endif