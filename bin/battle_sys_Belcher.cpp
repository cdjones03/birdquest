/*
	Code by Sydnee Belcher
	Date: 10/7/2019
	CS437 
	
	This is intended to be a text-only, early version of the 
	battle system for BirdQuest! 
	
	In this I use C++'s rand() function, which "randomly" picks the same numbers everytime
	This is good for testing purposes, but should be altered for a better random variation 
	of damage within a range. 
	
	Because of this, the player always loses if attack is always chosen.
	However, if the enemyAI is commented out, the player can effectively win.
	
	For blocking: we can always block all damage(in this case take no damage)
	or we can have some modifier to decrease damage taken. In this code, I just
	have the player not take damage at all
	
	Flee: flee just automatically succeeds and ends the loop
	
	Item: doesn't actually do anything since I have no Items to implement yet
	just prints a statement to screen saying that an item was used.
	

*/

#include <iostream>
#include <stdlib.h>  //for random()
#include <string.h>  //for strings

void enemyAI(char action, int &playerHP){  //just simple attack for now
	
	int randNumAI = rand()%(30-1 + 1) + 1; //damage = random num between 1 and 30, inclusive
	
	if (action == 'D' or action == 'd'){ //no damage if player blocks
		std::cout << "You take 0 points of damage!" << std::endl << std::endl;
	}
	
	else {
		std::cout << "You take " << randNumAI << " points of damage!" << std::endl << std::endl;
		playerHP = playerHP - randNumAI;
	}
	
}


void getAction(char action, int &enemyHP)
	{
		
		int randNum = rand()%(30-1 + 1) + 1; //damage = random num between 1 and 30, inclusive
	
		switch (action)
		{
			case 'a':
			case 'A':
				std::cout << "Enemy takes " << randNum << " points of damage!" << std::endl << std::endl;
				enemyHP = enemyHP - randNum;
				break;
				

			case 'd':
			case 'D':	
				std::cout << "You block!" << std::endl << std::endl;
				break;

			case 'm':  //magic does same amount of dmg as attack for now
			case 'M':			
				std::cout << "Enemy takes " << randNum << " points of damage!" << std::endl << std::endl;
				enemyHP = enemyHP - randNum;
				break;
				
			case 'f':
			case 'F':	
				std::cout << "You flee!" << std::endl << std::endl;
				break;

			case 'i':
			case 'I':			
				std::cout << "You use an item!" << std::endl << std::endl;
				break;
		}
		
	}

int print_HP(int enemyHP, int playerHP)
	{
		std::cout << "Enemy HP: " << enemyHP << " out of 100" << std::endl;
		std::cout << "Player HP: " << playerHP << " out of 100" << std::endl;
	}

char print_menu (void) // print menu and get option
    {
    
	std::cout << "Enter one of the following: " << std::endl;
	std::cout << "A to Attack" << std::endl;
	std::cout << "D to Defend" << std::endl;
	std::cout << "M to use Magic" << std::endl;
	std::cout << "F to Flee" << std::endl;
	std::cout << "I to use Item" << std::endl;
	std::cout << "Q to use quit" << std::endl;

    }



int main (void)// main player loop; execute option or call appropriate function
{
    char input[] = "";  //list for keyboard input
	char action = 'a';  //keep record of player's action, defaulted to a
	
	int enemyHP = 100;
	int static playerHP = 100; //why static? figure this out

	print_HP(enemyHP, playerHP); //print hp to screen to start
    print_menu(); //print menu of choices to screen to start

    while (std::cin >> input)
    {
        if (strlen(input) > 1){           //1 character is length of options  
            std::cout << input;           //invlaid if we go over this length
            std::cout << std::endl;
            std::cout << "Invalid option: " << input;
            std::cout << std::endl;
            print_menu();
        }

        else{

            switch(input[0]) {

                case 'a':
                case 'A':
                    std::cout << "you chose: " << input << std::endl;
                    action = input[0];
					getAction(action, enemyHP);
					
					if (enemyHP <= 0){
						enemyHP = 0;
						print_HP(enemyHP, playerHP);
						std::cout << "You Win!" << std::endl;
						return(0);
					}
					
					print_HP(enemyHP, playerHP);
					
					std::cout << "Enemy attacks you!" << std::endl;
					enemyAI(action, playerHP);  //enemy attack
					
					if (playerHP <= 0){
						playerHP = 0;
						print_HP(enemyHP, playerHP);
						std::cout << "You Lose!" << std::endl;
						return(0);
					}
					
					print_HP(enemyHP, playerHP);
					print_menu();
                    break;	

                case 'd':
                case 'D':
                    std::cout << "you chose: " << input << std::endl;
                    action = input[0];
                    getAction(action, enemyHP);
                    print_HP(enemyHP, playerHP);
					
					std::cout << "Enemy attacks you!" << std::endl;
					enemyAI(action, playerHP);  //enemy attack
					
					if (playerHP <= 0){
						playerHP = 0;
						print_HP(enemyHP, playerHP);
						std::cout << "You Lose!" << std::endl;
						return(0);
					}
					
					print_HP(enemyHP, playerHP);
					print_menu();
                    break;	

                case 'm':
                case 'M':
                    std::cout << "you chose: " << input << std::endl;
                    action = input[0];
					getAction(action, enemyHP);
                    
					if (enemyHP <= 0){
						enemyHP = 0;
						print_HP(enemyHP, playerHP);
						std::cout << "You Win!" << std::endl;
						return(0);  //when you beat the enemy, you win, quit battle
					}
					
					print_HP(enemyHP, playerHP);
					
					std::cout << "Enemy attacks you!" << std::endl;
					enemyAI(action, playerHP);  //enemy attack
					
					if (playerHP <= 0){
						playerHP = 0;
						print_HP(enemyHP, playerHP);
						std::cout << "You Lose!" << std::endl;
						return(0);
					}
					
					print_HP(enemyHP, playerHP);
					print_menu();
                    break;	

                case 'f':
                case 'F':
                    std::cout << "you chose: " << input << std::endl;
                    action = input[0];
					getAction(action, enemyHP);
                    print_HP(enemyHP, playerHP);
					
					std::cout << "Enemy attacks you!" << std::endl;
					enemyAI(action, playerHP);  //enemy attack
					
					if (playerHP <= 0){
						playerHP = 0;
						print_HP(enemyHP, playerHP);
						std::cout << "You Lose!" << std::endl;
						return(0);
					}
					
					print_HP(enemyHP, playerHP);
					print_menu();
                    break;	

                case 'i':
                case 'I':
                    std::cout << "you chose: " << input << std::endl;
                    action = input[0];
					getAction(action, enemyHP);
                    print_HP(enemyHP, playerHP);
					
					std::cout << "Enemy attacks you!" << std::endl;
					enemyAI(action, playerHP);  //enemy attack
					
					if (playerHP <= 0){
						playerHP = 0;
						print_HP(enemyHP, playerHP);
						std::cout << "You Lose!" << std::endl;
						return(0);
					}
					
					print_HP(enemyHP, playerHP);
					print_menu();
                    break;	

                case 'q':  //quits the menu for test purposes
                case 'Q':
                    std::cout << "You have quit.";
                    return(0);

                default:  //catch-all for anything else invalid for test purposes
                    std::cout << input << std::endl;
                    std::cout << "Invalid option: " << input << std::endl;
                    print_HP(enemyHP, playerHP);
					print_menu();

            }
        }
    }
	return (0);
}
