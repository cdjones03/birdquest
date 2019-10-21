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

  rectangle.setSize(sf::Vector2f(width/2, height/4.5));
  rectangle.setPosition(width/60, height - height/4.1);
  rectangle.setFillColor(sf::Color::Black);
  rectangle.setOutlineThickness(4);
  rectangle.setOutlineColor(sf::Color::White);

  //position each option on the screen, with the color red if it is highlighted
  optionText[0].setFont(font);
  optionText[0].setFillColor(sf::Color::Red);
  optionText[0].setString("Attack");
  optionText[0].setPosition(sf::Vector2f(width/35, height/(maxOptions+1)*4));

  optionText[1].setFont(font);
  optionText[1].setFillColor(sf::Color::Blue);
  optionText[1].setString("Magic");
  optionText[1].setPosition(sf::Vector2f(width/35, height/(maxOptions+1)*9/2));

  optionText[2].setFont(font);
  optionText[2].setFillColor(sf::Color::Blue);
  optionText[2].setString("Evade");
  optionText[2].setPosition(sf::Vector2f(width/3, height/(maxOptions+1)*4));

  optionText[3].setFont(font);
  optionText[3].setFillColor(sf::Color::Blue);
  optionText[3].setString("Item");
  optionText[3].setPosition(sf::Vector2f(width/3, height/(maxOptions+1)*9/2));

}

BattleMenu:: ~BattleMenu(){

}
void BattleMenu::draw(sf::RenderWindow &window){

  window.clear(sf::Color::Black);
  window.draw(rectangle);
  int i = 0;
  for (; i< maxOptions; i++){
    window.draw(optionText[i]);
  }
}

void BattleMenu::moveUp(){
  if (selectedIndex - 1 == 0 || selectedIndex - 1 == 2){
    optionText[selectedIndex].setFillColor(sf::Color::Blue);
    selectedIndex --;
    optionText[selectedIndex].setFillColor(sf::Color::Red);
  }
}

void BattleMenu::moveDown(){
  if (selectedIndex + 1 == 1 || selectedIndex + 1 == 3){
    optionText[selectedIndex].setFillColor(sf::Color::Blue);
    selectedIndex ++;
    optionText[selectedIndex].setFillColor(sf::Color::Red);
  }
}

void BattleMenu::moveRight(){
  if (selectedIndex + 2 == 3 || selectedIndex + 2 == 2){
    optionText[selectedIndex].setFillColor(sf::Color::Blue);
    selectedIndex += 2;
    optionText[selectedIndex].setFillColor(sf::Color::Red);
  }
}

void BattleMenu::moveLeft(){
  if (selectedIndex - 2 == 0 || selectedIndex - 2 == 1){
    optionText[selectedIndex].setFillColor(sf::Color::Blue);
    selectedIndex -= 2;
    optionText[selectedIndex].setFillColor(sf::Color::Red);
  }
}