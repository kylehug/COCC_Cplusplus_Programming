// COCC C++ - Kyle Hug - Assignment 4c
//
//	GOALS:
//	[X] 1. Write a function that takes a target X and Y and a current X and Y, and modifies the current X and Y so they move one space closer to the target X and Y. 
//	[X] 2. If tx == x and ty == y, x and y should return unchanged
//	[X] 3. Allow the user to input source and target.
//	[X] 4. Write a loop that shows the progression of x and y as they move toward the target.
//
//	EXTRAS:
//	[ ] Draw a grid representing the world and show the current position as an @, the target as a +, and empty spaces as periods. Each step, redraw the grid so the user can see the progress.
//	[ ] Put a delay in between subsequent grid printouts.
//
//	[X] Clean up warnings
//
//	NOTES FOR BEEJ:
//		The function "advanceToTarget" should satisfy goals 1, 2 and 4.
//		The "main" function and "parseUserInput" should satisfy goal 3.
//		There are currently some lines commented out which are WIP toward the extra goals. You can ignore them if I didn't get to these goals.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Global constants defining board size
const int SIZE_Y = 15;
const int SIZE_X = 20;

// Function Declarations (Prototypes)
bool parseUserInput(string userInput, vector<int>& position); // Extract a valid position vector2 from a user input string
vector<int> advanceToTarget(vector<int>& current, vector<int>& target); // Advances the current position toward the target
void makeBoard(char image[SIZE_Y][SIZE_X]); // Initialize the board
void drawImage(char image[SIZE_Y][SIZE_X]); // Draws the board on the screen
void clearScreen(int buffer=100); // Use the multi-newline hack to clear the screen

// Main function
int main() {

	// Local Variable Declarations
	string userInput;
	bool validInput = false;
	vector<int> targetPos(2);
	vector<int> currentPos(2);
	//char board[SIZE_Y][SIZE_X];
	
	/*
	// TODO: Allow the user to specify starting and target positions.
	currentPos.at(0) = 10;
	currentPos.at(1) = 15;
	targetPos.at(0) = 1;
	targetPos.at(1) = 2;
	*/
	
	// Get the user input for the start (current) position
	clearScreen();
	while (!validInput) {
		
		cout << "\nSpecify the start (Y,X) position between \"0,0\" and \"" << SIZE_Y << "," << SIZE_X << "\":\n";
		getline(cin, userInput);
		validInput = parseUserInput(userInput, currentPos);

		// If the user wants to quit, return 0 now to end
		if (validInput && userInput == "quit") {

			return 0;
		}
	}

	clearScreen();
	cout << "\nStart Position Will be: " << currentPos.at(0) << ',' << currentPos.at(1) << endl;
	
	// Get the user input for the target position
	validInput = false;
	while (!validInput) {
		
		cout << "\nSpecify the Target (Y,X) position between \"0,0\" and \"" << SIZE_Y << "," << SIZE_X << "\":\n";
		getline(cin, userInput);
		validInput = parseUserInput(userInput, targetPos);

		// If the user wants to quit, return 0 now to end
		if (validInput && userInput == "quit") {

			return 0;
		}
	}

	// Display the user specified values before executing
	clearScreen();
	cout << "Start Position: " << currentPos.at(0) << ',' << currentPos.at(1) << endl;
	cout << "Target Position: " << targetPos.at(0) << ',' << targetPos.at(1) << endl << endl;
	
	while (currentPos != targetPos) {
		
		// Move the character
		advanceToTarget(currentPos, targetPos);
	}
	
	// Initialize the board
	//makeBoard(board);

	// Draw the board on screen
	//drawImage(board);

	// User must enter "quit" to end
	userInput.clear();
	while (userInput != "quit") {

		cout << "\nEnter \"quit\" to end:\n";
		getline(cin, userInput);
	}
}

// Extract a valid position vector2 from a user input string
bool parseUserInput(string userInput, vector<int>& position) {
	
	// Local Variable Declarations
	int commaPos = 0;
	
	// Return true if the user wants to quit
	if (userInput == "quit") {
		return true;
	}
	
	// Extract the values & catch any errors
	try {

		commaPos = userInput.find(',');
		
		if (commaPos == -1) {
			throw 1;
		}

		position.at(0) = stoi(userInput.substr(0, commaPos));
		position.at(1) = stoi(userInput.substr(commaPos + 1, userInput.length()));

		if ((position.at(0) > SIZE_Y) || (position.at(1) > SIZE_X)) {
			throw 2;
		}

		return true;
	}

	// Catch unique errors
	catch(int e) {

		// Catch missing comma 
		if (e == 1) {

			clearScreen();
			cout << "Invalid Input: No comma. Use format \"Y,X\"\n";
		}

		// Catch Y or X are larger than SIZE_X or SIZE_Y
		else if (e == 2) {

			clearScreen();
			cout << "Invalid Input : One or both values are out of the allowed range.\n";
		}
	}

	// Catch non-integer values
	catch (invalid_argument) {
		
		clearScreen();
		cout << "Invalid Input: Only integers are allowed. \"int,int\"\n";
	}

	catch (out_of_range) {

		clearScreen();
		cout << "Invalid Input: One or both values are way too large.\n";
	}
	
	// Catch everything else bad
	catch (...) {

		clearScreen();
		cout << "Invalid Input: Uknown Exception. Try again.\n";
	}

	return false;
}

// Advances the current position toward the target
vector<int> advanceToTarget(vector<int>& current, vector<int>& target) {

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

// Use the multi-newline hack to clear the screen
void clearScreen(int buffer) {
	
	// Declare Local variables
	int i;
	
	// Print a new line to console "buffer" times
	for (i = 0; i < buffer; i++) {

		cout << endl;
	}
}