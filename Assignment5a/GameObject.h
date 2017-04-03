// Sorry about all the extra comments. I intend to use this file as reference.

#pragma once

class GameObject
{

// "PRIVATE MEMBERS"
// (variables and functions that are unavailable outside of the class)
// GOOD PRACTICE:
//	Data Members (class variables) should always be "private" (user-inaccessible).
private: 

// DECLARES THE "DATA MEMBERS"
// (internal variables of the class)

	int positionX;
	int positionY;
	char symbol;

// "PUBLIC MEMBERS"
// (variables and functions available outside of the class)
public: 

// DECLARES THE "DEFAULT CONSTRUCTOR"
// (called automatically when an "OBJECT" of this class is created.)
	// Create a Game Object
	GameObject();

// DECLARES AN "OVERLOADED CONSTRUCTOR"
// (called automatically instead of the default constructor when these extra arguments are provided)
	// Spawn a new Game Object at position (X Position, Y Position)
	GameObject(int atX, int atY);

// DECLARES "METHODS", ALSO CALLED "MEMBER FUNCTIONS"
// (internal functions of the class)
	
	// Set the symbol used to represent the Game Object on the screen		
	void SetSymbol(char newSymbol); // "MUTATOR" (changes a data member's value)
	
	// Get the symbol used to represent the Game Object on the screen	
	const char GetSymbol() const; // "ACCESSOR" (reads a data member's value) "const" makes the function's return value "IMMUTABLE"; cannot be altered. GOOD PRACTICE: Always make accessor functions immutable.
	
	// Sets the position of the Game Object	
	void SetPosition(int newX, int newY); // "MUTATOR" (changes data members' values)
	
	void SetPositionX(int newX);

	void SetPositionY(int newY);
															
	// Moves the Object 1 space in a direction	
	void Move(int moveX, int moveY); 
	
	// Get the X position of the Game Object
	const int GetPositionX() const; // "ACCESSOR" (reads a data member's value) "const" makes the function's return value "IMMUTABLE"; cannot be altered. GOOD PRACTICE: Always make accessor functions immutable.
	
	// Get the Y position of the Game Object	
	const int GetPositionY() const; // "ACCESSOR" (reads a data member's value) "const" makes the function's return value "IMMUTABLE"; cannot be altered. GOOD PRACTICE: Always make accessor functions immutable.
};