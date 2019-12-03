#pragma once
#include "SFML/Graphics.hpp"

class EndScreen
{
public:

    EndScreen(float width, float height);
    ~EndScreen();

    void draw(sf::RenderWindow &window);
    void processInputs(sf::Event event);

    bool inEnd;
    bool isInEnd();
private:
    sf::Texture texture;
    sf::Sprite sprite;
};
