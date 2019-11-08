#ifndef HUMANVIEW_HPP_INCLUDED
#define HUMANVIEW_HPP_INCLUDED

#include <LevelManager.hpp>
#include <LevelManager.fwd.hpp>
//#include <HumanView.fwd.hpp>


class HumanView {

public:

  HumanView();
  enum Dir { UP=0, DOWN=1, LEFT=2, RIGHT=3 };

  void move(sf::Sprite &thisSprite, Dir direction, LevelManager &thisLevelManager, sf::Sprite &otherSprite);
  bool checkCollision(int thisXPos, int thisYPos, Dir direction, LevelManager &thisLevelManager);
  void checkSpriteCollision(Dir direction, LevelManager &thisLevelManager);

  int curScreen;

private:

  const int windowTileWidth = 16;
  const int windowTileHeight = 16;
  const int windowPixelWidth = windowTileWidth*40;
  const int windowPixelHeight = windowTileHeight*40;
  const int moveVal = 16;


};

#endif
