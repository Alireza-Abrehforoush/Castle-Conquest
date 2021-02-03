#ifndef LAND_YVVYUBBNNIU
#define LAND_YVVYUBBNNIU
#include "Graph.h"
#include "Castle.h"
#include "Path.h"
class Land
{
protected:
private:
	Graph<Castle, Path> here;
public:
	Land();
	void buildLand();
};

#endif