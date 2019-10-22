/*
    3rd iteration, done by Sydnee Belcher

	Creates the class for making the indicator, which is the blue
	bar that moves back and forth across the battle bar and waits for
	user input (enter key) to be pressed.

	The indicator will stop where it's at and the damage function can
	be called for proper damage assiciated with the corresponding color

	NOTE: - Indicator now has damage function that keeps track of damage done when it's stopped,
		  - Code has been cleaned up to get rid of all unused/uneeded functions and variables
		  - update function now multiplies the velocity by a number less than 1 to slow the
		    speed of the indicator bar, as it was too fast before
		  - reset function now resets the indicator bar back to the center and turns the
            the velocity back to -1, which means the indicator will always start by going
			right
		  - damage and current x position printed to terminal
		  - this is printed twice and i can't figure out why
*/


#ifndef INDICATOR_H
#define INDICATOR_H
#include <iostream>
#include <stdio.h> //for using enum
#include <SFML/Graphics.hpp>


class Indicator {

	sf::RectangleShape indic;
	int velocity = 1;
	int stopGo = 1;

	private:
		//int x, y;
		int startX, startY;  //initial x and y coordinates
		int red = 1;      //damage values that coordinate with battle bar color
		int orange = 3;
		int yellow = 5;
		int green = 7;
		int width = 10;
		int height = 100;


	public:  //constructor
		Indicator();

		void reset();

		void drawIndicator(sf::RenderWindow &window);

		void changeToStop();  //change movement of indicator to stop

		void update();

		int damage();   //deal damage

		//int that will store the damage dealt
		int damageDealt;

		int getWidth();

};



#endif
