#include <Screen.hpp>
#include <iostream>
#include <tinyxml2.h>
#include <string>

/*
screen value of -1 = can't go that way
*/

Screen::Screen() {

}

//screen of temple, has tiles and sprites
Screen::Screen(const char* fileName) {

  doc.LoadFile(fileName);

  tinyxml2::XMLElement *curElement = doc.FirstChildElement("map")->FirstChildElement("properties")->FirstChildElement("property");

  tileSetImage = curElement->Attribute("value");

  curElement = curElement->NextSibling()->ToElement();
  upScreen = curElement->IntAttribute("value");

  curElement = curElement->NextSibling()->ToElement();
  downScreen = curElement->IntAttribute("value");

  curElement = curElement->NextSibling()->ToElement();
  leftScreen = curElement->IntAttribute("value");

  curElement = curElement->NextSibling()->ToElement();
  rightScreen = curElement->IntAttribute("value");

  tileString = doc.FirstChildElement("map")->FirstChildElement("layer")->FirstChildElement("data")->GetText();

  //find sprites for screen in info.xml
  std::string str { fileName };
  std::string str2 ("Sec");
  std::size_t found = str.find(str2);
  std::string newStr = str.substr(found);
	const char *c = newStr.c_str(); //name of file without path
  infoDoc.LoadFile("../resources/cur_info.xml");
  curElement = infoDoc.FirstChildElement("section1")->FirstChildElement(c)->FirstChildElement();
  if(curElement != NULL) {
    for(tinyxml2::XMLElement* e = curElement; e != NULL; e = e->NextSiblingElement()) {
      int x = 16*e->IntAttribute("positionx");
      int y = 16*e->IntAttribute("positiony");
      sf::Sprite newSprite;
      newSprite.setPosition(x, y);
      if(e->IntAttribute("alive") == 0) {
        spriteArr.push_back(newSprite);
      }
    }
  }
}

Screen::~Screen() = default;

Screen::Screen(const Screen &s) {
}

Screen& Screen::operator= (const Screen &s) {
  return *this;
}

void Screen::loadXMLFile() {

}

int Screen::getTileWidth() {
  return doc.FirstChildElement("map")->IntAttribute("tilewidth");
}

int Screen::getTileHeight() {
  return doc.FirstChildElement("map")->IntAttribute("tileheight");
}

int Screen::getWidth() {
  return doc.FirstChildElement("map")->IntAttribute("width");
}

int Screen::getHeight() {
  return doc.FirstChildElement("map")->IntAttribute("height");
}

const char* Screen::getTileset() {
  return doc.FirstChildElement("map")->FirstChildElement("properties")->FirstChildElement("property")->Attribute("value");
}

const char* Screen::getTileString(){
  return tileString;
}

int Screen::getRightScreen() {
  return rightScreen;
}

int Screen::getLeftScreen() {
  return leftScreen;
}

int Screen::getUpScreen() {
  return upScreen;
}

int Screen::getDownScreen() {
  return downScreen;
}

std::vector<sf::Sprite> Screen::getSprites() {
  return spriteArr;
}
