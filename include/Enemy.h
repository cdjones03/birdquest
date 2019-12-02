#pragma once
#include "BattleLogic.h"

//For different enemyies, we want different status effects:
//Snake: lingereing poison damage
//Cat:  confusion aka unpredictable damage
//owl: Freezes a random option for a turn

//final boss: does all 3 status effects
class Enemy
{
public:
    Enemy();
    ~Enemy() = default;
    enum EnemyType
    {
        Regular, Snake, Cat, IceOwl, FinalBoss
    };
    EnemyType type;
    void setEnemyType(EnemyType newType);
    EnemyType getEnemyType();

    void enemyEffect(sf::Text& output, int& userDamage, bool& userDefend,
        bool& item, bool& showBattleBar, bool& enemyDefend, int& enemyDamage);
    void setEnemyDisplay(sf::Text& name, sf::Texture& texture);
    void setSprite(sf::Sprite& sprite);

    BattleLogic logic;
    //int types;
    //BattleMenu bMenu;
    
private:
    //can delete later
    //int turnsPoisoned;
    int temp;
};
