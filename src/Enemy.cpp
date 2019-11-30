#include "Enemy.h"
#include <iostream>
#include <cstdlib>
#include <random>

Enemy::Enemy(){
    
}

//allows other classes to set the EnemyType
void Enemy::setEnemyType(EnemyType newType)
{
    type = newType;
}

void Enemy::enemyEffect(sf::Text& output, int& userDamage, bool& userDefend, bool& item, bool& showBattleBar){
    switch(type){
        case Regular:
            break;
        case Owl:
        //freeze the user 1 out of 4 times (can change for balance)
            freeze = (rand()%4);
            if (freeze == 0){
                userDamage = 0;
                userDefend = false;
                item = false;
                showBattleBar = false;
                //logic.enemyDefend = false;
                output.setString("The icy owl froze you!");
            }
            else{
                output.setString(" ");
            }
            break;
        case Snake:
            output.setString("The snake poisoned you!");
            break;
        case Cat:
            output.setString("The cat confused you!");
            break;


    }
}

Enemy::EnemyType Enemy::getEnemyType()
{
    return type;
}

