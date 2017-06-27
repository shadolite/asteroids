#include "rocks.h"

Rock::Rock()
{
}

BigRock::BigRock()
{
	size = BIG_ROCK_SIZE;
	spin = BIG_ROCK_SPIN;
}

void BigRock::draw()
{
	drawLargeAsteroid(point, size);
}

int BigRock::hit()
{
	return 0;
}

MediumRock::MediumRock()
{
	size = MEDIUM_ROCK_SIZE;
	spin = MEDIUM_ROCK_SPIN;
}

void MediumRock::draw()
{
	drawMediumAsteroid(point, size);
}

int MediumRock::hit()
{
	return 0;
}

SmallRock::SmallRock()
{
	size = SMALL_ROCK_SIZE;
	spin = SMALL_ROCK_SPIN;
}

void SmallRock::draw()
{
	drawSmallAsteroid(point, size);
}

int SmallRock::hit()
{
	return 0;
}
