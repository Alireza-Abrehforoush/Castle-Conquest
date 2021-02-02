#include <cmath>
#include "Castle.h"

map<string, Castle*>Castle::castle_ids_map;

int Castle::castle_generated_id = 0;

Castle::Castle()
{
	pair<string, Castle*> temp(std::to_string(castle_generated_id), this);
	castle_ids_map.insert(temp);
	castle_generated_id++;
}

string Castle::getId() const
{
	return this->id;
}

void Castle::setId(const string& id)
{
	this->id = id;
	return;
}

Castle* Castle::findCastleById(const string& id)
{
	return castle_ids_map.find(id)->second;
}

Soldier* Castle::findVanguardFor(const Soldier& opponent)
{
	Soldier* vanguard = nullptr;
	BSTNode<pair<double, string>>* temp = this->cstl_sldrs.search(pair<double, string>(opponent.getPower(), opponent.getId()));
	if (temp != nullptr)
	{
		vanguard = Soldier::findSoldierById(temp->getData().second);
	}
	else
	{
		this->cstl_sldrs.insert(pair<double, string>(opponent.getPower(), opponent.getId()));
		BSTNode<pair<double, string>>* kemp = this->cstl_sldrs.search(pair<double, string>(opponent.getPower(), opponent.getId()));
		double predecessor_of_kemp_power = this->cstl_sldrs.getPredecessorOf(kemp).first;
		string predecessor_of_kemp_id = this->cstl_sldrs.getPredecessorOf(kemp).second;
		double successor_of_kemp_power = this->cstl_sldrs.getSuccessorOf(kemp).first;
		string successor_of_kemp_id = this->cstl_sldrs.getSuccessorOf(kemp).second;
		if (abs(predecessor_of_kemp_power - opponent.getPower()) <= abs(successor_of_kemp_power) - opponent.getPower())
		{
			vanguard = Soldier::findSoldierById(predecessor_of_kemp_id);
		}
		else
		{
			vanguard = Soldier::findSoldierById(successor_of_kemp_id);
		}
		this->cstl_sldrs.remove(pair<double, string>(opponent.getPower(), opponent.getId()));
	}
	return vanguard;
}

Castle::~Castle()
{
	castle_ids_map.erase(this->getId());
}
