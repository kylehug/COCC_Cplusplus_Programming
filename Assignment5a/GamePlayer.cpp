
#include "GamePlayer.h"

void GamePlayer::SetGold(unsigned int newGold)
{
	goldCount = newGold;
}

void GamePlayer::ChangeGold(int addedGold)
{
	// Add/subtract the gold amount, but don't let it drop below 0.
	
	int totalGold = goldCount + addedGold;

	if (totalGold < 0)
	{
		goldCount = totalGold;
	}
	else
	{
		goldCount = 0;
	}
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