#include "TurnStrategy.h"
class AggressorStrategy: public TurnStrategy
{
public: 
	void ExecuteTurn(Actor* actor);
	string ToString();
};

