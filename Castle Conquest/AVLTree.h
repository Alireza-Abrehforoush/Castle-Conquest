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

	BSTNode<T>* singleRightRotate(BSTNode<T>*& t)
	{
		BSTNode<T>* u = t->getLeft();
		t->setLeft(u->getRight());
		u->setRight(t);
		t->setHeight(max(this->heightOf(t->getLeft()), this->heightOf(t->getRight())) + 1);
		u->setHeight(max(this->heightOf(u->getLeft()), t->getHeight()) + 1);
		return u;
	}

	BSTNode<T>* singleLeftRotate(BSTNode<T>*& t)
	{
		BSTNode<T>* u = t->getRight();
		t->setRight(u->getLeft());
		u->setLeft(t);
		t->setHeight(max(this->heightOf(t->getLeft()), this->heightOf(t->getRight())) + 1);
		u->setHeight(max(this->heightOf(t->getRight()), t->getHeight()) + 1);
		return u;
	}

	BSTNode<T>* doubleLeftRotate(BSTNode<T>*& t)
	{
		t->setRight(this->singleRightRotate(t->getRight()));
		return this->singleLeftRotate(t);
	}

	BSTNode<T>* doubleRightRotate(BSTNode<T>*& t)
	{
		t->setLeft(this->singleLeftRotate(t->getLeft()));
		return this->singleRightRotate(t);
	}
private:
public:
};

#endif