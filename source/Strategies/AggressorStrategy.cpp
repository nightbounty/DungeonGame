#include "Strategies/AggressorStrategy.h"
#include "Actor.h"

void AggressorStrategy::ExecuteTurn(Actor* actor) {
	cout << "Hellooooo from the mean turn execution! o^o" << endl;
	actor->MoveTowardTarget();
	actor->Attack();
}

string AggressorStrategy::ToString() {
	return "Aggressor Strategy";
}
