#pragma once
#include "BattleLogic.h"
//#include "BattleMenu.h"


//For different enemyies, we want different status effects:
//Snake: lingereing poison damage
//Cat: Erratic velocity
//owl: Freezes a random option for a turn

//final boss: does all 3 status effects
class Enemy
{
public:
    Enemy();
    ~Enemy() = default;
    enum EnemyType
    {
        Regular, Owl, Snake, Cat
    };
    EnemyType type;
    void setEnemyType(EnemyType newType);
    EnemyType getEnemyType();

    void enemyEffect(sf::Text& output, int& userDamage, bool& userDefend, bool& item, bool& showBattleBar);
    void snakeEffect();
    void catEffect();
    void owlEffect();
    BattleLogic logic;
    //int types;
    //BattleMenu bMenu;
    int freeze;
private:
    
    int poison;
};