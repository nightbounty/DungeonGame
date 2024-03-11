#include "Campaign.h"

Campaign::Campaign(Map** maps, int size){
	this->maps = maps;
	this->size = size;
}

Map* Campaign::Start() {
	return maps[0];
}

Map* Campaign::LoadAfter(int i) {
	return maps[i + 1];
}

