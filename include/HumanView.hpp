#ifndef HUMANVIEW_HPP_INCLUDED
#define HUMANVIEW_HPP_INCLUDED

#include <LevelManager.hpp>
#include <LevelManager.fwd.hpp>
//#include <HumanView.fwd.hpp>


class HumanView {

public:

  HumanView();
  enum Dir { UP=0, DOWN=1, LEFT=2, RIGHT=3 };

  void move(sf::Sprite &thisSprite, Dir direction, LevelManager &thisLevelManager);
  bool checkCollision(int thisXPos, int thisYPos, Dir direction, LevelManager &thisLevelManager);

  int curScreen;

private:

  const int windowTileWidth = 20;
  const int windowTileHeight = 20;
  const int windowPixelWidth = windowTileWidth*32;
  const int windowPixelHeight = windowTileHeight*32;
  const int moveVal = 32;


};

#endif
