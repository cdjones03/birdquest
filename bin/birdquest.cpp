#include <SFML/Graphics.hpp>
#include <TileMap.hpp>
#include <iostream>
#include <tinyxml2.h>
#include "BattleMenu.h"
#include "BattleBar.h"
#include <LevelManager.hpp>
#include "BattleLogic.h"
#include "PauseMenu.h"
#include <HumanView.hpp>

/*
Note: for items, place sprite on map
player walks over, press i, if coords are = , get item and remove sprite
*/

using namespace std;

int main(int argc, char** argv)
{
  const int windowTileWidth = 20;
  const int windowTileHeight = 20;
  const int windowPixelWidth = windowTileWidth*32;
  const int windowPixelHeight = windowTileHeight*32;
  const int moveVal = 32;


  // create main window; Style::Close disables resizing
  //The game should be played in an 800x600 window. Changing the size of the window sh
  sf::RenderWindow App(sf::VideoMode(windowPixelWidth, windowPixelWidth, 32), "BirdQuest!");//, sf::Style::Close);
  App.setFramerateLimit(60);
  //App.setKeyRepeatEnabled(false);

  //Create battleMenu object and boolean for if we are in the battle menu
  BattleMenu battleMenu(App.getSize().x, App.getSize().y);
  bool inBattleMenu = false;

  // Create pauseMenu object and boolean for if we are in the battle menu
  PauseMenu pauseMenu(App.getSize().x, App.getSize().y);
  bool inPauseMenu = false;

  // create the tilemap from the level definition
  LevelManager levelManager;
  levelManager.loadLevels();

  HumanView humanView;

  sf::Clock clock;
  int deltaMs;

  sf::Texture birdTexture;
  if(!birdTexture.loadFromFile("../resources/spritesheets/BirdKnight_spritesheet.png", sf::IntRect(0, 0, 16, 16))){
    return -1;
  }
  sf::Sprite birdSprite;
  birdSprite.setTexture(birdTexture);
  //birdSprite.setScale(2,2);

  sf::Texture blockTexture;
  if(!blockTexture.loadFromFile("../resources/spritesheets/birdnpc.png", sf::IntRect(0, 0, 32, 32))){
  }
  sf::Sprite blockSprite;
  blockSprite.setTexture(blockTexture);
  blockSprite.setPosition(320, 320);
  blockSprite.setScale(2,2);

  sf::Texture keyTexture;
  if(!keyTexture.loadFromFile("../resources/spritesheets/key.png", sf::IntRect(3, 3, 32, 32))){
  }
  sf::Sprite keySprite;
  keySprite.setTexture(keyTexture);
  keySprite.setPosition(290, 400);
  keySprite.setScale(0.5, 0.5);


  //sf::View view1(sf::FloatRect(0.f, 0.f, 200.f, 200.f));
  //App.setView(view1);

  // start main loop
  deltaMs = clock.getElapsedTime().asMilliseconds();
  while(App.isOpen())
  {
      deltaMs = clock.getElapsedTime().asMilliseconds();
      //std::cout << deltaMs << std::endl;
      if(deltaMs >= 2000) {
        deltaMs -= 2000;
        //birdSprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
      }
      if(birdSprite.getPosition().x == blockSprite.getPosition().x && birdSprite.getPosition().y == blockSprite.getPosition().y){
        blockSprite.move(32, 0);
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
          inBattleMenu = true;
          battleMenu.inMenu = true;
          battleMenu.showMenu = true;
        }
        //press p to get to pauseMenu
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
          inPauseMenu = true;
          pauseMenu.inPause = true;
        }
        //keypresses for when we are in the Stage
        if (!inBattleMenu && !inPauseMenu){
          //Handle input, delegate to HumanView.cpp
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            humanView.move(birdSprite, HumanView::UP, levelManager);
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            humanView.move(birdSprite, HumanView::DOWN, levelManager);
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            humanView.move(birdSprite, HumanView::LEFT, levelManager);
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            humanView.move(birdSprite, HumanView::RIGHT, levelManager);
          }

        }

        //key presses for when we are in the battle menu
        else if (inBattleMenu){

          battleMenu.processInputs(Event, App);
          if (!battleMenu.inMenu){
            inBattleMenu = false;
          }

        }

        //key presses for when we are in the pause menu
        else if (inPauseMenu){
          pauseMenu.processInputs(Event, App);
          if (!pauseMenu.inPause){
            inPauseMenu = false;
          }
        }
      }


      //Display
      App.clear(sf::Color::Black);
      //App.setView(view1);

      //draw map if not in battle
      if (!inBattleMenu){
        levelManager.drawMap(App);
        App.draw(birdSprite);
        App.draw(blockSprite);
        App.draw(keySprite);

        //draw pauseMenu
        if (inPauseMenu && pauseMenu.inPause){
          pauseMenu.draw(App);
        }

      }
      //draw battleMenu
      else if (inBattleMenu && battleMenu.inMenu){
        battleMenu.draw(App);
      }

      App.display();
    }


  // Done.
  return 0;
}
