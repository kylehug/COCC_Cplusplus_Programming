// "METHOD"/"MEMBER FUNCTION" "DEFINITIONS" for the GameBoard "CLASS"
//
// GOOD PRACTICE:
//	Class definitions should always be done in the *.cpp file only, while declarations should be done in the *.h file.
//


#include "GameBoard.h"
#include <iostream>
#include <string>


using namespace std;


// boardSize "MUTATOR": Sets the 2D value of boardSize
void GameBoard::SetBoardSize(unsigned int newSizeX, unsigned int newSizeY)
{	
	//FIXME: Validate inputs as ints in a correct range. Maybe use a helper function. 
	boardSizeX = newSizeX;
	boardSizeY = newSizeY;
}


// boardSizeX "ACCESSOR"
const unsigned int& GameBoard::GetBoardSizeX() const // "const" makes the function's return value "IMMUTABLE"; cannot be altered. GOOD PRACTICE: Always make accessor functions immutable.
{
	return boardSizeX;
}


// boardSizeY "ACCESSOR"
const unsigned int& GameBoard::GetBoardSizeY() const // "const" makes the function's return value "IMMUTABLE"; cannot be altered. GOOD PRACTICE: Always make accessor functions immutable.
{
	return boardSizeX;
}


// Draws the Game Board to the screen
void GameBoard::Draw() const
{
	int y;
	int x;
	string userInput;

	cout << "Game Board Address: " << this << endl;
	cout << "Game Board Size X: " << boardSizeX << endl;
	cout << "Game Board Size Y: " << boardSizeY << endl;

	// Draw periods to represent the board, visually.
	for (y = 0; y < boardSizeY; y++)
	{
		for (x = 0; x < boardSizeX; x++)
		{
			cout << " .";
		}
		cout << endl;
	}

	// Don't close the game
	getline(cin, userInput);
}


// GameBoard "DEFAULT CONSTRUCTOR"
GameBoard::GameBoard()
{
	SetBoardSize(10, 10);
}


// GameBoard "OVERLOADED CONSTRUCTOR"
GameBoard::GameBoard(unsigned int sizeX, unsigned int sizeY)
{
	SetBoardSize(sizeX, sizeY);
}