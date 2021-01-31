#include <iostream>
#include <cstdlib>
using namespace std;

#include "BST.h"
#include "AVLTree.h"

int main()
{
	
	//BST<int> kemp;
	//BSTNode<int>* temp = kemp.insert(0);
	//kemp.insert(111111111);
	//kemp.insert(102565);
	//kemp.insert(-256);
	//for (int i = 0; i < 1000; i++)
	//{
	//	kemp.insert(i);
	//}
	AVLTree<int> tr;
	//BSTNode<int> k(0);
	for (int i = 0; i < 10; i++)
	{
		tr.insert(i);
	}
	tr.print();
	tr.remove(7);
	tr.print();
	tr.remove(3);
	tr.print();
	tr.remove(6);
	tr.print();
	tr.~AVLTree();
	for (int i = 0; i < 10; i++)
	{
		tr.insert(i%3);
	}
	tr.print();
	return 0;
}