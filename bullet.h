/*************************************************************
* File: bird.h
* Author: Amy Chambers
*
* Description: Defines Bird
*************************************************************/
#ifndef bullet_h
#define bullet_h

#include "flyingObject.h"

#define BULLET_SPEED 5
#define BULLET_LIFE 40
#define BULLET_SIZE 1

class Bullet : public FlyingObject
{
public:
	Bullet();
	void fire(Velocity shipVelocity, const Point shipPoint, const float shipAngle);
	virtual void draw();
};
#endif /* bullet_h */