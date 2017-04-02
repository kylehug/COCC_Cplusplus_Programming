#pragma once

using namespace std;

class GameBoard
{
private:

	unsigned int boardSizeX;
	unsigned int boardSizeY;

public:

	// Sets the x and y size of the game board.
	void SetBoardSize(unsigned int newSizeX, unsigned int newSizeY);

	// Read the x size of the game board.
	const unsigned int& GetBoardSizeX() const;

	// Read the y size of the game board.
	const unsigned int& GetBoardSizeY() const;

	// Create a GameBoard object
	GameBoard();

	// Create a GameBoard object with the specified X and Y dimentions
	GameBoard(unsigned int sizeX, unsigned int sizeY);
};