#include <iostream>
#include "IntStackNode.h"

using namespace std;

IntStackNode::IntStackNode()
{
	cout << "IntStackNode: Default Constructor Called\n";
}

IntStackNode::IntStackNode(int value)
{
	cout << "IntStackNode: Constructor With Value Arg Called\n";
}

IntStackNode::IntStackNode(int value, IntStackNode *next)
{
	cout << "IntStackNode: Constructor With Value and Next Args Called\n";
}

IntStackNode::~IntStackNode()
{
	cout << "IntStackNode: Destructor Called\n";
}