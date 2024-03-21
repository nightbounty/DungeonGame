#include "Actor.h"


Actor::Actor()
{
	this->position = new Vector2(0, 0);
	this->currentTarget = NULL;
}

Actor::Actor(Vector2* pos, TurnStrategy* ts, Actor* target)
{
	this->position = pos;
	this->turnStrategy = ts;
	this->currentTarget = target;
}

Vector2* Actor::GetPosition()
{
	return this->position;
}

int Actor::GetPositionX() {
	return this->position->GetX();
}

int Actor::GetPositionY() {
	return this->position->GetY();
}

void Actor::SetPosition(Vector2* pos)
{
	this->position = pos;
}

TurnStrategy* Actor::GetTurnStrategy()
{
	return this->turnStrategy;
}

void Actor::SetTurnStrategy(TurnStrategy* ts)
{
	this->turnStrategy = ts;
}

Actor* Actor::GetCurrentTarget()
{
	return this->currentTarget;
}

void Actor::SetCurrentTarget(Actor* target)
{
	this->currentTarget = target;
}

int Actor::GetCurrentHitPoints() {
	return this->currentHitPoints;
}

int Actor::GetTotalHitPoints() {
	return this->totalHitPoints;
}

void Actor::SetCurrentHitPoints(int hitPoints) {
	this->currentHitPoints = hitPoints;
}
void Actor::SetTotalHitPoints(int hitPoints) {
	this->totalHitPoints = hitPoints;
}

int Actor::GetArmorClass() {
	return 10; // this needs to have the logic from character
}

void Actor::MoveTowardTarget() {
	int newX, newY;
	Vector2* oldPos = this->position;
	// determine whether to move in X direction
	if (this->currentTarget->GetPositionX() < this->GetPositionX()) {
		newX = this->GetPositionX() - 1;
	}
	else if (this->currentTarget->GetPositionX() > this->GetPositionX()) {
		newX = this->GetPositionX() + 1;
	}
	else {
		newX = this->GetPositionX();
	}
	// determine whether to move in Y direction
	if (this->currentTarget->GetPositionY() < this->GetPositionY()) {
		newY = this->GetPositionY() - 1;
	}
	else if (this->currentTarget->GetPositionY() > this->GetPositionY()) {
		newY = this->GetPositionY() + 1;
	}
	else {
		newY = this->GetPositionY();
	}
	this->position = new Vector2(newX, newY);
	GameManager::GetInstance()->MoveActor(this, oldPos, this->position);
}

