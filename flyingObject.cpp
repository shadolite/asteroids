/*************************************************************
* File: flyingObject.cpp
* Author: Amy Chambers
*wrap function if 200 -200, if -200 200
if ><
else if

velocity.setDx(velocity.getDx() + MOVE_AMT * (-sin(M_Pi/180 * angle))

Dan: the other one would be cos

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