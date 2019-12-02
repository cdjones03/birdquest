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
            //if the enemy attacked, it has a chance to poison you, dealing extra damage over 3 turns
            //still getting bug: for some reason it always poisons you on the first turn, and 
            //it will not poison you again after you are no longer poisoned.
            wasPoisonedLastTurn = false;
            if (!enemyDefend){
                poison = (rand()%3);
                std::cout<<"poison"<<poison<<std::endl;
                if (poison == 3){
                    poisoned = true;
                }
                else{
                    poisoned = false;
                    output.setString(" ");
                }
            }
            if (poisoned){
                if (turnsPoisoned <= 2){
                    turnsPoisoned+=1;
                    enemyDamage += 5;
                    if (turnsPoisoned == 1){
                        output.setString("You have been poisoned!\nYou took 5 additional damage");
                    }
                    else{
                        output.setString("You are still poisoned!\nYou took 5 additional damage");
                    }
                    
                }
                else{
                    wasPoisonedLastTurn = true;
                    poisoned = false;
                    output.setString("You are no longer poisoned!");
                    turnsPoisoned = 0;
                    
                }
                
                
            }
            if (!poisoned && !wasPoisonedLastTurn)
            {
                output.setString(" ");
            }
            
            break;
        case Cat:
        //probably going to make this change the damage you dealt instead of the indicator
            confuse = (rand()%4);
            output.setString("The cat confused you!");
            break;


    }
}

Enemy::EnemyType Enemy::getEnemyType()
{
    return type;
}
