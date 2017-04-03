
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

void GameObject::SetPosition(int newX, int newY)
{
	positionX = newX;
	positionY = newY;
}

void GameObject::SetPositionX(int newX)
{
	positionX = newX;
}

void GameObject::SetPositionY(int newY)
{
	positionY = newY;
}

void GameObject::Move(int moveX, int moveY)
{
	positionX += moveX;
	positionY += moveY;
}

const int GameObject::GetPositionX() const
{
	return positionX;
}

const int GameObject::GetPositionY() const
{
	return positionY;
}