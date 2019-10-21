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
  const int moveVal = 8;

  // create main window; Style::Close disables resizing
  //The game should be played in an 800x600 window. Changing the size of the window sh
  sf::RenderWindow App(sf::VideoMode(windowPixelWidth, windowPixelWidth, 32), "BirdQuest!");//, sf::Style::Close);
  App.setFramerateLimit(60);

  //Create battleMenu object and boolean for if we are in the battle menu
  BattleMenu battleMenu(App.getSize().x, App.getSize().y);
  bool inBattleMenu = false;

  // create the tilemap from the level definition
  LevelManager levelManager;
  levelManager.loadLevels();


  sf::View view(sf::FloatRect(0, 0, 320, 320));
  //App.setView(view);

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
            //view.move(32, 0);
            birdSprite.move(moveVal, 0);
            continue;
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && birdSprite.getPosition().x >= moveVal){
            birdSprite.move(-moveVal, 0);
            continue;
          }
        }
        //key presses for when we are in the battle menu
        else if (inBattleMenu){
          //moving up,down, left, right to select options

          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            battleMenu.moveUp();
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            battleMenu.moveDown();
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            battleMenu.moveRight();
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            battleMenu.moveLeft();
          }
          //once option is selected, do something
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {

            switch (battleMenu.getSelectedOption()){
              case 0:
                battleMenu.updateHPText();
                cout << "Attack pressed" << endl;
                //BattleBar();   //run the battle bar
				        break;
              case 1:
                battleMenu.updateHPText();
                cout << "Magic pressed" << endl;
                break;
              case 2:
                cout << "Evade pressed" << endl;
                break;
              case 3:
                cout << "Item pressed" << endl;
                break;
            }
            continue;
          }
        }
      }

      //Display
      App.clear(sf::Color::Black);
      //App.setView(view);
      //
      if (!inBattleMenu){
        levelManager.drawMap(App);
        App.draw(birdSprite);
      }
      else{
        battleMenu.draw(App);
      }


      App.display();
    }


  // Done.
  return 0;
}
