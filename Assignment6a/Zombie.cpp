#include "Zombie.h"

using namespace std;

Zombie::Zombie()
{
	setSymbol(" Z");
	setPosition(0, 0);
}

Zombie::Zombie(int atX, int atY, int boundsX, int boundsY)
{
	setSymbol(" Z");
	setPosition(atX, atY);
	this->boundsX = boundsX;
	this->boundsY = boundsY;
}

void Zombie::setSymbol(string newSymbol)
{
	symbol = newSymbol;
}

string Zombie::getSymbol() const
{
	return symbol;
}

void Zombie::setPosition(int newX, int newY)
{
	positionX = newX;
	positionY = newY;
}

void Zombie::setPositionX(int newX)
{
	positionX = newX;

	// keep position within in the board bounds
	if (positionX < 0)
	{
		positionX = 9;
	}
	else if (positionX > 9)
	{
		positionX = 0;
	}
}

void Zombie::setPositionY(int newY)
{
	positionY = newY;
}

const int Zombie::getPositionX() const
{
	return positionX;
}

const int Zombie::getPositionY() const
{
	return positionY;
}

// seems like I need an empty "move" method in order to use the subclass move when stored in a pointer array of baseclass
void Zombie::move()
{
	return;
}

Zombie::~Zombie(void)
{
	return;
}
