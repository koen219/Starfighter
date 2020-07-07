#include "laser.h"

void laser::shoot(vector2D pos, double dir, double speed) {
	if (counter < 0.01) {
		counter = cooldown;
		moveable* newlaser = new moveable;
		vector2D direction = vector2D(cos(dir * 3.1415 / 180.0), sin(dir * 3.1415 / 180.0));
		newlaser->Acceleration = vector2D(0, 0);
		newlaser->Force = vector2D(0, 0);
		newlaser->Position = pos;
		newlaser->Velocity = direction * (speed / direction.magnitude());
		newlaser->Tex.loadFromFile("./laser.png");
		newlaser->Spr.setTexture(newlaser->Tex);
		newlaser->mass = 1;
		newlaser->Rotation = dir;
		lasers.push_back(newlaser);
	}
}

void laser::move() {
	if (counter <= 0.0)
		counter = 0.0;
	else
		counter -= 0.0001;
	
	std::vector<int> indicesToDelete;
	for (int i = 0; i < lasers.size(); i++) {
		moveable* l = lasers[i];
		vector2D nextPos = l->getNextPos();
		if (nextPos.x < 16 or nextPos.x + 16>512) {
			l->Velocity = l->collisionWithWall(1) *l->Velocity.magnitude();
			if (int(l->Position.x) % 3 == 0) {
				indicesToDelete.push_back(i);
			}
		}
		else {
			if (nextPos.y < 16 or nextPos.y + 16 > 768) {
				l->Velocity = l->collisionWithWall(2) * l->Velocity.magnitude();
				if (int(l->Position.x) % 3 == 0) {
					indicesToDelete.push_back(i);
				}
			}
			else {
				l->move();
			}
		}

		/*if (l->Position.x < 0 or l->Position.x > 512 or l->Position.y < 0 or l->Position.y > 768) {
			if (int(l->Position.x) % 3 == 0) {
				indicesToDelete.push_back(i);
			}
			else {
				l->move();
			}

		}*/
	}
	for (int i : indicesToDelete) {
		moveable* l = lasers[i];
		lasers.erase(lasers.begin() + i);
		delete l;
	}
}
void laser::draw(sf::RenderWindow* window) {
	for (moveable* l : lasers) {
		l->draw(window);
		//l->print();
	}
}