#include <iostream>
#include <Enemy.h>

void Enemy::Battle(Character c) {
	cout << "the battle has begun!" << endl;
}

void Enemy::Interact(Character c) {
	Battle(c);
}
