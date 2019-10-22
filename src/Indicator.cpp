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

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Indicator.h"
#include <cmath>   //for pow function

Indicator::Indicator() {
	indic.setSize(sf::Vector2f(width, height));
	indic.setFillColor (sf::Color::Blue);
	indic.setPosition(315, 240);  //center the indicator
	startX = indic.getPosition().x;
	startY = indic.getPosition().y;
}

void Indicator::reset()  //reset the indicator to move again after stop
	{
	indic.setPosition(startX, startY);
	stopGo = 1;
	velocity = (-pow(velocity, 2));  //resets velocity to negative, always goes right first
	}

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
	}

	else
	{
		if(indic.getPosition().x+getWidth() > 639){     //change direction of indicator when reaches edge
			velocity *= -1;
		}
		else if(indic.getPosition().x < 1){
			velocity *= -1;
		}
		indic.move(velocity*(-8.00), 0);  //mult by number less than 1 to slow down movement speed
	}
}

int Indicator::damage(){

	int curX = indic.getPosition().x;
	std::cout << "x position: " << curX << std::endl;

	if ((0 <= curX && curX <= 150) || (490 <= curX && curX <= 640)){
		std::cout << "You did " << red << " points of damage!" << std::endl;
		damageDealt = red;
	}

	else if ((151 <= curX && curX <= 250) || (390 <= curX && curX <= 489)){
		std::cout << "You did " << orange << " points of damage!" << std::endl;
		damageDealt = orange;
	}

	else if ((251 <= curX && curX <= 300) || (340 <= curX && curX <= 389)){
		std::cout << "You did " << yellow << " points of damage!" << std::endl;
		damageDealt = yellow;
	}

	else if ((301 <= curX && curX <= 339)){
		std::cout << "You did " << green << " points of damage!" << std::endl;
		damageDealt = green;
	}

	return damageDealt;

}

int Indicator::getWidth(){
	return width;
}
