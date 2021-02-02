#include "Soldier.h"

map<string, Soldier*>Soldier::soldier_ids_map;

int Soldier::soldier_generated_id = 0;

Soldier::Soldier(double power, double velocity, bool is_alive)
	: power(power)
	, velocity(velocity)
	, is_alive(is_alive)
{
	pair<string, Soldier*> temp(std::to_string(soldier_generated_id), this);
	soldier_ids_map.insert(temp);
	soldier_generated_id++;
}

string Soldier::getId() const
{
	return this->id;
}

double Soldier::getPower() const
{
	return this->power;
}

double Soldier::getVelcity() const
{
	return this->velocity;
}

bool Soldier::isAlive() const
{
	return this->is_alive;
}

void Soldier::setId(string id)
{
	this->id = id;
	return;
}

void Soldier::setPower(double power)
{
	this->power = power;
	return;
}

void Soldier::setVelocity(double velocity)
{
	this->velocity = velocity;
	return;
}

void Soldier::setLifeStatus(bool is_alive)
{
	this->is_alive = is_alive;
	return;
}

bool Soldier::operator<(const Soldier& x)
{
	if (this->getPower() < x.getPower()) return true;
	else return false;
}

bool Soldier::operator>(const Soldier& x)
{
	if (this->getPower() > x.getPower()) return true;
	else return false;
}

bool Soldier::operator<=(const Soldier& x)
{
	if (this->getPower() <= x.getPower()) return true;
	else return false;
}

bool Soldier::operator>=(const Soldier& x)
{
	if (this->getPower() >= x.getPower()) return true;
	else return false;
}

bool Soldier::operator==(const Soldier& x)
{
	if (this->getPower() == x.getPower()) return true;
	else return false;
}

bool Soldier::operator!=(const Soldier& x)
{
	if (this->getPower() != x.getPower()) return true;
	else return false;
}

Soldier* Soldier::findSoldierById(const string& id)
{
	return soldier_ids_map.find(id)->second;
}

Soldier::~Soldier()
{
	soldier_ids_map.erase(this->getId());
	this->setId("");
	this->setPower(0);
	this->setVelocity(0);
	this->setLifeStatus(false);
}
