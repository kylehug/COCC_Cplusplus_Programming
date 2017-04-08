#ifndef EASTZOMBIE_H
#define EASTZOMBIE_H

#include "Zombie.h"

class EastZombie : public Zombie
{
public:
	// Create a Game Object
	EastZombie();

	// Spawn a new Game Object at position (X Position, Y Position)
	EastZombie(int atX, int atY);
	
	// Moves the Object a space in a direction	
	void move();
};
#endif