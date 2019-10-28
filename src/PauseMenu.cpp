#include "../include/PauseMenu.h"
#include <iostream>

PauseMenu::PauseMenu(float width, float height){
	inPause = true;
	selectedIndex = 0;

	if (!font.loadFromFile("../src/Gameplay.ttf")) {
  	//error
  	}

  	optionText[0].setFont(font);
  	optionText[0].setFillColor(sf::Color::Red);
  	optionText[0].setString("Items");
  	optionText[0].setPosition(sf::Vector2f(width/3, height/4));

  	optionText[1].setFont(font);
  	optionText[1].setFillColor(sf::Color::Blue);
  	optionText[1].setString("Save");
  	optionText[1].setPosition(sf::Vector2f(width/3, height/6));

  	optionText[2].setFont(font);
  	optionText[2].setFillColor(sf::Color::Blue);
  	optionText[2].setString("Resume");
  	optionText[2].setPosition(sf::Vector2f(width/3, height/8));
}

PauseMenu:: ~PauseMenu(){

}

void PauseMenu::draw(sf::RenderWindow &window){
	int i = 0;
	for(; i < maxPauseOptions; i++){
		window.draw(optionText[i]);
	}
}

void PauseMenu::moveUp(){

}

void PauseMenu::moveDown(){

}

int PauseMenu::processInputs(sf::Event event, sf::RenderWindow &window){
	sf:: Event pauseEvent;

	if(event.key.code == sf::Keyboard::Up){
		moveUp();
	}
	if(event.key.code == sf::Keyboard::Down){
		moveDown();
	}


}