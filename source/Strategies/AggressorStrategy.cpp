#include "Strategies/AggressorStrategy.h"
#include "Actor.h"

void AggressorStrategy::ExecuteTurn(Actor* actor) {
	actor->MoveTowardTarget();
	actor->Attack();
}

string AggressorStrategy::ToString() {
	return "Aggressor Strategy";
}
