#include <LevelLogic.hpp>
#include <HumanView.hpp>
#include <LevelManager.hpp>
#include <iostream>
#include "../include/Inventory.h"

std::vector<int> LevelLogic::buttonArray;

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
  int checkX;
  int checkY;
  bool ret = true;
  switch(direction){
    case HumanView::UP :
      checkX = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 16).x;
      checkY = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 16).y;
      break;
    case HumanView::DOWN :
      checkX = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos + 16).x;
      checkY = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos + 16).y;
      break;
    case HumanView::LEFT :
      checkX = thisLevelManager.getMap().getTexCoord(thisXPos-16, thisYPos).x;
      checkY = thisLevelManager.getMap().getTexCoord(thisXPos-16, thisYPos).y;
      break;
    case HumanView::RIGHT :
      checkX = thisLevelManager.getMap().getTexCoord(thisXPos+16, thisYPos).x;
      checkY = thisLevelManager.getMap().getTexCoord(thisXPos+16, thisYPos).y;
    }


  if(checkX < 0 && checkY < 0) { // out of bounds! should not be needed
        ret = false;
    }


  //section 1 no walk tiles
  if(checkX == 512 && checkY == 192) {
        ret = false;
    }
  if(checkX == 544 && checkY == 48) {
        ret = false;
    }
  if(checkX == 640 && checkY == 176) {
        ret = false;
    }
  if(checkX == 544 && checkY == 160) {
        ret = false;
    }
  if(checkX == 624 && checkY == 176) {
        ret = false;
    }
  if(checkX == 144 && checkY == 192) { //section 1 outer tile
        ret = false;
    }
  if(checkX == 144 && checkY == 48) { //section1 wall brick
        ret = false;
    }
  if(checkX == 32 && checkY == 48) { //section1 wall brick
        ret = false;
    }
  if(checkX == 176 && checkY == 80) { //section 1 sewer pipe
        ret = false;
    }
  if(checkX == 192 && checkY == 80) { //section 1 sewer pipe
        ret = false;
    }
  if(checkX == 208 && checkY == 80) { //section 1 sewer pipe
        ret = false;
    }
  if(checkX == 0 && checkY == 144) { //section 1 water with white
        ret = false;
    }
  if(checkX == 112 && checkY == 176) { //section 1 water with white
        ret = false;
    }
  if(checkX == 128 && checkY == 176) { //section 1 water with white
        ret = false;
    }

  if(checkX == 192 && checkY == 336) { //section 1 boss door
        ret = false;
    }
  if(checkX == 208 && checkY == 336) { //section 1 boss door
        ret = false;
    }

  if(checkX == 32 && checkY == 64) { //section 1 brick with line
        ret = false;
    }
  if(checkX == 0 && checkY == 144) { //section 1 water corner
        ret = false;
    }
  if(checkX == 176 && checkY == 144) { //section 1 sewer tile
        ret = false;
    }
  if(checkX == 192 && checkY == 144) { //section 1 sewer tile
        ret = false;
    }
  if(checkX == 208 && checkY == 144) { //section 1 sewer tile
        ret = false;
    }
  if(checkX == 176 && checkY == 160) { //section1 water
        ret = false;
    }
  if(checkX == 208 && checkY == 160) { //section 1 water
        ret = false;
    }
  if(checkX == 32 && checkY == 48) { //section 1 fire
        ret = false;
    }
  if(checkX == 64 && checkY == 80) { //section1 arch
        ret = false;
    }
  if(checkX == 80 && checkY == 80) { //section 1 arch
        ret = false;
    }
  if(checkX == 96 && checkY == 80) { //section 1 arch
        ret = false;
    }
  if(checkX == 64 && checkY == 96) { //section 1 water out
        ret = false;
    }
  if(checkX == 64 && checkY == 144) { //section 1 water out
        ret = false;
    }
  if(checkX == 96 && checkY == 96) { //section 1 water out
        ret = false;
    }
  if(checkX == 96 && checkY == 144) { //section 1 water out
        ret = false;
    }

  //section 2 no walk tiles


  if(checkX == 288 && checkY == 224) { //lava
        ret = false;
    }

  if(checkX == 384 && checkY == 208) { //lava with fire
        ret = false;
    }
  if(checkX == 400 && checkY == 304) { //lava with fire
        ret = false;
    }
  if(checkX == 256 && checkY == 240) { //lava with fire
        ret = false;
    }
  if(checkX == 256 && checkY == 272) { //lava with fire
        ret = false;
    }
  if(checkX == 272 && checkY == 240) { //lava with fire
        ret = false;
    }
  if(checkX == 496 && checkY == 16) { //section2 light brick
        ret = false;
    }
  if(checkX == 496 && checkY == 32) { //section2 brick
        ret = false;
    }
  if(checkX == 496 && checkY == 48) { //section 2 brick
        ret = false;
    }
  if(checkX == 320 && checkY == 64) { //section 2 fire
        ret = false;
    }
  if(checkX == 272 && checkY == 224) { //section 2 arch
        ret = false;
    }
  if(checkX == 272 && checkY == 208) {
        ret = false;
    }
  if(checkX == 304 && checkY == 208) {
        ret = false;
    }
  if(checkX == 288 && checkY == 208) {
        ret = false;
    }

  if(checkX == 448 && checkY == 336) { //section 2 boss door
        ret = false;
    }
  if(checkX == 464 && checkY == 336) { //section 2 boss door
        ret = false;
    }

  if(checkX == 352 && checkY == 64) { //section 2 fire brick
        ret = false;
    }
  if(checkX == 320 && checkY == 64) { //section 2 fire brick
        ret = false;
    }
  if(checkX == 288 && checkY == 224) { //lava fire
        ret = false;
    }
  if(checkX == 496 && checkY == 32) { //brick
        ret = false;
    }

  //section 3 no walk tiles

  if(checkX == 528 && checkY == 160) { //arch
        ret = false;
    }
  if(checkX == 528 && checkY == 176) {
        ret = false;
    }
  if(checkX == 560 && checkY == 176) {
        ret = false;
    }
  if(checkX == 528 && checkY == 192) { //water with dark spot
        ret = false;
    }
  if(checkX == 560 && checkY == 176) { //arch
        ret = false;
    }
  if(checkX == 650 && checkY == 160) {
        ret = false;
    }
  if(checkX == 704 && checkY == 336) { //section 1 outer tile
        ret = false;
    }
  if(checkX == 720 && checkY == 336) { //section1 wall brick
        ret = false;
    }


  if(checkX == 208 && checkY == 32) { //final boss door
        ret = false;
    }
  if(checkX == 224 && checkY == 32) { //final boss door
        ret = false;
    }




  return ret;
}

