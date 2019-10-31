#pragma once
#include "SFML/Graphics.hpp"

#define maxPauseOptions 3
#define maxItemOptions 4

class PauseMenu
{
public:
	PauseMenu(float width, float height);
	~PauseMenu();

	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();

	int getSelectedOption(){
		return selectedIndex;
	}
	bool inPause;
	bool inItem;
	int processInputs(sf::Event event, sf::RenderWindow &window);

private:
	sf::Font font;
	sf::Text optionText[maxPauseOptions];
	sf::Text itemText[maxItemOptions];
	int selectedIndex;
	sf::RectangleShape border;
	sf::RectangleShape itemBorder;

};