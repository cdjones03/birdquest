#pragma once
#include "SFML/Graphics.hpp"

#define maxOptions 4

class BattleMenu
{
public:
    BattleMenu(float width, float height);
    ~BattleMenu();

    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
private:
    int selectedIndex;
    sf::Font font;
    sf::Text optionText[maxOptions];
};