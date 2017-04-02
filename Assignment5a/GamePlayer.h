// Extends "GameObject"

#pragma once

#include "GameObject.h"

class GamePlayer : public GameObject
{
private:

	unsigned int goldCount;

public:
	// Set a new amount of gold for the Player.
	void SetGold(unsigned int newGold);

	// Add/subtract to the amount of gold that the Player has.
	void ChangeGold(int addedGold);

	// Get the current amount of gold that the Player has.
	const unsigned int GetGold() const;

	// Default Constructor
	GamePlayer();
};
