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
  int getCurrentMap();

private:

  const char* curScreenString;
  const char* section1[34];
  TileMap map;
  std::vector<sf::Sprite> curSprites;
  std::vector<sf::Texture> curTextures;
  tinyxml2::XMLDocument docu;
  int velocity = 16;
  std::vector<int> textNums;
  int curMap;

};

#endif
