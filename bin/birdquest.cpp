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
  bool view = false;
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

  // Remains true untill item is picked up
  bool itemView = true;

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
  birdSprite.setPosition(200, 624); //start at bottom of hub
  birdSprite.setTexture(birdTexture);
  birdSprite.setPosition(lastX, lastY);
  //birdSprite.setScale(2,2);

  sf::Texture keyTexture;
  if(!keyTexture.loadFromFile("../resources/spritesheets/key.png", sf::IntRect(0, 0, 16, 16))){
  }
  sf::Sprite keySprite;
  keySprite.setTexture(keyTexture);
  keySprite.setPosition(288, 400);
  keySprite.setScale(0.5, 0.5);


  sf::View view1(sf::FloatRect(150.f, 150.f, 250.f, 250.f));
  //App.setView(view1);

  sf::RectangleShape test;
  test.setPosition(0, 240);
  test.setSize(sf::Vector2f(150,100));
  //test.setFillColor

  // start main loop
  deltaMs = clock.getElapsedTime().asMilliseconds();
  otherMs = clock.getElapsedTime().asMilliseconds();
  while(App.isOpen())
  {
      deltaMs = clock.getElapsedTime().asMilliseconds();
      if(deltaMs > otherMs + 300) {
        otherMs = deltaMs;
        std::cout << "other " << otherMs << std::endl;
        if(levelManager.updateSprite(birdSprite.getPosition().x, birdSprite.getPosition().y)) { //if it sees you, start battle
          //inBattleMenu = true;
          //battleMenu.inMenu = true;
          //battleMenu.showMenu = true;
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

      //std::cout << deltaMs << " " << otherMs << std::endl;

      //std::cout << "x " << lastX << " y " << lastY << std::endl;
      //deltaMs = clock.getElapsedTime().asMilliseconds();
      //std::cout << deltaMs << std::endl;
      if(deltaMs >= 2000) {
        deltaMs -= 2000;
        //birdSprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
      }

      if(birdSprite.getPosition().x == keySprite.getPosition().x && birdSprite.getPosition().y == keySprite.getPosition().y && itemView == true){
        inventory.addItem("Key");
        itemView = false;
      }

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

          //pauseMenu.HP
          pauseMenu.HP_string.setString("HP: "+std::to_string(userHP) + "/100");

          //pauseMenu.HPstr = std::to_string(battleMenu.userHP);
          inPauseMenu = true;
          pauseMenu.inPause = true;
        }
        //keypresses for when we are in the Stage
        if (!inBattleMenu && !inPauseMenu){
          //Handle input, delegate to HumanView.cpp
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            birdTexture.loadFromFile("../resources/spritesheets/BirdKnight_spritesheet.png", sf::IntRect(0, 48, 16, 16));
			      birdSprite.setTexture(birdTexture);
			      lastY = birdSprite.getPosition().y;
            lastX = birdSprite.getPosition().x;
            humanView.movePlayer(App, birdSprite, HumanView::UP, levelManager);
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            birdTexture.loadFromFile("../resources/spritesheets/BirdKnight_spritesheet.png", sf::IntRect(0, 0, 16, 16));
			      birdSprite.setTexture(birdTexture);
			      lastY = birdSprite.getPosition().y;
            lastX = birdSprite.getPosition().x;
            humanView.movePlayer(App, birdSprite, HumanView::DOWN, levelManager);
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            birdTexture.loadFromFile("../resources/spritesheets/BirdKnight_spritesheet.png", sf::IntRect(48, 16, 16, 16));
			      birdSprite.setTexture(birdTexture);
			      lastY = birdSprite.getPosition().y;
            lastX = birdSprite.getPosition().x;
            humanView.movePlayer(App, birdSprite, HumanView::LEFT, levelManager);
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            birdTexture.loadFromFile("../resources/spritesheets/BirdKnight_spritesheet.png", sf::IntRect(0, 16, 16, 16));
			      birdSprite.setTexture(birdTexture);
			      lastY = birdSprite.getPosition().y;
            lastX = birdSprite.getPosition().x;
            humanView.movePlayer(App, birdSprite, HumanView::RIGHT, levelManager);
          }

        }

        //key presses for when we are in the battle menu
        else if (inBattleMenu){

          battleMenu.processInputs(Event, App);
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
      if(view)
        App.setView(view1);

      //draw map if not in battle
      if (!inBattleMenu){
        levelManager.drawMap(App);
        App.draw(birdSprite);

        if (itemView == true){
          App.draw(keySprite);
        }

        //draw pauseMenu
        if (inPauseMenu && pauseMenu.inPause){
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
