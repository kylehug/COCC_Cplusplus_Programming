// COCC C++ - Kyle Hug - Assignment 4c
//
//	GOALS:
//  [X] 1. Write a function that takes a target X and Y and a current X and Y, and modifies the current X and Y so they move one space closer to the target X and Y. 
//	[X] 2. If tx == x and ty == y, x and y should return unchanged
//	[ ] 3. Allow the user to input source and target.
//	[X] 4. Write a loop that shows the progression of x and y as they move toward the target.
//
//	EXTRAS:
//	[ ] Draw a grid representing the world and show the current position as an @, the target as a +, and empty spaces as periods. Each step, redraw the grid so the user can see the progress.
//	[ ] Put a delay in between subsequent grid printouts.
//
//	[ ] Clean up warnings
//
//
//	BEEJ:
//	The function "advanceToTarget" should satisfy goals 1, 2 and 4.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Global constants defining board size
const int SIZE_Y = 15;
const int SIZE_X = 20;

// Function Declarations (Prototypes)
bool parsePositionFromUserInput(string userInput, vector<int>& position); // Extract a valid position vector2 from a user input string
vector<int> advanceToTarget(vector<int>& current, vector<int>& target); // Advances the current position toward the target
void makeBoard(char image[SIZE_Y][SIZE_X]); // Initialize the board
void drawImage(char image[SIZE_Y][SIZE_X]); // Draws the board on the screen

// Main function
int main() {

	// Local Variable Declarations
	string userInput;
	bool validInput = false;
	vector<int> targetPos(2);
	vector<int> currentPos(2);
	char board[SIZE_Y][SIZE_X];
	
	// TODO: Allow the user to specify starting and target positions.
	currentPos.at(0) = 10;
	currentPos.at(1) = 15;
	targetPos.at(0) = 1;
	targetPos.at(1) = 2;
	
	/*
	while (!validInput) {
		cout << "Specify the Current (Y,X) position between \"0,0\" and \"15,20\": ";
		getline(cin, userInput);
		validInput = parsePositionFromUserInput(userInput, currentPos);
	}
	*/

	while (currentPos != targetPos) {
		
		// Move the character
		advanceToTarget(currentPos, targetPos);
	}
	
	// Initialize the board
	//makeBoard(board);

	// Draw the board on screen
	//drawImage(board);

	userInput.clear();
	cout << "Type something and press enter to exit...";
	getline(cin, userInput);
	
	return 0;
}

// Extract a valid position vector2 from a user input string
bool parsePositionFromUserInput(string userInput, vector<int>& position) {
	return false;
}

// Advances the current position toward the target
vector<int> advanceToTarget(vector<int>& current, vector<int>& target) {

	// Local Variable Declarations
	int y;
	int x;

	// Report current position and target position
	cout << "At " << current.at(0) << ',' << current.at(1) << " going to ";
	cout << target.at(0) << ',' << target.at(1) << endl;

	// Handle y axis movement. Advance toward the target.
	if (current.at(0) > target.at(0)) {

		current.at(0) -= 1;
	}
	else if (current.at(0) < target.at(0)) {

		current.at(0) += 1;
	}

	// Handle x axis movement. Advance toward the target.
	if (current.at(1) > target.at(1)) {

		current.at(1) -= 1;
	}
	else if (current.at(1) < target.at(1)) {

		current.at(1) += 1;
	}

	// Report once target is reached
	if (current == target) {

		cout << "Target reached\n";
	}
	return current;
}

// Poluates the board 2d array with a base "Board" layer
void makeBoard(char image[SIZE_Y][SIZE_X]) {
	
	// Local Variable Declarations
	int y;
	int x;

	// Populate the board with periods
	for (y = 0; y < SIZE_Y; y++) {

		for (x = 0; x < SIZE_X; x++) {

			image[y][x] = '.';
		}
	}
	return;
}

// Redraws the board on the screen
void drawImage(char image[SIZE_Y][SIZE_X]) {

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