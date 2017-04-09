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
#include "Human.h"

class GameEngine
{
private:

	GameBoard board;
	int board_x_width;
	int board_y_height;
	int ZombieSpawnChance;
	vector<Zombie *> zombies;
	vector<Human *> humans;

	// Draws the game world to the screen
	void Tick();

	// Spawn a random zombie type at a random location
	void SpawnRandomZombie(int rx = -1, int ry = -1);

	// Spawn a random human type at a random location
	void SpawnHuman(unsigned int spawnSeed);

public:
	// Run the Game
	void Run();

	// Default Constructor
	GameEngine();
};
#endif