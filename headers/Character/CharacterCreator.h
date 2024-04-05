#pragma once
#include "Character/Character.h"
#include "Strategies/HumanPlayerStrategy.h"
class CharacterCreator
{

public:
    static Character* LoadCharacter();
    static Character* CreateCharacter();
    static Weapon* SelectWeapon(Character* c);




};

