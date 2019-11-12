#ifndef HUMANVIEW_HPP_INCLUDED
#define HUMANVIEW_HPP_INCLUDED

#include <LevelManager.hpp>
#include <LevelManager.fwd.hpp>
//#include <HumanView.fwd.hpp>


class HumanView {

public:

  HumanView();
  enum Dir { UP=0, DOWN=1, LEFT=2, RIGHT=3 };

  void movePlayer(sf::Sprite &thisSprite, Dir direction, LevelManager &thisLevelManager);
  bool moveObject(sf::Sprite &thisSprite, int spriteNum, Dir direction, LevelManager &thisLevelManager);
  bool checkTileCollisionForPlayer(int thisXPos, int thisYPos, Dir direction, LevelManager &thisLevelManager);
  bool checkTileCollision(int thisXPos, int thisYPos, Dir direction, LevelManager &thisLevelManager);
  bool checkSpriteCollision(int thisXPos, int thisYPos, Dir direction, LevelManager &thisLevelManager);

private:

  const int windowTileWidth = 16;
  const int windowTileHeight = 16;
  const int windowPixelWidth = windowTileWidth*40;
  const int windowPixelHeight = windowTileHeight*40;
  const int moveVal = 16;  //change to 16!!


};

#endif
