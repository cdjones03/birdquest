#ifndef BATTLEBAR_H
#define BATTLEBAR_H

#include <BBBorder.h>
#include <Indicator.h>

class BattleBar {

	public:  //constructor
		BattleBar();
		void update(sf::RenderWindow &window);
		void barPressed();
		int getDamageDealt();
		Indicator indi;

	private:

		BBBorder borders; //create colored borders

		 //create indicator

};

#endif
