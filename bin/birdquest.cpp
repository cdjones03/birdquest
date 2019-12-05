#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
#include "TitleScreen.h"
#include <EndScreen.hpp>

using namespace std;

int main(int argc, char** argv)
{
  const int windowTileWidth = 40;
  const int windowTileHeight = 40;
  const int windowPixelWidth = 853;
  const int windowPixelHeight = windowTileHeight*16;
  const int moveVal = 32;
  int lastX = 352;
  int lastY = 352;
  int userHP;
  int enemyCheck;
  string item;


  // create main window; Style::Close disables resizing
  //The game should be played in an 800x600 window. Changing the size of the window sh
  sf::RenderWindow App(sf::VideoMode(windowPixelWidth, windowPixelHeight, 32), "BirdQuest!");//, sf::Style::Close);
  App.setFramerateLimit(60);
  //App.setKeyRepeatEnabled(false);

  //Create battleMenu object and boolean for if we are in the battle menu
  BattleMenu battleMenu;
  bool inBattleMenu = false;

  // Create pauseMenu object and boolean for if we are in the pause menu
  PauseMenu pauseMenu(App.getSize().x, App.getSize().y);
  bool inPauseMenu = false;

  // Create titleScreen object and boolean for if we are in the title screen
  TitleScreen titleScreen(App.getSize().x, App.getSize().y);
  bool inTitle = true;

  // Create endScreen object and boolean for if we are in the end screen
  EndScreen endScreen(App.getSize().x, App.getSize().y);
  bool inEnd = false;

  // Create inventory object
  Inventory inventory;

  //Create enemy object
  Enemy enemy;

  // create the tilemap from the level definition
  LevelManager levelManager;
  levelManager.loadLevels();

  //create humanview
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

  //load the music files
  sf::Music titleTheme;
  sf::Music dungeonTheme;
  bool firstDTheme = true;
  sf::Music battleTheme;
  bool firstBTheme = true;
  if (!titleTheme.openFromFile("../resources/sound/titleTheme.wav")) {
    //error
  }
  if (!dungeonTheme.openFromFile("../resources/sound/dungeonTheme.wav")) {
    //error
  }
  if (!battleTheme.openFromFile("../resources/sound/battleTheme.wav")) {
    //error
  }
  titleTheme.setLoop(true);
  titleTheme.play();

  // start main loop
  deltaMs = clock.getElapsedTime().asMilliseconds();
  otherMs = clock.getElapsedTime().asMilliseconds();
  while(App.isOpen())
  {
      deltaMs = clock.getElapsedTime().asMilliseconds();
      if(deltaMs > otherMs + 200) {
        otherMs = deltaMs;
        levelManager.moveEnemy();
      }
      if(!inBattleMenu) {
      enemyCheck = levelManager.checkForEnemy(birdSprite.getPosition().x, birdSprite.getPosition().y);
      if(enemyCheck >= 0) { //if it sees you, start battle
        battleMenu.setEnemy(enemyCheck);
        inBattleMenu = true;
        battleMenu.setInMenu(true);
        battleMenu.setShowMenu(true);
        firstBTheme = true;
        if (firstBTheme){
          dungeonTheme.stop();
          battleTheme.setLoop(true);
          battleTheme.play();
          firstBTheme = false;
          }
        }
      }

      // update inventory in battle menu
      battleMenu.setItemText(0, inventory.getItemArrayItem(0));
      battleMenu.setItemText(1, inventory.getItemArrayItem(1));
      battleMenu.setItemText(2, inventory.getItemArrayItem(2));
      battleMenu.setItemText(3, inventory.getItemArrayItem(3));

      battleMenu.setItem0(inventory.getItemArrayItem(0));
      battleMenu.setItem1(inventory.getItemArrayItem(1));
      battleMenu.setItem2(inventory.getItemArrayItem(2));
      battleMenu.setItem3(inventory.getItemArrayItem(3));

      // process events
      sf::Event Event;
      while(App.pollEvent(Event))
      {
        // Exit
        if(Event.type == sf::Event::Closed){
          App.close();
        }
        //press p to get to pauseMenu
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
          userHP = battleMenu.getUserHP();
          pauseMenu.setHealthBarSize(sf::Vector2f(640/3.5 * userHP/100, 640/30));

          pauseMenu.setItemText(0, inventory.getItemArrayItem(0));
          pauseMenu.setItemText(1, inventory.getItemArrayItem(1));
          pauseMenu.setItemText(2, inventory.getItemArrayItem(2));
          pauseMenu.setItemText(3, inventory.getItemArrayItem(3));

          //pauseMenu.HP
          pauseMenu.setHPString("HP: "+ std::to_string(userHP) + "/100");

          //pauseMenu.HPstr = std::to_string(battleMenu.userHP);
          inPauseMenu = true;
          pauseMenu.setInPause(true);
        }


        if (inTitle){
          titleScreen.processInputs(Event);
          if (!titleScreen.isInTitle()){
            titleTheme.stop();
            inTitle = false;
          }
        }

        //keypresses for when we are in the Stage
        else if (!inBattleMenu && !inPauseMenu){
          if (firstDTheme){
            dungeonTheme.setLoop(true);
            dungeonTheme.play();
            firstDTheme = false;
          }
          //Handle input, delegate to HumanView.cpp, animate bird
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
          inventory.useItem(battleMenu.getItem_Used());
          if (!battleMenu.isInMenu()) {
            inBattleMenu = false;
            battleTheme.stop();
            firstDTheme = true;
          }

          //player beat enemy
          if(battleMenu.getResult() == 0) {
            switch(battleMenu.getType()) {
              case 0: //beat regular enemy
                break;
              case 1: //beat snake boss
                levelManager.beatFirstSection();
                break;
              case 2: //beat cat boss
                levelManager.beatSecondSection();
                break;
              case 3: //beat ice owl boss
                levelManager.beatThirdSection();
                break;
              case 4: //beat final boss
                inEnd = true;
                break;
            }
            battleMenu.resetResult();
            levelManager.deleteSprite();
          }

          //player lost to enemy
          else if(battleMenu.getResult() == 1) {
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
            levelManager.drawMap(App);
            App.draw(birdSprite);
          }

        }

        //key presses for when we are in the pause menu
        else if (inPauseMenu){
          pauseMenu.processInputs(Event, App);
          if (!pauseMenu.isInPause()){

            inPauseMenu = false;
          }
        }
      }

      //Display
      App.clear(sf::Color::Black);

      if(inTitle && titleScreen.isInTitle()){
        titleScreen.draw(App);
      }

      else if(inEnd && endScreen.isInEnd()){
        endScreen.draw(App);
      }

      //draw map if not in battle
      else if (!inBattleMenu){
        levelManager.drawMap(App);
        App.draw(birdSprite);

        //draw pauseMenu
        if (inPauseMenu && pauseMenu.isInPause()){
          pauseMenu.draw(App);
        }

      }
      //draw battleMenu
      else if (inBattleMenu && battleMenu.isInMenu()){
        battleMenu.draw(App);

      }

      App.display();
    }


  // Done.
  return 0;
}
