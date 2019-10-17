#include <SFML/Graphics.hpp>
#include <TileMap.hpp>
#include <iostream>
#include <tinyxml2.h>

using namespace std;

int main(int argc, char** argv)
{
  const int windowTileWidth = 30;
  const int windowTileHeight = 30;
  const int windowPixelWidth = windowTileWidth*32;
  const int windowPixelHeight = windowTileHeight*32;

  // create main window; Style::Close disables resizing
  //The game should be played in an 800x600 window. Changing the size of the window sh
  sf::RenderWindow App(sf::VideoMode(windowPixelWidth, windowPixelWidth, 32), "BirdQuest!");//, sf::Style::Close);
  App.setFramerateLimit(60);

  // create the tilemap from the level definition
  tinyxml2::XMLDocument doc;
  doc.LoadFile("../SampleMap.xml");
  const char* tinymap = doc.FirstChildElement("map")->FirstChildElement("layer")->FirstChildElement("data")->GetText();

  tinyxml2::XMLDocument doc2;
  doc2.LoadFile("../SampleMap2.xml");
  const char* tinymap2 = doc2.FirstChildElement("map")->FirstChildElement("layer")->FirstChildElement("data")->GetText();

  TileMap map;
  if (!map.load("../include/tileset.png", sf::Vector2u(32, 32),
  tinymap, doc.FirstChildElement("map")->IntAttribute("width"),
  doc.FirstChildElement("map")->IntAttribute("height"))) //vector is size of each tile in pixel
      return -1;


  sf::Clock clock;
  int deltaMs;

  sf::Texture birdTexture;
  if(!birdTexture.loadFromFile("../resources/birdsprite.png")){
    return -1;
  }
  sf::Sprite birdSprite;
  birdSprite.setTexture(birdTexture);

  // start main loop
  while(App.isOpen())
  {
      deltaMs = clock.getElapsedTime().asMilliseconds();
      // process events
      sf::Event Event;
      while(App.pollEvent(Event))
      {
        // Exit
        if(Event.type == sf::Event::Closed){
          App.close();
        }
        //Handle input, delegate to HumanView.cpp
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
          if(birdSprite.getPosition().y >= 32){
          birdSprite.move(0, -32);
          continue;
        }
          else {
            map.load("../include/tileset.png", sf::Vector2u(32, 32),
            tinymap2, doc2.FirstChildElement("map")->IntAttribute("width"),
            doc2.FirstChildElement("map")->IntAttribute("height"));
            birdSprite.setPosition(birdSprite.getPosition().x, windowPixelHeight-32);
          }
        }

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
          if(birdSprite.getPosition().y < windowPixelHeight-32){
            birdSprite.move(0, 32);
            continue;
        }
          else {
            map.load("../include/tileset.png", sf::Vector2u(32, 32),
            tinymap, doc.FirstChildElement("map")->IntAttribute("width"),
            doc.FirstChildElement("map")->IntAttribute("height"));
            birdSprite.setPosition(birdSprite.getPosition().x, 0);
          }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && birdSprite.getPosition().x < windowPixelWidth-32){
          birdSprite.move(32, 0);
          continue;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && birdSprite.getPosition().x >= 32){
          birdSprite.move(-32, 0);
          continue;
        }
      }

      //Display
      App.clear(sf::Color::Black);
      App.draw(map);
      App.draw(birdSprite);
      App.display();
    }


  // Done.
  return 0;
}
