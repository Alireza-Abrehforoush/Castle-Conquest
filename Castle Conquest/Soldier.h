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
public:
	Soldier(string id = "", double power = 0, double velocity = 0)
		:id(id)
		,power(power)
		,velocity(velocity)
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
};

#endif