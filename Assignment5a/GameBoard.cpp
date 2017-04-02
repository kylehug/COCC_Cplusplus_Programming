// "METHOD"/"MEMBER FUNCTION" "DEFINITIONS" for the GameBoard "CLASS"
//
// GOOD PRACTICE:
//	Class definitions should always be done in the *.cpp file only, while declarations should be done in the *.h file.
//

#include "GameBoard.h"
#include <iostream>
#include <string>

using namespace std;

void GameBoard::SetBoardSize(unsigned int newSizeX, unsigned int newSizeY)
{	
	boardSizeX = newSizeX;
	boardSizeY = newSizeY;
}

const unsigned int& GameBoard::GetBoardSizeX() const 
{
	return boardSizeX;
}

const unsigned int& GameBoard::GetBoardSizeY() const 
{
	return boardSizeY;
}

GameBoard::GameBoard()
{
	SetBoardSize(10, 10);
}

GameBoard::GameBoard(unsigned int sizeX, unsigned int sizeY)
{
	SetBoardSize(sizeX, sizeY);
}