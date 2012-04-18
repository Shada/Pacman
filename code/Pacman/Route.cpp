#include "Route.h"

Route::Route()
{
	cost = 0;
}

void Route::pushBack(Direction dir)
{
	route.push_back(dir);
	cost++;
}

char Route::popBack()
{
	char temp = route.back();
	route.pop_back();
	cost--;
	return temp;
}

Route::~Route()
{
}