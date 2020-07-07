#include "moveable.h"
void moveable::move() {
	double dt = 0.01;
	Acceleration = Force * (1 / mass);
	Velocity = Velocity + Acceleration * dt;
	Position = Position + Velocity * dt;
}

vector2D moveable::getNextPos() {
	double dt = 0.01;
	return Position + (Velocity + (Force * (1 / mass)) * dt) * dt;
}

void moveable::round() {
	if (Velocity.magnitude() < eps)
		Velocity = vector2D(0.0, 0.0);
	if (Acceleration.magnitude() < eps)
		Acceleration = vector2D(0.0, 0.0);
}
vector2D moveable::collisionWithWall(int whereCol) {
	//Position = Position + Velocity * (-1);
	vector2D dir;
	if (whereCol == 1) {
		Rotation = 180 - Rotation;
		dir = vector2D(cos((3.1415 / 180.0) * Rotation), sin((3.1415 / 180.0) * Rotation));
		Velocity = dir * Velocity.magnitude();
	}
	if (whereCol == 2) {
		Rotation = -Rotation;
		dir = vector2D(cos((3.1415 / 180.0) * Rotation), sin((3.1415 / 180.0) * Rotation));
		Velocity = dir * Velocity.magnitude();
	}

	return dir;
}