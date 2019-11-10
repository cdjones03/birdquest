#include <LevelManager.hpp>
#include <SFML/Graphics.hpp>
#include <Screen.hpp>
#include <HumanView.hpp>
#include <tinyxml2.h>
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
  Screen screen0("../resources/xmlmaps/D_Entrance_simple.xml");
  curScreenString = "../resources/xmlmaps/D_Entrance_simple.xml";
  int tileWidth = screen0.getTileWidth();
  int tileHeight = screen0.getTileHeight();
  int width = screen0.getWidth();
  int height = screen0.getHeight();
  const char* tileset = screen0.getTileset();
  curSprites = screen0.getSprites();

  section1[0] = "../resources/xmlmaps/D_Entrance_simple.xml";
  //section1[1] = "../resources/xmlmaps/Left_1.xml";
  section1[1] = "../resources/xmlmaps/Sec1Scr1.xml";
  section1[2] = "../resources/xmlmaps/Left_2.xml";
  section1[3] = "../resources/xmlmaps/Right_1.xml";
  section1[4] = "../resources/xmlmaps/Right_2.xml";
  section1[5] = "../resources/xmlmaps/Sec1Scr5.xml";
  section1[6] = "../resources/xmlmaps/Sec1Scr6.xml";
  section1[7] = "../resources/xmlmaps/Sec1Scr7.xml";
  section1[8] = "../resources/xmlmaps/Sec1Scr8.xml";
  section1[9] = "../resources/xmlmaps/Sec1Scr9.xml";
  section1[10] = "../resources/xmlmaps/Sec1Scr10.xml";

  if (!map.load(tileset, sf::Vector2u(tileWidth, tileHeight),
  screen0.getTileString(), width, height)) { //vector is size of each tile in pixel
      exit(0);
    }

  const char* name = "../resources/info.xml";
  docu.LoadFile(name);
  tinyxml2::XMLElement *curElement = docu.FirstChildElement("section1")->FirstChildElement("textures");
  int length = curElement->IntAttribute("length");
  curElement = curElement->FirstChildElement("texture1");

  //load textures for section
  int x1, y1, x2, y2;
  for(int x = 0; x < length; x++) {
    sf::Texture texture;
    x1 = curElement->IntAttribute("x1");
    y1 = curElement->IntAttribute("y1");
    x2 = curElement->IntAttribute("x2");
    y2 = curElement->IntAttribute("y2");
    if(!texture.loadFromFile(curElement->Attribute("name"), sf::IntRect(x1, y1, x2, y2))) {
      std::cout << " error " << std::endl;
    }
    curTextures.push_back(texture);
    curElement = curElement->NextSiblingElement();
  }

  //load textures for sprites for screen
  curElement = docu.FirstChildElement("section1")->FirstChildElement("Scr1Sec1")->FirstChildElement();
  int textNum;
  for(int x = 0; x < curSprites.size(); x++){
    textNum = curElement->IntAttribute("texture");
    curSprites.at(x).setTexture(curTextures.at(textNum));
    curElement = curElement->NextSiblingElement();
  }

  }



void LevelManager::drawMap(sf::RenderWindow &window) {
  window.draw(map);
  if(!curSprites.empty()) {
    for(int x = 0; x < curSprites.size(); x++) {
      window.draw(curSprites.at(x));
    }
  }
}

//needs to switch based on given direction
//should assume that collision checking has been already done
//void LevelManager::switchMap(HumanView::dir direction){

bool LevelManager::switchMap(int mapDir) {

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

    break;

    case 3 :
    newMap = curScreen.getRightScreen();

    break;
  }

  if(newMap == -1) { //no room next to; won't switch map
    return false;
  }

  if(newMap == 1) {

  }


  const char* newScreenString = section1[newMap];

  Screen newScreen(newScreenString);
  int curTileWidth = newScreen.getTileWidth();
  int curTileHeight =  newScreen.getTileHeight();
  int curWidth = newScreen.getWidth();
  int curHeight = newScreen.getHeight();
  const char* curTileset = newScreen.getTileset();
  curSprites = newScreen.getSprites();

  if (!map.load(curTileset, sf::Vector2u(curTileWidth, curTileHeight),
  newScreen.getTileString(), curWidth, curHeight)) { //vector is size of each tile in pixel
      exit(0);
    }

  curScreenString = newScreenString;

  return true;
}


TileMap LevelManager::getMap(){
  return map;
}
