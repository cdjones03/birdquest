#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char** argv)
{
  // create main window; Style::Close disables resizing
  //The game should be played in an 800x600 window. Changing the size of the window sh
  sf::RenderWindow App(sf::VideoMode(800,600,32), "BirdQuest!", sf::Style::Close);
  App.setFramerateLimit(60);

  sf::Clock clock;
  int deltaMs;

  // start main loop
  //A well-defined game loop that coordinates game timing and event management (20%).
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
          continue;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
          continue;
        }
      }

      //Display
      App.clear(sf::Color::Black);
      App.display();
    }


  // Done.
  return 0;
}
