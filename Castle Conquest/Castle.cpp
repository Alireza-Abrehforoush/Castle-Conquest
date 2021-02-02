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

Castle* Castle::findCastleId(const string& id)
{
	return castle_ids_map.find(id)->second;
}

Soldier* Castle::findVanguardFor(const Soldier& oppenent)
{
	
}

Castle::~Castle()
{
	castle_ids_map.erase(this->getId());
}
