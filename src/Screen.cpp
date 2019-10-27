#include <Screen.hpp>
#include <iostream>

Screen::Screen() {

}

Screen::Screen(const char* fileName) {
  doc.LoadFile(fileName);
  tileString = doc.FirstChildElement("map")->FirstChildElement("layer")->FirstChildElement("data")->GetText();
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
  return doc.FirstChildElement("map")->FirstChildElement("tileset")->Attribute("source");
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

int Screen::getDonwScreen() {
  return downScreen;
}