/*
    First iteration of this done by Sydnee Belcher
	
	Creates the class for making the indicator, which is the blue
	bar that moves back and forth across the battle bar and waits for 
	user input (enter key?) to be pressed. The indicator will stop where
	it's at and the amount of damage corresponding to that color will be
	registered
	
	NOTE: creates the indicator and sets up functions for movement, but I
	      am not sure if any of the moving functions actually work
		  Need help from other team members 
*/


#ifndef INDICATOR_H
#define INDICATOR_H
#include <iostream>
#include <stdio.h> //for using enum
#include <SFML/Graphics.hpp>


class Indicator {  //what i had written for the indicator class, intended to be put in its own .cpp file
	               //decided not to use it for this iteration of the code
	
	sf::RectangleShape indic; 
	enum eDir {STOP = 0, LEFT = 1, RIGHT = 2};
	
	private:
		int x, y; 
		int startX, startY;  //initial x and y coordinates
		eDir direction;
		
		
	public:  //constructor
		Indicator(void){
			indic.setSize(sf::Vector2f(10, 150));
			indic.setFillColor (sf::Color::Blue);
			indic.setPosition(495, 0);
		}
		
		indicator(int posX, int posY);
		
	
		void reset();
		
		
		void changeDirection(eDir d);
		
	
		void randomDirection();
		
	
		int inline getX();
		
		
		int inline getY();
		
		
		inline getDirection();
		
		
		void moveIndicator();
		

		void drawIndicator(sf::RenderWindow &window);

};



#endif