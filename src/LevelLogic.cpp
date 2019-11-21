#include <LevelLogic.hpp>
#include <HumanView.hpp>
#include <LevelManager.hpp>
#include <iostream>

LevelLogic::LevelLogic() {

}

//returns true if move occurred
//false otherwise
bool LevelLogic::moveObject(sf::Sprite &thisSprite, int spriteNum, HumanView::Dir direction, LevelManager &thisLevelManager) {
  int thisX = thisSprite.getPosition().x;
  int thisY = thisSprite.getPosition().y;
  std::vector<sf::Sprite> checkSprites = thisLevelManager.getSprites();
  bool moveRet = false;

  switch(direction) {

    case HumanView::UP:

      if(checkTileCollision(thisX, thisY, HumanView::UP, thisLevelManager)) {
        moveRet = true;
        if(!checkSprites.empty()) {
          for(int x = 0; x < checkSprites.size(); x++) {
            //if there's another sprite in that direction, dont let it move
            if(thisX == checkSprites.at(x).getPosition().x && thisY-16 == checkSprites.at(x).getPosition().y) {
              std::cout << checkSprites.at(x).getPosition().x << " " << checkSprites.at(x).getPosition().y << std::endl;
              std::cout << checkSprites.at(x).getTexture() << std::endl;
              moveRet = false;
              break;
            }
          }
        }
      }

      if(moveRet) {
        thisLevelManager.moveSprite(spriteNum, 0, -16);
      }

      break;

    case HumanView::DOWN:

      if(checkTileCollision(thisX, thisY, HumanView::DOWN, thisLevelManager)) {
        moveRet = true;
        if(!checkSprites.empty()) {
          for(int x = 0; x < checkSprites.size(); x++) {
            if(thisX == checkSprites.at(x).getPosition().x && thisY+16 == checkSprites.at(x).getPosition().y) {
              moveRet = false;
              break;
            }
          }
        }
      }

      if(moveRet) {
        thisLevelManager.moveSprite(spriteNum, 0, 16);
      }

      break;

    case HumanView::LEFT:

      if(checkTileCollision(thisX, thisY, HumanView::LEFT, thisLevelManager)) {
        moveRet = true;
        if(!checkSprites.empty()) {
          for(int x = 0; x < checkSprites.size(); x++) {
            if(thisX-16 == checkSprites.at(x).getPosition().x && thisY == checkSprites.at(x).getPosition().y) {
              moveRet = false;
              break;
            }
          }
        }
      }

      if(moveRet) {
        thisLevelManager.moveSprite(spriteNum, -16, 0);
      }

      break;

    case HumanView::RIGHT:

      if(checkTileCollision(thisX, thisY, HumanView::RIGHT, thisLevelManager)) {
        moveRet = true;
        if(!checkSprites.empty()) {
          for(int x = 0; x < checkSprites.size(); x++) {
            if(thisX+16 == checkSprites.at(x).getPosition().x && thisY == checkSprites.at(x).getPosition().y) {
              moveRet = false;
              break;
            }
          }
        }
      }

      if(moveRet) {
        thisLevelManager.moveSprite(spriteNum, 16, 0);
      }

      break;

  }

  return moveRet;
}

