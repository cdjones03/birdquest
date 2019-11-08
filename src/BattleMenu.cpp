#include "../include/BattleMenu.h"
#include <iostream>

BattleMenu::BattleMenu(float width, float height){
  showMenu = true;
  firstMove = true;
  inMenu = true;
  showAttack = false;
  selectedIndex = 0;
  userDamage = 0;
  enemyDamage = 0;
  playerTurn = true;
  userHP = maxHP;
  enemyHP = maxHP;
  showBattleBar = false;
  returnJustPressed = false;
  

  if (!font.loadFromFile("../resources/game_over.ttf")) {
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

  // temporary placement for enemy sprite in battle screen
  enemy_sample.setRadius(80);
  enemy_sample.setFillColor(sf::Color::Blue);
  enemy_sample.setPosition(width/7, height/15);

  // name for enemy sprite
  enemy_Text.setFont(font);
  enemy_Text.setFillColor(sf::Color::White);
  enemy_Text.setCharacterSize(75);
  enemy_Text.setString("ENEMY");
  enemy_Text.setPosition(sf::Vector2f(width/5.1, height/5.8));

  // setup user and enemy HP text placement in battle menu
  userHP_Text.setFont(font);
  userHP_Text.setCharacterSize(65);
  std::string userHP_string1 = std::to_string(userHP);
  userHP_Text.setString("HP: " + userHP_string1);
  userHP_Text.setPosition(sf::Vector2f(width - width/2.3, height - height/5));

  enemyHP_Text.setFont(font);
  enemyHP_Text.setCharacterSize(65);
  std::string enemyHP_string1 = std::to_string(enemyHP);
  enemyHP_Text.setString("HP: " + enemyHP_string1);
  enemyHP_Text.setPosition(sf::Vector2f(width - width/2.3, 45));

  //setup output text that will say what happened last turn
  outputText.setFont(font);
  outputText.setCharacterSize(75);
  outputText.setPosition(sf::Vector2f(width/2 - 200, height/2-110));

  // red health bar for player in battle menu
  remainingBar.setSize(sf::Vector2f(width/3.5, (height/30)));
  remainingBar.setFillColor(sf::Color::Red);
  remainingBar.setPosition(width - width/2.8 , height - height/12);
  remainingBar.setOutlineThickness(3);

  // green health bar placement in battle menu
  healthBar.setSize(sf::Vector2f(width/3.5, height/30));
  healthBar.setFillColor(sf::Color(50, 255, 50));
  healthBar.setPosition(width - width/2.8, height - height/12);

  // red health bar for enemy in battle menu
  enemy_remainingBar.setSize(sf::Vector2f(width/3.5, (height/30)));
  enemy_remainingBar.setFillColor(sf::Color::Red);
  enemy_remainingBar.setPosition(sf::Vector2f(width - width/2.8, 55));
  enemy_remainingBar.setOutlineThickness(3);

  // green health bar for enemy in battle menu
  enemy_healthBar.setSize(sf::Vector2f(width/3.5, height/30));
  enemy_healthBar.setFillColor(sf::Color(50, 255, 50));
  enemy_healthBar.setPosition(sf::Vector2f(width - width/2.8, 55.5));

  //position each option on the screen, with the color red if it is highlighted
  optionText[0].setFont(font);
  optionText[0].setCharacterSize(85);
  optionText[0].setFillColor(sf::Color::Red);
  optionText[0].setString("Attack");
  optionText[0].setPosition(sf::Vector2f(width/35, height/(maxOptions+1)*3.5));

  optionText[1].setFont(font);
  optionText[1].setCharacterSize(85);
  optionText[1].setFillColor(sf::Color::Blue);
  optionText[1].setString("Magic");
  optionText[1].setPosition(sf::Vector2f(width/35, height/(maxOptions+1)*4));

  optionText[2].setFont(font);
  optionText[2].setCharacterSize(85);
  optionText[2].setFillColor(sf::Color::Blue);
  optionText[2].setString("Defend");
  optionText[2].setPosition(sf::Vector2f(width/3, height/(maxOptions+1)*3.5));

  optionText[3].setFont(font);
  optionText[3].setCharacterSize(85);
  optionText[3].setFillColor(sf::Color::Blue);
  optionText[3].setString("Item");
  optionText[3].setPosition(sf::Vector2f(width/3, height/(maxOptions+1)*4));

}

BattleMenu:: ~BattleMenu(){

}

//updates the text that displays the user and enemy HP, as well as the output text which
//says what happened last turn, and updates the health bar for visual
void BattleMenu::updateOutput()
{
  if (firstMove){
    outputText.setString("You are in Battle!\nChoose your move.");
  }
  std::string userDamageString = std::to_string(userDamageStored);
  std::string enemyDamageString = std::to_string(enemyDamage);
  
  if (playerTurn){
    std::string userHP_string = std::to_string(userHP);
    userHP_Text.setString("HP: " + userHP_string);
    playerTurn = false;

    // change later for variable width and height
    healthBar.setSize(sf::Vector2f(640/3.5 * userHP/100, 640/30));
  }
  else{
    std::string enemyHP_string = std::to_string(enemyHP);
    enemyHP_Text.setString("HP: " + enemyHP_string);
    playerTurn = true;

    // change later for variable width and height
    enemy_healthBar.setSize(sf::Vector2f(640/3.5 * enemyHP/100, 640/30));
  }
  if (showAttack && !firstMove){
    if (logic.enemyDefend){
      //reflect how much your attack was and how much damage enemy defended. Make defended damage random
      outputText.setString("You attacked for "+userDamageString+" damage.\nEnemy blocked 10 damage.");
    }
    else{
      outputText.setString("You attacked for "+userDamageString+" damage.\nEnemy attacked you for "+enemyDamageString+" damage.");
    }
    
  }
  //if you won, output text
  if (logic.whoWon(enemyHP, userHP) == 0){
    showMenu = false;
    outputText.setString("You won!\nPress Enter to continue");
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
      //exit battleMenu and reset everything. later, maybe dont reset userHP
      inMenu = false;
      enemyHP = logic.resetHP(enemyHP);
      userHP = logic.resetHP(userHP);
      returnJustPressed = false;
      showBattleBar = false;
      firstMove = true;

    }
  }
  //if you lost
  else if (logic.whoWon(enemyHP, userHP) == 1){
    showMenu = false;
    showAttack = false;
    outputText.setString("You lost!\nPress Enter to continue");
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
      //exit battleMenu and reset everything. later, make it so it resets at checkpoint
      inMenu = false;
      enemyHP = logic.resetHP(enemyHP);
      userHP = logic.resetHP(userHP);
      returnJustPressed = false;
      showBattleBar = false; 
      firstMove = true;
    }
  }
  



}


