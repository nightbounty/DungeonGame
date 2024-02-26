// comp345A1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Map.h>
#include "CharStats.cpp"
#include "Helmet.cpp"
#include "Armor.cpp"
#include "Item.cpp"
#include "Ring.cpp"
#include "Belt.cpp"
#include "Boots.cpp"
#include "Weapon.cpp"
#include "ItemContainer.cpp"
#include "Shield.cpp"

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

    // Display Item's Name
    std::cout << armor->toString() << std::endl;
    std::cout << boots->toString() << std::endl;

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
    std::cout << "After taking an item:\n"
              << std::endl;
    container1.displayItems();
}


