/**
COCC C++ - Assignment 7A - Kyle Hug
GOALS:
[X] Implement a Stack using a linked list.

EXTRAS:
[ ] Add a peek method to read the top item
[ ] Write code that tests the stack
[ ] Implement a copy constructor and copy assignment operator

*/

#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int main()
{
	string userInput;
	Stack theStack;
	
	while (userInput != "quit")
	{
		cout << "\nWhat do you want to do?\n> ";
		getline(cin, userInput);

		if (userInput == "push")
		{
			theStack.push(9);
		}
		else if (userInput == "pop")
		{
			theStack.pop();
		}
		else if (userInput == "quit")
		{
			break;
		}
		else
		{
			cout << "\nInvalid Input\n";
		}
	}
	return 0;
}
