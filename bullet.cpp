#include "bullet.h"

/*************************************************************
* File: bullet.cpp
* Author: Amy Chambers
*
* Description: Contains the function bodies for Bullet
*************************************************************/
Bullet::Bullet()
{
	alive = true;
	hp = BULLET_LIFE;
	size = BULLET_SIZE;
};

void Bullet::fire(Velocity shipVelocity, const Point shipPoint, const float shipAngle)
{
	setPoint(shipPoint);
	float Dx = BULLET_SPEED * (-sin(M_PI / 180.0 * shipAngle));
	float Dy = BULLET_SPEED * (cos(M_PI / 180.0 * shipAngle));

	velocity.setDx(Dx + shipVelocity.getDx());
	velocity.setDy(Dy + shipVelocity.getDx());
}

void Bullet::draw()
{
	drawDot(point);

	hp -= 1;

	if (hp == 0)
	{
		alive = false;
	}
}