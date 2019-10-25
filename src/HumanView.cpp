#include <SFML/Graphics.hpp>
#include <HumanView.hpp>



HumanView::HumanView(){

}

void HumanView::move(sf::Sprite &thisSprite, Dir direction, LevelManager &thisLevelManager){
  switch(direction) {
    case UP :
    if(thisSprite.getPosition().y >= moveVal)
      thisSprite.move(0, -moveVal);
    else if(thisSprite.getPosition().y <= moveVal){
      thisLevelManager.switchMap(2);
      thisSprite.setPosition(thisSprite.getPosition().x, windowPixelHeight-32);
    }
      break;

    case DOWN :
    if(thisSprite.getPosition().y < windowPixelHeight-moveVal)
      thisSprite.move(0, moveVal);
    else {
      thisLevelManager.switchMap(1);
      thisSprite.setPosition(thisSprite.getPosition().x, 0);
    }
      break;

    case LEFT :
      if(thisSprite.getPosition().x >= moveVal)
      thisSprite.move(-moveVal, 0);
      break;

    case RIGHT :
      if(thisSprite.getPosition().x < windowPixelWidth-moveVal){
        if(thisLevelManager.getMap().getTexCoord(thisSprite.getPosition().x+32, thisSprite.getPosition().y) != 32){//if moving right, and tile to right is water, won't allow movement
          thisSprite.move(moveVal, 0);
        }
      }
      break;

  }
}
