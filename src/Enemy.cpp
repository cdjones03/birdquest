#include "Enemy.h"
#include <iostream>
#include <cstdlib>
#include <random>

Enemy::Enemy(){
    //turnsPoisoned = 0;
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

void Enemy::setEnemyDisplay(sf::Text& name, sf::Texture& texture){
    //displays the enemy's name and sets sprite texture in battleMenu based on what type it is
    switch(type){
    case Regular:
      name.setString("ENEMY");
      if(!texture.loadFromFile("../resources/spritesheets/owl_1.png", sf::IntRect(0, 0, 90, 90))){
        }
      break;
    case IceOwl:
      name.setString("Ice Owl");
      if(!texture.loadFromFile("../resources/spritesheets/owl_boss.png", sf::IntRect(0, 0, 90, 90))){
        }
      break;
    case Snake:
      name.setString("Snake Boss");
      if(!texture.loadFromFile("../resources/spritesheets/snake_boss.png", sf::IntRect(0, 0, 90, 90))){
        }
      break;
    case Cat: 
      name.setString("Cat Boss");
      if(!texture.loadFromFile("../resources/spritesheets/cat_boss.png", sf::IntRect(0, 0, 90, 90))){
        }
      break;
    case FinalBoss:
      name.setString("Malphas");
      if(!texture.loadFromFile("../resources/spritesheets/Malphas_front.png", sf::IntRect(0, 0, 90, 90))){
        }
      break;
  }
}

//sets the sprite to appear in the battleMenu based on the type
void Enemy::setSprite(sf::Sprite& sprite){

}

Enemy::EnemyType Enemy::getEnemyType()
{
    return type;
}
