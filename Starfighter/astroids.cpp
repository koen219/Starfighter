#include "astroids.h"
#include <random>
void astroids::move() {
	std::vector<int> indicesToDelete;
	for (int i = 0; i < astroid.size(); i++) {
		moveable* a = astroid[i];
		vector2D nextPos = a->getNextPos();
		if (nextPos.x < 16 or nextPos.x + 16>512) {
			a->Velocity = a->collisionWithWall(1) * a->Velocity.magnitude();
		}
		else {
			if (nextPos.y < 16 or nextPos.y + 16 > 768) {
				a->Velocity = a->collisionWithWall(2) * a->Velocity.magnitude();
			}
			else {
				for (moveable* l : bullets->lasers) {
					vector2D test = l->Position + a->Position * (-1);
					if (test.magnitude() <= 32.0)
					{
						indicesToDelete.push_back(i);
					}
				}
				a->move();
			}
		}
	}
	for (int i : indicesToDelete) {
		moveable* a = astroid[i];
		vector2D A;
		A.x = std::rand() % 512; A.y = std::rand() %728;
		a->Position = A;
		a->Rotation = std::rand() % 360;
		
	}
}
void astroids::draw(sf::RenderWindow* window) {
	for (moveable* a : astroid) {
		a->draw(window);
		//l->print();
	}
}

void astroids::newAstroid(vector2D pos, double dir, double speed) {
	moveable* newastroid = new moveable;
	vector2D direction = vector2D(cos(dir * 3.1415 / 180.0), sin(dir * 3.1415 / 180.0));
	newastroid->Acceleration = vector2D(0, 0);
	newastroid->Force = vector2D(0, 0);
	newastroid->Position = pos;
	newastroid->Velocity = direction * (speed / direction.magnitude());
	newastroid->Tex.loadFromFile("./astroid.png");
	newastroid->Spr.setTexture(newastroid->Tex);
	newastroid->mass = 10;
	newastroid->Rotation = dir;
	astroid.push_back(newastroid);
}