#include "rocks.h"

Rock::Rock()
{
	alive = true;
	points = 10;
	angle = random(0.0, 360.0);
}

BigRock::BigRock()
{
	size = BIG_ROCK_SIZE;
	spin = BIG_ROCK_SPIN;
	hp = 3;

	point.setX(random(-150.0, 150.0));
	point.setY(random(-150.0, 150.0));
	if ((point.getX() < 15.0 && point.getX() > -15.0) && (point.getY() < 15.0 && point.getY() > -15.0))
	{
		point.setX(-150.0);
		point.setY(50.0);
	}

	velocity.setDx(random(-1.0, 1.0));
	if (velocity.getDx() == 0)
		velocity.setDx(0.5);

	velocity.setDy(random(-1.0, 1.0));
	if (velocity.getDy() == 0)
		velocity.setDy(0.5);
}

void BigRock::draw()
{
	drawLargeAsteroid(point, spin += BIG_ROCK_SIZE);
}

int BigRock::hit()
{
	--hp;

	if (hp < 1)
	{
		kill();
		return points + 70;
	}

	return points;
}

MediumRock::MediumRock()
{
	size = MEDIUM_ROCK_SIZE;
	spin = MEDIUM_ROCK_SPIN;
	hp = 2;
}

void MediumRock::draw()
{
	drawMediumAsteroid(point, spin += MEDIUM_ROCK_SIZE);
}

int MediumRock::hit()
{
	--hp;

	if (hp < 1)
	{
		kill();
		return points + 30;
	}

	return points;
}

SmallRock::SmallRock()
{
	size = SMALL_ROCK_SIZE;
	spin = SMALL_ROCK_SPIN;
	hp = 1;
}

void SmallRock::draw()
{
	drawSmallAsteroid(point, spin += SMALL_ROCK_SPIN);
}

int SmallRock::hit()
{
	kill();
	return points;
}
