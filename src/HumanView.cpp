#include <SFML/Graphics.hpp>
#include <HumanView.hpp>
#include <iostream>



HumanView::HumanView(){

}

void HumanView::move(sf::Sprite &thisSprite, Dir direction, LevelManager &thisLevelManager){
  int x = thisSprite.getPosition().x;
  int y = thisSprite.getPosition().y;

  std::cout << y << std::endl;

  switch(direction) {
    case UP :
    if(y >= moveVal) {
      if (checkCollision(x, y, direction, thisLevelManager)) {
        thisSprite.move(0, -moveVal);
      }
    }
    else {
      if(y < moveVal) {
        thisLevelManager.switchMap(2);
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
        thisLevelManager.switchMap(2);
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
          thisLevelManager.switchMap(2);
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
          thisLevelManager.switchMap(2);
          thisSprite.setPosition(0, y);
        }
      }
      break;

  }
}

//true = no collision; i.e. not a water tile in tilset.png
bool HumanView::checkCollision(int thisXPos, int thisYPos, Dir direction, LevelManager &thisLevelManager){
  bool ret = false;
  switch(direction){
    case UP :

      if(thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 32) != 32)
        ret = true;

    break;

    case DOWN :

      if(thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos + 32) != 32)
        ret = true;

    break;

    case LEFT :

      if(thisLevelManager.getMap().getTexCoord(thisXPos - 32, thisYPos) != 32)
        ret = true;

    break;

    case RIGHT :

      if(thisLevelManager.getMap().getTexCoord(thisXPos + 32, thisYPos) != 32)
        ret = true;

    break;
  }

  return ret;
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
