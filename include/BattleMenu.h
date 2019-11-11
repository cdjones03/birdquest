#pragma once
#include "SFML/Graphics.hpp"
#include "BattleLogic.h"
#include "BattleBar.h"
#include "Indicator.h"

#define maxOptions 4

class BattleMenu
{
public:
    BattleMenu();
    ~BattleMenu();

    void draw(sf::RenderWindow &window);
    void updateOutput();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getSelectedOption(){
        return selectedIndex;
    }
    int getHP();
    bool playerTurn;
    bool inMenu;
    int processInputs(sf::Event event, sf::RenderWindow &window);
    //bool whoseTurn();
    bool showMenu;
    Indicator indicator;
    int userHP;
    

private:
    bool showAttack;
    bool firstMove;

    sf::Texture birdTexture;
    sf::Sprite birdSprite;
	
	sf::Texture bossTexture;
	sf::Sprite bossSprite;
    
    float width;
    float height;

    BattleBar battleBar;
    int userDamage;
    int enemyDamage;
    int enemyHP;
    BattleLogic logic;
    int selectedIndex;
    sf::Font font;
    sf::Text optionText[maxOptions];
    sf::RectangleShape rectangle;
    //sf::CircleShape bird_battle;
    //sf::CircleShape enemy_sample;
    sf::Text userHP_Text;
    sf::Text enemyHP_Text;
    sf::Text outputText;
    sf::Text enemy_Text;
    sf::RectangleShape healthBar;
    sf::RectangleShape remainingBar;
    sf::RectangleShape enemy_healthBar;
    sf::RectangleShape enemy_remainingBar;
    bool showBattleBar;
    bool returnJustPressed;
    bool enemyDefend;
    int userDamageStored;
    bool magic;
    bool userDefend;
    bool item;
    int userDefendStored;
    int enemyDamageStored;
};
