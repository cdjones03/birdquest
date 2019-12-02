#include "Enemy.h"
#include <iostream>
#include <cstdlib>
#include <random>

Enemy::Enemy(){
    turnsPoisoned = 0;
}

//allows other classes to set the EnemyType
void Enemy::setEnemyType(EnemyType newType)
{
    type = newType;
}

void Enemy::enemyEffect(sf::Text& output, int& userDamage, bool& userDefend, bool& item,
                                bool& showBattleBar, bool& enemyDefend, int& enemyDamage){

    switch(type){
        case Regular:
            break;
        case IceOwl:
        //freeze the user 1 out of 4 times (can change for balance)
            logic.OwlBoss(userDamage,userDefend,item, showBattleBar, output);
            break;
        case Snake:
            //if the enemy attacked, it has a chance to poison you, dealing extra damage over 3 turns
            //it will not poison you again after you are no longer poisoned? check.
            logic.SnakeBoss(enemyDamage, output, enemyDefend);
            break;
        
        case Cat:
        //the enemy has a chance to steal your attack damage and cause you to attack for 0.
            logic.CatBoss(output, userDamage, item, userDefend, enemyDamage, enemyDefend);
            break;

        case FinalBoss:
            break;

    }
}

Enemy::EnemyType Enemy::getEnemyType()
{
    return type;
}
