#include "Strategies/AggressorStrategy.h"

void AggressorStrategy::ExecuteTurn(Actor* actor) {
	actor->MoveTowardTarget();
	actor->Attack();
}