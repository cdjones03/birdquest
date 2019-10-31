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
  if(!birdTexture.loadFromFile("../resources/BirdKnight_spritesheet.png")){
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
      else if (inBattleMenu && battleMenu.inMenu){
        battleMenu.draw(App);
      }





      App.display();
    }


  // Done.
  return 0;
}
