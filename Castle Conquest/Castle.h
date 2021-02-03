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
	MyQueue<Soldier*> in;
	static map<string, Castle*> castle_ids_map;
	static int castle_generated_id;
public:
	Castle();
	string getId() const;
	void setId(const string& id);
	void insertSoldier(Soldier* x);
	static Castle* findCastleById(const string& id);
	Soldier* findVanguardFor(const Soldier& opponent);
	void fillFibonacciHeap(FibonacciHeap<pair<double, string>>* winner_finder_fibonacci_heap, BSTNode<pair<double, string>>* x);
	void twoByTwoFight(Soldier* home, Soldier* opponent);
	~Castle();
};

#endif