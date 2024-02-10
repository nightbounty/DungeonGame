#pragma once
#include "Cell.h"
class Map
{
private:
	Cell grid[][100];
public:
	Map(int arg1, int arg2) {
		grid = new Cell[arg1][20];
	}
};

