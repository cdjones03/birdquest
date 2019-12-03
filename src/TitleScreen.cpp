#include "TitleScreen.h"
#include <iostream>

TitleScreen::TitleScreen(float width, float height){
    

    if(!texture.loadFromFile("../resources/titlee.png")){
        }

    inTitle = true;
    sprite.setTexture(texture);
    sprite.setScale(0.8, 0.8);
    sprite.setPosition(0, 40);

}
TitleScreen:: ~TitleScreen(){

}

void TitleScreen::draw(sf::RenderWindow &window){
    window.draw(sprite);
}

void TitleScreen::processInputs(sf::Event event){
    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Return){
            inTitle = false;
        }
    }
    
}

bool TitleScreen::isInTitle(){
    return inTitle;
}