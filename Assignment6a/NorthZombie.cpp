#include "NorthZombie.h"

NorthZombie::NorthZombie()
{
	setSymbol(" N");
	setPosition(0, 0);
	boundsX = 0;
	boundsY = 0;
}

NorthZombie::NorthZombie(int atX, int atY, int boundsX, int boundsY)
{
	setSymbol(" N");
	setPosition(atX, atY);
	this->boundsX = boundsX;
	this->boundsY = boundsY;
}

void NorthZombie::move()
{
	int newYposition = getPositionY() - 1;

	// keep position within in the board bounds
	if (newYposition < 0)
	{
		setPositionY(boundsY - 1);
	}
	else
	{
		setPositionY(newYposition);
	}
}
