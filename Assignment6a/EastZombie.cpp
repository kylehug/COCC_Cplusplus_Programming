#include "EastZombie.h"

EastZombie::EastZombie()
{
	setSymbol(" E");
	setPosition(0, 0);
	boundsX = 0;
	boundsY = 0;
}

EastZombie::EastZombie(int atX, int atY, int boundsX, int boundsY)
{
	setSymbol(" E");
	setPosition(atX, atY);
	this->boundsX = boundsX;
	this->boundsY = boundsY;
}

void EastZombie::move()
{
	int newXposition = getPositionX() + 1;

	// keep position within in the board bounds
	if (newXposition >= boundsX)
	{
		setPositionX(0);
	}
	else
	{
		setPositionX(newXposition);
	}
}
