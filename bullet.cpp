#include "bullet.h"
#include <cmath>

/*************************************************************
* File: bullet.cpp
* Author: Amy Chambers
*
* Description: Contains the function bodies for Bullet
*************************************************************/
Bullet::Bullet()
{
	point.setX(200);
	point.setY(-200);
	alive = true;
	hp = BULLET_LIFE;
};

void Bullet::fire(const Point point, const float angle)
{
	float Dx = BULLET_SPEED * (-cos(M_PI / 180.0 * angle));
	float Dy = BULLET_SPEED * (sin(M_PI / 180.0 * angle));

	velocity.setDx(Dx);
	velocity.setDy(Dy);
}

void Bullet::draw()
{
	drawDot(point);
}