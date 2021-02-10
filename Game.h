#ifndef GAME_H
#define GAME_H

#include "Robot.h"
#include <string>
#include <vector>

class game
{
	/**
	* Private constant data member that represents the game's name
	*/
	const std::string _name;
public:
	/**
	* Constructor for the game object;
	*/
	explicit game(const std::string& n) : _name(n) {};
	/**
	* Destructor for the game object;
	*/
	~game() {};
	/**
	* Public member function that prints to the standard output the current positions of all the robots still in the system, in the same format as start.txt, but in ascending order of robot number.
	*/
	void show(std::vector<robot>& v);
	/*
	* Public member function that prints all the robots in the system, each with the total distance it has travelled. For example, if a robot has moved north 3 steps, east 1 step, and then south 2 steps, it has moved a total of 6 steps, even though it is only 2 positions from where it started.
	* Each line of the output consist of two numbers, the robot number and the distance travelled, and they are in increasing order of distance travelled. If two robots have travelled the same distance they are ordered by robot number.
	*/
	void travelled(std::vector<robot>& v);
	/*
	* Public member fuction that prints out the number of robots within n steps of the origin. (That is, the distance is n or less.) Each number is printed on a line by itself, with no extra text. The distance is the sum of the absolute values of the x- and y-coordinates (the Manhattan metric), so the distance to (2, -5) is 7.
	*/
	int within(std::vector<robot> &v, int &n);
	/*
	* Public member function that allows the game object to rotate robot r to the left
	*/
	void turnleft(robot& r);
	/*
	* Public member function that allows the game object to rotate robot r to the right
	*/
	void turnright(robot& r);
	/*
	* Public member function that allows the game object to move robot r one step in the direction that is facing
	*/
	void move(std::vector<robot>& r, int& n);
	/*
	* Public member function that reads contents of start.txt and validates good input such as positive robot's name and team. It creates robots and stores them in a vector
	*/
	void read_start(std::vector<robot>& v);
	/*
	* Public member function that reads the contents of commands.txt
	*/
	void read_commands(std::vector<robot>& v);

};

#endif