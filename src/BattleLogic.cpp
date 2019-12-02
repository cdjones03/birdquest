#include "BattleLogic.h"
#include <iostream>
#include <cstdlib>
#include <random>

BattleLogic::BattleLogic(){
    //enemyDefend = false;
    poisoned = false;

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

//enemy will either choose to defend and attack for 0, or attack with damage between 5-30
int BattleLogic::getEnemyDamage()
{   
    enemyDefend = false;
    defend = (rand()%5);
    std::cout << "defend " << defend << std::endl;
    
    if (defend == 2){
        enemyDefend = true;
    }
    if (enemyDefend){
        damage = 0;
    }
    else{
        damage = 5+(rand()%25);
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

void BattleLogic::OwlBoss(int& userDamage, bool& userDefend, bool& item, bool& showBattleBar, sf::Text& output){
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
}

void BattleLogic::SnakeBoss(int& enemyDamage, sf::Text& output, bool& eDefend){
    //if the enemy attacked, it has a chance to poison you, dealing extra damage over 3 turns
    if (!eDefend && !poisoned){
        poison = (rand()%3);
        std::cout<<"poison"<<poison<<std::endl;
        poisoned = false;
        if (poison == 1){
            poisoned = true;
            turnsPoisoned = 0;
        }
        else{
            output.setString(" ");
        }
    }
    if (eDefend){
        poisoned = false;
    }
    if (poisoned){
        if (turnsPoisoned <= 2){
            turnsPoisoned+=1;
            enemyDamage += 5;
            if (turnsPoisoned == 1){
                output.setString("You have been poisoned!\nYou took 5 additional damage");
            }
            else if (turnsPoisoned >1){
                output.setString("You are still poisoned!\nYou took 5 additional damage");
            }           
        }
        else{
            //wasPoisonedLastTurn = true;
            poisoned = false;
            output.setString("You are no longer poisoned!");
            turnsPoisoned = 0;           
        }         
    }
    /**
    if (!poisoned && !wasPoisonedLastTurn)
    {
        output.setString(" ");
    }
    */
}

void BattleLogic::CatBoss(sf::Text& output, int& userDamage, bool&item, bool&userDefend)
{
    confuse = (rand()%4);
    
    output.setString("The cat confused you!");
    
}