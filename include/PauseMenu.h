#pragma once
#include "SFML/Graphics.hpp"
#include "BattleMenu.h"
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
	void addItem(std::string item);

	int getSelectedOption(){
		return selectedIndex;
	}

	int getSelectedItem(){
		return itemIndex;
	}

	bool inPause;
	bool inItem;
	bool inStatus;
	// inventory and itemCount
	std::string inventory [4] = {"-", "-", "-", "-"};
	int itemCount;

	void processInputs(sf::Event event, sf::RenderWindow &window);

private:
	std::string HP;
	sf::Font font;
	sf::Text optionText[maxPauseOptions];
	sf::Text itemText[maxItemOptions];
	int selectedIndex;
	int itemIndex;
	sf::RectangleShape border;
	sf::RectangleShape itemBorder;
	sf::Texture keyTexture;
	sf::Sprite keySprite;
	BattleMenu bMenu;
	sf::Texture birdTexture;
	sf::Sprite birdSprite;
	sf::RectangleShape healthBar;
	sf::RectangleShape remainingBar;
	sf::RectangleShape statusBorder;
	sf::Text HP_string;

};