// COCC C++ - Kyle Hug - Assignment 3b
//  - Draw out a 2D Array ( WORK IN PROGRESS )

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string userInput;
	
	// Initialize the 2D Array, "image"
	const int X_SIZE = 70;
	const int Y_SIZE = 20;
	char image[X_SIZE][Y_SIZE];
	int x;
	int y;

	// Populate image with periods
	for (x = 0; x < X_SIZE; x++) {
		
		for (y = 0; y < Y_SIZE; y++) {
			
			image[x][y] = '.';
		}
	}

	// Print out the image
	for (y = 0; y < Y_SIZE; y++) {
		
		for (x = 0; x < X_SIZE; x++) {
			
			cout << image[x][y];
		}
		
		cout << endl;
	}

	// Pause at the end
	while (userInput != "quit") {

		cout << "Enter \"quit\" to end: ";
		getline(cin, userInput);
	}

	return 0;
}

