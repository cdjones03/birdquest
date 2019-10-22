#include "../include/BattleMenu.h"
#include <iostream>

BattleMenu::BattleMenu(float width, float height){

  selectedIndex = 0;
  //damage = indicator.damageDealt;
  userDamage = 6;
  enemyDamage = 6;
  playerTurn = true;
  userHP = maxHP;
  enemyHP = maxHP;

  if (!font.loadFromFile("../src/Gameplay.ttf")) {
  //error
  }

  // border around the option in battle screen
  rectangle.setSize(sf::Vector2f(width/2, height/4.5));
  rectangle.setPosition(width/60, height - height/4.1);
  rectangle.setFillColor(sf::Color::Black);
  rectangle.setOutlineThickness(4);
  rectangle.setOutlineColor(sf::Color::White);

  // temporary placement for birdknight sprite in battle screen
  bird_battle.setRadius(80);
  bird_battle.setFillColor(sf::Color(30, 30, 255));
  bird_battle.setPosition(width - width/2.8, height - height/2.2);

  // HP text placement in battle menu
  userHP_Text.setFont(font);
  userHP_Text.setCharacterSize(18);
  std::string userHP_string1 = std::to_string(userHP);
  userHP_Text.setString("HP: " + userHP_string1);
  userHP_Text.setPosition(sf::Vector2f(width - width/2.3, height - height/8));

  enemyHP_Text.setFont(font);
  enemyHP_Text.setCharacterSize(18);
  std::string enemyHP_string1 = std::to_string(enemyHP);
  enemyHP_Text.setString("HP: " + enemyHP_string1);
  enemyHP_Text.setPosition(sf::Vector2f(width - width/2.3, height - height + 30));

  //setup output text
  outputText.setFont(font);
  outputText.setCharacterSize(22);
  outputText.setString("output test");
  outputText.setPosition(sf::Vector2f(width/2 - 200, height/2 -50));




  // health bar placement in battle menu
  healthBar.setSize(sf::Vector2f(width/3.5, height/30));
  healthBar.setFillColor(sf::Color(50, 255, 50));
  healthBar.setPosition(width - width/2.8, height - height/12);
  healthBar.setOutlineThickness(3);

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

//updates the text that displays the user and enemy HP, based on whose turn it is.
void BattleMenu::updateHPText()
{

  if (playerTurn){
    userHP = logic.updateHP(enemyDamage, userHP);
    std::string userHP_string = std::to_string(userHP);
    userHP_Text.setString("HP: " + userHP_string);
    playerTurn = false;
  }
  else{
    enemyHP = logic.updateHP(userDamage, enemyHP);
    std::string enemyHP_string = std::to_string(enemyHP);
    enemyHP_Text.setString("HP: " + enemyHP_string);
    playerTurn = true;
  }


}

/**
void BattleMenu::updateOutputText(int input){
  switch (input){
    case 0:

  }
}
*/

void BattleMenu::draw(sf::RenderWindow &window){

  window.draw(rectangle);
  window.draw(bird_battle);
  window.draw(userHP_Text);
  window.draw(enemyHP_Text);
  window.draw(healthBar);
  window.draw(outputText);
  int i = 0;
  for (; i< maxOptions; i++){
    window.draw(optionText[i]);
  }
  battleBar.update(window);
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

int BattleMenu::processInputs(sf::Event event){
  std::string userDamageString = std::to_string(userDamage);
  std::string enemyDamageString = std::to_string(enemyDamage);

  //moving up,down, left, right to select options

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    moveUp();
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    moveDown();
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    moveRight();
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    moveLeft();
  }
  //once option is selected, do something
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {

    switch (getSelectedOption()){
      case 0:
        updateHPText();
        std::cout << "Attack pressed" << std::endl;
        //BattleBar();   //run the battle bar

        outputText.setString("You attacked for "+userDamageString+" damage.\nEnemy attack you for "+enemyDamageString+" damage.");
        break;
      case 1:
        updateHPText();
        std::cout << "Magic pressed" << std::endl;
        outputText.setString("You attacked for "+userDamageString+" damage.\nEnemy attack you for "+enemyDamageString+" damage.");
        break;
      case 2:
        std::cout << "Evade pressed" << std::endl;
        break;
      case 3:
        std::cout << "Item pressed" << std::endl;
        break;
    }

  }
}
