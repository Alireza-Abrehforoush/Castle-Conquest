#include <iostream>
#include <cstdlib>
using namespace std;

#include "BST.h"
#include "AVLTree.h"
#include "TLinkedList.h"
#include "FibonacciHeap.h"
#include "Soldier.h"
#include "Castle.h"
#include "Land.h"

int main()
{
	Castle home;
	Soldier s1;
	FibonacciHeap<int> heap(12);
	Land world;
	world.buildLand();
	return 0;
}