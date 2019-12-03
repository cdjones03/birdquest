#ifndef LEVELMANAGER_HPP_INCLUDED
#define LEVELMANAGER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <TileMap.hpp>
#include <tinyxml2.h>
#include <Screen.hpp>
#include <HumanView.hpp>
#include <string>

class LevelManager {

public:

  LevelManager();
  void loadLevels();
  void drawMap(sf::RenderWindow &window); //will be gone once HumanView is made
  bool switchMap(int mapDir);
  TileMap getMap();
  std::vector<sf::Sprite> getSprites();
  std::vector<sf::Texture> getTextures();
  void moveSprite(int spriteNum, int moveX, int moveY);
  int updateSprite(int x, int y);
  int getTexture(int num);
  void setButtonGreen(int spriteNum, int textNum);
  void resetButtons();
  int getCurrentMap();
  void resetToStart();

  void switchPuzzleMap();
  void deleteSprite();

  void foundFirstKey();
  void foundSecondKey();
  void foundThirdKey();

  void beatFirstSection();
  void beatSecondSection();
  void beatThirdSection();

  sf::Texture getEnemyTexture(int textureNum);

private:

  const char* curScreenString;
  const char* section1[35];
  TileMap map;
  std::vector<sf::Sprite> curSprites;
  std::vector<sf::Texture> curTextures;
  tinyxml2::XMLDocument org_doc;
  tinyxml2::XMLDocument cur_doc;
  int velocity = 16;
  std::vector<int> textNums;
  int curMap;

  bool firstSectionDone;
  bool secondSectionDone;
  bool thirdSectionDone;

};

#endif
