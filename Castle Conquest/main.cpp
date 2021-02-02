#include <iostream>
#include <cstdlib>
using namespace std;

#include "BST.h"
#include "AVLTree.h"
#include "TLinkedList.h"
#include "FibonacciHeap.h"

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
	FibonacciHeap<int> kemp(20);
	kemp.insert(10);
	kemp.insert(30);
	kemp.insert(238);
	kemp.extractMinimum();
	kemp.print();
	kemp.~FibonacciHeap();
	return 0;
}