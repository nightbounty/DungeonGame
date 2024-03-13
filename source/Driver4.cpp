#include "Map2.h"
#include "Items/Item.h"
#include "MapBuilder.h"
#include "MapInterface.h"
#include "Items/ItemSub.h"
#include "MapBuilder2.h"
#include <iostream>

int driver4(){
// *********************************************
// PART 4: MAP BUILDER
// *********************************************

std::cout << "===========================" << std::endl;
std::cout << "Concrete Builder " << std::endl;
std::cout << "===========================" << std::endl;
std::cout << "Checking if a Map is saved, then creating a Map object..." << std::endl;
// Create a Map Builder
MapBuilder mapBuilder;

// Read Map.txt file
mapBuilder.readFile(".\\source\\UserCreatedMaps\\MapSaved.txt");
//****** Builder 1: Check if map is saved, then create a map object ******
mapBuilder.createMap();


//****** Builder 2: Check Map contents, then modifies map object based on Map Contents ******
std::cout << "===========================" << std::endl;
std::cout << "Concrete Builder 2" << std::endl;
std::cout << "===========================" << std::endl;
std::cout << "Checking saved Map contents and modifying a Map based on contents" << std::endl;

// Create Map Builder #2
MapBuilder2 mapBuilder2;
// Read Map.txt file
mapBuilder2.readFile(".\\source\\UserCreatedMaps\\MapContents.txt");
mapBuilder2.createMap();

return 0;
}

// int main(){
//     return driver4();
// }