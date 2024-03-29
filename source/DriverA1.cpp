/*****************************************************************//**
 * \file   Driver.cpp
 * \brief  Driver for COMP345 Assignment 1
 *  Includes testing for character, map, items, and dice
 * 
 * \author Kevin Theam (40192205), Jasmar Louie Badion (40174632), Eliza Bulatao (40252258), Alissia Bocarro (40243259)
 * \date   February 2024
 *********************************************************************/

#include <iostream>
#include "Map.h"
#include "Items/Helmet.h"
#include "Items/Armor.h"
#include "Items/Item.h"
#include "Items/Ring.h"
#include "Items/Belt.h"
#include "Items/Boots.h"
#include "Items/Weapon.h"
#include "Items/ItemContainer.h"
#include "Items/Shield.h"
#include "Character/Character.h"
#include "Dice.h"
#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()
using namespace std;

/*int main()
{
    // Character Testing

    cout << "Welcome to the GAME! +_+\n";
    cout << "**\n";

    cout << "Let's create your character\n";
    cout << "**\n";

    // Seed the random number generator once
    srand(static_cast<unsigned int>(time(0)));

    // Prompt for character creation details
    string name;
    string characterClass= "Fighter";
    int level;

    cout << "Enter your Fighter's name: ";
    cin >> name;

    cout << "Enter your character's level: ";
    cin >> level;

    // Create the character
    Character myCharacter(level, characterClass);

    // Display character stats
    myCharacter.displayStats();

    // Equip an item
    string item;
    cout << "Enter an item for your character to wear: ";
    cin >> item;
    myCharacter.wearItem(item);

    
    // MAP TESTING!
    int rows, columns, startY;

    cout << "\n======================================" << endl;
    cout << "Next, let's test the map creation!~";
    cout << "\n======================================\n" << endl;
    
    cout << "Please enter the number of rows for the map: \n";
    cin >> rows;

    cout << "Please enter the number of columns for the map: \n";
    cin >> columns;

    cout << "Please enter the y start coordinate for the map: \n";
    cin >> startY;

    cout << "Generating a map based on your input! :D" << endl;
    Map* testMap = new Map(rows, columns, new Vector2(0, startY));
   
    cout << "\n=== LEGEND ===\nD: Door\nE: Enemy\nC: Chest\nO: Empty\nW: Wall";
    
    cout << "\n=== YOUR MAP!! *^* ===\n\n" << testMap->ToString();

    // Part 3: ITEMS & ITEM CONTAINER
    // Create Items

    cout << "\n======================================" << endl;
    cout << "Now testing the item system! :)";
    cout << "\n======================================\n" << endl;
    Armor *armor = new Armor("Basic Armor");
    Helmet *helm = new Helmet("Basic Helmet");
    Shield *shield = new Shield("White Shield");
    Ring *ring = new Ring("Silver Ring");
    Belt *belt = new Belt("Orange Belt");
    Boots *boots = new Boots("Red Boots");
    Weapon *sword = new Weapon("Black Sword");

    // Display Item's Enhancement
    armor->displayEnhancement();
    boots->displayEnhancement();
    sword->displayEnhancement();

    // skip line
    std::cout << "\n";

    // Display Item's Name
    std::cout << armor->toString() << std::endl;
    std::cout << boots->toString() << std::endl;

    // skip line
    std::cout << "\n";

    // Create an Item Container
    ItemContainer container1;

    // Adding items to container
    container1.addToContainer(armor);
    container1.addToContainer(helm);
    container1.addToContainer(shield);
    container1.addToContainer(ring);
    container1.addToContainer(belt);
    container1.addToContainer(boots);
    container1.addToContainer(sword);

    // Display Items Currently Inside Container
    container1.displayItems();

    // Take an item from the container
    Item *takenItem = container1.takeItem("Basic Armor");

    // Display Current Items In Container After Taken Item
    cout << "\nAfter taking an item:"
              << std::endl;
    container1.displayItems();

    // part 4: dice 

    cout << "\n======================================" << endl;
    cout << "Aaaand lastly, testing the dice! :D";
    cout << "\n======================================\n" << endl;
    Dice dice;
    string input;
    cout << "Roll dice of the following pattern xdy+z: ";
    cin >> input;
    int result = dice.rollDice(input);
    cout << "Result of the dice: " << result << std::endl;

    cout << "\n======================================" << endl;
    cout << "Thanks for playing!! :3";
    cout << "\n======================================\n" << endl;
} */


