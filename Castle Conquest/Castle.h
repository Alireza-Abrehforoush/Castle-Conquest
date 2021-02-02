#ifndef CASTLE_CVYTFCVTCX
#define CASTLE_CVYTFCVTCX
#include "AVLTree.h"
#include "Soldier.h"
#include "MyStack.h"
class Castle
{
protected:
private:
	AVLTree<Soldier*> cstl_sldrs;
	MyStack<Soldier*> martyrs;
public:
	Soldier* findVanguardFor(Soldier* oppenent) const
	{
		Soldier* temp = nullptr;
		//
	}

};

#endif