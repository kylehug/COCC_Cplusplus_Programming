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

void GameBoard::drawBoard(vector <Zombie *> drawZombies, vector <Human *> drawHumans)
{
	unsigned int z, h;
	int x, y, z_x, z_y, h_x, h_y;
	string z_symb, h_symb;

	// Clear the board
	clearBoard();

	// Composite the human symbols into the board image
	for (h = 0; h < drawHumans.size(); h++)
	{
		h_x		= drawHumans.at(h)->getPositionX();
		h_y		= drawHumans.at(h)->getPositionY();
		h_symb	= drawHumans.at(h)->getSymbol();
		boardImage[h_y][h_x] = h_symb;
	}
	
	// Composite the zombie symbols into the board image
	for (z = 0; z < drawZombies.size(); z++)
	{
		z_x		= drawZombies.at(z)->getPositionX();
		z_y		= drawZombies.at(z)->getPositionY();
		z_symb	= drawZombies.at(z)->getSymbol();
		boardImage[z_y][z_x] = z_symb;
	}

	// Clear the screen
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	// Print the stats
	cout << " The game will continue until all humans have been turned into zombies.\n\n";
	cout << " Zombie Count:  " << drawZombies.size() << endl;
	cout << " Human Count:   " << drawHumans.size() << endl;

	// Draw the image
	for (y = 0; y < Y_HEIGHT; y++)
	{
		for (x = 0; x < X_WIDTH; x++)
		{
			cout << boardImage[y][x];
		}
		cout << endl;
	}
	cout << "\n \"N\" (North-Moving Zombie)\n";
	cout << " \"E\" (East-Moving Zombie)\n";
	cout << " \"R\" (Random-Moving Zombie)\n";
	cout << " \"H\" (Human)\n";
}

int GameBoard::getXWidth() const
{
	return X_WIDTH;
}

int GameBoard::getYHeight() const
{
	return Y_HEIGHT;
}

