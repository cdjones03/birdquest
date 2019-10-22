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

  //BBBorder borders; //create colored borders

	//Indicator indi; //create indicator

}

void BattleBar::barPressed(){

				indi.changeToStop(); //stop indicator where it's at when enter is pressed
				indi.damage();     //get damage and out put to terminal
				indi.reset();  //start moving bar again when hit r

}

	 //update battle bar

void BattleBar::update(sf::RenderWindow &window){

		indi.update();  //update indicator for movement

		borders.drawBorder(window); //draw battlebar borders to screen

		indi.drawIndicator(window); //draw indicator

	}

int BattleBar::getDamageDealt(){
  	return indi.damage();
}
