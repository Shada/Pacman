#include "Route.h"

Route::Route()
{
	cost = 0;
}

void Route::pushBack(char dir)
{
	route.push_back(dir);
	cost++;
}

char Route::popFront()
{
	char temp = route.front();
	route.pop_front();
	cost--;
	return temp;
}

Route::~Route()
{
}