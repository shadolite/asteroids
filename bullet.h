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
#define _USE_MATH_DEFINES

class Bullet : public FlyingObject
{
public:
	Bullet();
	void fire(const Point point, const float angle);
	virtual void draw();
};
#endif /* bullet_h */