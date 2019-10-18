/*
    First iteration of this done by Sydnee Belcher

	Creates the main loop for the battle bar

	NOTE: incomplete, no movement, need help
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
		sf::Event Event;

		while(BattleBar.pollEvent(Event))
		{

			if(Event.type == sf::Event::Closed)  //exit window
				BattleBar.close();
		}


		BattleBar.clear(sf::Color::Black);  //clear screen and set bg to black

		borders.drawBorder(BattleBar); //draw battlebar borders to screen

		indi.drawIndicator(BattleBar);

		BattleBar.display();  //display window

	}

	return 0;
}
