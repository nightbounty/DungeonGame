#ifndef HUMANPLAYERSTRAT_H
#define HUMANPLAYERSTRAT_H
#include "TurnStrategy.h"
class HumanPlayerStrategy: public TurnStrategy
{
public:
	void ExecuteTurn(Actor* actor);
	string ToString();
};

#endif;

