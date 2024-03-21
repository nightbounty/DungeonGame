#pragma once
#include "Map.h"
#include "Campaign.h"
#include "Actor.h"
#include "CampaignManager.h"
class GameManager
{
private:
	Map* currentMap;
	Campaign* currentCampaign;
	Enemy* enemies;
	Character* characters;
	static GameManager* instancePtr;
	GameManager() 
	{
	}

public:
	
	GameManager(const GameManager& obj) = delete;
	static GameManager* GetInstance();
	void SelectCampaign();
	void StartCampaign();
	
	void EnterNewMap();

	bool MoveActor(Actor* a, Vector2* oldPos, Vector2* newPos);
	bool IsValidMove(Vector2* position);
	
	void DisplayEnemiesInMap();
};

