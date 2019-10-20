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

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Indicator.h"

Indicator::Indicator() {
	indic.setSize(sf::Vector2f(10, 150));
	indic.setFillColor (sf::Color::Blue);
	indic.setPosition(495, 0);
}

Indicator::Indicator(int posX, int posY)
	{
	startX = posX;  //set coordinates to start coordinates
	startY = posY;  //useful for resetting the bar in between uses
	x = posX;
	y = posY;
	//direction = STOP; //no initial movement
	}

void Indicator::reset()
	{
	x = startX;
	y = startY;
	//direction = STOP;
	}
/*
void Indicator::changeDirection(eDir d)
	{
	direction = d;
	}

void Indicator::randomDirection()
	{
	direction = (eDir)((rand() % 2) + 1); //randomly go left or right at the start
	}


int inline Indicator::getX()
	{
	return x;
	}

int inline Indicator::getY()
	{
	return y;
	}

Indicator::eDir inline Indicator::getDirection()
	{
	return direction;
	}


void Indicator::moveIndicator()
	{
	switch (direction){
		case STOP:
			break;

		case LEFT:
			x--;    //decrease x-value
			break;

		case RIGHT:
			x++;   //increase x-value
			break;

		default:
			break;
		}
	}
*/
void Indicator::drawIndicator(sf::RenderWindow &window){
	window.draw(indic);
}

void Indicator::changeToStop(){  //makes the update function stop moving 
	stopGo = 0; 
}

void Indicator::update(){
	
	if (stopGo == 0)
	{
		//do nothing really, just stops the indicator from moving anymore
		//indic.move(0, 0);
		//std::cout << "stop position (x,y): " << indic.getPosition().x << ", " << indic.getPosition().y << std::endl;
	}
	
	else
	{
		if(indic.getPosition().x > 999){     //change direction of indicator when reaches edge
			velocity *= -1;
		}
		else if(indic.getPosition().x < 1){
			velocity *= -1;
		}
		indic.move(velocity, 0);
	}
}
