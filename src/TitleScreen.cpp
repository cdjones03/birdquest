#include "TitleScreen.h"
#include <iostream>

TitleScreen::TitleScreen(float width, float height){
    

    if(!texture.loadFromFile("../resources/titlee.png")){
        }
    sprite.setTexture(texture);
    sprite.setPosition(width/2, height/2);

}
TitleScreen:: ~TitleScreen(){

}

void TitleScreen::draw(sf::RenderWindow &window){
    window.draw(sprite);
}

void TitleScreen::processInputs(sf::Event event){
    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Enter){
            inTitle = false;
        }
    }
    
}

bool TitleScreen::isInTitle(){
    return inTitle;
}