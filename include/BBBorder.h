/*
    2nd interation, done by Sydnee Belcher
	
	Creates the class for making the "borders" or blocks of colors that
	denote the damage on the battle bar
	
	NOTE: - removed functions that were unused/not needed  
*/

#ifndef BBBORDER_H
#define BBBORDER_H

class BBBorder {
	sf::RectangleShape value1L;  //left 1 
	sf::RectangleShape value3L;  //left 3 
	sf::RectangleShape value5L;  //left 5 
	
	sf::RectangleShape value1R;  //right 1
	sf::RectangleShape value3R;  //right 3
	sf::RectangleShape value5R;  //right 5
	
	sf::RectangleShape value7;  //center value 7
	
	
	public: 
		BBBorder(){
			
			value1L.setPosition(0, 25);
			value1L.setSize(sf::Vector2f(150,100));
			value1L.setFillColor (sf::Color::Red);
			
			value1R.setPosition(490, 25);
			value1R.setSize(sf::Vector2f(150,100));
			value1R.setFillColor (sf::Color::Red);
	
			value3L.setPosition(150, 25);
			value3L.setSize(sf::Vector2f(100, 100));
			value3L.setFillColor (sf::Color(255, 153, 51));  //color orange
			
			value3R.setPosition(390, 25);
			value3R.setSize(sf::Vector2f(100, 100));
			value3R.setFillColor (sf::Color(255, 153, 51));  //color orange
			
			value5L.setPosition(250, 25);
			value5L.setSize (sf::Vector2f(50, 100));
			value5L.setFillColor (sf::Color::Yellow);
			
			value5R.setPosition(340, 25);
			value5R.setSize (sf::Vector2f(50, 100));
			value5R.setFillColor (sf::Color::Yellow);
			
			value7.setPosition(300, 25);
			value7.setSize (sf::Vector2f(40, 100));
			value7.setFillColor (sf::Color::Green);
			
			
		}
	
	void drawBorder(sf::RenderWindow &window);

};

#endif