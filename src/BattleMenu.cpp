#include "../include/BattleMenu.h"
#include <iostream>

BattleMenu::BattleMenu(float width, float height){

  selectedIndex = 0;

  if (!font.loadFromFile("../src/Gameplay.ttf")) {
  //error
  //create BattleMenu object
  //BattleMenu battleMenu(App.getSize().x, App.getSize().y);
  //#include "BattleMenu.h"
  }

  //position each option on the screen, with the color red if it is highlighted
  optionText[0].setFont(font);
  optionText[0].setFillColor(sf::Color::Red);
  optionText[0].setString("Attack");
  optionText[0].setPosition(sf::Vector2f(width/4, height/(maxOptions+1)*1/2));

  optionText[1].setFont(font);
  optionText[1].setFillColor(sf::Color::Blue);
  optionText[1].setString("Magic");
  optionText[1].setPosition(sf::Vector2f(width/4, height/(maxOptions+1)*1));

  optionText[2].setFont(font);
  optionText[2].setFillColor(sf::Color::Blue);
  optionText[2].setString("Evade");
  optionText[2].setPosition(sf::Vector2f(width/4, height/(maxOptions+1)*3/2));

  optionText[3].setFont(font);
  optionText[3].setFillColor(sf::Color::Blue);
  optionText[3].setString("Item");
  optionText[3].setPosition(sf::Vector2f(width/4, height/(maxOptions+1)*4/2));

}

BattleMenu:: ~BattleMenu(){

}
void BattleMenu::draw(sf::RenderWindow &window){

  window.clear(sf::Color::Black);

  int i = 0;
  for (; i< maxOptions; i++){
    window.draw(optionText[i]);
  }
}

void BattleMenu::moveUp(){
  std::cout << selectedIndex << std::endl;
  if (selectedIndex - 1 >= 0){
    optionText[selectedIndex].setFillColor(sf::Color::Blue);
    selectedIndex --;
    optionText[selectedIndex].setFillColor(sf::Color::Red);
  }
}

void BattleMenu::moveDown(){
  if (selectedIndex + 1 < maxOptions){
    optionText[selectedIndex].setFillColor(sf::Color::Blue);
    selectedIndex ++;
    optionText[selectedIndex].setFillColor(sf::Color::Red);
  }
}
