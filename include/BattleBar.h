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

	private:

		BBBorder borders; //create colored borders

		Indicator indi; //create indicator

};

#endif
