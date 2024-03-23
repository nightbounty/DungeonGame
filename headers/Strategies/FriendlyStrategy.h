#include "TurnStrategy.h"
class FriendlyStrategy: public TurnStrategy
{
public:
	void ExecuteTurn(Actor* actor);
	string ToString();
};

