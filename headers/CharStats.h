#ifndef CHARSTATS_H
#define CHARSTATS_H
#include <string>
#include <sstream>

class CharStats
{
private:
    int intelligence;
    int wisdom;
    int armorClass;


public:
    // constructor
    CharStats()
    {
    }

    // Methods that Increases Character Stats
public:
    void increaseIntelligence()
    {
    }

    void increaseWisdom()
    {
    }

    void increaseArmorClass()
    {
    }

    // toString method
    std::string toString() const;
};

#endif // CHARSTATS_H