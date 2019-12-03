#pragma once
#include "SFML/Graphics.hpp"

class TitleScreen
{
public:

    TitleScreen(float width, float height);
    ~TitleScreen();

    void draw(sf::RenderWindow &window);
    void processInputs(sf::Event event);

    bool inTitle;
    bool isInTitle();
private:
    sf::Texture texture;
    sf::Sprite sprite;
};