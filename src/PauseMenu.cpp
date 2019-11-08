#include "../include/PauseMenu.h"
#include <iostream>
#include <string>

PauseMenu::PauseMenu(float width, float height){
	inPause = true;
	inItem = false;
	selectedIndex = 0;
	itemIndex = 0;
	itemCount = 0;

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

  	//position each item option on the screen, with the color red if it is highlighted
  	itemText[0].setFont(font);
  	itemText[0].setFillColor(sf::Color::Red);
  	itemText[0].setString("-");
  	itemText[0].setPosition(sf::Vector2f(width/1.4, height/2));

  	itemText[1].setFont(font);
  	itemText[1].setString("-");
  	itemText[1].setPosition(sf::Vector2f(width/1.4, height/1.7));

  	itemText[2].setFont(font);
  	itemText[2].setString("-");
  	itemText[2].setPosition(sf::Vector2f(width/1.4, height/1.48));

  	itemText[3].setFont(font);
  	itemText[3].setString("-");
  	itemText[3].setPosition(sf::Vector2f(width/1.4, height/1.32));

  	itemText[4].setFont(font);
  	itemText[4].setString("Return");
  	itemText[4].setPosition(sf::Vector2f(width/1.4, height/1.18));
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

		int j = 0;
		for (; j < maxItemOptions; j++){
			window.draw(itemText[j]);
		}	
	}
}

void PauseMenu::addItem(std::string item){
	std::cout << item;
	itemText[itemCount].setString(item);
	itemCount++;
}

void PauseMenu::moveUp(){
	if (selectedIndex - 1 >= 0 && inItem == false){
		optionText[selectedIndex].setFillColor(sf::Color::White);
		selectedIndex--;
		optionText[selectedIndex].setFillColor(sf::Color::Red);
	}
	else if (itemIndex - 1 >= 0){
		itemText[itemIndex].setFillColor(sf::Color::White);
		itemIndex--;
		itemText[itemIndex].setFillColor(sf::Color::Red);
	}
}

void PauseMenu::moveDown(){
	if (selectedIndex + 1 < maxPauseOptions && inItem == false){
		optionText[selectedIndex].setFillColor(sf::Color::White);
		selectedIndex++;
		optionText[selectedIndex].setFillColor(sf::Color::Red);
	}
	else if (itemIndex + 1 < maxItemOptions){
		itemText[itemIndex].setFillColor(sf::Color::White);
		itemIndex++;
		itemText[itemIndex].setFillColor(sf::Color::Red);
	}
}

int PauseMenu::processInputs(sf::Event event, sf::RenderWindow &window){

	if(event.type == sf::Event::KeyPressed){

		if(event.key.code == sf::Keyboard::Up){
			moveUp();
		}

		else if(event.key.code == sf::Keyboard::Down){
			moveDown();
		}

		else if(event.key.code == sf::Keyboard::Return && inItem == false){
			switch (getSelectedOption()){
				//item
				case 0:
					std::cout << "Item Pressed" << std::endl;
					itemText[itemIndex].setFillColor(sf::Color::White);
					itemIndex = 0;
					itemText[itemIndex].setFillColor(sf::Color::Red);
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

	else if(event.key.code == sf::Keyboard::Return && inItem == true){
		switch (getSelectedItem()){
			//item 1
			case 0:
				std::cout << "Item 1 Pressed" << std::endl;
				break;

			//item 2
			case 1:
				std::cout << "Item 2 Pressed" << std::endl;
				break;

			//item 3
			case 2:
				std::cout << "Item 3 Pressed" << std::endl;
				break;

			//item 4
			case 3:
				std::cout << "Item 4 Pressed" << std::endl;
				break;

			//Return
			case 4:
				std::cout << "Return Pressed" << std::endl;
				inItem = false;
				break;

		}
	}

}