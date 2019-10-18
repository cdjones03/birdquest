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

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Indicator.h"


Indicator::indicator(int posX, int posY)
	{
	startX = posX;  //set coordinates to start coordinates
	startY = posY;  //useful for resetting the bar in between uses
	x = posX;
	y = posY;
	direction = STOP; //no initial movement
	}
	
void Indicator::reset()
	{
	x = startX;
	y = startY;
	direction = STOP;
	}
		
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
		
inline Indicator::getDirection()
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

void Indicator::drawIndicator(sf::RenderWindow &window){
	window.draw(indic);
	}