#include "Game.h"
#include <iostream>

using namespace std;

int main()
{
	// Declares an empty vector of robots
	vector<robot> robots;
	
	// Declares a constant string to represent the game's name :D
	const string name = "Robot War";

	// Declares a game object with the name "Robot War"
	game game(name);

	// The game object calls its member fuction to read the contents of start.txt
	game.read_start(robots);

	// The game object calls its member fuction to read the contents of commands.txt
	game.read_commands(robots);

	// Returns the main function
	return 0;
}