//true = no collision; i.e. not an empty tile (collision of tiles in tilset)
//collision for sprites -- not player
bool LevelLogic::checkTileCollision(int thisXPos, int thisYPos, HumanView::Dir direction, LevelManager &thisLevelManager){
  //16, 80 is circle tile
  bool ret = false;
  int checkX;
  int checkY;
  switch(direction){
    case HumanView::UP : {
      checkX = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 16).x;
      checkY = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 16).y;
      break;
    }
    case HumanView::DOWN : {
      checkX = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos+16).x;
      checkY = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos+16).y;
      break;
    }
    case HumanView::LEFT : {
      checkX = thisLevelManager.getMap().getTexCoord(thisXPos-16, thisYPos).x;
      checkY = thisLevelManager.getMap().getTexCoord(thisXPos-16, thisYPos).y;
      break;
    }
    case HumanView::RIGHT : {
      checkX = thisLevelManager.getMap().getTexCoord(thisXPos+16, thisYPos).x;
      checkY = thisLevelManager.getMap().getTexCoord(thisXPos+16, thisYPos).y;
      break;
    }
  }

    if(checkX >= 0 && checkY >= 0) { //check if tile is empty
      ret = true;
    }
    if(checkX == 16 && checkY == 80) {
      ret = false;
    }
    if(checkX == 288 && checkY == 224) {
      ret = false;
    }


  return ret;
}

