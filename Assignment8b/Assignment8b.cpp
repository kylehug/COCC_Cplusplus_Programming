/**
COCC C++ - Assignment 8B - Kyle Hug

GOALS:
[X] Write a function add() that takes 4 parameters of arbitrary types and adds them together...

EXTRAS:
[X] What happens when you try add("A","B","C","D")? Why?
[X] What happens when you try add(string("A"),2,3,4)? Why?

*/

#include <iostream>
#include <string>
using namespace std;

template<typename typeA, typename typeB, typename typeC, typename typeD>
typeA add(typeA numA, typeB numB, typeC numC, typeD numD)
{
	return numA + numB + numC + numD;
}


int main()
{
	string userInput;

	cout << "\nExample with floats:\n\tadd(1.0, 2.0, 3.0, 4.0) = ";
	cout << add(1.0, 2.0, 3.0, 4.0) << endl;

	cout << "\nExample with ints:\n\tadd(1, 2, 3, 4) = ";
	cout << add(1, 2, 3, 4) << endl;

	cout << "\nExample with mixed number types:\n\tadd(1, 2, 3.0, 4.0) = ";
	cout << add(1, 2, 3.0, 4.0) << endl;

	cout << "\nExample with chars:\n\tadd('1', '2', '3', '4') = ";
	cout << add('1', '2', '3', '4') << endl;
	cout << "\n\tI think we get this result because it's adding the char ASCII values, resulting in a character at the index of the added value.\n";

	cout << "\nExample with strings:\n\tadd(\"A\", \"B\", \"C\", \"D\") = ";
	cout << add(string("A"), string("B"), string("C"), string("D")) << endl;
	cout << "\n\tI think we get this result because the string type has overridden the \"+\" operator to append strings, rather than add their character values.\n";

	cout << "\nExample with mixed ints/string:\n\tadd(\"A\", 2, 3, 4) = FAILS\n";
	//cout << add(string("A"), 2, 3, 4) << endl;
	cout << "\n\tI think this fails because the compiler gets confused between the two separate behaviors of the \"+\" operator with numerical types and strting types.";

	cout << "Any key to quit\n> ";
	getline(cin, userInput);

	return 0;
}
