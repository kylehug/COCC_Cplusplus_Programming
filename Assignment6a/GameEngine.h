#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <time.h>
#include "GameBoard.h"
#include "EastZombie.h"
#include "NorthZombie.h"
#include "RandomZombie.h"

class GameEngine
{
private:

	GameBoard board;
	int board_x_width;
	int board_y_height;
	int spawnChance;
	vector<Zombie *> zombies;

	// Draws the game world to the screen
	void Tick();

	// Spawn a random zombie type at a random location
	void SpawnRandomZombie();

public:
	// Run the Game
	void Run();

	// Default Constructor
	GameEngine();
};
#endif