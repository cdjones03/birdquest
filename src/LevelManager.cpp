#include <tinyxml2.h>
#include <LevelManager.hpp>
#include <SFML/Graphics.hpp>
#include <Screen.hpp>

/*

Should make an array of screens per section of temple

*/

LevelManager::LevelManager(){

  Screen Sec0Screen0;

  //loadLevels();
}

//should be done once per branch of temple; total of 3 (?) times
void LevelManager::loadLevels() {

  // create the tilemap from the level definition
  Screen screen1("../resources/SampleMap.xml");
  int tileWidth = screen1.getTileWidth();
  int tileHeight = screen1.getTileHeight();
  int width = screen1.getWidth();
  int height = screen1.getHeight();
  const char* tileset = screen1.getTileset();

  doc1.LoadFile("../resources/SampleMap.xml");
  tinymap1 = doc1.FirstChildElement("map")->FirstChildElement("layer")->FirstChildElement("data")->GetText();

  doc2.LoadFile("../resources/SampleMap2.xml");
  tinymap2 = doc2.FirstChildElement("map")->FirstChildElement("layer")->FirstChildElement("data")->GetText();

  if (!map.load(tileset, sf::Vector2u(tileWidth, tileHeight), tinymap1, width, height)) { //vector is size of each tile in pixel
      exit(0);
    }
  }

void LevelManager::drawMap(sf::RenderWindow &window) {
  window.draw(map);
}

//needs to switch based on given direction
//should assume that collision checking has been already done
void LevelManager::switchMap(int mapVal){
  if(mapVal == 1){
    if (!map.load("../resources/tileset.png", sf::Vector2u(32, 32),
    tinymap1, doc1.FirstChildElement("map")->IntAttribute("width"),
    doc1.FirstChildElement("map")->IntAttribute("height"))) { //vector is size of each tile in pixel
        exit(0);
      }
    }
  else if(mapVal == 2){
    if (!map.load("../resources/foresttiles.gif", sf::Vector2u(16, 16),
    tinymap2, doc2.FirstChildElement("map")->IntAttribute("width"),
    doc2.FirstChildElement("map")->IntAttribute("height"))) { //vector is size of each tile in pixel
        exit(0);
      }
  }
}

TileMap LevelManager::getMap(){
  return map;
}
