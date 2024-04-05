#pragma once
#include "Map.h"
#include "Campaign.h"
#include "Actor.h"
#include "CampaignManager.h"
#include "GameLoggerSubject.h"

class GameManager : public GameLoggerSubject
{
private:
	
	Character* character;
	Campaign* currentCampaign;
	std::vector<Actor*> initiativeOrder;
	std::vector<Enemy*> enemies;
	static GameManager* instancePtr;
	std::string logEntry; // Game Log related member
	void NotifyObservers(); // Game Log related private function
	GameManager() 
	{
	}

public:
	Map* currentMap;
	GameManager(const GameManager& obj) = delete;
	static GameManager* GetInstance();
	void SetCampaign(Campaign* campaign);
	void StartCampaign();
	
	void EnterNewMap();

	bool MoveActor(Actor* a, Vector2* oldPos, Vector2* newPos);
	bool IsEmptyCell(Vector2* position);
	bool IsInBounds(Vector2* position);
	
	void DisplayEnemiesInMap();
	Enemy* GetEnemyInMap(int i);
	Character* GetCharacterInMap();

	void LogEvent(const std::string& event); // Game log related function
};

