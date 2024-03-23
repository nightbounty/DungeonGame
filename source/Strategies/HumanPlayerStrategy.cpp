#include "Strategies/HumanPlayerStrategy.h"
#include <iostream>
#include <GameManager.h>
#include "CellOccupants/Enemy.h"
using namespace std;

void HumanPlayerStrategy::ExecuteTurn(Actor* actor){
	cout << "Hellooooo from the turn execution! o^o" << endl;
	
	actor->MoveActorFromInput();

	int enemyIndex;
	string attack;
	cout << "Would you like to attack? y or n" << endl;
	cin >> attack;
	if (attack == "y") {
		cout << "Which enemy would you like to attack?" << endl;
		GameManager::GetInstance()->DisplayEnemiesInMap();
		cin >> enemyIndex;
		Enemy* target = GameManager::GetInstance()->GetEnemyInMap(enemyIndex);
		actor->SetCurrentTarget(target);
		actor->Attack();
	}

	
	cout << "Using free actions would go here" << endl;
}

string HumanPlayerStrategy::ToString() {
	return "Human Strategy";
}