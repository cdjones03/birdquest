/*
    2nd interation, done by Sydnee Belcher
	
	Creates the class for making the "borders" or blocks of colors that
	denote the damage on the battle bar
	
	NOTE: - removed functions that were unused/not needed  
*/

#include <SFML/Graphics.hpp>
#include "BBBorder.h"


void BBBorder::drawBorder(sf::RenderWindow &window){
	window.draw(value1L);
	window.draw(value1R);
	window.draw(value3L);
	window.draw(value3R);
	window.draw(value5L);
	window.draw(value5R);
	window.draw(value7);
	}