#include <iostream>
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
	for (int i = 0; i < 20; i++)
	{
		tr.insert(i);
		tr.print();
	}
	
	return 0;
}