//collision of current screen's sprites
bool LevelLogic::checkSpriteCollision(int thisXPos, int thisYPos, HumanView::Dir direction, LevelManager &thisLevelManager, sf::RenderWindow& thisApp, Inventory &thisInventory){
  std::vector<sf::Sprite> checkSprites = thisLevelManager.getSprites();
  bool thisRet = true;
  int floorPuz [4] = {23,19,21,25}; //answer to the puzzle: x-value for switches 3,1,2,4
  int max_length = 4; //max number of button pushes

  switch(direction){

    case HumanView::UP :
      if(!checkSprites.empty()) {
        for(int x = 0; x < checkSprites.size(); x++) {
           //sprite to tile above

		  if(thisXPos == checkSprites.at(x).getPosition().x && thisYPos-16 == checkSprites.at(x).getPosition().y) {
            if(checkForKey(x, thisLevelManager)) {
              break;
            }

      			if (thisLevelManager.getTexture(x) == 3) {  //3 = texture number for the button
              int what = checkSprites.at(x).getPosition().x/16;
      				buttonArray.push_back(what);  //supposed to push current x onto array
      				//print statements just for testing
              for (int i = 0; i < buttonArray.size(); i++) {
      		         std::cout << "button " << i << " " << buttonArray.at(i) << std::endl;
      	      }
              thisLevelManager.setButtonGreen(x, 4);
      				if(buttonArray.size() == max_length) {
      					for (int i = 0; i < 4; i++){ //loop thru both arrays to compare
      						if (buttonArray.at(i) != floorPuz[i]){
      							std::cout << "Wrong" << std::endl;
                    buttonArray.clear();
                    thisLevelManager.resetButtons();
                    break;
      							//reset puzzle code here
      						}
      						else{
      							std::cout << "Solved!" << std::endl;
                    thisLevelManager.switchPuzzleMap();
                    thisApp.clear(sf::Color::Black);
                    thisLevelManager.drawMap(thisApp);
                    thisApp.display();
                    break;
      							//solved, remove lava from screen here
      						}
      					}
      				}

              thisRet = false;
              break;
			        }
            if(thisLevelManager.getTexture(x) == 4) {
              thisRet = false;
              break;
            }
            if(thisLevelManager.getTexture(x) == 6) { //potion
              thisRet = true; //can change to true once key can be added to inventory
              thisInventory.addItem("Potion");
              thisLevelManager.deleteSprite();
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
            if(checkForKey(x, thisLevelManager)) {
              break;
            }
            if(thisLevelManager.getTexture(x) == 3) {
              thisRet = false;
              break;
            }
            if(thisLevelManager.getTexture(x) == 4) {
              thisRet = false;
              break;
            }
            if(thisLevelManager.getTexture(x) == 6) { //potion
              thisRet = true; //can change to true once key can be added to inventory
              thisInventory.addItem("Potion");
              thisLevelManager.deleteSprite();
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
            if(checkForKey(x, thisLevelManager)) {
              break;
            }
            if(thisLevelManager.getTexture(x) == 3) {
              thisRet = false;
              break;
            }
            if(thisLevelManager.getTexture(x) == 4) {
              thisRet = false;
              break;
            }
            if(thisLevelManager.getTexture(x) == 6) { //potion
              thisRet = true; //can change to true once key can be added to inventory
              thisInventory.addItem("Potion");
              thisLevelManager.deleteSprite();
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
            if(checkForKey(x, thisLevelManager)) {
              break;
            }
            if(thisLevelManager.getTexture(x) == 3) {
              thisRet = false;
              break;
            }
            if(thisLevelManager.getTexture(x) == 4) {
              thisRet = false;
              break;
            }
            if(thisLevelManager.getTexture(x) == 6) { //potion
              thisRet = true; //can change to true once key can be added to inventory
              thisInventory.addItem("Potion");
              thisLevelManager.deleteSprite();
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

bool LevelLogic::checkForIceTile(int thisXPos, int thisYPos, HumanView::Dir direction, LevelManager &thisLevelManager) {
  int checkX;
  int checkY;
  switch (direction) {
    case HumanView::UP :
      checkX = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 16).x;
      checkY = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos - 16).y;
      break;
    case HumanView::DOWN :
      checkX = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos + 16).x;
      checkY = thisLevelManager.getMap().getTexCoord(thisXPos, thisYPos + 16).y;
      break;
    case HumanView::LEFT :
      checkX = thisLevelManager.getMap().getTexCoord(thisXPos - 16, thisYPos).x;
      checkY = thisLevelManager.getMap().getTexCoord(thisXPos - 16, thisYPos).y;
      break;
    case HumanView::RIGHT :
      checkX = thisLevelManager.getMap().getTexCoord(thisXPos + 16, thisYPos).x;
      checkY = thisLevelManager.getMap().getTexCoord(thisXPos + 16, thisYPos).y;
      break;
  }
  //std::cout << " x " << checkX << " " << checkY << std::endl;
  if(checkX == 576 && checkY == 192) { //ice tile texture
    return true;
  }
return false;
}

void LevelLogic::addKey(LevelManager &thisLevelManager){
  thisLevelManager.deleteSprite();
  int map = thisLevelManager.getCurrentMap();
  if(map >= 0 && map <= 10) {
    thisLevelManager.foundFirstKey();
  }
  else if(map >= 11 && map <= 22) {
    thisLevelManager.foundSecondKey();
  }
  else if(map >= 23 && map <= 33) {
    thisLevelManager.foundThirdKey();
  }
  else if(map == 34) {

  }
}

bool LevelLogic::checkForKey(int checkNum, LevelManager &thisLevelManager) {
  if(thisLevelManager.getTexture(checkNum) == 2) { //real key!
    addKey(thisLevelManager);
    return true;
  }
  return false;
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
