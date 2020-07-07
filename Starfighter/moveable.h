#pragma once
#include "vector2D.h"
#include <iostream>
#include <SFML/Graphics.hpp>
class moveable
{
public:
	double mass;
	vector2D Position;
	vector2D Velocity;
	vector2D Acceleration;
	vector2D Force;
	double Rotation;
	double eps = 0.05;
	sf::Sprite Spr;
	sf::Texture Tex;
	void move();
	void round();
	vector2D getNextPos();

	inline void draw(sf::RenderWindow* window) {
		Spr.setOrigin(Tex.getSize().x/2, Tex.getSize().y/2);
		Spr.setPosition(Position.x, Position.y);
		Spr.setRotation(Rotation);
		window->draw(Spr);
	}

	inline void print() {
		std::cout << "Ik besta op ";
		Position.print();
		std::cout << std::endl;
	}
	vector2D collisionWithWall(int whereCol);
};

