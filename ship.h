#ifndef ship_h
#define ship_h
#include "flyingObject.h"

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5
#define DOWN_THRUST_AMOUNT -0.5

class Ship : public FlyingObject
{
private:
	bool thrust;

public:
	Ship();
	virtual void draw();
	void moveRight();
	void moveLeft();
	float getAngle();
	void shipThrustUp();
	void shipThrustDown();
};
#endif /* ship_h */
