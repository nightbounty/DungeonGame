/** @class MapInterface */
#ifndef MAPINTERFACE_H
#define MAPINTERFACE_H

#include <string>
#include <vector>
#include "Items/Item.h"
class MapInterface{

    public:
        /**Destructor */
        virtual ~MapInterface(){};
        /**Method to Read a Map File*/
        virtual void readFile(const std::string &fileName)=0;
        /**Method: Imports Map Level From Given File*/
        virtual int importMapLevel() = 0;
        /**Method: Imports World Level From Given File*/
        virtual std::string importWorldName() = 0;
        /**Method: Imports World Tier (Beginner, Intermediate, Hard, Advanced) From Given File*/
        virtual std::string importWorldTier() = 0;
        /**Method: Imports Items From Given File*/
        virtual std::vector<Item*> &importItems() = 0;
        /**Method: Imports Characters From Given File*/
        virtual std::vector<std::string> importCharacters() = 0;

};

#endif
