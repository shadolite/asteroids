/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <limits>
#include <algorithm>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "bullet.h"
#include "rocks.h"
#include "ship.h"

#define CLOSE_ENOUGH 15
#define AMOUNT_ROCK 5
#define OFF_SCREEN_BORDER_AMOUNT 5


 /*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
	/*********************************************
	* Constructor
	* Initializes the game
	*********************************************/
	Game(Point tl, Point br);
	~Game();

	/*********************************************
	* Function: handleInput
	* Description: Takes actions according to whatever
	*  keys the user has pressed.
	*********************************************/
	void handleInput(const Interface & ui);

	/*********************************************
	* Function: advance
	* Description: Move everything forward one
	*  step in time.
	*********************************************/
	void advance();

	/*********************************************
	* Function: draw
	* Description: draws everything for the game.
	*********************************************/
	void draw(const Interface & ui);

private:
	// The coordinates of the screen
	Point topLeft;
	Point bottomRight;

	int score;

	Ship ship;
	std::vector<Bullet> bullets;
	std::vector<Rock *> vRocks;


	/*************************************************
	* Private methods to help with the game logic.
	*************************************************/
	bool isOnScreen(const Point & point);
	void advanceBullets();
	void advanceRocks();
	void advanceShip();
	void hitRock(int rock);
	void handleCollisions();
	void breakRock(int rock);
	void cleanUpZombies();
	float getClosestDistance(FlyingObject &obj1, FlyingObject &obj2);
};


#endif /* GAME_H */
