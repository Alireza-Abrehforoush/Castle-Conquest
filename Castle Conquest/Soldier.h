#ifndef SOLDIER_PEOEUEYGHFEBNCEIG
#define SOLDIER_PEOEUEYGHFEBNCEIG
#include <string>
using namespace std;
class Soldier
{
protected:
private:
	string id;
	double power;
	double velocity;
	bool isAlive;
public:
	Soldier(string id = "", double power = 0, double velocity = 0, bool isAlive = true)
		: id(id)
		, power(power)
		, velocity(velocity)
		, isAlive(isAlive)
	{
	}

	string getId() const
	{
		return this->id;
	}
	double getPower() const
	{
		return this->power;
	}
	double getVelcity() const
	{
		return this->velocity;
	}

	void setId(string id)
	{
		this->id = id;
		return;
	}
	void setPower(double power)
	{
		this->power = power;
		return;
	}
	void setVelocity(double velocity)
	{
		this->velocity = velocity;
		return;
	}

	~Soldier()
	{
		this->setId("");
		this->setPower(0);
		this->setVelocity(0);
		//this->setLifeStatus(false);
	}
};

#endif