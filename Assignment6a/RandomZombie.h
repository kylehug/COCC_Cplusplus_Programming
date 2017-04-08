#ifndef RANDOMZOMBIE_H
#define RANDOMZOMBIE_H

#include "Zombie.h"

class RandomZombie : public Zombie
{
public:
	// Create a Game Object
	RandomZombie();

	// Spawn a new Game Object at position (X Position, Y Position)
	RandomZombie(int atX, int atY, int boundsX, int boundsY);

	// Moves the Object a space in a direction	
	void move();
};
#endif