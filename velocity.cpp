/***********************************************************************
* Source File:
*    Velocity: Class definition for velocity of lander object
* Author:
*    Amy Chambers
* Summary:
*    Everything needed for manipulation of the lander velocity.
************************************************************************/

#include "velocity.h"

/******************************************
* getDx
*
*****************************************/
float Velocity::getDx()
{
	return Dx;
}

/******************************************
* getDy
*
*****************************************/
float Velocity::getDy()
{
	return Dy;
}

/******************************************
* setDx
*
*****************************************/
void Velocity::setDx(float Dx)
{
	this->Dx = Dx;
}

/******************************************
* setDy
*
*****************************************/
void Velocity::setDy(float Dy)
{
	this->Dy = Dy;
}