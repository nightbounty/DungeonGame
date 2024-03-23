/** @class ItemDecorator 
 * Is a subclass to Character
*/
#ifndef ITEMDECORATOR_H
#define ITEMDECORATOR_H

#include "Character.h"
#include "Item.h"
class ItemDecorator : public Character{

    public:
    ItemDecorator();
    // ItemDecorator(Character* c);
        void equipItem(Item* item) override;

        /** Contructor
         * @param character
        */

        /** Destructor*/
        virtual ~ItemDecorator(){}
};


#endif