#ifndef LEVELLOGIC_HPP_INCLUDED
#define LEVELLOGIC_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <HumanView.hpp>
#include <LevelManager.hpp>

class LevelLogic {

private:

  //bool checkForRealKey(int j);

public:

  LevelLogic();
  static bool moveObject(sf::Sprite &thisSprite, int spriteNum, HumanView::Dir direction, LevelManager &thisLevelManager);
  static bool checkTileCollisionForPlayer(int thisXPos, int thisYPos, HumanView::Dir direction, LevelManager &thisLevelManager);
  static bool checkTileCollision(int thisXPos, int thisYPos, HumanView::Dir direction, LevelManager &thisLevelManager);
  static bool checkSpriteCollision(int thisXPos, int thisYPos, HumanView::Dir direction, LevelManager &thisLevelManager);

};

#endif
