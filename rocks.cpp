#include "rocks.h"

Rock::Rock()
{
	alive = true;
	points = 1;
	angle = random(0.0, 360.0);

	point.setX(random(-150, 150));
	point.setY(random(-150, 150));

	velocity.setDx(random(-1.0, 1.0)); //check
	if (velocity.getDx() == 0)
		velocity.setDx(0.5);

	velocity.setDy(random(-1.0, 1.0)); //check
	if (velocity.getDy() == 0)
		velocity.setDy(0.5);
}

BigRock::BigRock()
{
	size = BIG_ROCK_SIZE;
	spin = BIG_ROCK_SPIN;
}

void BigRock::draw()
{
	drawLargeAsteroid(point, spin);
}

int BigRock::hit()
{
	kill();
	return points;
}

MediumRock::MediumRock()
{
	size = MEDIUM_ROCK_SIZE;
	spin = MEDIUM_ROCK_SPIN;
}

void MediumRock::draw()
{
	drawMediumAsteroid(point, spin);
}

int MediumRock::hit()
{
	kill();
	return points;
}

SmallRock::SmallRock()
{
	size = SMALL_ROCK_SIZE;
	spin = SMALL_ROCK_SPIN;
}


void SmallRock::draw()
{
	drawSmallAsteroid(point, spin);
}

int SmallRock::hit()
{
	kill();
	return points;
}
