#include "../include/BattleMenu.h"
#include <iostream>
//fix enemy block output

BattleMenu::BattleMenu(){
  showMenu = true;
  firstMove = true;
  inMenu = true;
  showItem = false;
  showAttack = false;
  item = false;
  selectedIndex = 0;
  userDamage = 0;
  enemyDamage = 0;
  playerTurn = true;
  userHP = maxHP;
  enemyHP = maxHP;
  showBattleBar = false;
  returnJustPressed = false;
  invalid = false;
  width = 640.0;
  height = 640.0;
  itemIndex = 0;

  

  if (!font.loadFromFile("../resources/game_over.ttf")) {
  //error
  }

  // border around the option in battle screen
  rectangle.setSize(sf::Vector2f(width/2, height/4.5));
  rectangle.setPosition(width/60, height - height/4.1);
  rectangle.setFillColor(sf::Color::Black);
  rectangle.setOutlineThickness(4);
  rectangle.setOutlineColor(sf::Color::White);

  item_menu_box.setSize(sf::Vector2f(width/2, height/4.5));
  item_menu_box.setPosition(width/60, height - height/4.1);
  item_menu_box.setFillColor(sf::Color::Black);
  item_menu_box.setOutlineThickness(4);
  item_menu_box.setOutlineColor(sf::Color::White);

  
  //player's battle sprite 
  if(!birdTexture.loadFromFile("../resources/spritesheets/battlesprite_player.png", sf::IntRect(0, 0, 90, 90))){
  }
  birdSprite.setTexture(birdTexture);
  birdSprite.setPosition(420, 400);
  birdSprite.setScale(2.0, 2.0);

  if(!bossTexture.loadFromFile("../resources/spritesheets/owl_1.png", sf::IntRect(0, 0, 90, 90))){
  }
  bossSprite.setTexture(bossTexture);
  bossSprite.setPosition(100, 30);
  bossSprite.setScale(2.0, 2.0);



/*
  // temporary placement for birdknight sprite in battle screen
  bird_battle.setRadius(80);
  bird_battle.setFillColor(sf::Color(30, 30, 255));
  bird_battle.setPosition(width - width/2.8, height - height/2.2);


  // temporary placement for enemy sprite in battle screen
  enemy_sample.setRadius(80);
  enemy_sample.setFillColor(sf::Color::Blue);
  enemy_sample.setPosition(width/7, height/15);
*/


  // name for enemy sprite
  enemy_Text.setFont(font);
  enemy_Text.setFillColor(sf::Color::White);
  enemy_Text.setCharacterSize(75);
  enemy_Text.setString("ENEMY");
  enemy_Text.setStyle(sf::Text::Bold);
  enemy_Text.setPosition(sf::Vector2f(width/15 -30, height/5.8));
  

  // setup user and enemy HP text placement in battle menu
  userHP_Text.setFont(font);
  userHP_Text.setCharacterSize(65);
  std::string userHP_string1 = std::to_string(userHP);
  userHP_Text.setString("HP: " + userHP_string1 + "/100");
  userHP_Text.setPosition(sf::Vector2f(width - width/2.3, height - height/5));

  enemyHP_Text.setFont(font);
  enemyHP_Text.setCharacterSize(65);
  std::string enemyHP_string1 = std::to_string(enemyHP);
  enemyHP_Text.setString("HP: " + enemyHP_string1 + "/100");
  enemyHP_Text.setPosition(sf::Vector2f(width - width/2.3, 45));

  //setup output text that will say what happened last turn
  outputText.setFont(font);
  outputText.setFillColor(sf::Color::Yellow);
  outputText.setCharacterSize(75);
  outputText.setPosition(sf::Vector2f(width/2 - 250, height/2-105));

  //setup instruction text to tell players how to select an option
  instructions.setFont(font);
  instructions.setFillColor(sf::Color::Magenta);
  instructions.setStyle(sf::Text::Italic);
  instructions.setCharacterSize(55);
  instructions.setPosition(sf::Vector2f(width/2 - 300, height/2));
  instructions.setString("Use the arrow keys to navigate the options,\npress Enter to select your move.");

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

  // Draws texts for items

  itemText[0].setFont(font);
  itemText[0].setCharacterSize(85);
  itemText[0].setFillColor(sf::Color::Red);
  itemText[0].setString("-");
  itemText[0].setPosition(sf::Vector2f(width/35, height/(maxOptions+1)*3.5));

  itemText[1].setFont(font);
  itemText[1].setCharacterSize(85);
  itemText[1].setFillColor(sf::Color::Blue);
  itemText[1].setString("-");
  itemText[1].setPosition(sf::Vector2f(width/35, height/(maxOptions+1)*4));

  itemText[2].setFont(font);
  itemText[2].setCharacterSize(85);
  itemText[2].setFillColor(sf::Color::Blue);
  itemText[2].setString("-");
  itemText[2].setPosition(sf::Vector2f(width/3, height/(maxOptions+1)*3.5));

  itemText[3].setFont(font);
  itemText[3].setCharacterSize(85);
  itemText[3].setFillColor(sf::Color::Blue);
  itemText[3].setString("-");
  itemText[3].setPosition(sf::Vector2f(width/3, height/(maxOptions+1)*4));


}

