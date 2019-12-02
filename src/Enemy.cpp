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
<<<<<<< HEAD
        case IceOwl:
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

=======
        case Owl:
            logic.OwlBoss(userDamage, userDefend, item, showBattleBar, output);
            break;
        case Snake:
            logic.SnakeBoss(enemyDamage, output);       
>>>>>>> 1256301360721bc0e0ff16365dffd2d9e2ee3588
            break;
        case Cat:
        //actually going to switch enemy and user Damage randomly
            logic.CatBoss(output, userDamage, item, userDefend);
            break;

        case FinalBoss:
            break;

    }
}

Enemy::EnemyType Enemy::getEnemyType()
{
    return type;
}
