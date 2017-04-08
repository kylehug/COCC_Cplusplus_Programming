#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include "GameBoard.h"
#include "EastZombie.h"
#include "NorthZombie.h"

class GameEngine
{
private:

	GameBoard board;
	const int BOARD_X_WIDTH = board.getXWidth();
	const int BOARD_Y_HEIGHT = board.getYHeight();
	vector<Zombie *> zombies;

	// Draws the game world to the screen
	void Tick();

public:
	// Run the Game
	void Run();

	// Default Constructor
	GameEngine();
};
#endif