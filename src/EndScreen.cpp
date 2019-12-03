#include <EndScreen.hpp>
#include <iostream>

EndScreen::EndScreen(float width, float height){

    if(!texture.loadFromFile("../resources/spritesheets/End_Screen_800.png")){
        }

    inEnd = true;
    sprite.setTexture(texture);
    sprite.setScale(0.8, 0.8);
    //sprite.setPosition(0, 40);

}
EndScreen:: ~EndScreen(){

}

void EndScreen::draw(sf::RenderWindow &window){
    window.draw(sprite);
}

void EndScreen::processInputs(sf::Event event){
    if(event.type == sf::Event::KeyPressed){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
            inEnd = false;
        }
    }
}

bool EndScreen::isInEnd(){
    return inEnd;
}
