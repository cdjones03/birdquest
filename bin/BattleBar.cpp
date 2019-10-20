/*
    2nd iteration: update method fixed by Chase
				   indicator stops based on uder input (enter)

	Creates the main loop for the battle bar

*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "BBBorder.h"
#include "Indicator.h"


int main(int argc, char** argv){

	sf::RenderWindow BattleBar(sf::VideoMode(1000,150,32), "Battle Bar", sf::Style::Titlebar | sf::Style::Close);

	BBBorder borders; //create borders

	Indicator indi; //create indicator

	// start main loop
	while(BattleBar.isOpen())
	{
		//int deltaMs = clock.getElapsedTime().asMilliseconds();

		sf::Event Event;

		while(BattleBar.pollEvent(Event))
		{

			if(Event.type == sf::Event::Closed)  //exit window
				BattleBar.close();

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				indi.changeToStop(); //stop indicator where it's at when enter is pressed
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
