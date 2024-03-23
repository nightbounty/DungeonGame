#include "Strategies/FriendlyStrategy.h"
#include "Actor.h"

void FriendlyStrategy::ExecuteTurn(Actor* actor) {
	cout << "Hellooooo from the friendly turn execution! o^o" << endl;
	actor->MoveTowardTarget();
}

string FriendlyStrategy::ToString() {
	return "Friendly Strategy";
}
