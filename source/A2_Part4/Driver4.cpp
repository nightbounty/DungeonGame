#include "Map2.h"
#include "Item.h"
#include "MapBuilder.h"
#include "MapInterface.h"
#include "ItemSub.h"
#include "MapBuilder2.h"
#include <iostream>

int driver4(){
// *********************************************
// PART 4: MAP BUILDER
// *********************************************

std::cout << "\nConcrete Builder 1\n" << std::endl;
// Create a Map Builder
MapBuilder mapBuilder;

// Read Map.txt file
mapBuilder.readFile("MapSaved.txt");
//****** Builder 1: Check if map is saved, then create a map object ******
mapBuilder.createMap();


//****** Builder 2: Check Map Contents, then modifies map object based on Map Contents ******
std::cout << "\nConcrete Builder 2" << std::endl;
// Create Map Builder #2
MapBuilder2 mapBuilder2;
// Read Map.txt file
mapBuilder2.readFile("MapContents.txt");
mapBuilder2.createMap();

return 0;
}

// int main(){
//     return driver4();
// }