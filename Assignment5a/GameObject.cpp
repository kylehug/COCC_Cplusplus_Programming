
#include "GameObject.h"

GameObject::GameObject()
{
	SetSymbol('?');
	SetPosition(0, 0);
}

GameObject::GameObject(int atX, int atY)
{
	SetSymbol('?');
	SetPosition(atX, atY);
}

void GameObject::SetSymbol(char newSymbol)
{
	symbol = newSymbol;
}

const char GameObject::GetSymbol() const
{
	return symbol;
}

void GameObject::SetPosition(unsigned int newX, unsigned int newY)
{
	positionX = newX;
	positionY = newY;
}

void GameObject::Move(int moveX, int moveY)
{
	positionX += moveX;
	positionY += moveY;
}

const unsigned int GameObject::GetPositionX() const
{
	return positionX;
}

const unsigned int GameObject::GetPositionY() const
{
	return positionY;
}