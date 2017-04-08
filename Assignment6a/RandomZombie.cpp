#include "RandomZombie.h"
#include <iostream>

RandomZombie::RandomZombie()
{
	setSymbol(" R");
	setPosition(0, 0);
	boundsX = 0;
	boundsY = 0;
}

RandomZombie::RandomZombie(int atX, int atY, int boundsX, int boundsY)
{
	setSymbol(" R");
	setPosition(atX, atY);
	this->boundsX = boundsX;
	this->boundsY = boundsY;
}

void RandomZombie::move()
{
	int roll;
	int newYposition = 0;
	int newXposition = 0;

	roll = rand() % 5;
	//roll = 4;

	switch (roll)
	{
	case 0: // Move North
		newYposition = positionY - 1;
		if (newYposition < 0)
		{
			setPositionY(boundsY - 1);
		}
		else
		{
			setPositionY(newYposition);
		}
		break;

	case 1: // Move West
		newXposition = positionX - 1;
		if (newXposition < 0)
		{
			setPositionX(boundsX - 1);
		}
		else
		{
			setPositionX(newXposition);
		}
		break;

	case 2: // Move South
		newYposition = positionY + 1;
		if (newYposition >= boundsY)
		{
			setPositionY(0);
		}
		else
		{
			setPositionY(newYposition);
		}
		break;

	case 3: // Move East
		newXposition = positionX + 1;
		if (newXposition >= boundsX)
		{
			setPositionX(0);
		}
		else
		{
			setPositionX(newXposition);
		}
		break;

	default:
		break; // if a 4 is rolled, don't move
	}
}
