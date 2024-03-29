#include "TitleScreen.h"
#include <iostream>

TitleScreen::TitleScreen(float width, float height){

    if(!texture.loadFromFile("../resources/titlee.png")){
        }

    inSprite = true;
    inTitle = true;
    sprite.setTexture(texture);
    sprite.setScale(0.8, 0.8);
    sprite.setPosition(0, 40);
    if (!font.loadFromFile("../resources/game_over.ttf")) {
    //error
    }
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(75);
    text.setPosition(65, 0);
    text.setString("The Evil Malphas has kidnapped the\nBird Princess of Featherfall Kingdom!\nIt's up to you, the loyal Bird Knight\nto embark on a quest to rescue her\nand restore peace.\nHowever, your power of flight\nhas also been taken!\nYou must defeat three\n treacherous bosses to gather\nall three keys before you can face\n the malevolent Malphas . . .\n\nUse the arrow keys to move, and press P to pause.\n              Press Enter to continue!");    
}
TitleScreen:: ~TitleScreen(){
}

void TitleScreen::draw(sf::RenderWindow &window){
    if (inSprite){
        window.draw(sprite);
    }
    else{
        window.draw(text);
    }    
}

void TitleScreen::processInputs(sf::Event event){
    if(event.type == sf::Event::KeyPressed){
        if (inSprite){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
                inSprite = false;
            }
        }
        else{
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
                inTitle = false;
            }
        }   
    }  
}

bool TitleScreen::isInTitle(){
    return inTitle;
}