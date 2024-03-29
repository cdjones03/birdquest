#pragma once
#include <iostream>
#include <string>

class Inventory
{
public:
    Inventory();
    ~Inventory();

    std::string itemArray[4] = {"-", "-", "-", "-"};

    void addItem(std::string item);
    void useItem(int index);
    std::string getItemArrayItem(int index);

private:

    int itemCount;
    int potion_count;
    int potion_index;
};
