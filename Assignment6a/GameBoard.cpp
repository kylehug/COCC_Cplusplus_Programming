#include "GameBoard.h"

GameBoard::GameBoard()
{
	empty = " .";
	clearBoard();
}

void GameBoard::clearBoard()
{
	int x, y;

	// Populate the 2D array with the empty character.
	for (y = 0; y < Y_HEIGHT; y++)
	{
		for (x = 0; x < X_WIDTH; x++)
		{
			boardImage[y][x] = empty;
		}
	}
}

void GameBoard::drawBoard(vector <Zombie *> drawZombies)
{
	int x, y, z, z_x, z_y;
	string z_symb;

	// Clear the board
	clearBoard();

	// Composite the zombie symbols into the board image
	for (z = 0; (unsigned int)z < drawZombies.size(); z++)
	{
		z_x		= drawZombies.at(z)->getPositionX();
		z_y		= drawZombies.at(z)->getPositionY();
		z_symb	= drawZombies.at(z)->getSymbol();
		boardImage[z_y][z_x] = z_symb;
	}

	// Clear the screen
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	// Draw the image
	for (y = 0; y < Y_HEIGHT; y++)
	{
		for (x = 0; x < X_WIDTH; x++)
		{
			cout << boardImage[y][x];
		}
		cout << endl;
	}
}

int GameBoard::getXWidth() const
{
	return X_WIDTH;
}

int GameBoard::getYHeight() const
{
	return Y_HEIGHT;
}