//true = no collision; i.e. not an empty tile (collision of tiles in tilset)
//collision for player
bool LevelLogic::checkTileCollisionForPlayer(int thisXPos, int thisYPos, HumanView::Dir direction, LevelManager &thisLevelManager){
  bool ret = false;
  switch(direction){
    case HumanView::UP : {
      int checkX = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 16).x;
      int checkY = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 16).y;
      if(checkX >= 0 && checkY >= 0) { //check if tile is empty
        ret = true;
      }
    }

    break;

    case HumanView::DOWN : {
      int checkX = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos + 16).x;
      int checkY = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos + 16).y;
      if(checkX >= 0 && checkY >= 0) {
          ret = true;
        }
    }

    break;

    case HumanView::LEFT : {
      int checkX = thisLevelManager.getMap().getTexCoord(thisXPos-16, thisYPos).x;
      int checkY = thisLevelManager.getMap().getTexCoord(thisXPos-16, thisYPos).y;
      if(checkX >= 0 && checkY >= 0) {
          ret = true;
        }
      }

    break;

    case HumanView::RIGHT : {
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
//collision for sprites -- not player
bool LevelLogic::checkTileCollision(int thisXPos, int thisYPos, HumanView::Dir direction, LevelManager &thisLevelManager){
  //16, 80 is circle tile
  bool ret = false;
  switch(direction){
    case HumanView::UP : {
      int checkX = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 16).x;
      int checkY = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 16).y;
      if((checkX >= 0 && checkY >= 0) && (checkX != 16 || checkY != 80)) { //check if tile is empty
        ret = true;
      }
    }

    break;

    case HumanView::DOWN : {
      int checkX = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos+16).x;
      int checkY = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos+16).y;
      if((checkX >= 0 && checkY >= 0) && (checkX != 16 || checkY != 80)) { //check if tile is empty
          ret = true;
    }
  }

    break;

    case HumanView::LEFT : {
      int checkX = thisLevelManager.getMap().getTexCoord(thisXPos-16, thisYPos).x;
      int checkY = thisLevelManager.getMap().getTexCoord(thisXPos-16, thisYPos).y;
      if((checkX >= 0 && checkY >= 0) && (checkX != 16 || checkY != 80)) { //check if tile is empty
          ret = true;
      }
    }

    break;

    case HumanView::RIGHT : {
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
bool LevelLogic::checkSpriteCollision(int thisXPos, int thisYPos, HumanView::Dir direction, LevelManager &thisLevelManager){
  std::vector<sf::Sprite> checkSprites = thisLevelManager.getSprites();
  bool thisRet = true;
  switch(direction){

    case HumanView::UP :
      if(!checkSprites.empty()) {
        for(int x = 0; x < checkSprites.size(); x++) {
           //sprite to tile above
          if(thisXPos == checkSprites.at(x).getPosition().x && thisYPos-16 == checkSprites.at(x).getPosition().y) {
            if(thisLevelManager.getTexture(x) == 4) { //real key!
              thisRet = false; //can change to true once key can be added to inventory
              //inventory.add(key)
              std::cout << "You found the real key!" << std::endl;
              break;
            }
            if(!moveObject(checkSprites.at(x), x, HumanView::UP, thisLevelManager)) { //if sprite moves, bird can move too
              thisRet = false;
              break;
            }
          }
        }
      }

      break;

    case HumanView::DOWN :
      if(!checkSprites.empty()) {
        for(int x = 0; x < checkSprites.size(); x++) {
          if(thisXPos == checkSprites.at(x).getPosition().x && thisYPos+16 == checkSprites.at(x).getPosition().y) {
            if(thisLevelManager.getTexture(x) == 4) { //real key!
              thisRet = false; //can change to true once key can be added to inventory
              //inventory.add(key)
              std::cout << "You found the real key!" << std::endl;
              break;
            }
            if(!moveObject(checkSprites.at(x), x, HumanView::DOWN, thisLevelManager)) { //if sprite moves, bird can move too
              thisRet = false;
              break;
            }
          }
        }
      }

      break;

    case HumanView::LEFT :
      if(!checkSprites.empty()) {
        for(int x = 0; x < checkSprites.size(); x++) {
          if(thisXPos-16 == checkSprites.at(x).getPosition().x && thisYPos == checkSprites.at(x).getPosition().y) {
            if(thisLevelManager.getTexture(x) == 4) { //real key!
              thisRet = false; //can change to true once key can be added to inventory
              //inventory.add(key)
              std::cout << "You found the real key!" << std::endl;
              break;
            }
            if(!moveObject(checkSprites.at(x), x, HumanView::LEFT, thisLevelManager)) { //if sprite moves, bird can move too
              thisRet = false;
              break;
            }
          }
        }
      }

      break;

    case HumanView::RIGHT :
      if(!checkSprites.empty()) {
        for(int x = 0; x < checkSprites.size(); x++) {
          if(thisXPos+16 == checkSprites.at(x).getPosition().x && thisYPos == checkSprites.at(x).getPosition().y) {
            if(thisLevelManager.getTexture(x) == 4) { //real key!
              thisRet = false; //can change to true once key can be added to inventory
              //inventory.add(key)
              std::cout << "You found the real key!" << std::endl;
              break;
            }
            if(!moveObject(checkSprites.at(x), x, HumanView::RIGHT, thisLevelManager)) { //if sprite moves, bird can move too
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

/*
bool LevelLogic::checkForRealKey() {
  if(LevelManager.getTexture(x) == 4) { //real key!
    thisRet = false; //can change to true once key can be added to inventory
    //inventory.add(key)
    std::cout << "You found the real key!" << std::endl;
    break;
}
*/

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
