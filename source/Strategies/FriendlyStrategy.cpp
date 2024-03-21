#include "Strategies/FriendlyStrategy.h"

void FriendlyStrategy::ExecuteTurn(Actor* actor) {
	actor->MoveTowardTarget();
}
