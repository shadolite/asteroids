#ifndef VELOCITY_H
#define VELOCITY_H

/*********************************************
* VELOCITY
* Velocity of flying objects.
*********************************************/
class Velocity
{
private:
	float Dx;
	float Dy;

public:
	//constructors
	Velocity() : Dx(0.0), Dy(0.0) {}
	Velocity(float Dx, float Dy) : Dx(0.0), Dy(0.0) {}

	//getters
	float getDx();
	float getDy();

	//setters
	void setDx(float Dx);
	void setDy(float Dy);
};
#endif /* velocity_h */
