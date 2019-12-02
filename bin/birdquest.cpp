#include <SFML/Graphics.hpp>
#include <TileMap.hpp>
#include <iostream>
#include <tinyxml2.h>
#include "BattleMenu.h"
#include "BattleBar.h"
#include <LevelManager.hpp>
#include "BattleLogic.h"
#include "PauseMenu.h"
#include "Inventory.h"
#include "Enemy.h"
#include <HumanView.hpp>

/*
Note: for items, place sprite on map
player walks over, press i, if coords are = , get item and remove sprite
*/

using namespace std;

int main(int argc, char** argv)
{
  const int windowTileWidth = 40;
  const int windowTileHeight = 40;
  const int windowPixelWidth = windowTileWidth*16;
  const int windowPixelHeight = windowTileHeight*16;
  const int moveVal = 32;
  int lastX = 352;
  int lastY = 352;
  int userHP;
  string item;


  // create main window; Style::Close disables resizing
  //The game should be played in an 800x600 window. Changing the size of the window sh
  sf::RenderWindow App(sf::VideoMode(windowPixelWidth, windowPixelWidth, 32), "BirdQuest!");//, sf::Style::Close);
  App.setFramerateLimit(60);
  //App.setKeyRepeatEnabled(false);

  //Create battleMenu object and boolean for if we are in the battle menu
  BattleMenu battleMenu;
  bool inBattleMenu = false;



  // Create pauseMenu object and boolean for if we are in the battle menu
  PauseMenu pauseMenu(App.getSize().x, App.getSize().y);
  bool inPauseMenu = false;

  // Create inventory object
  Inventory inventory;

  // create the tilemap from the level definition
  LevelManager levelManager;
  levelManager.loadLevels();

  HumanView humanView;

  sf::Clock clock;
  int deltaMs;
  int otherMs;

  sf::Texture birdTexture;
  if(!birdTexture.loadFromFile("../resources/spritesheets/BirdKnight_spritesheet.png", sf::IntRect(0, 0, 16, 16))){
    return -1;
  }

  sf::Sprite birdSprite;
  birdSprite.setPosition(lastX, lastY); //start at bottom of hub
  birdSprite.setTexture(birdTexture);
  birdSprite.setPosition(lastX, lastY);
  //birdSprite.setScale(2,2);

  // start main loop
  deltaMs = clock.getElapsedTime().asMilliseconds();
  otherMs = clock.getElapsedTime().asMilliseconds();
  while(App.isOpen())
  {
      deltaMs = clock.getElapsedTime().asMilliseconds();
      if(deltaMs > otherMs + 300) {
        otherMs = deltaMs;
        int enemyCheck = levelManager.updateSprite(birdSprite.getPosition().x, birdSprite.getPosition().y);
        if(enemyCheck >= 0) { //if it sees you, start battle
          //std::cout << enemyCheck << std::endl;
          inBattleMenu = true;
          battleMenu.inMenu = true;
          battleMenu.showMenu = true;
          //enemyCheck corresponds to the # of the texture in info.xml
          //so if it's 7, its the owl
          //if it's 9, its the snake
          //etc.
        }
      }

      // update inventory in battle menu
      battleMenu.itemText[0].setString(inventory.itemArray[0]);
      battleMenu.itemText[1].setString(inventory.itemArray[1]);
      battleMenu.itemText[2].setString(inventory.itemArray[2]);
      battleMenu.itemText[3].setString(inventory.itemArray[3]);

      battleMenu.item_0 = inventory.itemArray[0];
      battleMenu.item_1 = inventory.itemArray[1];
      battleMenu.item_2 = inventory.itemArray[2];
      battleMenu.item_3 = inventory.itemArray[3];


      /*
      if(birdSprite.getPosition().x == keySprite.getPosition().x && birdSprite.getPosition().y == keySprite.getPosition().y){
        inventory.addItem("Potion");
        inventory.addItem("Potion");
        inventory.addItem("Potion");
        inventory.addItem("Potion");
      }
      */

      // process events
      sf::Event Event;
      while(App.pollEvent(Event))
      {
        // Exit
        if(Event.type == sf::Event::Closed){
          App.close();
        }
        //press b to get to battleMenu.
        //later, make it so that this can only occur when near an
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
          inBattleMenu = true;
          battleMenu.inMenu = true;
          battleMenu.showMenu = true;
        }
        //press p to get to pauseMenu
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
          //userHP = battleMenu.userHP;
          //pauseMenu.getUserHP(userHP);
          userHP = battleMenu.userHP;
          //pauseMenu.HP = userHP;
          pauseMenu.healthBar.setSize(sf::Vector2f(640/3.5 * userHP/100, 640/30));

          pauseMenu.itemText[0].setString(inventory.itemArray[0]);
          pauseMenu.itemText[1].setString(inventory.itemArray[1]);
          pauseMenu.itemText[2].setString(inventory.itemArray[2]);
          pauseMenu.itemText[3].setString(inventory.itemArray[3]);

          if (inventory.itemArray[0] == "Key"){

            pauseMenu.keySprite.setPosition(550,320);
          }

          //pauseMenu.HP
          pauseMenu.HP_string.setString("HP: "+std::to_string(userHP) + "/100");

          //pauseMenu.HPstr = std::to_string(battleMenu.userHP);
          inPauseMenu = true;
          pauseMenu.inPause = true;
        }
        //keypresses for when we are in the Stage
        if (!inBattleMenu && !inPauseMenu){
          //Handle input, delegate to HumanView.cpp
          lastY = birdSprite.getPosition().y;
          lastX = birdSprite.getPosition().x;

          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            birdTexture.loadFromFile("../resources/spritesheets/BirdKnight_spritesheet.png", sf::IntRect(0, 48, 16, 16));
			      birdSprite.setTexture(birdTexture);
            humanView.movePlayer(App, birdSprite, HumanView::UP, levelManager, inventory);
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            birdTexture.loadFromFile("../resources/spritesheets/BirdKnight_spritesheet.png", sf::IntRect(0, 0, 16, 16));
			      birdSprite.setTexture(birdTexture);
            humanView.movePlayer(App, birdSprite, HumanView::DOWN, levelManager, inventory);
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            birdTexture.loadFromFile("../resources/spritesheets/BirdKnight_spritesheet.png", sf::IntRect(48, 16, 16, 16));
			      birdSprite.setTexture(birdTexture);
            humanView.movePlayer(App, birdSprite, HumanView::LEFT, levelManager, inventory);
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            birdTexture.loadFromFile("../resources/spritesheets/BirdKnight_spritesheet.png", sf::IntRect(0, 16, 16, 16));
			      birdSprite.setTexture(birdTexture);
            humanView.movePlayer(App, birdSprite, HumanView::RIGHT, levelManager, inventory);
          }


        }

        //key presses for when we are in the battle menu
        else if (inBattleMenu){

          battleMenu.processInputs(Event, App);

          inventory.useItem(battleMenu.item_used);

          if (!battleMenu.inMenu) {
            inBattleMenu = false;
          }

        }

        //key presses for when we are in the pause menu
        else if (inPauseMenu){
          //here!


          pauseMenu.processInputs(Event, App);
          //std::cout<<battleMenu.userHP<<std::endl;

          if (!pauseMenu.inPause){

            inPauseMenu = false;
          }
        }
      }

      //Display
      App.clear(sf::Color::Black);

      //draw map if not in battle
      if (!inBattleMenu){
        levelManager.drawMap(App);
        App.draw(birdSprite);

        //draw pauseMenu
        if (inPauseMenu && pauseMenu.inPause){
          pauseMenu.draw(App);
        }

      }
      //draw battleMenu
      else if (inBattleMenu && battleMenu.isInMenu()){
        battleMenu.draw(App);
        if(battleMenu.getResult() == 0) {
          std::cout << "      you won   " << battleMenu.getType()<< std::endl;
          switch(battleMenu.getType()) {
            case 0:
              break;
            case 1:
              levelManager.beatFirstSection();
              break;
            case 2:
              levelManager.beatSecondSection();
              break;
            case 3:
              levelManager.beatThirdSection();
              break;
            case 4:
              //display end screen
              break;
          }
          battleMenu.resetResult();
          levelManager.deleteSprite();
        }
        else if(battleMenu.getResult() == 1) {
          std::cout << "      you lost" << std::endl;
          int map = levelManager.getCurrentMap();
          if(map >= 0 && map <= 10) {
            levelManager.resetToStart();
          }
          else if(map >= 11 && map <= 22) {
            levelManager.resetToStart();
          }
          else if(map >= 23 && map <= 33) {
            levelManager.resetToStart();
          }
          else if(map == 34) {
            levelManager.resetToStart();
          }

          battleMenu.resetResult();
          App.clear(sf::Color::Black);
          birdSprite.setPosition(352, 352);
          //levelManager.resetToStart();
          levelManager.drawMap(App);
          App.draw(birdSprite);
          App.display();
        }
      }

      App.display();
    }


  // Done.
  return 0;
}
