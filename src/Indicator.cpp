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
	indic.setSize(sf::Vector2f(10, 150));
	indic.setFillColor (sf::Color::Blue);
	indic.setPosition(495, 0);
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
		if(indic.getPosition().x > 999){     //change direction of indicator when reaches edge
			velocity *= -1;
		}
		else if(indic.getPosition().x < 1){
			velocity *= -1;
		}
		indic.move(velocity*(-0.25), 0);  //mult by number less than 1 to slow down movement speed
	}
}

float Indicator::damage(){
	
	int curX = indic.getPosition().x;
	std::cout << "x position: " << curX << std::endl;
	
	if ((0 <= curX && curX <= 200) || (800 <= curX && curX <= 1000)){
		std::cout << "You did " << red << " points of damage!" << std::endl;
	}
	
	else if ((201 <= curX && curX <= 350) || (650 <= curX && curX <= 799)){
		std::cout << "You did " << orange << " points of damage!" << std::endl;
	}
	
	else if ((351 <= curX && curX <= 470) || (530 <= curX && curX <= 649)){
		std::cout << "You did " << yellow << " points of damage!" << std::endl;
	}
	
	else if ((471 <= curX && curX <= 529)){
		std::cout << "You did " << green << " points of damage!" << std::endl;
	}
}
