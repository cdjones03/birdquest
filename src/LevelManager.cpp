#include <tinyxml2.h>
#include <LevelManager.hpp>
#include <SFML/Graphics.hpp>

LevelManager::LevelManager(){
  //loadLevels();
}

void LevelManager::loadLevels() {

  // create the tilemap from the level definition
  doc1.LoadFile("../resources/SampleMap.xml");
  tinymap1 = doc1.FirstChildElement("map")->FirstChildElement("layer")->FirstChildElement("data")->GetText();

  doc2.LoadFile("../resources/SampleMap2.xml");
  tinymap2 = doc2.FirstChildElement("map")->FirstChildElement("layer")->FirstChildElement("data")->GetText();

  if (!map.load("../resources/tileset.png", sf::Vector2u(32, 32),
  tinymap1, doc1.FirstChildElement("map")->IntAttribute("width"),
  doc1.FirstChildElement("map")->IntAttribute("height"))) { //vector is size of each tile in pixel
      exit(0);
    }
  }

void LevelManager::drawMap(sf::RenderWindow &window) {
  window.draw(map);
}

void LevelManager::switchMap(int mapVal){
  if(mapVal == 1){
    if (!map.load("../resources/tileset.png", sf::Vector2u(32, 32),
    tinymap1, doc1.FirstChildElement("map")->IntAttribute("width"),
    doc1.FirstChildElement("map")->IntAttribute("height"))) { //vector is size of each tile in pixel
        exit(0);
      }
    }
  else if(mapVal == 2){
    if (!map.load("../resources/tileset.png", sf::Vector2u(32, 32),
    tinymap2, doc2.FirstChildElement("map")->IntAttribute("width"),
    doc2.FirstChildElement("map")->IntAttribute("height"))) { //vector is size of each tile in pixel
        exit(0);
      }
  }
}

TileMap LevelManager::getMap(){
  return map;
}
