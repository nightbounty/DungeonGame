#include "Strategies/HumanPlayerStrategy.h"
#include <iostream>
using namespace std;

void HumanPlayerStrategy::ExecuteTurn(Actor* actor){
	string direction;
	cout << "Where would you like to move?" << endl;
	cin >> direction;
	// actor.move(direction)
	cout << "Which enemy would you like to attack?" << endl;
	// GameManager.DisplayEnemies()
	cout << "Would you like to use a free action?" << endl;

}
