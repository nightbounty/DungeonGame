#include "Strategies/FriendlyStrategy.h"
#include "Actor.h"

void FriendlyStrategy::ExecuteTurn(Actor* actor) {
	actor->MoveTowardTarget();
}

string FriendlyStrategy::ToString() {
	return "Friendly Strategy";
}
