#include "BattleLogic.h"
#include <iostream>
#include <cstdlib>
#include <random>
BattleLogic::BattleLogic(){
    enemyDefend = false;

}

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
    if (enemyHP <= 0 && (enemyHP < userHP)){
        return 0;
    }
    if (userHP <= 0 && (enemyHP >userHP)){
        return 1;
    }
    else if (enemyHP > 0 && userHP > 0){
        return 2;
    }
    return 3;
}


//enemy will either choose to defend and attack for 0, or attack with damage between 1-20
int BattleLogic::getEnemyDamage()
{   
    enemyDefend = false;
    int defend = (rand()%5);
    std::cout << "defend " << defend << std::endl;
    int damage;
    if (defend == 2){
        enemyDefend = true;
    }
    if (enemyDefend == true){
        damage = 0;
    }
    else{
        damage = 1+(rand()%19);
    }
    
    return damage;
}

int BattleLogic::resetHP(int HP){
    return (HP = maxHP);
}