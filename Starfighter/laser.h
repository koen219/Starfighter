#pragma once
#include "moveable.h"
#include "vector2D.h"
#include <vector>
class laser
{
public:
	std::vector<moveable*> lasers;
	void shoot(vector2D pos, double direction, double speed);
	void move();
	void draw(sf::RenderWindow*);
	double cooldown = 1.0;
	double counter = 0;
};