BattleMenu:: ~BattleMenu(){

}

//updates the text that displays the user and enemy HP, as well as the output text which
//says what happened last turn, and updates the health bar for visual
void BattleMenu::updateOutput()
{
  
  if (firstMove){
    outputText.setString("You are in Battle!");
  }
  if (showBattleBar){
    instructions.setString("Press Space to stop the blue bar.\nLand in the Green for maximum effectiveness!");
  }
  else{
    //for now, I think we only need to give the user instructions on navigating the menu once.
    if (!firstMove){
      instructions.setString(" ");
    }
    
    //instructions.setString("Use the arrow keys to navigate the options,\npress Enter to select your move.");
  }
  std::string userDamageString = std::to_string(userDamageStored);
  std::string enemyDamageString = std::to_string(enemyDamageStored);
  std::string userDefendString = std::to_string(userDefendStored);
  
  if (playerTurn){
    std::string userHP_string = std::to_string(userHP);
    userHP_Text.setString("HP: " + userHP_string + "/100");
    playerTurn = false;

    // change later for variable width and height
    healthBar.setSize(sf::Vector2f(640/3.5 * userHP/100, 640/30));
  }
  else{
    std::string enemyHP_string = std::to_string(enemyHP);
    enemyHP_Text.setString("HP: " + enemyHP_string + "/100");
    playerTurn = true;

    // change later for variable width and height
    enemy_healthBar.setSize(sf::Vector2f(640/3.5 * enemyHP/100, 640/30));
  }
  if (item){
    //for future, allow enemy to defend if you choose item, so he does no damage and you heal
    if (!logic.enemyDefend){
      outputText.setString("You healed for 30 HP.\nEnemy attacked for " +enemyDamageString+ " damage.");
    }
    else if (logic.enemyDefend){
      outputText.setString("You healed for 30 HP.\nEnemy tried to defend and did 0 damage.");
    }

    
    }
  if (inMenu&&!firstMove&&!item){
    
    if (logic.enemyDefend && !userDefend){
      //reflect how much your attack was and how much damage enemy defended. Make defended damage random
      outputText.setString("Enemy blocked your attack.\nYou did "+userDamageString+" damage.");
    }
    if (logic.enemyDefend && userDefend){
      outputText.setString("You and enemy both defended\ndoing 0 damage each.");
    }
    if (!logic.enemyDefend && !userDefend){
      outputText.setString("You attacked for "+userDamageString+" damage.\nEnemy attacked you for "+enemyDamageString+" damage.");
    }
    //if user defended
    if (!logic.enemyDefend && userDefend){
      outputText.setString("Enemy attacked for "+enemyDamageString+" damage.\nYou blocked "+userDefendString+" damage.");
    }
    
    
  }
  //if you won or lost, output text
  if (logic.whoWon(enemyHP, userHP) != 2){
    showMenu = false;
    
    std::cout<<"userHP"<<userHP<<" enemyHP"<<enemyHP<<" userDamage"<<userDamage<<" enemyDamage"<<enemyDamage<<std::endl;
    
    
    //if you won
    if (logic.whoWon(enemyHP, userHP) == 0){
      //sometimes we will win even though our HP is 0 or negative because we attacked the enemy first for
      //more damage, so we will check if our HP is 0 or less and replace the damage taken.
      if (userHP <=0){
        userHP += enemyDamage;
      }
    
      outputText.setString("You won!\nPress Enter to continue");
    
    }
    //if you lost
    else if (logic.whoWon(enemyHP, userHP) == 1){
      
      outputText.setString("You lost!\nPress Enter to continue");

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
      //exit battleMenu and reset everything. later, maybe dont reset userHP
      if (userHP <= 0){
        userHP = logic.resetHP(userHP);
      }
      //reset selection to be top left
      moveUp();
      moveLeft();
      showAttack = false;
      inMenu = false;
      returnJustPressed = false;
      showBattleBar = false;
      firstMove = true;
      enemyHP = logic.resetHP(enemyHP);
      
    }
    
    
    
  }

}
void BattleMenu::draw(sf::RenderWindow &window){
  //std::cout<<"userHP"<<userHP<<" enemyHP"<<enemyHP<<std::endl;

  window.draw(outputText);

  if (showMenu){
    window.draw(instructions);
    updateOutput();
    window.draw(rectangle);
    window.draw(birdSprite);
    window.draw(bossSprite);
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

    if(showItem){
      window.draw(item_menu_box);

      int j = 0;
      for (; j< maxOptions; j++){
        window.draw(itemText[j]);
      }
    }
  }
}

