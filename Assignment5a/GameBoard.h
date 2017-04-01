// "METHOD"/"MEMBER FUNCTION" "DECLARATIONS" for the GameBoard "CLASS"
//
// GOOD PRACTICE:
//	Class definitions should always be done in the *.cpp file only, while declarations should be done in the *.h file.
//

#pragma once

#include <vector>


using namespace std;


class GameBoard
{
public: // Accessible to the user

	/* "METHOD"/"MEMBER FUNCTION" ( CLASS FUNCTION ) DECLARATIONS */
	// GOOD PRACTICE:
	//	Use "Mutators" and "Accessor" methods to allow users to Set and Get data member values publicly */
	
	// boardSize "MUTATOR"
	void SetBoardSize(unsigned int newSizeX, unsigned int newSizeY);

	// boardSizeX "ACCESSOR"
	const unsigned int& GetBoardSizeX() const;

	// boardSizeY "ACCESSOR"
	const unsigned int& GetBoardSizeY() const;

	// Draws the Game Board to the screen
	void Draw() const;

	// GameBoard "DEFAULT CONSTRUCTOR"
	GameBoard();

	// GameBoard "OVERLOADED CONSTRUCTOR"
	GameBoard(unsigned int sizeX, unsigned int sizeY);

private: // Inaccessible to the user

	/* "DATA MEMBER" ( CLASS VARIABLE ) DECLARATIONS */
	// GOOD PRACTICE:
	//	Data Members (class variables) should always be "private" (user-inaccessible).


	// Specifies the two dimentional size of the game baord
	unsigned int boardSizeX;
	unsigned int boardSizeY;

	/* "METHOD"/"MEMBER FUNCTION" ( CLASS FUNCTION ) DECLARATIONS */
};