#include "Strategies/AggressorStrategy.h"
#include "Actor.h"

void AggressorStrategy::ExecuteTurn(Actor* actor) {
	actor->MoveTowardTarget();
	actor->Attack();
}