#include "../include/Inventory.h"
#include <iostream>
#include <string>
#include <array>

Inventory::Inventory()
{
	itemCount = 0;
};

Inventory:: ~Inventory(){

}

void Inventory::addItem(std::string item){
	itemArray[itemCount] = item;
	itemCount++;
	
}

