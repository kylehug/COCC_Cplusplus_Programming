// COCC C++ - Kyle Hug - Assignment 4c
//
//	GOALS:
//  [ ] Write a function that takes a target X and Y and a current X and Y, and modifies the current X and Y so they move one space closer to the target X and Y. 
//	[ ] If tx == x and ty == y, x and y should return unchanged
//	[ ] Allow the user to input source and target.
//	[ ] Write a loop that shows the progression of x and y as they move toward the target.
//
//	EXTRAS:
//	[ ] Draw a grid representing the world and show the current position as an @, the target as a +, and empty spaces as periods. Each step, redraw the grid so the user can see the progress.
//	[ ] Put a delay in between subsequent grid printouts.
//
//	[ ] Clean up warnings
//

//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Global constants defining image size
const int SIZE_Y = 25;
const int SIZE_X = 75;

// Function Declarations (Prototypes)
void generateTerrain(char image[SIZE_Y][SIZE_X]); // Populates the image with the base layer; Ground, Terrain, Board or whatever you want to call it.
void drawFrame(char image[SIZE_Y][SIZE_X]); // Draws the image on the screen

// Main function
int main() {

	// Local Variable Declarations
	string userPause;
	vector<int> targetPosition(2);
	vector<int> currentPosition(2);
	char image[SIZE_Y][SIZE_X];
	
	// Put in the ground
	generateTerrain(image);

	// Draw the image on screen
	drawFrame(image);

	cout << "Type something and press enter to exit...";
	cin >> userPause;
	
	return 0;
}

// Populates the image with the base layer; Ground, Terrain, Board or whatever you want to call it.
void generateTerrain(char image[SIZE_Y][SIZE_X]) {
	
	// Local Variable Declarations
	int y;
	int x;

	// Populate the image with periods
	for (y = 0; y < SIZE_Y; y++) {

		for (x = 0; x < SIZE_X; x++) {

			image[y][x] = '.';
		}
	}
	return;
}

// Redraws the image on the screen
void drawFrame(char image[SIZE_Y][SIZE_X]) { // BEEJ: Can you explain this syntax for a 2D array parameter to me? - "char (&image)[][]" I don't understand why the brackets around "&image" are neccessary.

	// Local Variable Declarations
	int y;
	int x;

	for (y = 0; y < SIZE_Y; y++) {

		for (x = 0; x < SIZE_X; x++) {

			cout << ".";
		}

		cout << endl;
	}
	
	return;
}