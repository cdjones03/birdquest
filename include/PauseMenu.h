#pragma once
#include "SFML/Graphics.hpp"

#define maxPauseOptions 3

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
	int processInputs(sf::Event event, sf::RenderWindow &window);
private:
	sf::Font font;
	sf::Text optionText[maxPauseOptions];
	int selectedIndex;

};