/** @class MapBuilder
 * @brief Determines whether a Map .txt file
 * was saved by user. If yes, transforms contents to a
 * Map Object for future editing.
 */

#ifndef MAPBUILDER_H
#define MAPBUILDER_H

#include <string>
#include <vector>
#include "Items/Item.h"
#include "MapInterface.h"
#include "Map2.h"
#include "Items/ItemSub.h"

#include <iostream>
#include <fstream>
#include <sstream>



class MapBuilder: public MapInterface{

    private:
        std::vector<std::string> mapFileCopy;
        std::vector<Item*> tempItems;
        std::vector<std::string> tempChars;
        public:
        
        // Constructor
        MapBuilder();

        virtual void readFile(const std::string &fileName) override;

         virtual int importMapLevel()override;
         std::string importWorldName() override;
         std::string importWorldTier() override;
         std::vector<Item*> &importItems() override;
        std::vector<std::string> importCharacters() override;
        /**Boolean method: returns true if map saved*/
         bool isMapSaved();
        /**Method: Creates a Map if .txt file was saved*/
          void createMap();
};




#endif
