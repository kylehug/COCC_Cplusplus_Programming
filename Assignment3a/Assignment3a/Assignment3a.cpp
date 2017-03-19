// COCC C++ - Kyle Hug - Assignment3a
//
//	Extras:
//		Added user input for the list

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Returns true or false depending on if input can be converted to a valid int
bool validateInput(string input) {
	
	bool is_valid = true;
	int i;
	
	// Try converting the input to an int
	try {

		i = stoi(input);
	}

	// If the error is due to an invalid argument
	catch (invalid_argument) {

		bool is_valid = false;	
	}

	// If the error is due to int overflow
	catch (out_of_range) {

		bool is_valid = false;
	}

	// Say something if the input is invalid.
	if (!is_valid) {

		cout << input << " is not a valid number.";
	}

	return is_valid;
}


int main()
{
	string userSize;
	string userValue;
	string pause;

	vector<int> v;

	bool inputValid = false;

	unsigned int i; // Unsigned to fix warnings, should be fine since it's just an iterator
	unsigned int j; // Unsigned to fix warnings, should be fine since it's just an iterator
	int temp;

	
	// Make sure that valid input is entered
	while (!inputValid) {

		cout << "\nEnter \"quit\" at anytime to end.\n\nSpecify the number of items: ";
		getline(cin, userSize);

		// End if the user entered quit
		if (userSize == "quit") {

			return 0;
		}

		// Check if the users input is a valid int
		inputValid = validateInput(userSize);
	}
		
	// Resize the vector to the user's specified size
	v.resize(stoi(userSize));

	// Input the vector values from the user
	for (i = 0; i < v.size(); i++) {
		
		// Reset the validation variable
		inputValid = false;

		while (!inputValid) {

			cout << "Enter item " << (i + 1) << ": ";
			getline(cin, userValue);

			// End if the user entered quit
			if (userValue == "quit") {

				return 0;
			}

			// Check if the users input is a valid int
			inputValid = validateInput(userValue);
		}

		// Add the user's value to the vector
		v.at(i) = stoi(userValue);
	}
	
	// Print out the full original list
	cout << "\nOriginal List: ";
	for (i = 0; i < v.size(); i++) {

		cout << v.at(i) << " ";
	}

	// Console Spacer
	cout << "\n\n";
	
	// Loop the current value
	for (i = 0; i < (v.size() - 1); i++) {
		
		// Loop the comparison value
		for (j = i + 1; j < (v.size()); j++) {
			
			// Report the numbers being compared
			cout << "  Comparing " << v.at(i) << " and " << v.at(j);
			
			// Swap if the current value is greater than the compared value
			if (v.at(i) > v.at(j)) {
				
				cout << " - Swapping " << v.at(i) << " and " << v.at(j);
				temp = v.at(i);
				v.at(i) = v.at(j);
				v.at(j) = temp;
			}

			cout << endl;
		}
	}

	// Print out the sorted list
	cout << "\nSorted List: ";
	for (i = 0; i < v.size(); i++) {

		cout << v.at(i) << " ";
	}

	// Console Spacer
	cout << "\n\n";

	// Add a pause at the end
	while (pause != "quit") {
		cout << "Enter \"quit\" to exit: ";
		getline(cin, pause);
	}
	
	return 0;
}

