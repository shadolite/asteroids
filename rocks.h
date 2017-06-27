#ifndef rocks_h
#define rocks_h
#include "flyingObject.h"

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

//   Rock
class Rock : public FlyingObject
{
protected:
	int size;
	int points;
	int spin;

public:
	Rock();
	virtual int hit() = 0;
};

//   BigRock
class BigRock : public Rock
{
public:
	BigRock();
	virtual void draw();
	virtual int hit();
};

//   MediumRock
class MediumRock : public Rock
{
public:
	MediumRock();
	virtual void draw();
	virtual int hit();
};

//   SmallRock
class SmallRock : public Rock
{
public:
	SmallRock();
	virtual void draw();
	virtual int hit();
};

#endif /* rocks_h */