#pragma once
#include "Actor.h"
class Enemy :
    public Actor
{
private:
    int index;
public: 
    Enemy(string name, Vector2* pos, TurnStrategy* ts = NULL, int level = 1, string cls = "", Actor* target = NULL);
    string GetTokenCode();
    string ToString();
    void SetIndex(int index);
    int GetIndex();
    
};

