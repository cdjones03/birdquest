#pragma once
#include "SFML/Graphics.hpp"

#define maxOptions 4

class BattleMenu
{
public:
    BattleMenu(float width, float height);
    ~BattleMenu();

    void draw(sf::RenderWindow &window);
    void updateHP(int userHP, int enemyHP);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getSelectedOption(){
        return selectedIndex;
    }
private:
    int selectedIndex;
    sf::Font font;
    sf::Text optionText[maxOptions];
    sf::RectangleShape rectangle;
    sf::CircleShape bird_battle;
    sf::Text userHP;
    sf::Text enemyHP;
    sf::RectangleShape healthBar;
};