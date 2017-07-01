#include "ship.h"

// Put your ship methods here

Ship::Ship()
{
}

void Ship::draw()
{
	drawShip(point, rotation, thrust);
}

void Ship::moveRight()
{
}

void Ship::moveLeft()
{
}

float Ship::getAngle()
{
	return angle;
}
