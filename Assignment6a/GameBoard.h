#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <string>
#include <vector>
#include <iostream>
#include "Zombie.h"

using namespace std;

class GameBoard
{
private:
	
	// Private Data Members
	static const int X_WIDTH = 20;
	static const int Y_HEIGHT = 18;
	string empty;
	string boardImage[Y_HEIGHT][X_WIDTH];

public:

	// Default Constructor
	GameBoard();

	// Reinitializes the board with empty spaces
	void clearBoard();

	// Draw the gameboard to the screen
	void drawBoard(vector <Zombie *> drawZombies);

	// Get the X width of the board
	int getXWidth() const;

	// Get the y height of the board
	int getYHeight() const;
};
#endif