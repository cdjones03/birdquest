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
#include "BattleBar.h"


BattleBar::BattleBar(){
 
	sf::RenderWindow BatBar(sf::VideoMode(640,150,32), "Battle Bar", sf::Style::None); //no style/title bar

	BBBorder borders; //create colored borders

	Indicator indi; //create indicator
	
	// start main loop
	
	while(BatBar.isOpen())
	{
		sf::Event Event;

		while(BatBar.pollEvent(Event))
		{

			if(Event.type == sf::Event::Closed)  //exit window
				BatBar.close();

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
				BatBar.close(); //exit window by hitting escape
			}
		
		}

	 //update battle bar

		BatBar.clear(sf::Color::Black);  //clear screen and set bg to black

		indi.update();  //update indicator for movement
		
		borders.drawBorder(BatBar); //draw battlebar borders to screen

		indi.drawIndicator(BatBar); //draw indicator

		BatBar.display();  //display window

	}
}
