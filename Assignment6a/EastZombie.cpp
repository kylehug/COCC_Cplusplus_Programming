#include "EastZombie.h"

EastZombie::EastZombie()
{
	setSymbol(" E");
	setPosition(0, 0);
}

EastZombie::EastZombie(int atX, int atY)
{
	setSymbol(" E");
	setPosition(atX, atY);
}

void EastZombie::move()
{
	setPositionX(positionX + 1);
}
