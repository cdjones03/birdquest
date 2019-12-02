#ifndef SCREEN_HPP_INCLUDED
#define SCREEN_HPP_INCLUDED

#include <tinyxml2.h>
#include <SFML/Graphics.hpp>

class Screen {

public:

  Screen();
  Screen(const char* fileName);
  Screen(const Screen &s);
  Screen& operator=(const Screen &s);
  virtual ~Screen();
  void loadXMLFile();

  int getTileWidth();
  int getTileHeight();
  int getWidth();
  int getHeight();
  const char* getTileset();
  const char* getTileString();

  int getRightScreen();
  int getLeftScreen();
  int getUpScreen();
  int getDownScreen();

  std::vector<sf::Sprite> getSprites();




private:

  tinyxml2::XMLDocument doc; //actual xml file
  tinyxml2::XMLDocument infoDoc;
  const char* tileSetImage; //string to array with tile values for screen
  const char* tileString;
  int width;
  int height;
  int section;

  int leftScreen; //value of map connected by going left; -1 if none
  int rightScreen;
  int upScreen;
  int downScreen;
  std::vector<sf::Sprite> spriteArr;

};

#endif
