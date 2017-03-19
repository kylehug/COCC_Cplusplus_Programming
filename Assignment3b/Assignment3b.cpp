// COCC C++ - Kyle Hug - Assignment 3b
//
//  [x] Draw out a 2D Array of periods
//	[x] Change a point to be an asterisk 
//	[x] Draw a horizontal line
//	[ ] Draw a vertical line ( WORK IN PROGRESS )
//	[ ] Draw a diagonal line
//	[x] Using Loops show the array on screen
//
//	[ ] Clean up warnings
//

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

// Get a unique random integer
int GetRandInt(int max, int seedOffset) {
	
	int randInt;

	srand((unsigned)time(NULL) + seedOffset);
	randInt = rand() % max;

	return randInt;
}

int main()
{
	// Initialize the 2D Array, "image"
	const int X_SIZE = 70;
	const int Y_SIZE = 20;
	char image[X_SIZE][Y_SIZE];
	int x;
	int y;

	// Initialize asterisk variables
	int asterRandX;
	int asterRandY;

	// Initialize horizontal line variables
	const int H_LINE_WIDTH = 10;
	int hLineRandStart;
	int hLineRandYPos;
	
	string userInput = "y";

	// Pause at the end
	while (userInput == "y") {
		
		// Clear user input
		userInput = "";

		// This is an ugly way to clear the screen, but at least it's OS independent...
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		
		// Set up population of the asterisk
		asterRandX = GetRandInt(X_SIZE, 999);
		asterRandY = GetRandInt(Y_SIZE, -69);
	
		// Set up population of the horizontal line
		hLineRandStart = GetRandInt(X_SIZE, 42);
		hLineRandYPos = GetRandInt(Y_SIZE, 13);
		
		// Populate image
		for (x = 0; x < X_SIZE; x++) {
		
			for (y = 0; y < Y_SIZE; y++) {
			
				// Populate a random asterisk
				if ((x == asterRandX) && y == (asterRandY)) {
				
					image[x][y] = '*';
				}
				// Populate the horizontal line
				else if ((x >= hLineRandStart) && (x <= (hLineRandStart + H_LINE_WIDTH)) && (y == hLineRandYPos)) {

					image[x][y] = '-';

				}
			
				// Populate with a period
				else {
				
					image[x][y] = '.';
				}
			}
		}

		// Print out the image
		for (y = 0; y < Y_SIZE; y++) {
		
			// Offset image position on screen
			cout << '\t';

			for (x = 0; x < X_SIZE; x++) {
			
				cout << image[x][y];
			}
		
			cout << endl;
		}

		// Spacer
		cout << "\n\n";

		// Ask to quit or start over
		while ((userInput != "y") && (userInput != "n")) {

			cout << "Draw Again? [y/n]: ";
			getline(cin, userInput);
		}
	}

	return 0;
}

