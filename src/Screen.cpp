#include <Screen.hpp>
#include <iostream>

/*
screen value of -1 = can't go that way
*/

Screen::Screen() {

}

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
