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
    int getUserDamage(int damage, bool magic, bool userDefend);
    int userDefend(int enemyDamage, int userDamage, bool defend);


    bool enemyDefend;
    //add a poison attack, that will cause consistent damage.
    bool enemyPoison;

    Indicator indi;
    BattleBar bar;
    //Enemy enemy;
private:
    int defend;
    int damage;
    
    int userHP_;
    int enemyHP_;

};