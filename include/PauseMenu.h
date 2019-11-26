#pragma once
#include "SFML/Graphics.hpp"
#include "BattleMenu.h"
#include "Inventory.h"
#include <iostream>
#include <string>

#define maxPauseOptions 3
#define maxItemOptions 5

class PauseMenu
{
public:
	PauseMenu(float width, float height);
	~PauseMenu();

	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	//void addItem(std::string item);

	int getSelectedOption(){
		return selectedIndex;
	}

	int getSelectedItem(){
		return itemIndex;
	}
	void getUserHP(int HP);
	bool isInPause();
	bool inPause;
	bool inItem;
	bool inStatus;
	
	void processInputs(sf::Event event, sf::RenderWindow &window);
	int HP;
	sf::Text HP_string;
	sf::RectangleShape healthBar;

	Inventory inventory;
	sf::Text itemText[maxItemOptions];
private:
	
	std::string HPstr;
	sf::Font font;
	sf::Text optionText[maxPauseOptions];
	int selectedIndex;
	int itemIndex;
	sf::RectangleShape border;
	sf::RectangleShape itemBorder;
	sf::Texture keyTexture;
	sf::Sprite keySprite;
	BattleMenu bMenu;
	sf::Texture birdTexture;
	sf::Sprite birdSprite;
	//sf::RectangleShape healthBar;
	sf::RectangleShape remainingBar;
	sf::RectangleShape statusBorder;
	

	

};