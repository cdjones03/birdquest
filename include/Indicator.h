/*
    2nd iteration, done by Sydnee Belcher

	Creates the class for making the indicator, which is the blue
	bar that moves back and forth across the battle bar and waits for
	user input (enter key) to be pressed. 
	
	The indicator will stop where it's at and the coordinates 
	corresponding to that color will be registered so that proper 
	damaged can be logged

	NOTE: Indicator update now works an lets the indicator move thanks to Chase's help,
	      indicator update function now has a stopGo variable and there is a stopGo
		  function that changes it from 1 to 0, which keeps it from moving anymore
		  when the main loop in BattleBar.cpp detects the enter key has been pressed
*/


#ifndef INDICATOR_H
#define INDICATOR_H
#include <iostream>
#include <stdio.h> //for using enum
#include <SFML/Graphics.hpp>


class Indicator {  //what i had written for the indicator class, intended to be put in its own .cpp file
	               //decided not to use it for this iteration of the code

	sf::RectangleShape indic;
	//enum eDir {STOP = 0, GO = 1};
	int velocity = 1;
	int stopGo = 1;

	private:
		int x, y;
		int startX, startY;  //initial x and y coordinates
		//eDir direction;

	public:  //constructor
		Indicator();

		Indicator(int posX, int posY);

		void reset();


		//void changeDirection(eDir d);


		//void randomDirection();


		//int inline getX();


		//int inline getY();


		//eDir inline getDirection();


		//void moveIndicator();


		void drawIndicator(sf::RenderWindow &window);

		void changeToStop();  //change movement of indicator to stop 

		void update();
		
};



#endif
