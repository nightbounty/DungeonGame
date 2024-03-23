#pragma once
#include "Map.h"
#include "Campaign.h"
#include "Actor.h"
#include "CampaignManager.h"
#include "GameLoggerSubject.h"

class GameManager : public GameLoggerSubject
{
private:
	Map* currentMap;
	std::vector<Character*> characters;
	Campaign* currentCampaign;
	std::vector<Enemy*> enemies;
	static GameManager* instancePtr;
	std::string logEntry; // Game Log related member
	void NotifyObservers(); // Game Log related private function
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
	void MoveCharacterFromInput(int characterIndex);
	
	void DisplayEnemiesInMap();
	Enemy* GetEnemyInMap(int i);
	Character* GetCharacterInMap(int i);

	void InitiateCombat(Actor* enemy);

	void LogEvent(const std::string& event); // Game log related function
};

