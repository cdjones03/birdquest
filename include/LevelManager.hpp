#ifndef LEVELMANAGER_HPP_INCLUDED
#define LEVELMANAGER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <TileMap.hpp>
#include <tinyxml2.h>
#include <Screen.hpp>

class LevelManager {

public:

  LevelManager();
  void loadLevels();
  void drawMap(sf::RenderWindow &window); //will be gone once HumanView is made
  void switchMap(int mapVal);
  TileMap getMap();

private:



  tinyxml2::XMLDocument doc1;
  const char* tinymap1;
  tinyxml2::XMLDocument doc2;
  const char* tinymap2;

  Screen section1[12];
  TileMap map;


};

#endif
