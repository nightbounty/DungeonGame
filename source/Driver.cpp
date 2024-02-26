// comp345A1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

using namespace std;

int main()
{
    
    // MAP TESTING!
    int rows, columns, startY;

    cout << "Welcome to the d20 Map Generator! :D\n";
    cout << "************************************\n";
    
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
    std::cout << "\nAfter taking an item:"
              << std::endl;
    container1.displayItems();
}


