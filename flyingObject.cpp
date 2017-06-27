/*************************************************************
* File: flyingObject.cpp
* Author: Amy Chambers
*
* Description: Contains the function bodies for flyingObject
*************************************************************/

#include "flyingObject.h"

#include <cassert>

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
}