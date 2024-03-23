#pragma once
#include "Actor.h"
class Enemy :
    public Actor
{
public: 
    Enemy(string name, Vector2* pos, TurnStrategy* ts = NULL, int level = 1, string cls = "", Actor* target = NULL);
    void Interact();
    string GetTokenCode();
    string ToString();
};

