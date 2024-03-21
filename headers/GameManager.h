#pragma once
#include "Map.h"
#include "Campaign.h"
#include "Actor.h"
class GameManager
{
private:
	Map* currentMap;
	Campaign* currentCampaign;
	Enemy* enemies;
	Character* characters;

public:
	void EnterNewMap();
	bool MoveActor(Actor* a, Vector2* oldPos, Vector2* newPos);
	bool IsValidMove(Vector2* position);
	void SelectCampaign();
	void StartCampaign();
	void DisplayEnemiesInMap();
};