void BattleMenu::draw(sf::RenderWindow &window){

  window.draw(outputText);

  if (showMenu){
    updateOutput();
    window.draw(rectangle);
    window.draw(bird_battle);
    window.draw(enemy_sample);
    window.draw(enemy_Text);
    window.draw(userHP_Text);
    window.draw(enemyHP_Text);
    window.draw(remainingBar);
    window.draw(healthBar);
    window.draw(enemy_remainingBar);
    window.draw(enemy_healthBar);

    int i = 0;
    for (; i< maxOptions; i++){
      window.draw(optionText[i]);
    }
    if(showBattleBar){
      battleBar.update(window);
    }
  }
  else{
    
  }

}

//functions to navigate through menu options
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

int BattleMenu::processInputs(sf::Event event, sf::RenderWindow &window){
  
  if(event.type == sf::Event::KeyPressed)
  {
  //moving up,down, left, right to select options

  if(event.key.code == sf::Keyboard::Up) {
    moveUp();
  }
  if(event.key.code == sf::Keyboard::Down) {
    moveDown();
  }
  if(event.key.code == sf::Keyboard::Right){
    moveRight();
  }
  if(event.key.code == sf::Keyboard::Left){
    moveLeft();
  }
  //once option is selected, do something
  if(event.key.code == sf::Keyboard::Return) {
    firstMove = false;
    enemyDamage = logic.getEnemyDamage();


    std::cout << "return" << std::endl;

    if(!showBattleBar){

    switch (getSelectedOption()){
      //attack
      case 0:
        battleBar.indi.velocity = 1;
        showAttack = true;
        std::cout << "Attack pressed" << std::endl;
        showBattleBar = true;
        returnJustPressed = true;
        break;
      //magic
      case 1:
        battleBar.indi.velocity = 2;
        showAttack = true;
        std::cout << "Magic pressed" << std::endl;
        showBattleBar = true;
        returnJustPressed = true;
        break;
      //evade
      case 2:
        std::cout << "Defend pressed" << std::endl;
        //inMenu = false;

        break;
      //item
      case 3:
        //healing with potion, need to fix
        userHP = logic.healItem(enemyDamage, userHP);
        std::string enemyDamageString = std::to_string(enemyDamage);
        showAttack = false;
        std::cout << "Item pressed" << std::endl;
        outputText.setString("You healed for 20 HP.\nEnemy attacked for " +enemyDamageString+ " damage.");
        break;
    }
  }
}
  //we should move this to battleLogic
  else if (showBattleBar && returnJustPressed){
    if(event.key.code == sf::Keyboard::Space){
      std::cout << "pressed" << std::endl;
      userDamage = battleBar.getDamageDealt();
      userDamageStored = userDamage;
      
      //if enemy chose to defend, user damage is 0, later change to be userDamage-=10 or something
      if (logic.enemyDefend){
        if (userDamage >= 10){
          userDamage -=10;
        }
        else{
          userDamage = 0;
        }
      }
      
      battleBar.barPressed();
      showBattleBar = false;
      returnJustPressed = false;
      
      userHP = logic.updateHP(enemyDamage, userHP);
      
      enemyHP = logic.updateHP(userDamage, enemyHP);
     
    }
  }

  updateOutput();
}
}

