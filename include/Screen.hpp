#ifndef SCREEN_HPP_INCLUDED
#define SCREEN_HPP_INCLUDED

#include <tinyxml2.h>

class Screen {

public:

  Screen();
  Screen(const char* fileName);
  void loadXMLFile();

  int getTileWidth();
  int getTileHeight();
  int getWidth();
  int getHeight();
  const char* getTileset();

  int getRightScreen();
  int getLeftScreen();
  int getUpScreen();
  int getDonwScreen();



private:

  tinyxml2::XMLDocument doc; //actual xml file
  const char* tileString; //string to array with tile values for screen
  int width;
  int height;

  int section;
  int screenNum;

  int leftScreen; //value of map connected by going left; -1 if none
  int rightScreen;
  int upScreen;
  int downScreen;


};

#endif
