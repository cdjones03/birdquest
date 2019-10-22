#include "BattleLogic.h"


int BattleLogic::updateHP(int damage, int HP)
{
    if (damage <= HP){
        HP -= damage;
    }
    if (damage > HP){
        HP = 0;
    }
    return HP;
}

//returns who has won based on if the HP is 0, returns 2 if nobody has won
int BattleLogic::whoWon(int enemyHP, int userHP)
{
    if (enemyHP == 0){
        return 0;
    }
    if (userHP == 0){
        return 1;
    }
    else if (enemyHP > 0 && userHP > 0){
        return 2;
    }
    return 3;
}
