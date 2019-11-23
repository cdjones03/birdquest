#include "BattleLogic.h"
#include <iostream>
#include <cstdlib>
#include <random>

BattleLogic::BattleLogic(){
    enemyDefend = false;

}

int BattleLogic::updateHP(int damage, int HP)
{
    
    HP -= damage;
    
    
    return HP;
}

//returns who has won based on if the HP is 0, returns 2 if nobody has won
int BattleLogic::whoWon(int enemyHP, int userHP)
{
    //if you win
    if ((enemyHP <= 0) && (enemyHP <= userHP)){
        return 0;
    }
    //if you lose
    if ((userHP <= 0) && (enemyHP >userHP)){
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
        damage = 1+(rand()%29);
    }
    
    return damage;
}

int BattleLogic::resetHP(int HP){
    return (HP = maxHP);
}

int BattleLogic::healItem(int damage, int HP){
    
    HP = updateHP(damage, HP) + 30;
    if ((HP) > 100){
          HP = 100 - damage;
        } 
    return HP;
}

int BattleLogic::getUserDamage(int damage, bool magic, bool userDefend){
    if (magic){
        damage *= 1.5;
    }
    if (userDefend){
        damage = 0;
        //return damage;
    }
    if (enemyDefend && !userDefend){
        if (damage >= 10){
          damage -=10;
        }
        else{
          damage = 0;
        }
      }
    
    return damage;
}
//could try to add this to getEnemyDamage, but for now this requires less refactoring
int BattleLogic::userDefend(int enemyDamage, int userDamage, bool defend){
    if (defend){
        if (enemyDamage >= userDamage){
            enemyDamage -= userDamage;
        }
        else if (enemyDamage < userDamage){
            enemyDamage = 0;
        }
        
    }
    return enemyDamage;
}