
#include "GameGold.h"

void GameGold::SetGoldValue(unsigned int newValue)
{
	goldValue = newValue;
}

const unsigned int GameGold::GetGoldValue() const
{
	return goldValue;
}

GameGold::GameGold()
{
	SetSymbol('*');
	SetGoldValue(5);
}

GameGold::GameGold(unsigned int positionX, unsigned int positionY, unsigned int value)
{
	SetSymbol('*');
	SetGoldValue(value);
	SetPosition(positionX, positionY);
}