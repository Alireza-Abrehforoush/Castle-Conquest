#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
	BSTNode<int> temp(0);
	BST<int> kemp;
	kemp.insert(0);
	kemp.insert(111111111);
	kemp.insert(102565);
	kemp.insert(-256);
	cout << (*kemp.search(-256)).getData() << endl << kemp.search(5) << endl;
	(*kemp.search(-256)).setData(1);
	cout << (*kemp.search(1)).getData() << endl << kemp.search(5);
	return 0;
}