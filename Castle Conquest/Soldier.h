#ifndef SOLDIER_PEOEUEYGHFEBNCEIG
#define SOLDIER_PEOEUEYGHFEBNCEIG
#include <string>
#include <map>
using namespace std;
class Soldier
{
protected:
private:
	string id;
	double power;
	double velocity;
	bool is_alive;
	static map<string, Soldier*> soldier_ids_map;
	static int soldier_generated_id;
public:
	Soldier(double power = 0, double velocity = 0, bool is_alive = true);

	string getId() const;
	double getPower() const;
	double getVelcity() const;
	bool isAlive() const;
	void setId(string id);
	void setPower(double power);
	void setVelocity(double velocity);
	void setLifeStatus(bool is_alive);
	bool operator< (const Soldier& x);
	bool operator> (const Soldier& x);
	bool operator<=(const Soldier& x);
	bool operator>=(const Soldier& x);
	bool operator==(const Soldier& x);
	bool operator!=(const Soldier& x);
	static Soldier* findSoldierId(const string& id);
	~Soldier();
};

#endif