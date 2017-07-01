#ifndef flyingObject_h
#define flyingObject_h
#define _USE_MATH_DEFINES

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class FlyingObject
{
protected:
	Point point;
	Velocity velocity;
	bool alive;
	int hp;

public:
	Velocity getVelocity() const;
	void setVelocity(Velocity velocity);
	Point getPoint() const;
	void setPoint(Point point);
	void kill();
	bool isAlive();
	void advance();
	virtual void draw() = 0;
};
#endif /* flyingObject_h */
