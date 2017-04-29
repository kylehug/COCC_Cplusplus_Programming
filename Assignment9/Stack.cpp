#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack()
{
	top = NULL;
	cout << "Stack: Created\n";
}

Stack::~Stack()
{
	cout << "Stack: Destroyed\n";
}

void Stack::push(int v)
{
	// Create the stack node
	IntStackNode *node = new IntStackNode;

	// Set the value of the node
	node->value = v;

	// Point to the next node
	node->next = top;

	// Set the top to be the new node
	top = node;

	// Print what happened
	cout << "Stack: Added item " << v << " to stack at address " << node << endl;

	return;
}

int Stack::pop()
{
	int r;

	try
	{
		if (isEmpty())
		{
			throw runtime_error("Runtime Error: The Stack is Empty.");
		}

		IntStackNode *node = top;
		r = node->value;

		// Set top to the next node before deleting the current top item
		top = top->next;

		// Delete the current top-most item
		delete node;

		// Print what happened
		cout << "Stack: Removed item " << r << " from the stack\n";
	}

	catch (runtime_error& e)
	{
		cout << e.what() << endl;
		r = NULL;
	}

	return r;
}

void Stack::peek()
{
	if (top != NULL)
	{
		cout << "Stack: Top item is " << top->value << " at address " << top << endl;
	}
	else
	{
		cout << "Stack: The Top item is empty\n";
	}

	return;
}

bool Stack::isEmpty()
{
	if (top == NULL) {
		return true;
	}
	else
	{
		return false;
	}
}