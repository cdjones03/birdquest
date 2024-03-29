#include "../include/BattleMenu.h"
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <random>
//fix enemy block output
//need to fix output for Special Moves, also for Ice Owl, try to have enemy never defend if you are frozen

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

  result = -1;
  item_used = -1;


  //create enemy object, for now, setting the type here
  enemy.setEnemyType(type);


  if (!font.loadFromFile("../resources/game_over.ttf")) {
  //error
  }

  if (!attackBuffer.loadFromFile("../resources/sound/attack.wav")) {
      //error
  }

  if (!optionBuffer.loadFromFile("../resources/sound/option.wav")) {
      //error
  }

  attackSound.setBuffer(attackBuffer);
  optionSound.setBuffer(optionBuffer);

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
  birdSprite.setPosition(415, 405);
  birdSprite.setScale(2.0, 2.0);

  // name and texture for enemy sprite
  enemy_Text.setFont(font);
  enemy_Text.setFillColor(sf::Color::White);
  enemy_Text.setCharacterSize(75);
  enemy_Text.setStyle(sf::Text::Bold);
  enemy_Text.setPosition(sf::Vector2f(width/15 -30, height/5.8));
  //enemy.setEnemyDisplay(enemy_Text, bossTexture);


  bossSprite.setPosition(100, 30);
  bossSprite.setScale(2.0, 2.0);


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

  //setup text to display the enemy's special move based on its type (freeze, poison, etc.)
  enemySpecialMove.setFont(font);
  enemySpecialMove.setFillColor(sf::Color::Cyan);
  enemySpecialMove.setCharacterSize(75);
  enemySpecialMove.setPosition(sf::Vector2f(width/2 - 250, height/2-25));
  enemySpecialMove.setString(" ");

  //setup instruction text to tell players how to select an option
  instructions.setFont(font);
  instructions.setFillColor(sf::Color::Magenta);
  instructions.setStyle(sf::Text::Italic);
  instructions.setCharacterSize(55);
  instructions.setPosition(sf::Vector2f(width/2 - 300, height/2 + 30));
  instructions.setString("Use the arrow keys to navigate the options,\npress Enter to select your move.");

  item_instructions.setFont(font);
  item_instructions.setFillColor(sf::Color::Magenta);
  item_instructions.setStyle(sf::Text::Italic);
  item_instructions.setCharacterSize(55);
  item_instructions.setPosition(sf::Vector2f(width/2 - 300, height/2 + 30));
  item_instructions.setString("\nPress backspace to return to menu.");

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
    //only need to give the user instructions on navigating the menu once.
    if (!firstMove){
      instructions.setString(" ");

    }

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
  //if user is poisoned


  if (item){
    //for future, allow enemy to defend if you choose item, so he does no damage and you heal
    if (!logic.enemyDefend){
      outputText.setString("You healed to 100 HP.\nEnemy attacked for " +enemyDamageString+ " damage!");
    }
    else if (logic.enemyDefend){
      outputText.setString("You healed to 100 HP.\nEnemy tried to defend and did 0 damage!");
    }


  }
  if (inMenu && !firstMove&& !item && !invalid){

    if (logic.enemyDefend && !userDefend){
      //reflect how much your attack was and how much damage enemy defended. Make defended damage random
      outputText.setString("Enemy blocked your attack.\nYou did "+userDamageString+" damage");
    }
    if (logic.enemyDefend && userDefend){
      outputText.setString("You and enemy both defended\ndoing 0 damage each");
    }
    if (!logic.enemyDefend && !userDefend){
      outputText.setString("You attacked for "+userDamageString+" damage\nEnemy attacked you for "+enemyDamageString+" damage");
    }
    //if user defended
    if (!logic.enemyDefend && userDefend){
      outputText.setString("Enemy attacked for "+enemyDamageString+" damage\nYou blocked "+userDefendString+" damage");
    }


  }

  //if you won or lost, output text
  if (logic.whoWon(enemyHP, userHP) != 2){
    showMenu = false;
    enemySpecialMove.setString(" ");

    std::cout<<"userHP"<<userHP<<" enemyHP"<<enemyHP<<" userDamage"<<userDamage<<" enemyDamage"<<enemyDamage<<std::endl;


    //if you won
    if (logic.whoWon(enemyHP, userHP) == 0){
      //sometimes we will win even though our HP is 0 or negative because we attacked the enemy first for
      //more damage, so we will check if our HP is 0 or less and replace the damage taken.
      if (userHP <=0){
        userHP += enemyDamage;
      }

      outputText.setString("You won!\nPress Enter to continue.");
      result = 0;

    }
    //if you lost
    else if (logic.whoWon(enemyHP, userHP) == 1){

      outputText.setString("You lost!\nPress Enter to continue");
      result = 1;

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
      userHP = logic.resetHP(userHP);

    }

  }

}
void BattleMenu::draw(sf::RenderWindow &window){

  window.draw(outputText);

  if (showMenu){

    window.draw(instructions);
    updateOutput();
    if (!showBattleBar){
      window.draw(enemySpecialMove);
    }

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
      window.draw(item_instructions);
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
  if (selectedIndex - 1 == 0 || (selectedIndex - 1 == 2 && showItem == false)){
    optionText[selectedIndex].setFillColor(sf::Color::Blue);
    selectedIndex --;
    optionText[selectedIndex].setFillColor(sf::Color::Red);
  }
  else if (itemIndex - 1 == 0 || (itemIndex - 1 == 2 && showItem == true)){
    itemText[itemIndex].setFillColor(sf::Color::Blue);
    itemIndex --;
    itemText[itemIndex].setFillColor(sf::Color::Red);
  }
  optionSound.play();
}

void BattleMenu::moveDown(){
  if (selectedIndex + 1 == 1 || (selectedIndex + 1 == 3 && showItem == false)){
    optionText[selectedIndex].setFillColor(sf::Color::Blue);
    selectedIndex ++;
    optionText[selectedIndex].setFillColor(sf::Color::Red);
  }
  else if (itemIndex + 1 == 1 || (itemIndex + 1 == 3 && showItem == true)){
    itemText[itemIndex].setFillColor(sf::Color::Blue);
    itemIndex ++;
    itemText[itemIndex].setFillColor(sf::Color::Red);
  }
  optionSound.play();
}

void BattleMenu::moveRight(){
  if (selectedIndex + 2 == 3 || (selectedIndex + 2 == 2 && showItem == false)){
    optionText[selectedIndex].setFillColor(sf::Color::Blue);
    selectedIndex += 2;
    optionText[selectedIndex].setFillColor(sf::Color::Red);
  }
  else if (itemIndex + 2 == 3 || (itemIndex + 2 == 2 && showItem == true)){
    itemText[itemIndex].setFillColor(sf::Color::Blue);
    itemIndex += 2;
    itemText[itemIndex].setFillColor(sf::Color::Red);
  }
  optionSound.play();
}

void BattleMenu::moveLeft(){
  if (selectedIndex - 2 == 0 || (selectedIndex - 2 == 1 && showItem == false)){
    optionText[selectedIndex].setFillColor(sf::Color::Blue);
    selectedIndex -= 2;
    optionText[selectedIndex].setFillColor(sf::Color::Red);
  }
  else if (itemIndex - 2 == 0 || (itemIndex - 2 == 1 && showItem == true)){
    itemText[itemIndex].setFillColor(sf::Color::Blue);
    itemIndex -= 2;
    itemText[itemIndex].setFillColor(sf::Color::Red);
  }
  optionSound.play();
}

void BattleMenu::processInputs(sf::Event event, sf::RenderWindow &window){

  if(event.type == sf::Event::KeyPressed)
  {
  //moving up,down, left, right to select options

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    moveUp();
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    moveDown();
  }
  if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right))){
    moveRight();
  }
  if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left))){
    moveLeft();
  }
  if((sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))){
    showItem = false;
    optionSound.play();
  }
  //once option is selected, do something
  if((sf::Keyboard::isKeyPressed(sf::Keyboard::Return))) {
    firstMove = false;
    optionSound.play();

    std::cout << "return" << std::endl;

    if(!showBattleBar && !showItem){

      switch (getSelectedOption()){
        //attack
        case 0:
          magic = false;
          userDefend = false;
          battleBar.indi.velocity = 1.75;
          showAttack = true;
          std::cout << "Attack pressed" << std::endl;
          showBattleBar = true;
          returnJustPressed = true;
          item = false;
          invalid = false;
          break;
        //magic
        case 1:
          magic = true;
          userDefend = false;
          //speed up battlebar
          battleBar.indi.velocity = 2.75;
          showAttack = true;
          std::cout << "Magic pressed" << std::endl;
          showBattleBar = true;
          returnJustPressed = true;
          item = false;
          invalid = false;
          break;
        //defend
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
          invalid = false;


          break;
        //item
        case 3:
          //healing with potion,
          showItem = true;
          showAttack = false;
          std::cout << "Item pressed" << std::endl;
          invalid = true;


          break;
      }

    }

    else if (showItem){

      switch (getSelectedItem()){

        case 0:

          if (item_0 != "Key" && item_0 != "-"){\
            item = true;
            userHP = logic.resetHP(userHP);
            invalid = false;
            item_used = 0;

          }
          else{
            invalid = true;
          }

        case 1:

          if (item_1 != "Key" && item_1 != "-"){
            item = true;
            userHP = logic.healItem(enemyDamage, userHP);
            invalid = false;
            item_used = 1;

          }
          else{
            invalid = true;
          }

        case 2:

          if (item_2 != "Key" && item_2 != "-"){
            item = true;
            userHP = logic.healItem(enemyDamage, userHP);
            invalid = false;
            item_used = 2;

          }
          else{
            invalid = true;
          }

        case 3:

          if (item_3 != "Key" && item_3 != "-"){
            item = true;
            userHP = logic.healItem(enemyDamage, userHP);
            invalid = false;
            item_used = 3;

          }
          else{
            invalid = true;
          }

      }
    }
  //after pressing a button, make sure the enemy special effect is in place.

  enemyDamage = logic.getEnemyDamage();
  enemyDamageStored = enemyDamage;
  enemyDefend = logic.enemyDefend;

  //for the Cat effect, we need to get the battle bar damage first, so we will do that effect later
  if (type != Enemy::Cat){
    std::cout << " yes here " << std::endl;
    enemy.enemyEffect(enemySpecialMove, userDamage, userDefend, item, showBattleBar, enemyDefend, enemyDamage);
  }


  userDamageStored = userDamage;
  if (!showBattleBar && !invalid){
    std::cout << " here bit " << std::endl;
    userHP = logic.updateHP(enemyDamage, userHP);
    enemyHP = logic.updateHP(userDamage, enemyHP);
  }
  }

  //once we are in the battle bar view, check for user damage
  else if (showBattleBar && returnJustPressed){

    if(event.key.code == sf::Keyboard::Space){
      attackSound.play();
      std::cout << "pressed" << std::endl;
      userDamage = battleBar.getDamageDealt();
      userDefendStored = userDamage;

      enemyDamage = logic.userDefend(enemyDamage, userDamage, userDefend);
      userDamage = logic.getUserDamage(userDamage, magic, userDefend);

      if (type == Enemy::Cat){
        enemy.enemyEffect(enemySpecialMove, userDamage, userDefend, item, showBattleBar, enemyDefend, enemyDamage);
        enemyDamageStored = enemyDamage;
      }
      userDamageStored = userDamage;


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

//checks if we should be in the battle menu
bool BattleMenu::isInMenu()
{
  return inMenu;
}

int BattleMenu::getResult()
{
  return result;
}

void BattleMenu::resetResult()
{
  result = -1;
}

int BattleMenu::getType()
{
  return type;
}

//sets the enemy type, and texture/special moves based on the type
void BattleMenu::setEnemy(int enemyNum) {

  switch(enemyNum) {
    case 7: {
    type = Enemy::Regular;
    bossTexture.loadFromFile("../resources/spritesheets/Owl_OW.png", sf::IntRect(0, 0, 16, 16));
    bossSprite.setTexture(bossTexture, true);
    enemy.setEnemyType(type);
    enemy.setEnemyDisplay(enemy_Text);
    break;
  }

    case 8: {
    type = Enemy::Regular;
    bossTexture.loadFromFile("../resources/spritesheets/owl_1.png", sf::IntRect(0, 0, 90, 90));
    bossSprite.setTexture(bossTexture, true);
    enemy.setEnemyType(type);
    enemy.setEnemyDisplay(enemy_Text);
    break;
  }

    case 9: {
    type = Enemy::Regular;
    bossTexture.loadFromFile("../resources/spritesheets/Snake_OW.png", sf::IntRect(0, 0, 16, 16));
    bossSprite.setTexture(bossTexture, true);
    enemy.setEnemyType(type);
    enemy.setEnemyDisplay(enemy_Text);
    break;
  }

    case 10: {
    type = Enemy::Snake;
    bossTexture.loadFromFile("../resources/spritesheets/snake_boss.png", sf::IntRect(0, 0, 90, 90));
    bossSprite.setTexture(bossTexture, true);
    enemy.setEnemyType(type);
    enemy.setEnemyDisplay(enemy_Text);
    break;
  }

    case 11: {
    type = Enemy::Regular;
    bossTexture.loadFromFile("../resources/spritesheets/Cat_OW.png", sf::IntRect(0, 0, 16, 16));
    bossSprite.setTexture(bossTexture, true);
    enemy.setEnemyType(type);
    enemy.setEnemyDisplay(enemy_Text);
    break;
  }

    case 12: {
    type = Enemy::Cat;
    bossTexture.loadFromFile("../resources/spritesheets/cat_boss.png", sf::IntRect(0, 0, 90, 90));
    enemy.setEnemyType(type);
    bossSprite.setTexture(bossTexture, true);
    enemy.setEnemyDisplay(enemy_Text);
    break;
  }

    case 13: {
    type = Enemy::Regular;
    bossTexture.loadFromFile("../resources/spritesheets/Owl_OW_ice.png", sf::IntRect(0, 0, 16, 16));
    bossSprite.setTexture(bossTexture, true);
    enemy.setEnemyType(type);
    enemy.setEnemyDisplay(enemy_Text);
    break;
  }

    case 14: {
    type = Enemy::IceOwl;
    bossTexture.loadFromFile("../resources/spritesheets/owl_boss.png", sf::IntRect(0, 0, 90, 90));
    bossSprite.setTexture(bossTexture, true);
    enemy.setEnemyType(type);
    enemy.setEnemyDisplay(enemy_Text);
    break;
  }

    case 15: {
    type = Enemy::FinalBoss;
    bossTexture.loadFromFile("../resources/spritesheets/Malphas.png", sf::IntRect(0, 0, 90, 90));
    bossSprite.setTexture(bossTexture, true);
    enemy.setEnemyType(type);
    enemy.setEnemyDisplay(enemy_Text);
    break;
  }
}

}

void BattleMenu::setInMenu(bool newVal) {
  inMenu = newVal;
}
void BattleMenu::setShowMenu(bool newVal) {
  showMenu = newVal;
}
void BattleMenu::setItem_Used(bool newVal) {
  item_used = newVal;
}
bool BattleMenu::getItem_Used() {
  return item_used;
}
int BattleMenu::getUserHP() {
  return userHP;
}
void BattleMenu::setItemText(int index, std::string newString) {
  itemText[index].setString(newString);
}
void BattleMenu::setItem0(std::string newString) {
  item_0 = newString;
}
void BattleMenu::setItem1(std::string newString) {
  item_1 = newString;
}
void BattleMenu::setItem2(std::string newString) {
  item_2 = newString;
}
void BattleMenu::setItem3(std::string newString) {
  item_3 = newString;
}
