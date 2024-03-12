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
	static void EditLoadedMap(Map* loadedMap);
	static Campaign* LoadCampaign();
	static Campaign* CreateNewCampaign();
	static void EditLoadedCampaign(Campaign* loadedCampaign);
};

