/*
    3rd iteration: - indicator slowed down to resonable speed
				   - window has no title bar so it will fit better inside
				     the main game screen 
				   - hitting the escape key exits the window now since there's no 
				     title bar

	Creates the main loop for the battle bar

*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "BBBorder.h"
#include "Indicator.h"


int main(int argc, char** argv){

	sf::RenderWindow BattleBar(sf::VideoMode(1000,150,32), "Battle Bar", sf::Style::None); //no style/title bar

	BBBorder borders; //create colored borders

	Indicator indi; //create indicator

	// start main loop
	while(BattleBar.isOpen())
	{
		sf::Event Event;

		while(BattleBar.pollEvent(Event))
		{

			if(Event.type == sf::Event::Closed)  //exit window
				BattleBar.close();

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				indi.changeToStop(); //stop indicator where it's at when enter is pressed
				indi.damage();     //get damage and out put to terminal
			}

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				indi.reset();  //start moving bar again when hit r
			}
			
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				BattleBar.close(); //exit window by hitting escape
			}
		
		}

	 //update battle bar

		BattleBar.clear(sf::Color::Black);  //clear screen and set bg to black

		indi.update();  //update indicator for movement
		
		borders.drawBorder(BattleBar); //draw battlebar borders to screen

		indi.drawIndicator(BattleBar); //draw indicator

		BattleBar.display();  //display window

	}

	return 0;
}
