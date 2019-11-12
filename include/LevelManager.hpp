#ifndef LEVELMANAGER_HPP_INCLUDED
#define LEVELMANAGER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <TileMap.hpp>
#include <tinyxml2.h>
#include <Screen.hpp>
#include <HumanView.hpp>
#include <string>
//#include <HumanView.fwd.hpp>
//#include <LevelManager.fwd.hpp>

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

private:

  const char* curScreenString;
  const char* section1[12];
  TileMap map;
  std::vector<sf::Sprite> curSprites;
  std::vector<sf::Texture> curTextures;
  tinyxml2::XMLDocument docu;

};

#endif
