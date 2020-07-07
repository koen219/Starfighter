#pragma once
#include "laser.h"
class astroids
{
public:

	laser* bullets;
	std::vector<moveable*> astroid;
	void move();
	void draw(sf::RenderWindow*);
	void newAstroid(vector2D,double,double);
};

