#include <LevelManager.hpp>
#include <SFML/Graphics.hpp>
#include <Screen.hpp>
#include <HumanView.hpp>
#include <tinyxml2.h>
#include <iostream>
#include <LevelLogic.hpp>

/*

Should make an array of screens per section of temple

*/

LevelManager::LevelManager(){

}

//should be done once per branch of temple; total of 3 (?) times
void LevelManager::loadLevels() {

  // create the tilemap from the level definition
  curScreenString = "../resources/xmlmaps/Sec1Scr0_D_Entrance_simple.xml";
  curMap = 0;
  Screen screen0(curScreenString);
  int tileWidth = screen0.getTileWidth();
  int tileHeight = screen0.getTileHeight();
  int width = screen0.getWidth();
  int height = screen0.getHeight();
  const char* tileset = screen0.getTileset();
  curSprites = screen0.getSprites();

  section1[0] = curScreenString;
  section1[1] = "../resources/xmlmaps/Sec1Scr1.xml";
  section1[2] = "../resources/xmlmaps/Sec1Scr2.xml";
  section1[3] = "../resources/xmlmaps/Sec1Scr3.xml";
  section1[4] = "../resources/xmlmaps/Sec1Scr4.xml";
  section1[5] = "../resources/xmlmaps/Sec1Scr5.xml";
  section1[6] = "../resources/xmlmaps/Sec1Scr6.xml";
  section1[7] = "../resources/xmlmaps/Sec1Scr7.xml";
  section1[8] = "../resources/xmlmaps/Sec1Scr8.xml";
  section1[9] = "../resources/xmlmaps/Sec1Scr9.xml";
  section1[10] = "../resources/xmlmaps/Sec1Scr10.xml";

  section1[11] = "../resources/xmlmaps/Sec2Scr1.xml";
  section1[12] = "../resources/xmlmaps/Sec2Scr2.xml";
  section1[13] = "../resources/xmlmaps/Sec2Scr3.xml";
  section1[14] = "../resources/xmlmaps/Sec2Scr4.xml";
  section1[15] = "../resources/xmlmaps/Sec2Scr5.xml";
  section1[16] = "../resources/xmlmaps/Sec2Scr6.xml";
  section1[17] = "../resources/xmlmaps/Sec2Scr7.xml";
  section1[18] = "../resources/xmlmaps/Sec2Scr8.xml";
  section1[19] = "../resources/xmlmaps/Sec2Scr9.xml";
  section1[20] = "../resources/xmlmaps/Sec2Scr10.xml";
  section1[21] = "../resources/xmlmaps/Sec2Scr11.xml";
  section1[22] = "../resources/xmlmaps/Sec2Scr12.xml";

  section1[23] = "../resources/xmlmaps/Sec3Scr1.xml";
  section1[24] = "../resources/xmlmaps/Sec3Scr2.xml";
  section1[25] = "../resources/xmlmaps/Sec3Scr3.xml";
  section1[26] = "../resources/xmlmaps/Sec3Scr4.xml";
  section1[27] = "../resources/xmlmaps/Sec3Scr5.xml";
  section1[28] = "../resources/xmlmaps/Sec3Scr6.xml";
  section1[29] = "../resources/xmlmaps/Sec3Scr7.xml";
  section1[30] = "../resources/xmlmaps/Sec3Scr8.xml";
  section1[31] = "../resources/xmlmaps/Sec3Scr9.xml";
  section1[32] = "../resources/xmlmaps/Sec3Scr10.xml";
  section1[33] = "../resources/xmlmaps/Sec3Scr11.xml";

  //section1[34] = "../resources/xmlmaps/Sec4Scr1.xml"; //final boss room

  if (!map.load(tileset, sf::Vector2u(tileWidth, tileHeight),
  screen0.getTileString(), width, height)) { //vector is size of each tile in pixel
      exit(0);
    }

  //load textures for section
  const char* name = "../resources/info.xml";
  docu.LoadFile(name);
  tinyxml2::XMLElement *curElement = docu.FirstChildElement("section1")->FirstChildElement("textures");
  //int length = curElement->IntAttribute("length");
  curElement = curElement->FirstChildElement();

  int x1, y1, x2, y2;
  //cycle through textures in info.xml, add to array curTextures
  for(tinyxml2::XMLElement* e = curElement; e != NULL; e = e->NextSiblingElement()) {
    sf::Texture texture;
    x1 = e->IntAttribute("x1");
    y1 = e->IntAttribute("y1");
    x2 = e->IntAttribute("x2");
    y2 = e->IntAttribute("y2");
    if(!texture.loadFromFile(e->Attribute("name"), sf::IntRect(x1, y1, x2, y2))) {
      std::cout << " error " << std::endl;
    }
    curTextures.push_back(texture);
  }

  //load textures for sprites for initial screen
  curElement = docu.FirstChildElement("section1")->FirstChildElement("Sec1Scr0_D_Entrance_simple.xml")->FirstChildElement();
  int textNum;
  int x = 0;
  for(tinyxml2::XMLElement* e = curElement; e != NULL; e = e->NextSiblingElement()) {
    textNum = e->IntAttribute("texture");
    textNums.push_back(textNum);
    curSprites.at(x).setTexture(curTextures.at(textNum));
    x++;
  }

  }



