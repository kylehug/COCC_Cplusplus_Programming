
#include "GamePlayer.h"

void GamePlayer::SetGold(unsigned int newGold)
{
	goldCount = newGold;
}

void GamePlayer::ChangeGold(int addedGold)
{
	goldCount += addedGold;
}

const unsigned int GamePlayer::GetGold() const
{
	return goldCount;
}

GamePlayer::GamePlayer()
{
	SetPosition(0, 0);
	SetSymbol('@');
	SetGold(0);
}