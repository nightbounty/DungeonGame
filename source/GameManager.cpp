#include "GameManager.h"

bool GameManager::MoveActor(Actor* a, Vector2* oldPos, Vector2* newPos) {
	if (IsValidMove(newPos)) return false;
	currentMap->SetCellOccupant(oldPos->GetX(), oldPos->GetY(), NULL);
	currentMap->SetCellOccupant(newPos->GetX(), newPos->GetY(), a);
	return true;
}

bool GameManager::IsValidMove(Vector2* position) {
	return position->GetX() < currentMap->GetColumns()
		&& position->GetY() < currentMap->GetRows()
		&& position->GetX() > 0 && position->GetY() > 0;
}
