#pragma once

#define maxHP 100

class BattleLogic
{
public: 
    BattleLogic();
    ~BattleLogic() = default;
    
    int updateHP(int damage, int HP);
    int whoWon(int enemyHP, int userHP);
    int getEnemyDamage();
    int resetHP(int HP);

    bool enemyDefend;


private:
    int userHP_;
    int enemyHP_;

};