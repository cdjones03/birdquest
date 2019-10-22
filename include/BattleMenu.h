#pragma once
#include "SFML/Graphics.hpp"
#include "BattleLogic.h"
#include "Indicator.h"

#define maxOptions 4

class BattleMenu
{
public:
    BattleMenu(float width, float height);
    ~BattleMenu();

    void draw(sf::RenderWindow &window);
    void updateHPText();
    void updateOutputText(int input);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getSelectedOption(){
        return selectedIndex;
    }
    bool playerTurn;
    int processInputs(sf::Event event);
    //bool whoseTurn();
private:
    Indicator indicator;
    int userDamage;
    int enemyDamage;
    int userHP;
    int enemyHP;
    BattleLogic logic;
    int selectedIndex;
    sf::Font font;
    sf::Text optionText[maxOptions];
    sf::RectangleShape rectangle;
    sf::CircleShape bird_battle;
    sf::Text userHP_Text;
    sf::Text enemyHP_Text;
    sf::Text outputText;
    sf::RectangleShape healthBar;
};