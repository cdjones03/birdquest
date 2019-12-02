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
        case Owl:
            logic.OwlBoss(userDamage, userDefend, item, showBattleBar, output);
            break;
        case Snake:
            logic.SnakeBoss(enemyDamage, output);       
            break;
        case Cat:
        //probably going to make this change the damage you dealt instead of the indicator
            confuse = (rand()%4);
            output.setString("The cat confused you!");
            break;

        case FinalBoss:
            break;

    }
}

Enemy::EnemyType Enemy::getEnemyType()
{
    return type;
}
