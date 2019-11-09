#include <SFML/Graphics.hpp>
#include <HumanView.hpp>
#include <iostream>



HumanView::HumanView(){

}

void HumanView::move(sf::Sprite &thisSprite, Dir direction, LevelManager &thisLevelManager, sf::Sprite &otherSprite){
  int x = thisSprite.getPosition().x;
  int y = thisSprite.getPosition().y;

  //std::cout << y << std::endl;

  switch(direction) {
    case UP :
    if(y >= moveVal) {
      if (checkCollision(x, y, direction, thisLevelManager)) {
        thisSprite.move(0, -moveVal);
      }
    }
    else {
      if(y < moveVal) {
        if(thisLevelManager.switchMap(0))
          thisSprite.setPosition(x, windowPixelHeight-32);
      }
    }
      break;

    case DOWN :
    if(y < windowPixelHeight-moveVal){
      if(checkCollision(x, y, direction, thisLevelManager))
        thisSprite.move(0, moveVal);
      }
    else {
      if(y >= windowPixelHeight-moveVal) {
        if(thisLevelManager.switchMap(1))
          thisSprite.setPosition(x, 0);
      }
    }
      break;

    case LEFT :
      if(x >= moveVal) {
        if(checkCollision(x, y, direction, thisLevelManager)) {
          thisSprite.move(-moveVal, 0);
        }
      }
      else {
        if(x < moveVal) {
          if(thisLevelManager.switchMap(2))
            thisSprite.setPosition(windowPixelWidth-32, y);
        }
      }

      break;

    case RIGHT :
      if(x < windowPixelWidth-moveVal) {
        if(checkCollision(x, y, direction, thisLevelManager)){//if moving right, and tile to right is water, won't allow movement
          thisSprite.move(moveVal, 0);
        }
      }
      else {
        if(x >= windowPixelWidth-moveVal) {
          if(thisLevelManager.switchMap(3))
            thisSprite.setPosition(0, y);
        }
      }
      break;

  }
}

//true = no collision; i.e. not a water tile in tilset.png
bool HumanView::checkCollision(int thisXPos, int thisYPos, Dir direction, LevelManager &thisLevelManager){
  std::cout << thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos) << std::endl;
  std::cout << thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 16) << std::endl;
  std::cout << thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos + 16) << std::endl;
  std::cout << thisLevelManager.getMap().getTexCoord(thisXPos - 16, thisYPos) << std::endl;
  std::cout << thisLevelManager.getMap().getTexCoord(thisXPos + 16, thisYPos) << std::endl << std::endl;

  bool ret = false;
  switch(direction){
    case UP :

      if(thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 16) >= 0) //check if tile is empty
        ret = true;

    break;

    case DOWN :

      if(thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos + 16) >= 0)
        ret = true;

    break;

    case LEFT :

      if(thisLevelManager.getMap().getTexCoord(thisXPos - 16, thisYPos) >= 0)
        ret = true;

    break;

    case RIGHT :

      if(thisLevelManager.getMap().getTexCoord(thisXPos + 16, thisYPos) >= 0)
        ret = true;

    break;
  }

  //ret = true;
  return ret;
}

void HumanView::checkSpriteCollision(Dir direction, LevelManager &thisLevelManager) {
  switch(direction){
    case UP :

      thisLevelManager.switchMap(0);

    break;

    case DOWN :

      thisLevelManager.switchMap(1);

    break;

    case LEFT :

      thisLevelManager.switchMap(2);

    break;

    case RIGHT :

      thisLevelManager.switchMap(3);

    break;
  }
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
