#pragma once
#include "BattleLogic.h"
#include "BattleBar.h"
#include "Indicator.h"

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
    void snakeEffect();
    void catEffect();
    void owlEffect();
    int types;
private:

};