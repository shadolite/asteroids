/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *********************************************************************/

// These are needed for the getClosestDistance function...

#include "game.h"

using namespace std;

/***************************************
* GAME CONSTRUCTOR
***************************************/
Game::Game(Point tl, Point br)
	: topLeft(tl), bottomRight(br)
{
	// Set up the initial conditions of the game
	score = 0;

	// Add rocks to the game's vector.
	for (int i = 0; i < AMOUNT_ROCK; i++)
	{
		Rock * pRock;
		pRock = new BigRock;
		vRocks.push_back(pRock);
	}
}

/****************************************
* GAME DESTRUCTOR
****************************************/
Game :: ~Game()
{
	// check for dead rock
	vector<Rock*>::iterator rockIt = vRocks.begin();
	while (rockIt != vRocks.end())
	{
		Rock* pRock = *rockIt;

		// If we had a list of pointers, we would need to delete the memory here...
		delete pRock;
		pRock = NULL;

		// Remove from list and advance
		rockIt = vRocks.erase(rockIt);
	}

	// Look for dead bullets
	vector<Bullet>::iterator bulletIt = bullets.begin();
	while (bulletIt != bullets.end())
	{
		Bullet bullet = *bulletIt;

		// Remove from list and advance
		bulletIt = bullets.erase(bulletIt);
	}
}

/***************************************
* GAME :: ADVANCE
* advance the game one unit of time
***************************************/
void Game::advance()
{
	advanceBullets();
	advanceRocks();
	advanceShip();

	handleCollisions();
	cleanUpZombies();
}

/***************************************
* GAME :: ADVANCE BULLETS
* Go through each bullet and advance it.
***************************************/
void Game::advanceBullets()
{
	// Move each of the bullets forward if it is alive
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			// this bullet is alive, so tell it to move forward
			bullets[i].advance();

			if (!isOnScreen(bullets[i].getPoint()))
			{
				// the bullet has left the screen
				bullets[i].kill();
			}
		}
	}
}

/**************************************************************************
* GAME :: ADVANCE Asteroid
* If there is a rock, and it's alive, advance it
**************************************************************************/
void Game::advanceRocks()
{
	// Move each of the rocks forward if it is alive
	for (int i = 0; i < vRocks.size(); i++)
	{
		if (vRocks[i]->isAlive())
		{
			// this rock is alive, so tell it to move forward
			vRocks[i]->advance();
		}
	}
}

/**************************************************************************
* GAME :: ADVANCE Ship
* Check if the ship is alive, then draw it, then advance
**************************************************************************/
void Game::advanceShip()
{
	if (ship.isAlive())
	{
		ship.draw();
		ship.advance();
	}
}
/**************************************************************************
* GAME :: BREAK ROCK
* Create a rock of a specific type according to the rules of the game.
**************************************************************************/
void Game::breakRock(int rock)
{
	Rock * pRock;
	Velocity local = vRocks[rock]->getVelocity();

	if (vRocks[rock]->getSize() == BIG_ROCK_SIZE)
	{
		for (int i = 0; i < 3; i++)
		{
			switch (i)
			{
			case 0:
 				local.setDy(local.getDy() + 1.0);

   				pRock = new MediumRock;
				pRock->setPoint(vRocks[rock]->getPoint());
				pRock->setVelocity(local);
				break;
			case 1:
				local.setDy(local.getDy() - 1.0);

				pRock = new MediumRock;
				pRock->setPoint(vRocks[rock]->getPoint());
				pRock->setVelocity(local);
				break;
			case 2:
				local.setDx(local.getDx() + 2.0);

				pRock = new SmallRock;
				pRock->setPoint(vRocks[rock]->getPoint());
				pRock->setVelocity(local);
				break;
			}
			vRocks.push_back(pRock);
		}
	}

	else if (vRocks[rock]->getSize() == MEDIUM_ROCK_SIZE)
	{
		for (int i = 0; i < 2; i++)
		{
			switch (i)
			{
			case 0:
				local.setDx(local.getDx() + 3.0);

				pRock = new SmallRock;
				pRock->setPoint(vRocks[rock]->getPoint());
				pRock->setVelocity(local);
				break;
			case 1:
				local.setDx(local.getDx() - 3.0);

				pRock = new SmallRock;
				pRock->setPoint(vRocks[rock]->getPoint());
				pRock->setVelocity(local);
				break;
			}
			vRocks.push_back(pRock);
		}
	}
	pRock = NULL;
	delete pRock;
}

