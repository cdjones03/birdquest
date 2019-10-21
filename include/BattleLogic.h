#pragma once
#include "BattleMenu.h"

class BattleLogic
{
public: 
    BattleLogic();
    ~BattleLogic() = default;
    
    void updateHP(int damage, int HP);
    int whoWon(int enemyHP, int userHP);

private:

};