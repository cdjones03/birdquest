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
    bool inSprite;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Text text;
    sf::Font font;
};