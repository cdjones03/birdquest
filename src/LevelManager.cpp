#include <tinyxml2.h>
#include <LevelManager.hpp>
#include <SFML/Graphics.hpp>
#include <Screen.hpp>
#include <HumanView.hpp>
#include <iostream>

/*

Should make an array of screens per section of temple

*/

LevelManager::LevelManager(){

  //Screen Sec0Screen0;

  //loadLevels();
}

//should be done once per branch of temple; total of 3 (?) times
void LevelManager::loadLevels() {

  // create the tilemap from the level definition
  Screen screen0("../resources/HubScreen.xml");
  curScreenString = "../resources/HubScreen.xml";
  int tileWidth = screen0.getTileWidth();
  int tileHeight = screen0.getTileHeight();
  int width = screen0.getWidth();
  int height = screen0.getHeight();
  const char* tileset = screen0.getTileset();

  section1[0] = "../resources/HubScreen.xml";
  section1[1] = "../resources/Sec1Scr1.xml";
  section1[2] = "../resources/Sec1Scr2.xml";
  section1[3] = "../resources/Sec1Scr3.xml";
  section1[4] = "../resources/Sec1Scr4.xml";
  section1[5] = "../resources/Sec1Scr5.xml";

  if (!map.load(tileset, sf::Vector2u(tileWidth, tileHeight),
  screen0.getTileString(), width, height)) { //vector is size of each tile in pixel
      exit(0);
    }
  }

void LevelManager::drawMap(sf::RenderWindow &window) {
  window.draw(map);
}


//needs to switch based on given direction
//should assume that collision checking has been already done
//void LevelManager::switchMap(HumanView::dir direction){

void LevelManager::switchMap(int mapDir) {

  int newMap;

  Screen curScreen(curScreenString);

  switch(mapDir) {

    case 0 :
    newMap = curScreen.getUpScreen();

    break;

    case 1 :
    newMap = curScreen.getDownScreen();

    break;

    case 2 :
    newMap = curScreen.getLeftScreen();
    std::cout << "left " << curScreen.getLeftScreen() << std::endl;

    break;

    case 3 :
    newMap = curScreen.getRightScreen();

    break;
  }


  const char* newScreenString = section1[newMap];
  std::cout << "newstring " << newScreenString << " newmap " << newMap << std::endl;

  Screen newScreen(newScreenString);
  int curTileWidth = newScreen.getTileWidth();
  int curTileHeight =  newScreen.getTileHeight();
  int curWidth = newScreen.getWidth();
  int curHeight = newScreen.getHeight();
  const char* curTileset = newScreen.getTileset();

  if (!map.load(curTileset, sf::Vector2u(curTileWidth, curTileHeight),
  newScreen.getTileString(), curWidth, curHeight)) { //vector is size of each tile in pixel
      exit(0);
    }

  curScreenString = newScreenString;
}


TileMap LevelManager::getMap(){
  return map;
}
