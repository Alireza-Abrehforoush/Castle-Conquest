#ifndef PATH_GHYCCFGFCHBBHBH
#define PATH_GHYCCFGFCHBBHBH
#include "Castle.h"
class Path
{
protected:
private:
	double length;
	Castle* head;
	Castle* tail;
public:
	Path(double length = 0, Castle* head = nullptr, Castle* tail = nullptr);
};

#endif