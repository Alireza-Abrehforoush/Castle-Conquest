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
	//cout << kemp.search(kemp.getRoot(), -256) << endl;
	//(*kemp.search(kemp.getRoot(), -256)).setData(1);
	//cout << kemp.search(kemp.getRoot(), -256) << endl;
	//cout << kemp.search(kemp.getRoot(), 1);
	cout << kemp.getSuccessorOf(0);

	return 0;
}