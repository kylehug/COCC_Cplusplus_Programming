#include "Zombie.h"

using namespace std;

Zombie::Zombie()
{
	setSymbol(" Z");
	setPosition(0, 0);
}

Zombie::Zombie(int atX, int atY)
{
	setSymbol(" Z");
	setPosition(atX, atY);
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
