#include "../include/Inventory.h"
#include <iostream>
#include <string>
#include <array>

Inventory::Inventory()
{
	itemCount = 0;
	potion_count = 0;
	potion_index = -1;
};

Inventory:: ~Inventory(){

}

void Inventory::addItem(std::string item){
	if (item == "Potion"){
		potion_count++;
		if (potion_index == -1){
			itemArray[itemCount] = "Potion x " + std::to_string(potion_count);
			potion_index = itemCount;
		}
		else {
			itemArray[potion_index] = "Potion x " + std::to_string(potion_count);
		}
	}
	else {
		itemArray[itemCount] = item;
		itemCount++;
	}
}

void Inventory::useItem(int index){
	if (index == potion_index){
		if (potion_count == 0){
			itemArray[itemCount] = "-";
		} 
		else {
			potion_count--;
			itemArray[potion_index] = "Potion x " + std::to_string(potion_count);
		}
	}
	else {
		itemArray[index] = "-";
	}
}