//functions to navigate through menu options
void BattleMenu::moveUp(){
  if (selectedIndex - 1 == 0 || selectedIndex - 1 == 2 && showItem == false){
    optionText[selectedIndex].setFillColor(sf::Color::Blue);
    selectedIndex --;
    optionText[selectedIndex].setFillColor(sf::Color::Red);
  }
  else if (itemIndex - 1 == 0 || itemIndex - 1 == 2 && showItem == true){
    itemText[itemIndex].setFillColor(sf::Color::Blue);
    itemIndex --;
    itemText[itemIndex].setFillColor(sf::Color::Red);
  }
}

void BattleMenu::moveDown(){
  if (selectedIndex + 1 == 1 || selectedIndex + 1 == 3 && showItem == false){
    optionText[selectedIndex].setFillColor(sf::Color::Blue);
    selectedIndex ++;
    optionText[selectedIndex].setFillColor(sf::Color::Red);
  }
  else if (itemIndex + 1 == 1 || itemIndex + 1 == 3 && showItem == true){
    itemText[itemIndex].setFillColor(sf::Color::Blue);
    itemIndex ++;
    itemText[itemIndex].setFillColor(sf::Color::Red);
  }
}

void BattleMenu::moveRight(){
  if (selectedIndex + 2 == 3 || selectedIndex + 2 == 2 && showItem == false){
    optionText[selectedIndex].setFillColor(sf::Color::Blue);
    selectedIndex += 2;
    optionText[selectedIndex].setFillColor(sf::Color::Red);
  }
  else if (itemIndex + 2 == 3 || itemIndex + 2 == 2 && showItem == true){
    itemText[itemIndex].setFillColor(sf::Color::Blue);
    itemIndex += 2;
    itemText[itemIndex].setFillColor(sf::Color::Red);
  }
}

