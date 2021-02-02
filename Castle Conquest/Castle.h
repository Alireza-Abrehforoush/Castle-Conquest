#ifndef CASTLE_CVYTFCVTCX
#define CASTLE_CVYTFCVTCX
#include <map>
#include "AVLTree.h"
#include "Soldier.h"
#include "MyStack.h"
#include "FibonacciHeap.h"
class Castle
{
protected:
private:
	string id;
	AVLTree<pair<double, string>> cstl_sldrs;
	MyStack<Soldier*> military_hospital;
	static map<string, Castle*> castle_ids_map;
	static int castle_generated_id;
public:
	Castle();
	string getId() const;
	void setId(const string& id);
	static Castle* findCastleById(const string& id);
	Soldier* findVanguardFor(const Soldier& opponent);
	void fillFibonacciHeap(FibonacciHeap<pair<double, string>>* winner_finder_fibonacci_heap, BSTNode<pair<double, string>>* x);
	void twoByTwoFight(Soldier* home, Soldier* opponent)
	{
		FibonacciHeap<pair<double, string>> wffh;
		fillFibonacciHeap(&wffh, cstl_sldrs.getRoot());
		wffh.insert(pair<double, string>(opponent->getPower(), opponent->getId()));
		//delete all nodes except fighters
	}
	~Castle();
};

#endif