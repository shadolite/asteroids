/*************************************************************
* File: flyingObject.cpp
* Author: Amy Chambers
*
	velocity.setDx(velocity.getDx() + MAX_SPEED * (-sin(M_PI / 180 * angle));
* Description: Contains the function bodies for flyingObject
*************************************************************/

#include "flyingObject.h"

Velocity FlyingObject::getVelocity() const
{
	return velocity;
}

void FlyingObject::setVelocity(Velocity velocity)
{
	this->velocity = velocity;
}

Point FlyingObject::getPoint() const
{
	return point;
}

void FlyingObject::setPoint(Point point)
{
	this->point = point;
}

void FlyingObject::kill()
{
	alive = false;
}

bool FlyingObject::isAlive()
{
	return alive;
}

void FlyingObject::advance()
{
	point.setX(point.getX() + velocity.getDx());
	point.setY(point.getY() + velocity.getDy());
	wrap();
}

void FlyingObject::wrap()
{
	if (point.getX() > 200)
	{
		point.setX(-200);
	}

	else if (point.getX() < -200)
	{
		point.setX(200);
	}

	if (point.getY() > 200)
	{
		point.setY(-200);
	}

	else if (point.getY() < -200)
	{
		point.setY(200);
	}
}

float FlyingObject::getSize()
{
	return size;
}