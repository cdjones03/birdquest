#pragma once
#include "SFML/Graphics.hpp"
#include "BattleLogic.h"
#include "BattleBar.h"
#include "Indicator.h"
#include "Enemy.h"

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
    bool isInMenu();
    void enemyEffect(sf::Text outpt, int userDamage, bool userDefend, bool item, bool showBattleBar);

    int getSelectedOption(){
        return selectedIndex;
    }

    int getSelectedItem(){
        return itemIndex;
    }

    int getHP();
    bool playerTurn;
    bool inMenu;
    void processInputs(sf::Event event, sf::RenderWindow &window);
    //bool whoseTurn();
    bool showMenu;
    Indicator indicator;
    int userHP;
    sf::Text itemText[maxOptions];

    std::string item_0;
    std::string item_1;
    std::string item_2;
    std::string item_3;

    sf::Text enemySpecialMove;
    sf::Text outputText;
    int userDamage;
    int enemyDamage;
    bool userDefend;
    bool enemyDefend;
    bool item;
    bool showBattleBar;
    Enemy enemy;
    Enemy::EnemyType type;

    int getResult();
    void resetResult();

    int item_used;

private:
    int freeze;
    bool showAttack;
    bool firstMove;
    bool invalid;


    sf::Texture birdTexture;
    sf::Sprite birdSprite;

	sf::Texture bossTexture;
	sf::Sprite bossSprite;

    float width;
    float height;

    BattleBar battleBar;

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

    sf::Text instructions;
    sf::Text item_instructions;
    sf::Text enemy_Text;
    sf::RectangleShape healthBar;
    sf::RectangleShape remainingBar;
    sf::RectangleShape enemy_healthBar;
    sf::RectangleShape enemy_remainingBar;
    sf::RectangleShape item_menu_box;
    bool showItem;

    bool returnJustPressed;

    int userDamageStored;
    bool magic;


    int userDefendStored;
    int enemyDamageStored;

    int itemIndex;

    int result;
};
