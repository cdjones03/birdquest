#pragma once
#include "Indicator.h"
#include "BattleBar.h"

#define maxHP 100

class BattleLogic
{
public: 
    BattleLogic();
    ~BattleLogic() = default;
    
    int updateHP(int damage, int HP);
    int whoWon(int enemyHP, int userHP);
    int getEnemyDamage();
    int resetHP(int HP);
    int healItem(int damage, int HP);
    int getUserDamage(int damage, bool magic);


    bool enemyDefend;
    //add a poison attack, that will cause consistent damage.
    bool enemyPoison;

    Indicator indi;
    BattleBar bar;
private:
    
    int userHP_;
    int enemyHP_;

};