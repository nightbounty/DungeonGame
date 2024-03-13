/** @class MapBuilder2
 * @brief inherits from MapInterface
 * This Class Reads a Map .txt file & updates the Character Hero Tier,
 * Item Tier & Enemy Tier to reflect the World's Map Level.
*/

#ifndef MAPBUILDER2_H
#define MAPBUILDER2_H

#include <string>
#include <vector>
#include "Items/Item.h"
#include "MapInterface.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "MapBuilder.h"
#include "Map2.h"
#include "Items/Item.h"
#include "Items/ItemSub.h"


class MapBuilder2: public MapInterface{

    private:

        std::vector<std::string> mapFileCopy;
        std::vector<Item*> tempItems;
        std::vector<std::string> tempChars;
        
        public:
        /**Map Concrete Builder 2 Constructor*/
        MapBuilder2();

        virtual void readFile(const std::string &fileName) override;

         virtual int importMapLevel()override;
         std::string importWorldName() override;
         std::string importWorldTier() override;
         std::vector<Item*> &importItems() override;
        std::vector<std::string> importCharacters() override;

          /**Tier methods: Updates map to have appropriate Char, Items and Enemies*/
          void tier1map();
          void tier2map();
          void tier3map();
          void tier4map();
          void createMap();
};




#endif
