#ifndef HUMANVIEW_HPP_INCLUDED
#define HUMANVIEW_HPP_INCLUDED

#include <LevelManager.hpp>
#include <LevelManager.fwd.hpp>


class HumanView {

public:

  HumanView();
  enum Dir { UP=0, DOWN=1, LEFT=2, RIGHT=3 };

  void movePlayer(sf::Sprite &thisSprite, Dir direction, LevelManager &thisLevelManager);

private:

  const int windowTileWidth = 16;
  const int windowTileHeight = 16;
  const int windowPixelWidth = windowTileWidth*40;
  const int windowPixelHeight = windowTileHeight*40;
  const int moveVal = 16;  //change to 16!!
  //LevelLogic levelLogic;


};

#endif
