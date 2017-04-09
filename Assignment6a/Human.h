#ifndef HUMAN_H
#define HUMAN_H

#include "Zombie.h"

class Human : public Zombie
{
public:
	// Create a Game Object
	Human();

	// Spawn a new Game Object at position (X Position, Y Position)
	Human(int atX, int atY, int boundsX, int boundsY);

	// Moves the Object a space in a direction	
	void move();
};
#endif