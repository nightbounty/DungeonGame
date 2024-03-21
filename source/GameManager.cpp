#include "GameManager.h"


GameManager* GameManager::GetInstance() {
    {
        // If there is no instance then create one
        if (instancePtr == NULL)
        {
            instancePtr = new GameManager();
            return instancePtr;
        }
        else
        {
        // otherwise return the existing pointer
            return instancePtr;
        }
    }
}

void GameManager::StartCampaign() {
    currentCampaign = CampaignManager::LoadCampaign();
}
bool GameManager::MoveActor(Actor* a, Vector2* oldPos, Vector2* newPos) {
	if (IsValidMove(newPos)) return false;
	currentMap->SetCellOccupant(oldPos->GetX(), oldPos->GetY(), NULL);
    dynamic_cast<CellOccupant*>(a);
	currentMap->SetCellOccupant(newPos->GetX(), newPos->GetY(), a);
	return true;
}

bool GameManager::IsValidMove(Vector2* position) {
	return position->GetX() < currentMap->GetColumns()
		&& position->GetY() < currentMap->GetRows()
		&& position->GetX() > 0 && position->GetY() > 0;
}
