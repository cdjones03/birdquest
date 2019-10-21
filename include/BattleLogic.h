#pragma once


#define maxHP 100

class BattleLogic
{
public: 
    BattleLogic() = default;
    ~BattleLogic() = default;
    
    void updateHP(int damage, int HP);
    int whoWon(int enemyHP, int userHP);

private:
    int userHP_;
    int enemyHP_;

};