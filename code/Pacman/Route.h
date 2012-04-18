#pragma once
#include "stdafx.h"
#include "Tile.h"
#include <list>

class Route
{
private:
	int cost;
	list<Direction> route;
public:
	Route();
	~Route();

	bool isEmpty() { return route.empty(); }
	int getCost() { return cost; }

	void pushBack(Direction dir);
	char popBack();
};