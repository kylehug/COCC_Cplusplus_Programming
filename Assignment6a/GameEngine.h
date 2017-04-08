#include "GameBoard.h"

class GameEngine
{
private:

	GameBoard board;
	vector<Zombie *> zombies;

	// Draws the game world to the screen
	void Tick();

public:
	// Run the Game
	void Run();

	// Default Constructor
	GameEngine();
};