/**
COCC C++ - Assignment 9 - Kyle Hug

GOALS:
[X] Modify the stack from Assignment 8 (or 7) to throw an exception if the user attempts to pop() an empty stack.

EXTRAS:
[ ] Add a class StackException that subclasses (inherits) from runtime_error.

*/

#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int main()
{
	string userInput;
	Stack theStack;
	int i = 1;

	cout << "\nSTACK CONSOLE\nValid commands are \"push\", \"pop\", \"peek\" or \"quit\"\n";
	while (userInput != "quit")
	{
		cout << "\n> ";
		getline(cin, userInput);

		// Break if the user entered "quit"
		if (userInput == "quit")
		{
			break;
		}

		// Add next number to the stack if user enters "push"
		else if (userInput == "push")
		{
			theStack.push(i);
			i++;
		}

		// Remove the top item from the stack if the user enters "pop"
		else if (userInput == "pop")
		{
			// Make sure the stack isn't empty first
			if (!theStack.isEmpty())
			{
				theStack.pop();
			}
			else
			{
				cout << "\nThe Stack is Empty\n";
			}
		}

		// If the user enters peek
		else if (userInput == "peek")
		{
			theStack.peek();
		}

		// Error if the user input is unusable
		else
		{
			cout << "\nInvalid Input\n";
		}
	}
	return 0;
}