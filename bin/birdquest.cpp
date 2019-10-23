#include <SFML/Graphics.hpp>
#include <TileMap.hpp>
#include <iostream>
#include <tinyxml2.h>
#include "BattleMenu.h"
#include "BattleBar.h"
#include <LevelManager.hpp>
#include "BattleLogic.h"

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

  // create the tilemap from the level definition
  LevelManager levelManager;
  levelManager.loadLevels();

  sf::Clock clock;
  int deltaMs;

  sf::Texture birdTexture;
  if(!birdTexture.loadFromFile("../resources/birdsprite.png")){
    return -1;
  }
  sf::Sprite birdSprite;
  birdSprite.setTexture(birdTexture);

  // start main loop
  while(App.isOpen())
  {
      deltaMs = clock.getElapsedTime().asMilliseconds();
      // process events
      sf::Event Event;
      while(App.pollEvent(Event))
      {
        // Exit
        if(Event.type == sf::Event::Closed){
          App.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
          inBattleMenu = true;
        }
        //keypresses for when we are in the Stage
        if (!inBattleMenu){
          //Handle input, delegate to HumanView.cpp
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if(birdSprite.getPosition().y >= moveVal){
              birdSprite.move(0, -moveVal);
              continue;
            }
            else {
              levelManager.switchMap(2);
              birdSprite.setPosition(birdSprite.getPosition().x, windowPixelHeight-32);
            }
          }

          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if(birdSprite.getPosition().y < windowPixelHeight-moveVal){
              birdSprite.move(0, moveVal);
              continue;
          }
            else {
              levelManager.switchMap(1);
              birdSprite.setPosition(birdSprite.getPosition().x, 0);
            }
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && birdSprite.getPosition().x < windowPixelWidth-moveVal){
            if(levelManager.getMap().getTexCoord(birdSprite.getPosition().x+32, birdSprite.getPosition().y) != 32){//if moving right, and tile to right is water, won't allow movement
            birdSprite.move(moveVal, 0);
            std::cout << birdSprite.getPosition().x << " " << birdSprite.getPosition().y << std::endl;
            std::cout << levelManager.getMap().getTexCoord(birdSprite.getPosition().x, birdSprite.getPosition().y) << std::endl;
            continue;
          }
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && birdSprite.getPosition().x >= moveVal){
            birdSprite.move(-moveVal, 0);
            continue;
          }
        }
        //key presses for when we are in the battle menu
        else if (inBattleMenu){
          //std::cout << "hello" << std::endl;

          battleMenu.processInputs(Event, App);
          if (!battleMenu.inMenu){
            inBattleMenu = false;
          }

        }
      }


      //Display
      App.clear(sf::Color::Black);

      if (!inBattleMenu){
        levelManager.drawMap(App);
        App.draw(birdSprite);
      }
      else if (inBattleMenu && battleMenu.inMenu){
        battleMenu.draw(App);
      }


      App.display();
    }


  // Done.
  return 0;
}
