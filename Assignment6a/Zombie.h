#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

using namespace std;

class Zombie
{
protected:

	int positionX;
	int positionY;
	int boundsX;
	int boundsY;
	string symbol;

public:

	// Default Constructor
	Zombie();
	
	// Spawn a new Game Object at position (X Position, Y Position)
	Zombie(int atX, int atY, int boundsX, int boundsY);

	// Set the symbol used to represent the Game Object on the screen		
	void setSymbol(string newSymbol);

	// Get the symbol used to represent the Game Object on the screen	
	string getSymbol() const;

	// Sets the 2D position of the Game Object	
	void setPosition(int newX, int newY);

	// Sets the X position of the Game Object	
	void setPositionX(int newX);

	// Sets the Y position of the Game Object
	void setPositionY(int newY);

	// Get the X position of the Game Object
	const int getPositionX() const;

	// Get the Y position of the Game Object	
	const int getPositionY() const;
	
	// Moves the Object a space in a direction	
	virtual void move();

	// Destructor
	virtual ~Zombie(void);
};
#endif