void LevelManager::drawMap(sf::RenderWindow &window) {
  window.draw(map);
  if(!curSprites.empty()) {
    for(int x = 0; x < curSprites.size(); x++) {
      window.draw(curSprites.at(x)); //draw screen's sprites
    }
  }
}

//needs to switch based on given direction
//should assume that collision checking has been already done
//and loads new screen's sprites

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

  const char* newScreenString = section1[newMap];
  curMap = newMap;

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

  //load textures for new screen's sprites
  std::string str { newScreenString };
  std::string str2 ("Sec");
  std::size_t found = str.find(str2);
  std::string newStr = str.substr(found);
	const char *c = newStr.c_str(); //name of file without path

  textNums.clear();
  tinyxml2::XMLElement* curElement = docu.FirstChildElement("section1")->FirstChildElement(c)->FirstChildElement();
  int textNum;
  int x = 0;
  for(tinyxml2::XMLElement* e = curElement; e != NULL; e = e->NextSiblingElement()) {
    textNum = e->IntAttribute("texture");
    textNums.push_back(textNum);
    curSprites.at(x).setTexture(curTextures.at(textNum));
    x++;
  }

  curScreenString = newScreenString;

  return true;
}


TileMap LevelManager::getMap(){
  return map;
}

std::vector<sf::Sprite> LevelManager::getSprites() {
  return curSprites;
}

std::vector<sf::Texture> LevelManager::getTextures() {
  return curTextures;
}

void LevelManager::moveSprite(int spriteNum, int moveX, int moveY) {
  curSprites.at(spriteNum).move(moveX, moveY);
}

int LevelManager::updateSprite(int x, int y) {
  int ret = -1;
  if(!curSprites.empty()) {
    for(int count = 0; count < curSprites.size(); count++) {
      if(getTexture(count) == 7) {
        if(curSprites[count].getPosition().x > 25*16-16) {
          velocity *= -1;
        }
        else if(curSprites[count].getPosition().x < 14*16+16) {
          velocity *= -1;
        }

        if(curSprites[count].getPosition().x == x && curSprites[count].getPosition().y < y){
          std::cout << "I See You!" << std::endl;
          ret = 7;
        }

      }

      if(getTexture(count) == 9) {
        if(curSprites[count].getPosition().x > 25*16-16) {
          velocity *= -1;
        }
        else if(curSprites[count].getPosition().x < 14*16+16) {
          velocity *= -1;
        }

        if(curSprites[count].getPosition().x == x && curSprites[count].getPosition().y < y){
          std::cout << "I See You!" << std::endl;
          ret = 9;
        }
      }

      if(getTexture(count) == 11) {
        if(curSprites[count].getPosition().x > 25*16-16) {
          velocity *= -1;
        }
        else if(curSprites[count].getPosition().x < 14*16+16) {
          velocity *= -1;
        }

        if(curSprites[count].getPosition().x == x && curSprites[count].getPosition().y < y){
          std::cout << "I See You!" << std::endl;
          ret = 11;
        }
      }

      if(getTexture(count) == 13) {
        if(curSprites[count].getPosition().x > 25*16-16) {
          velocity *= -1;
        }
        else if(curSprites[count].getPosition().x < 14*16+16) {
          velocity *= -1;
        }

        if(curSprites[count].getPosition().x == x && curSprites[count].getPosition().y < y){
          std::cout << "I See You!" << std::endl;
          ret = 13;
        }
      }

        curSprites[count].move(velocity, 0);


    }
  }


  return ret;
}

int LevelManager::getTexture(int num) {
  return textNums[num];
}

int LevelManager::getCurrentMap() {
  return curMap;
}
