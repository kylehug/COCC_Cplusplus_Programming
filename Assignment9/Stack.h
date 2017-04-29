#include "IntStackNode.h"

class Stack
{
private:

	// Head declaration
	IntStackNode *top;

public:

	// Constructor
	Stack();

	// Destructor
	~Stack();

	// Add item to stack
	void push(int n);

	// Remove item from stack
	int pop();

	// Print the top item in the stack
	void peek();

	// Check if the stack is empty
	bool isEmpty();
};