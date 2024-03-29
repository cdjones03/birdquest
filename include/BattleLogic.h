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

    void OwlBoss(int& userDamage, bool& userDefend, bool& item, bool& showBattleBar, sf::Text& output);
    void SnakeBoss(int& enemyDamage, sf::Text& output, bool& enemyDefend);
    void CatBoss(sf::Text& output, int& userDamage, bool&item, bool&userDefend, 
        int& enemyDamage, bool&enemyDefend);
    void FinalBoss();

    bool enemyDefend;
    //add a poison attack, that will cause consistent damage.
    bool enemyPoison;

    Indicator indi;
    BattleBar bar;
    //Enemy enemy;
private:
    int freeze;
    int defend;
    int damage;
    int poison;
    int confuse;
    bool poisoned;
    bool wasPoisonedLastTurn;
    int turnsPoisoned;
    int userHP_;
    int enemyHP_;
    int enemyDamageStored;

};