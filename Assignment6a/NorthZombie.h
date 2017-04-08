#ifndef NORTHZOMBIE_H
#define NORTHZOMBIE_H

#include "Zombie.h"

class NorthZombie : public Zombie
{
public:
	// Create a Game Object
	NorthZombie();

	// Spawn a new Game Object at position (X Position, Y Position)
	NorthZombie(int atX, int atY, int boundsX, int boundsY);

	// Moves the Object a space in a direction	
	void move();
};
#endif