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

void Enemy::enemyEffect(EnemyType type){
    switch(type){
        case Regular:
            break;
        case Owl:
        //freeze the user 1 out of 4 times (can change for balance)
            freeze = (rand()%4);
            if (freeze == 0){
                bMenu.userDamage = 0;
                bMenu.userDefend = false;
                bMenu.item = false;
                bMenu.showBattleBar = false;
                bMenu.enemySpecialMove.setString("The icy owl froze you!");
            }
            break;
        case Snake:
            bMenu.enemySpecialMove.setString("The snake poisoned you!");
            break;
        case Cat:
            bMenu.enemySpecialMove.setString("The cat confused you!");
            break;


    }
}

