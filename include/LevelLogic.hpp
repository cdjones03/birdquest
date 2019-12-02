#ifndef LEVELLOGIC_HPP_INCLUDED
#define LEVELLOGIC_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <HumanView.hpp>
#include <LevelManager.hpp>

class LevelLogic {

private:

  //bool checkForRealKey(int j);
  const int moveVal = 16;
  //const static int floorPuz [4] = {21,17,19,23}; //answer to the puzzle: x-value for switches 3,1,2,4
  static std::vector<int> buttonArray; //array for given answer
  //const static int max_length = 4; //max number of button pushes

public:

  LevelLogic();
  static bool moveObject(sf::Sprite &thisSprite, int spriteNum, HumanView::Dir direction, LevelManager &thisLevelManager);
  static bool checkTileCollisionForPlayer(int thisXPos, int thisYPos, HumanView::Dir direction, LevelManager &thisLevelManager);
  static bool checkTileCollision(int thisXPos, int thisYPos, HumanView::Dir direction, LevelManager &thisLevelManager);
  static bool checkSpriteCollision(int thisXPos, int thisYPos, HumanView::Dir direction, LevelManager &thisLevelManager, sf::RenderWindow& thisApp);

  static bool checkForIceTile(int thisXPos, int thisYPos, HumanView::Dir direction, LevelManager &thisLevelManager);
};

#endif
