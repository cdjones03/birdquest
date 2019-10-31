#include "../include/PauseMenu.h"
#include <iostream>

PauseMenu::PauseMenu(float width, float height){
	inPause = true;
	inItem = false;
	selectedIndex = 0;

	if (!font.loadFromFile("../src/Gameplay.ttf")) {
  	//error
  	}

  	//border around the option in pause screen
  	border.setSize(sf::Vector2f(width/3.25, height/3));
  	border.setPosition(sf::Vector2f(width/1.5, height/12));
  	border.setFillColor(sf::Color::Black);
  	border.setOutlineThickness(4);
  	border.setOutlineColor(sf::Color::White);

  	//border around the item option in pause screen
  	itemBorder.setSize(sf::Vector2f(width/3.25, height/2.1));
  	itemBorder.setPosition(sf::Vector2f(width/1.5, height/2.2));
  	itemBorder.setFillColor(sf::Color::Black);
  	itemBorder.setOutlineThickness(4);
  	itemBorder.setOutlineColor(sf::Color::White);

  	//position each option on the screen, with the color red if it is highlighted
  	optionText[0].setFont(font);
  	optionText[0].setFillColor(sf::Color::Red);
  	optionText[0].setString("Items");
  	optionText[0].setPosition(sf::Vector2f(width/1.4, height/8));

  	optionText[1].setFont(font);
  	optionText[1].setString("Save");
  	optionText[1].setPosition(sf::Vector2f(width/1.4, height/4.5));

  	optionText[2].setFont(font);
  	optionText[2].setString("Resume");
  	optionText[2].setPosition(sf::Vector2f(width/1.4, height/3.1));
}

PauseMenu:: ~PauseMenu(){

}

void PauseMenu::draw(sf::RenderWindow &window){
	window.draw(border);

	int i = 0;
	for (; i < maxPauseOptions; i++){
		window.draw(optionText[i]);
	}

	if (inItem){
		window.draw(itemBorder);
	}
}

void PauseMenu::moveUp(){
	if (selectedIndex - 1 >= 0){
		optionText[selectedIndex].setFillColor(sf::Color::White);
		selectedIndex--;
		optionText[selectedIndex].setFillColor(sf::Color::Red);
	}
}

void PauseMenu::moveDown(){
	if (selectedIndex + 1 < maxPauseOptions){
		optionText[selectedIndex].setFillColor(sf::Color::White);
		selectedIndex++;
		optionText[selectedIndex].setFillColor(sf::Color::Red);
	}
}

int PauseMenu::processInputs(sf::Event event, sf::RenderWindow &window){
	sf:: Event pauseEvent;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		moveUp();
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		moveDown();
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		switch (getSelectedOption()){
			//item
			case 0:
				std::cout << "Item Pressed" << std::endl;
				inItem = true;
				break;

			//save
			case 1:
				std::cout << "Save Pressed" << std::endl;
				break;

			//resume
			case 2:
				std::cout << "Resume Pressed" << std::endl;
				inPause = false;
				break;
		}
	}
}