#ifndef CASTLE_CVYTFCVTCX
#define CASTLE_CVYTFCVTCX
#include <map>
#include "AVLTree.h"
#include "Soldier.h"
#include "MyStack.h"
class Castle
{
protected:
private:
	string id;
	AVLTree<pair<string, double>> cstl_sldrs;
	MyStack<Soldier*> martyrs;
	static map<string, Castle*> castle_ids_map;
	static int castle_generated_id;
public:
	Castle();
	string getId() const;
	void setId(const string& id);
	static Castle* findCastleId(const string& id);
	Soldier* findVanguardFor(const Soldier& oppenent);

	~Castle();
};

#endif