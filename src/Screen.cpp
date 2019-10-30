#include <Screen.hpp>
#include <iostream>

Screen::Screen() {

}

Screen::Screen(const char* fileName) {
  doc.LoadFile(fileName);
  tileString = doc.FirstChildElement("map")->FirstChildElement("layer")->FirstChildElement("data")->GetText();
  upScreen = doc.FirstChildElement("map")->IntAttribute("upScreen");
  downScreen = doc.FirstChildElement("map")->IntAttribute("downScreen");
  leftScreen = doc.FirstChildElement("map")->IntAttribute("leftScreen");
  rightScreen = doc.FirstChildElement("map")->IntAttribute("rightScreen");
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
