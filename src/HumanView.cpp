#include <SFML/Graphics.hpp>
#include <HumanView.hpp>
#include <LevelLogic.hpp>
#include <iostream>

HumanView::HumanView(){

}

void HumanView::movePlayer(sf::Sprite &thisSprite, Dir direction, LevelManager &thisLevelManager) {
  int x = thisSprite.getPosition().x;
  int y = thisSprite.getPosition().y;

  switch(direction) {
    case UP :
    if(y >= moveVal) {
      if (LevelLogic::checkTileCollisionForPlayer(x, y, direction, thisLevelManager) && LevelLogic::checkSpriteCollision(x, y, direction, thisLevelManager)) { //true = no collision
        thisSprite.move(0, -moveVal);
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
      if(LevelLogic::checkTileCollisionForPlayer(x, y, direction, thisLevelManager) && LevelLogic::checkSpriteCollision(x, y, direction, thisLevelManager)) {
        thisSprite.move(0, moveVal);
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
        if(LevelLogic::checkTileCollisionForPlayer(x, y, direction, thisLevelManager) && LevelLogic::checkSpriteCollision(x, y, direction, thisLevelManager)) {
          thisSprite.move(-moveVal, 0);
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
        if(LevelLogic::checkTileCollisionForPlayer(x, y, direction, thisLevelManager) && LevelLogic::checkSpriteCollision(x, y, direction, thisLevelManager)) {//if moving right, and tile to right is water, won't allow movement
          thisSprite.move(moveVal, 0);
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
