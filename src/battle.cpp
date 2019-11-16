#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

int main(){
  //default_random_engine generator;
  ////uniform_int_distribution<int> distribution1(4,8);
  //int attackRoll = distribution1(generator);
  //uniform_int_distribution<int> distribution2(1,11);
  //int magicRoll = distribution2(generator);
  int enemyAttack;
  int userAttack;
  int userMagic;
  int defend;


  int input = 0;
  int enemyHP = 100;
  int userHP = 100;

  while (input != 5){
    enemyAttack = (rand()%10);
    userAttack = 4+(rand()%5);
    userMagic = 1+(rand()%10);
    defend = (rand()%10);

    cout << "Enemy HP = " << enemyHP << endl;
    cout << "User HP = " << userHP << endl;
    cout << "\nInput a number to choose your move:\n1 for Attack\n2 for Magic\n3 for Item\n4 for Defend\n5 for run" << endl;
    cin  >> input;
    switch(input){
      case 1:
        enemyHP -= userAttack;
        userHP -= enemyAttack;
        break;
      case 2:
        enemyHP -= userMagic;
        userHP -= enemyAttack;
        break;
      case 3:
        userHP += (10 - enemyAttack);

        break;
      case 4:
        if (enemyAttack-defend <=0){
          userHP -= 0;
        }
        else{
          userHP = (userHP - enemyAttack + defend);
        }
        break;
    }
    if (enemyHP <= 0){
      cout << "You Win!" << endl;
      break;
    }
    if (userHP <= 0){
      cout << "Game Over!" << endl;
      break;
    }
    userHP -= enemyAttack;
  }

  if (input == 5){
    cout << "You succesfully ran away!\n";
  }
  return 0;
}
