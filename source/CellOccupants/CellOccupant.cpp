#include "CellOccupants/CellOccupant.h"
#include <Vector2.h>
class Character;
CellOccupant::CellOccupant(Vector2* position, string name) {
    this->position = position;
    this->name = name;
}
CellOccupant::CellOccupant() {
    this->position = new Vector2(0, 0);
}
bool CellOccupant::Interact(Character* character)
{
	return false;
}


string CellOccupant::GetTokenCode()
{
	return "";
}

#pragma region Position

Vector2* CellOccupant::GetPosition()
{
    return this->position;
}

int CellOccupant::GetPositionX() {
    return this->position->GetX();
}

int CellOccupant::GetPositionY() {
    return this->position->GetY();
}

void CellOccupant::SetPosition(Vector2* pos)
{
    this->position = pos;
}

string CellOccupant::ToString() {
    return name + " at (" +
        std::to_string(GetPositionX()) + ", " +
        std::to_string(GetPositionY()) + ")";
}

