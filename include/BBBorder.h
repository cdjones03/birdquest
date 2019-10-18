/*
    First iteration of this done by Sydnee Belcher
	
	Creates the class for making the "borders" or blocks of colors that
	denote the damage on the battle bar
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
		BBBorder(void){
			
			value1L.setPosition(0, 25);
			value1L.setSize(sf::Vector2f(200,100));
			value1L.setFillColor (sf::Color::Red);
			
			value1R.setPosition(800, 25);
			value1R.setSize(sf::Vector2f(200,100));
			value1R.setFillColor (sf::Color::Red);
	
			value3L.setPosition(200, 25);
			value3L.setSize(sf::Vector2f(150, 100));
			value3L.setFillColor (sf::Color(222, 132, 31));  //color orange
			
			value3R.setPosition(650, 25);
			value3R.setSize(sf::Vector2f(150, 100));
			value3R.setFillColor (sf::Color(222, 132, 31));  //color orange
			
			value5L.setPosition(350, 25);
			value5L.setSize (sf::Vector2f(120, 100));
			value5L.setFillColor (sf::Color::Yellow);
			
			value5R.setPosition(530, 25);
			value5R.setSize (sf::Vector2f(120, 100));
			value5R.setFillColor (sf::Color::Yellow);
			
			value7.setPosition(470, 25);
			value7.setSize (sf::Vector2f(60, 100));
			value7.setFillColor (sf::Color::Green);
			
			
		}
	
	void drawBorder(sf::RenderWindow &window);

	float getEdgeLeft (void);   //get left and right edges of the bar
	float getEdgeRight (void);
};

#endif