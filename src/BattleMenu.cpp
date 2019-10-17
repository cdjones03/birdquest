#include "../include/BattleMenu.h"

BattleMenu::BattleMenu(float width, float height){
    if (!font.loadFromFile("/assets/battleFont.ttf")) {
    //error
  }
  optionText[0].setFont(font);
  optionText[0].setColor(sf::Color::Black);
  optionText[0].setString("Attack");
  optionText[0].setPosition(sf::Vector2f(width/2, height/(maxOptions+1)*1));

}