void BattleMenu::moveLeft(){
  if (selectedIndex - 2 == 0 || selectedIndex - 2 == 1 && showItem == false){
    optionText[selectedIndex].setFillColor(sf::Color::Blue);
    selectedIndex -= 2;
    optionText[selectedIndex].setFillColor(sf::Color::Red);
  }
  else if (itemIndex - 2 == 0 || itemIndex - 2 == 1 && showItem == true){
    itemText[itemIndex].setFillColor(sf::Color::Blue);
    itemIndex -= 2;
    itemText[itemIndex].setFillColor(sf::Color::Red);
  }
}

void BattleMenu::processInputs(sf::Event event, sf::RenderWindow &window){
  
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
  if(event.key.code == sf::Keyboard::BackSpace){
    showItem = false;
  }
  //once option is selected, do something
  if(event.key.code == sf::Keyboard::Return) {
    firstMove = false;
    enemyDamage = logic.getEnemyDamage();
    enemyDamageStored = enemyDamage;

    

    std::cout << "return" << std::endl;

    if(!showBattleBar && !showItem){

      switch (getSelectedOption()){
        //attack
        case 0:
          magic = false;
          userDefend = false;
          battleBar.indi.velocity = 1.5;
          showAttack = true;
          std::cout << "Attack pressed" << std::endl;
          showBattleBar = true;
          returnJustPressed = true;
          item = false;
          break;
        //magic
        case 1:
          magic = true;
          userDefend = false;
          //speed up battlebar
          battleBar.indi.velocity = 2.5;
          showAttack = true;
          std::cout << "Magic pressed" << std::endl;
          showBattleBar = true;
          returnJustPressed = true;
          item = false;
          break;
        //evade
        case 2:
        
          //later, maybe get the output to say how much damage the enemy actually did, instead of just how much he blocked
          //also, maybe get enemy to defend for a random amount of damage
          //still might adjust speed for the indicator
          battleBar.indi.velocity = 2.2;
          std::cout << "Defend pressed" << std::endl;
          userDefend = true;
          magic = false;
          showBattleBar = true;
          returnJustPressed = true;
          item = false;

          //inMenu = false;

          break;
        //item
        case 3:
          //healing with potion, need to fix
          //item = true;
          showItem = true;
          //userHP = logic.healItem(enemyDamage, userHP);
          //std::string enemyDamageString = std::to_string(enemyDamage);
          showAttack = false;
          std::cout << "Item pressed" << std::endl;
          
          
          break;
      }
    }
    else if (showItem){

      switch (getSelectedItem()){

        case 0:

          if (item_0 == "Key"){
            item = true;
            userHP = logic.healItem(enemyDamage, userHP);
          }
          else{
            invalid = true;
          }

        case 1:

          if (item_1 == "Key"){
            item = true;
            userHP = logic.healItem(enemyDamage, userHP);
          }
          else{
            invalid = true;
          }

        case 2:

          if (item_2 == "Key"){
            item = true;
            userHP = logic.healItem(enemyDamage, userHP);
          }
          else{
            invalid = true;
          }

        case 3:

          if (item_3 == "Key"){
            item = true;
            userHP = logic.healItem(enemyDamage, userHP);
          }
          else{
            invalid = true;
          }

      }
    }

  }
  
  //once we are in the battle bar view
  else if (showBattleBar && returnJustPressed){
    if(event.key.code == sf::Keyboard::Space){
      std::cout << "pressed" << std::endl;
      userDamage = battleBar.getDamageDealt();
      userDefendStored = userDamage;
      
      enemyDamage = logic.userDefend(enemyDamage, userDamage, userDefend);
      userDamage = logic.getUserDamage(userDamage, magic, userDefend);
      userDamageStored = userDamage;
      
      //if enemy chose to defend, user damage is 0, later change to be userDamage-=10 or something
            
      
      battleBar.barPressed();
      showBattleBar = false;
      returnJustPressed = false;
      
      userHP = logic.updateHP(enemyDamage, userHP);
      
      enemyHP = logic.updateHP(userDamage, enemyHP);
     
    }
  }
  
  if (!invalid){
    updateOutput();
  }
  
  }
}

bool BattleMenu::isInMenu()
{
  return inMenu;
}