#include "TurnStrategy.h"
class HumanPlayerStrategy: public TurnStrategy
{
public:
	void ExecuteTurn(Actor* actor);
	string ToString();
};

