#pragma once
#include "stdafx.h"
#include "Tile.h"
#include <list>

class Route
{
private:
	int cost;
	list<char> route;
public:
	Route();
	~Route();

	bool isEmpty() { return route.empty(); }
	int getCost() { return cost; }

	void pushBack(char dir);
	char popFront();
};