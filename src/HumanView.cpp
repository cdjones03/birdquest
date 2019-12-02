#include <SFML/Graphics.hpp>
#include <HumanView.hpp>
#include <LevelLogic.hpp>
#include <iostream>
#include "Inventory.h"

HumanView::HumanView(){

}

void HumanView::movePlayer(sf::RenderWindow& thisApp, sf::Sprite &thisSprite, Dir direction, LevelManager &thisLevelManager, Inventory &thisInventory) {
  int x = thisSprite.getPosition().x;
  int y = thisSprite.getPosition().y;
  sf::Clock clock;
  bool check = false;

  switch(direction) {
    case UP :
    if(y >= moveVal) {
      if (LevelLogic::checkTileCollisionForPlayer(x, y, direction, thisLevelManager) && LevelLogic::checkSpriteCollision(x, y, direction, thisLevelManager, thisApp, thisInventory)) { //true = no collision

        while(LevelLogic::checkForIceTile(x, y, direction, thisLevelManager) && LevelLogic::checkTileCollisionForPlayer(x, y-16, direction, thisLevelManager))
        {
          check = true;
          while(check){
            if (clock.getElapsedTime().asSeconds() > 0.10f){
              thisSprite.move(0, -moveVal);
              y = thisSprite.getPosition().y;
              thisApp.clear(sf::Color::Black);
              thisLevelManager.drawMap(thisApp);
              thisApp.draw(thisSprite);
              thisApp.display();
              clock.restart();
              check = false;
            }
            else {
              check = true;
            }
          }
        }
        if(!check) {
          thisSprite.move(0, -moveVal);
        }

      }
    }
    else {
      if(y < moveVal) { //at top edge of map
        if(thisLevelManager.switchMap(0))
          thisSprite.setPosition(x, windowPixelHeight-32);
      }
    }
      break;

    case DOWN :
    if(y < windowPixelHeight-moveVal){
      if(LevelLogic::checkTileCollisionForPlayer(x, y, direction, thisLevelManager) && LevelLogic::checkSpriteCollision(x, y, direction, thisLevelManager, thisApp, thisInventory)) {

        while(LevelLogic::checkForIceTile(x, y, direction, thisLevelManager) && LevelLogic::checkTileCollisionForPlayer(x, y+16, direction, thisLevelManager))
        {
          check = true;
          while(check){
            if (clock.getElapsedTime().asSeconds() > 0.10f){
              thisSprite.move(0, moveVal);
              y = thisSprite.getPosition().y;
              thisApp.clear(sf::Color::Black);
              thisLevelManager.drawMap(thisApp);
              thisApp.draw(thisSprite);
              thisApp.display();
              clock.restart();
              check = false;
            }
            else {
              check = true;
            }
          }
        }
        if(!check) {
          thisSprite.move(0, moveVal);
        }

      }
    }
    else {
      if(y >= windowPixelHeight-moveVal) { //at bottom edge of map
        if(thisLevelManager.switchMap(1))
          thisSprite.setPosition(x, 0);
      }
    }
      break;

    case LEFT :
      if(x >= moveVal) {
        if(LevelLogic::checkTileCollisionForPlayer(x, y, direction, thisLevelManager) && LevelLogic::checkSpriteCollision(x, y, direction, thisLevelManager, thisApp, thisInventory)) {

          while(LevelLogic::checkForIceTile(x, y, direction, thisLevelManager) && LevelLogic::checkTileCollisionForPlayer(x-16, y, direction, thisLevelManager))
          {
            check = true;
            while(check){
              if (clock.getElapsedTime().asSeconds() > 0.10f){
                thisSprite.move(-moveVal, 0);
                x = thisSprite.getPosition().x;
                thisApp.clear(sf::Color::Black);
                thisLevelManager.drawMap(thisApp);
                thisApp.draw(thisSprite);
                thisApp.display();
                clock.restart();
                check = false;
              }
              else {
                check = true;
              }
            }
          }
          if(!check) {
            thisSprite.move(-moveVal, 0);
          }

        }
      }
      else {
        if(x < moveVal) { //at left edge of map
          if(thisLevelManager.switchMap(2))
            thisSprite.setPosition(windowPixelWidth-32, y);
        }
      }

      break;

    case RIGHT :
      if(x < windowPixelWidth-moveVal) {
        if(LevelLogic::checkTileCollisionForPlayer(x, y, direction, thisLevelManager) && LevelLogic::checkSpriteCollision(x, y, direction, thisLevelManager, thisApp, thisInventory)) {//if moving right, and tile to right is water, won't allow movement

        while(LevelLogic::checkForIceTile(x, y, direction, thisLevelManager) && LevelLogic::checkTileCollisionForPlayer(x+16, y, direction, thisLevelManager))
        {
          check = true;
          while(check){
            if (clock.getElapsedTime().asSeconds() > 0.10f){
              thisSprite.move(moveVal, 0);
              x = thisSprite.getPosition().x;
              thisApp.clear(sf::Color::Black);
              thisLevelManager.drawMap(thisApp);
              thisApp.draw(thisSprite);
              thisApp.display();
              clock.restart();
              check = false;
            }
            else {
              check = true;
            }

          }
        }
        if(!check) {
          thisSprite.move(moveVal, 0);
        }

        }
      }
      else {
        if(x >= windowPixelWidth-moveVal) { //at right edge of map
          if(thisLevelManager.switchMap(3))
            thisSprite.setPosition(0, y);
        }
      }
      break;
    }
}
