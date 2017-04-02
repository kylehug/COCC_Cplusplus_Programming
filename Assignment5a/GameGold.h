// Extends GameObject

#pragma once

#include "GameObject.h"

class GameGold : public GameObject
{
private:

	unsigned int goldValue;

public:
	// Sets the gold value of the object
	void SetGoldValue(unsigned int newValue);

	// Gets the gold value of the object
	const unsigned int GetGoldValue() const;

	// Default Constructor
	GameGold();

	// Spawn a Gold Object at the specified location with the specified value
	GameGold(unsigned int positionX, unsigned int positionY, unsigned int value);
};