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
    
private:
        
    int itemCount;
};