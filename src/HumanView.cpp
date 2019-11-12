#include <SFML/Graphics.hpp>
#include <HumanView.hpp>
#include <iostream>



HumanView::HumanView(){

}

void HumanView::movePlayer(sf::Sprite &thisSprite, Dir direction, LevelManager &thisLevelManager) {
  int x = thisSprite.getPosition().x;
  int y = thisSprite.getPosition().y;

  switch(direction) {
    case UP :
    if(y >= moveVal) {
      if (checkTileCollisionForPlayer(x, y, direction, thisLevelManager) && checkSpriteCollision(x, y, direction, thisLevelManager)) { //true = no collision
        std::cout << "here" << std::endl;
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
      if(checkTileCollisionForPlayer(x, y, direction, thisLevelManager) && checkSpriteCollision(x, y, direction, thisLevelManager)) {
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
        if(checkTileCollisionForPlayer(x, y, direction, thisLevelManager) && checkSpriteCollision(x, y, direction, thisLevelManager)) {
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
        if(checkTileCollisionForPlayer(x, y, direction, thisLevelManager) && checkSpriteCollision(x, y, direction, thisLevelManager)) {//if moving right, and tile to right is water, won't allow movement
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

//returns true if move occurred
//false otherwise
bool HumanView::move(sf::Sprite &thisSprite, int spriteNum, Dir direction, LevelManager &thisLevelManager){
  int thisX = thisSprite.getPosition().x;
  int thisY = thisSprite.getPosition().y;
  std::cout << "x " << thisX << " y " << thisY << std::endl;
  std::vector<sf::Sprite> checkSprites = thisLevelManager.getSprites();
  bool moveRet = false;

  switch(direction) {

    case UP:

    if(checkTileCollision(thisX, thisY, UP, thisLevelManager)) {
      moveRet = true;
      if(!checkSprites.empty()) {
        for(int x = 0; x < checkSprites.size(); x++) {
          if(thisX == checkSprites.at(x).getPosition().x && thisY-16 == checkSprites.at(x).getPosition().y) {
            std::cout << "true" << std::endl;
            moveRet = false;
            break;
          }
          else {
            std::cout << "false" << std::endl;
          }
        }
      }
    }

    if(moveRet) {
      std::cout << "moveret" << std::endl;
      thisLevelManager.moveSprite(spriteNum, 0, -16);
    }

    break;

    case DOWN:

    if(checkTileCollision(thisX, thisY, DOWN, thisLevelManager)) {
      moveRet = true;
      if(!checkSprites.empty()) {
        for(int x = 0; x < checkSprites.size(); x++) {
          if(thisX == checkSprites.at(x).getPosition().x && thisY+16 == checkSprites.at(x).getPosition().y) {
            std::cout << "true" << std::endl;
            moveRet = false;
            break;
          }
          else {
            std::cout << "false" << std::endl;
          }
        }
      }
    }

    if(moveRet) {
      std::cout << "moveret" << std::endl;
      thisLevelManager.moveSprite(spriteNum, 0, 16);
    }

    break;

    case LEFT:

    if(checkTileCollision(thisX, thisY, LEFT, thisLevelManager)) {
      moveRet = true;
      if(!checkSprites.empty()) {
        for(int x = 0; x < checkSprites.size(); x++) {
          if(thisX-16 == checkSprites.at(x).getPosition().x && thisY == checkSprites.at(x).getPosition().y) {
            std::cout << "true" << std::endl;
            moveRet = false;
            break;
          }
          else {
            std::cout << "false" << std::endl;
          }
        }
      }
    }

    if(moveRet) {
      std::cout << "moveret" << std::endl;
      thisLevelManager.moveSprite(spriteNum, -16, 0);
    }

    break;

    case RIGHT:

    if(checkTileCollision(thisX, thisY, RIGHT, thisLevelManager)) {
      moveRet = true;
      if(!checkSprites.empty()) {
        for(int x = 0; x < checkSprites.size(); x++) {
          if(thisX+16 == checkSprites.at(x).getPosition().x && thisY == checkSprites.at(x).getPosition().y) {
            std::cout << "true" << std::endl;
            moveRet = false;
            break;
          }
          else {
            std::cout << "false" << std::endl;
          }
        }
      }
    }

    if(moveRet) {
      std::cout << "moveret" << std::endl;
      thisLevelManager.moveSprite(spriteNum, 16, 0);
    }

    break;

  }

  return moveRet;

}

//true = no collision; i.e. not an empty tile (collision of tiles in tilset)
bool HumanView::checkTileCollisionForPlayer(int thisXPos, int thisYPos, Dir direction, LevelManager &thisLevelManager){

  bool ret = false;
  switch(direction){
    case UP : {
      int checkX = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 16).x;
      int checkY = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 16).y;
      if(checkX >= 0 && checkY >= 0) { //check if tile is empty
        std::cout << "good to go - tile up here" << std::endl;
        ret = true;
      }
    }

    break;

    case DOWN : {
      int checkX = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos + 16).x;
      int checkY = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos + 16).y;
      if(checkX >= 0 && checkY >= 0) {
          ret = true;
        }
    }

    break;

    case LEFT : {
      int checkX = thisLevelManager.getMap().getTexCoord(thisXPos-16, thisYPos).x;
      int checkY = thisLevelManager.getMap().getTexCoord(thisXPos-16, thisYPos).y;
      if(checkX >= 0 && checkY >= 0) {
          ret = true;
        }
      }

    break;

    case RIGHT : {
      int checkX = thisLevelManager.getMap().getTexCoord(thisXPos+16, thisYPos).x;
      int checkY = thisLevelManager.getMap().getTexCoord(thisXPos+16, thisYPos).y;
      if(checkX >= 0 && checkY >= 0) {
          ret = true;
        }
    }

    break;
  }

  return ret;
}

//true = no collision; i.e. not an empty tile (collision of tiles in tilset)
bool HumanView::checkTileCollision(int thisXPos, int thisYPos, Dir direction, LevelManager &thisLevelManager){

  bool ret = false;
  switch(direction){
    case UP : {
      int checkX = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 16).x;
      int checkY = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 16).y;
      if((checkX >= 0 && checkY >= 0) && (checkX != 16 || checkY != 80)) { //check if tile is empty
        std::cout << "good to go - tile up here" << std::endl;
        ret = true;
      }
    }

    break;

    case DOWN : {
      int checkX = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos+16).x;
      int checkY = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos+16).y;
      if((checkX >= 0 && checkY >= 0) && (checkX != 16 || checkY != 80)) { //check if tile is empty
          ret = true;
    }
  }

    break;

    case LEFT : {
      int checkX = thisLevelManager.getMap().getTexCoord(thisXPos-16, thisYPos).x;
      int checkY = thisLevelManager.getMap().getTexCoord(thisXPos-16, thisYPos).y;
      if((checkX >= 0 && checkY >= 0) && (checkX != 16 || checkY != 80)) { //check if tile is empty
          ret = true;
      }
    }

    break;

    case RIGHT : {
      int checkX = thisLevelManager.getMap().getTexCoord(thisXPos+16, thisYPos).x;
      int checkY = thisLevelManager.getMap().getTexCoord(thisXPos+16, thisYPos).y;
      if((checkX >= 0 && checkY >= 0) && (checkX != 16 || checkY != 80)) { //check if tile is empty
          ret = true;
    }
  }

    break;
  }

  return ret;
}

