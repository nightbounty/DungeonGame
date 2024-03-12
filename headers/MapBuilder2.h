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
        // std::vector<std::string> characterTier = {"Tier 1" , "Tier 2", "Tier 3", "Tier 4"};
        // std::vector<std::string> worldTier = {"Beginner", "Intermediate", "Hard", "Advance"};
        // std::vector<std::string> itemTier = {"Common", "Uncommon", "Rare", "Very Rare"};
        
        public:
        // Constructor
        MapBuilder2();

        virtual void readFile(const std::string &fileName) override;

         virtual int importMapLevel()override;
         std::string importWorldName() override;
         std::string importWorldTier() override;
         std::vector<Item*> &importItems() override;
        std::vector<std::string> importCharacters() override;
        // std::vector<std::string> importCharacterTier();
        // std::vector<std::string> importItemTier();
          
          void tier1map();
          void tier2map();
          void tier3map();
          void tier4map();
          void createMap();
};




#endif