/**
COCC C++ - Assignment 6A - Kyle Hug

	GOALS:
	[X] 1. Create a base class Zombie.
	[X] 2. From that create a number of derived classes.
	[X] 3. Each zombie subclass will have a move() method that will cause it to move.
	[X] 4. Write a function that spawns a number of Zombies stored in vector<*Zombie>.
	[X] 5. Use the "new" operator to create your zombies.
	[X] 6. Each step, show Zombies on screen, 20 wide and 10 tall.
	[X] 7. Each zombie type should be identified by a unique character.
	
	EXTRAS:
	[X] 1. Use a loop to add lots of zombies.
	[ ] 2. Make a class SlowZombie that only moves once every 2 frames.
	[ ] 3. Make zombies refuse to overlap eachother.
	[X] 4. Add instances of a person class.
	[ ] 5. Make the people (persons) run away.
	[ ] 6. Make instances of a "Chaser" zombie class that chases people.
	[X] 7. Turn caught people into random zombie type.
	[ ] 8. Add a damage value to zombies, when it reaches 100, remove them.
	[ ] 9. Make it so that people cause damage to zombies at a certain range.
	[ ] 10. Every 50 moves, randomly spawn a new person or zombie.
	[ ] 11. Balance everything so that it turns into a good battle.
	[ ] 12. Implement wass that creatures can't move through.
	[ ] 13. Make people hide behind walls.
	[ ] 14. Make zombies unable to see through walls.

	[ ] Fix Warnings

	NOTES FOR BEEJ:
	 - I set this up to start with a bunch of humans and just one zombie that turns the humans on to zombies on overlap. I thought this would be fun since you can watch the zombie plaque spread to the other humans. >:)
	 - Seems like I need an empty virtual "move" method in order to use the subclass' "move" when stored in a pointer array of baseclass, in this case Zombie. This seems kind of uneccessary. I left it in for the purpose of finishing the assignment, but how would I avoid having to do this?
	 - I'm still seeing some warnings with external libraries (time.h), I'm ignoring those.
	 - I'm using a 10x10 grid instead of 10x20, since I'm using spaces to make a more square, grid-like board.
*/

#include <string>
#include "GameEngine.h"

using namespace std;

int main()
{
	string userInput = "";
	bool validInput = false;

	GameEngine game;
	game.Run();

	while (!validInput) {

		cout << "\n Do you want to \"quit\" or \"restart\" ?\n >";
		getline(cin, userInput);

		// If the user wants to restart, call self to start over.
		if (userInput == "restart")
		{
			main();
			validInput = true;
		}

		// If the user wants to quit, return now to end
		else if (userInput == "quit")
		{
			validInput = true;
		}
	}

	return 0;
}