/**************************************************************************
* GAME :: IS ON SCREEN
* Determines if a given point is on the screen.
**************************************************************************/
bool Game::isOnScreen(const Point & point)
{
	return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
		&& point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
		&& point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
		&& point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
* GAME :: HANDLE COLLISIONS
* Check for a collision between a rock and a bullet.
**************************************************************************/
void Game::hitRock(int rock)
{
	score += vRocks[rock]->hit();

	if (vRocks[rock]->getSize() > SMALL_ROCK_SIZE && !vRocks[rock]->isAlive())
	{
		breakRock(rock);
	}
}

/**************************************************************************
* GAME :: HANDLE COLLISIONS
* Check for a collision between a rock and a bullet.
**************************************************************************/
void Game::handleCollisions()
{
	// now check for a hit (if it is close enough to any live bullets)
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			for (int j = 0; j < vRocks.size(); j++)
			{
				if (vRocks[j]->isAlive())
				{
					if (getClosestDistance(bullets[i], *vRocks[j]) <= bullets[i].getSize() + vRocks[j]->getSize())
					{
						bullets[i].kill();
						hitRock(j);
					}
				}
			}
		}
	}

	for (int j = 0; j < vRocks.size(); j++)
	{
		if (vRocks[j]->isAlive())
		{
			if (getClosestDistance(ship, *vRocks[j]) <= ship.getSize() + vRocks[j]->getSize())
			{
				ship.kill();
				vRocks[j]->kill();
			}
		}
	}
}

/**************************************************************************
* GAME :: CLEAN UP ZOMBIES
* Remove any dead objects (take bullets out of the list, deallocate rock)
**************************************************************************/
void Game::cleanUpZombies()
{
	// check for dead rock
	vector<Rock*>::iterator rockIt = vRocks.begin();
	while (rockIt != vRocks.end())
	{
		Rock* pRock = *rockIt;

		if (!pRock->isAlive())
		{
			// If we had a list of pointers, we would need to delete the memory here...
			delete pRock;
			pRock = NULL;

			// remove from list and advance
			rockIt = vRocks.erase(rockIt);
		}
		else
		{
			rockIt++; // advance
		}
	}

	// Look for dead bullets
	vector<Bullet>::iterator bulletIt = bullets.begin();
	while (bulletIt != bullets.end())
	{
		Bullet bullet = *bulletIt;

		if (!bullet.isAlive())
		{
			// remove from list and advance
			bulletIt = bullets.erase(bulletIt);
		}
		else
		{
			bulletIt++; // advance
		}
	}
}

/***************************************
* GAME :: HANDLE INPUT
* accept input from the user
***************************************/
void Game::handleInput(const Interface & ui)
{
	// Change the direction of the ship
	if (ui.isLeft())
	{
		ship.moveLeft();
	}

	if (ui.isRight())
	{
		ship.moveRight();
	}

	if (ui.isUp())
	{
		ship.shipThrustUp();
	}

	if (ui.isDown())
	{
		ship.shipThrustDown();
	}

	// Check for "Spacebar
	if (ui.isSpace())
	{
		if (ship.isAlive())
		{
			Bullet newBullet;
			newBullet.fire(ship.getVelocity(), ship.getPoint(), ship.getAngle());
			bullets.push_back(newBullet);
		}
	}
}

/*********************************************
* GAME :: DRAW
* Draw everything on the screen
*********************************************/
void Game::draw(const Interface & ui)
{
	// draw the rock
		// draw the ship
	if (ship.isAlive())
	{
		ship.draw();
	}

	for (int i = 0; i < vRocks.size(); i++)
	{
		if (vRocks[i]->isAlive())
		{
			vRocks[i]->draw();
		}
	}

	//// draw the bullets, if they are alive
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			bullets[i].draw();
		}
	}

	// Put the score on the screen
	Point scoreLocation;
	scoreLocation.setX(topLeft.getX() + 5);
	scoreLocation.setY(topLeft.getY() - 5);

	drawNumber(scoreLocation, score);
}

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game :: getClosestDistance(FlyingObject &obj1, FlyingObject &obj2)
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }   
   return sqrt(distMin);
}


