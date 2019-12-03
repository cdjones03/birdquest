#include "../include/PauseMenu.h"
#include "../include/BattleMenu.h"
#include "../include/Inventory.h"
#include <iostream>
#include <string>

PauseMenu::PauseMenu(float width, float height){
	inPause = true;
	inItem = false;
	inStatus = false;
	selectedIndex = 0;
	itemIndex = 0;

	if (!font.loadFromFile("../resources/game_over.ttf")) {
  	//error
  	}
  	if(!keyTexture.loadFromFile("../resources/spritesheets/key.png", sf::IntRect(0, 0, 16, 16))){
  	}

  	if(!birdTexture.loadFromFile("../resources/spritesheets/battlesprite_player.png", sf::IntRect(0, 0, 90, 90))){
  	}

  	//health bar for the status update
  	birdSprite.setTexture(birdTexture);
  	birdSprite.setPosition(sf::Vector2f(width/3.1, height/11));
  	//birdSprite.setScale(0.25, 0.25);

  	//health bar for the status update
	  
  	healthBar.setSize(sf::Vector2f(width/3.5, height/30));
  	healthBar.setFillColor(sf::Color(50, 255, 50));
  	healthBar.setPosition(sf::Vector2f(width/3.2, height/4.25));

  	remainingBar.setSize(sf::Vector2f(width/3.5, height/30));
  	remainingBar.setFillColor(sf::Color::Red);
  	remainingBar.setPosition(width/3.2, height/4.25);
  	remainingBar.setOutlineThickness(3);

  	//text that shows user HP in status menu
	HP = bMenu.userHP;
	std::cout<<"here:"<<HP;
	

  	HP_string.setFont(font);
  	HP_string.setCharacterSize(50);
  	HP_string.setFillColor(sf::Color::White);
  	HP_string.setString("HP: "+HPstr + "/100");
  	HP_string.setPosition(sf::Vector2f(width/2.1 - 10, height/5-40));

  	//border around status screen
  	statusBorder.setSize(sf::Vector2f(width/2.9, height/4.8));
  	statusBorder.setPosition(sf::Vector2f(width/3.5, height/12));
  	statusBorder.setFillColor(sf::Color::Black);
  	statusBorder.setOutlineThickness(4);
  	statusBorder.setOutlineColor(sf::Color::White);

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
	optionText[0].setCharacterSize(90);
  	optionText[0].setFillColor(sf::Color::Red);
  	optionText[0].setString("Items");
  	optionText[0].setPosition(sf::Vector2f(width/1.4, height/8 - 65));

  	optionText[1].setFont(font);
	optionText[1].setCharacterSize(90);
  	optionText[1].setString("Status");
  	optionText[1].setPosition(sf::Vector2f(width/1.4, height/4.5 - 65));

  	optionText[2].setFont(font);
	optionText[2].setCharacterSize(90);
  	optionText[2].setString("Resume");
  	optionText[2].setPosition(sf::Vector2f(width/1.4, height/3.1 - 65));

  	//position each item option on the screen, with the color red if it is highlighted
  	itemText[0].setFont(font);
	itemText[0].setCharacterSize(80);
  	itemText[0].setFillColor(sf::Color::Red);
  	itemText[0].setString("-");
  	itemText[0].setPosition(sf::Vector2f(width/1.4, height/2-55));

  	itemText[1].setFont(font);
	itemText[1].setCharacterSize(80);
  	itemText[1].setString("-");
  	itemText[1].setPosition(sf::Vector2f(width/1.4, height/1.7-55));

  	itemText[2].setFont(font);
	itemText[2].setCharacterSize(80);
  	itemText[2].setString("-");
  	itemText[2].setPosition(sf::Vector2f(width/1.4, height/1.48-55));

  	itemText[3].setFont(font);
	itemText[3].setCharacterSize(80);
  	itemText[3].setString("-");
  	itemText[3].setPosition(sf::Vector2f(width/1.4, height/1.32-55));

  	itemText[4].setFont(font);
	//want to make return a different color or style, 
	//so that it doesn't look like it's in the list of items
	//itemText[4].setFillColor(sf::Color::Green);
	itemText[4].setCharacterSize(80);
  	itemText[4].setString("-Return-");
  	itemText[4].setPosition(sf::Vector2f(width/1.4, height/1.18-55));

  	//keySprite.setTexture(keyTexture);
  	//keySprite.setScale(2, 2);
	//keySprite.setPosition(550,320);

  }

PauseMenu:: ~PauseMenu(){

}


void PauseMenu::draw(sf::RenderWindow &window){
	window.draw(border);

	int i = 0;
	for (; i < maxPauseOptions; i++){
		window.draw(optionText[i]);

	}

	if (inStatus){
		window.draw(statusBorder);
		window.draw(HP_string);
		window.draw(birdSprite);
		window.draw(remainingBar);
		window.draw(healthBar);
	}

	if (inItem){
		window.draw(itemBorder);

		int j = 0;
		for (; j < maxItemOptions; j++){
			window.draw(itemText[j]);
		}
		window.draw(keySprite);	
	}
}

//void PauseMenu::addItem(std::string item){
//	inventory[itemCount] = item;
//	itemText[itemCount].setString(inventory[itemCount]);
//	itemCount++;

//}

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

void PauseMenu::processInputs(sf::Event event, sf::RenderWindow &window){

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
					std::cout << "Status Pressed" << std::endl;		
					//std::cout<<"here1:"<<HP;				
					inStatus = !inStatus;
									
					break;

				//resume
				
				case 2:
					std::cout << "Resume Pressed" << std::endl;
					inPause = false;
					//reset so items is selected first
					moveUp();
					moveUp();
					inStatus = false;
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
bool PauseMenu::isInPause(){
	return inPause;
}
