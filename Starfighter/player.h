#pragma once
#include "moveable.h"
#include <SFML/Graphics.hpp>
class Player :
	public moveable
{
	int Health;
public:
	inline Player() {
		Health = 10;
		Position = vector2D(256, 512);
		Velocity = vector2D(0, 0);
		Force = vector2D(0, 0);
		Acceleration = vector2D(0, 0);
		Rotation = 0.0;
		mass = 1;
	}
	
	inline void draw(sf::RenderWindow* window) {
		Spr.setOrigin(16, 16);
		Spr.setPosition(Position.x, Position.y);
		Spr.setRotation(Rotation);
		
		window->draw(Spr);
	}
};

