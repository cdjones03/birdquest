#pragma once
#include "SFML/Graphics.hpp"
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
	// inventory and itemCount
	std::string inventory [4] = {"-", "-", "-", "-"};
	int itemCount;

	int processInputs(sf::Event event, sf::RenderWindow &window);

private:
	sf::Font font;
	sf::Text optionText[maxPauseOptions];
	sf::Text itemText[maxItemOptions];
	int selectedIndex;
	int itemIndex;
	sf::RectangleShape border;
	sf::RectangleShape itemBorder;
	sf::Texture keyTexture;
	sf::Sprite keySprite;

};