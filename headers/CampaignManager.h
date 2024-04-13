#ifndef CAMPAIGNMANAGER_H
#define CAMPAIGNMANAGER_H
#include <iostream>
#include "Map.h"
#include "Campaign.h"
#include <fstream>
class CampaignManager
{
public:
	static void SetMapCellOccupant(string type, Map* map);
	static Map* CreateNewMap();
	static Map* LoadMap();
	static Map* LoadMapWithName(string name);
	static void EditLoadedMap(Map* loadedMap);
	static void WriteMapToFile(Map* map);
	static Campaign* LoadCampaign();
	static Campaign* CreateNewCampaign();
	static void EditLoadedCampaign(Campaign* loadedCampaign);
	static void DisplayMainMenu();
};
#endif