//collision of current screen's sprites
bool HumanView::checkSpriteCollision(int thisXPos, int thisYPos, Dir direction, LevelManager &thisLevelManager) {
  std::vector<sf::Sprite> checkSprites = thisLevelManager.getSprites();
  bool thisRet = true;
  switch(direction){
    case UP :
    if(!checkSprites.empty()) {
      std::cout << "not empty" << std::endl;
      for(int x = 0; x < checkSprites.size(); x++) {
        if(thisXPos == checkSprites.at(x).getPosition().x && thisYPos-16 == checkSprites.at(x).getPosition().y) {
          std::cout << "sprite here up" << std::endl;
          if(!move(checkSprites.at(x), x, UP, thisLevelManager)) { //if sprite moves, bird can move too
            thisRet = false;
            break;
          }
        }
      }
    }

    break;

    case DOWN :
    if(!checkSprites.empty()) {
      std::cout << "not empty" << std::endl;
      for(int x = 0; x < checkSprites.size(); x++) {
        if(thisXPos == checkSprites.at(x).getPosition().x && thisYPos+16 == checkSprites.at(x).getPosition().y) {
          std::cout << "sprite here up" << std::endl;
          if(!move(checkSprites.at(x), x, DOWN, thisLevelManager)) { //if sprite moves, bird can move too
            thisRet = false;
            break;
          }
        }
      }
    }


    break;

    case LEFT :
    if(!checkSprites.empty()) {
      std::cout << "not empty" << std::endl;
      for(int x = 0; x < checkSprites.size(); x++) {
        if(thisXPos-16 == checkSprites.at(x).getPosition().x && thisYPos == checkSprites.at(x).getPosition().y) {
          std::cout << "sprite here up" << std::endl;
          if(!move(checkSprites.at(x), x, LEFT, thisLevelManager)) { //if sprite moves, bird can move too
            thisRet = false;
            break;
          }
        }
      }
    }


    break;

    case RIGHT :
    if(!checkSprites.empty()) {
      std::cout << "not empty" << std::endl;
      for(int x = 0; x < checkSprites.size(); x++) {
        if(thisXPos+16 == checkSprites.at(x).getPosition().x && thisYPos == checkSprites.at(x).getPosition().y) {
          std::cout << "sprite here up" << std::endl;
          if(!move(checkSprites.at(x), x, RIGHT, thisLevelManager)) { //if sprite moves, bird can move too
            thisRet = false;
            break;
          }
        }
      }
    }


    break;
  }

  return thisRet;
}

//Switch map IF
//going left -> xpos >= moveVal; i.e. if moveVal = 32, if pos <= 32 switch to left map
//going right -> xpos < windowPixelWidth - moveVal; i.e. if moveVal = 32, WPW = 1032, if pos >= 1000 switch to right map
//going up -> ypos >= moveVal; i.e. if moveVal = 32, if pos <= 32 switch to up map
//going down -> ypos < windowPixelWidth - moveVal; i.e. if moveVal = 32, WPW = 1032, if pos >= 1000 switch to down map

//check map; either move tile or switch map; check collision first

//if(valid position and not collide)
//move to tile
//else
//switch map
