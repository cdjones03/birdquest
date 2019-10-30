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

private:

  const char* curScreenString;
  const char* section1[12];
  TileMap map;

};

#endif
