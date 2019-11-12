#pragma once

#include "PauseMenu.h"
#include <iostream>
#include <string>

class Inventory
{
    public:
        Inventory(float width, float height);
        ~Inventory();

        std::string getItem(std::string itemArray[], int itemIndex);
        int getItemCount(int itemArray[], int itemIndex);

        std::string itemArray[4] = {"Key","Potion","Poison","Mana"};
        int itemCount[4];

    private:
        
        //int itemIndex;
        PauseMenu pMenu(float width, float height);
        

};