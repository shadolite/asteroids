#include "ship.h"

// Put your ship methods here

Ship::Ship()
{
	angle = random(0.0, 360.0);
	size = SHIP_SIZE;
	alive = true;
}

void Ship::draw()
{
	drawShip(point, angle, thrust);
	thrust = false;
}

void Ship::moveRight()
{
	angle -= 6;
}

void Ship::moveLeft()
{
	angle += 6;
}

float Ship::getAngle()
{
	return angle;
}

void Ship::shipThrustUp()
{
	thrust = true;
	velocity.setDx(velocity.getDx() + THRUST_AMOUNT * (-sin(M_PI / 180 * angle)));
	velocity.setDy(velocity.getDy() + THRUST_AMOUNT * (cos(M_PI / 180 * angle)));
}

void Ship::shipThrustDown()
{
	thrust = true;
	velocity.setDx(velocity.getDx() + DOWN_THRUST_AMOUNT * (-sin(M_PI / 180 * angle)));
	velocity.setDy(velocity.getDy() + DOWN_THRUST_AMOUNT * (cos(M_PI / 180 * angle)));
}