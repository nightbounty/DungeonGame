#include "Campaign.h"

Campaign::Campaign(vector<Map*> maps, string title, int size){
	this->maps = maps;
	this->title = title;
	this->size = size;
	for (int i = 0; i < size-1; i++) {
		maps[i]->GetExitDoor()->SetConnectedMap(maps[i + 1]);
	}
	maps[size - 1]->GetExitDoor()->SetConnectedMap(NULL);
}

void Campaign::AddMap(Map* mapToAdd) {
	maps.push_back(mapToAdd);
	size++;
}

void Campaign::RemoveMap(int mapToRemove) {
	if (mapToRemove > 0) {
		maps[mapToRemove - 1]->GetExitDoor()->SetConnectedMap(maps[mapToRemove + 1]);
	}
	for (int i = mapToRemove; i < size-1; i++) {
		maps[i] = maps[i + 1];
	}
	delete maps[size - 1];
	maps[size - 1] = NULL;
}
Map* Campaign::Start() {
	return maps[0];
}

Map* Campaign::LoadAfter(int i) 
{
	return maps[i + 1];
}

string Campaign::GetTitle() {
	return this->title;
}
string Campaign::ToString(){
	string str = "==========================\n" + this->title + "\n==========================\n";
	for (int i = 0; i < size; i++) {
		str += std::to_string(i) + ". " + maps[i]->GetName() + "\n";
	}
	return str;
}

vector<Map*> Campaign::GetMaps() {
	return this->maps;
}
