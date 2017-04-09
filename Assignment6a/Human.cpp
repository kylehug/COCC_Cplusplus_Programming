#include "Human.h"

Human::Human()
{
	setSymbol(" H");
	setPosition(0, 0);
	boundsX = 0;
	boundsY = 0;
}

Human::Human(int atX, int atY, int boundsX, int boundsY)
{
	setSymbol(" H");
	setPosition(atX, atY);
	this->boundsX = boundsX;
	this->boundsY = boundsY;
}

void Human::move()
{
	int roll;
	int newYposition = 0;
	int newXposition = 0;

	roll = rand() % 20; // Humans don't move around as much as zombies. They'll stand still more often.

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
		break; // if a 4 or higher is rolled, don't move
	}
}
