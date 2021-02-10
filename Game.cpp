#include "Game.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void game::show(vector<robot>& v)
{

	// Sorts the robots vector in ascending orber by its robot name
	sort(v.begin(), v.end(), [](robot& lr, robot& rr) {
		return lr.name() < rr.name();
		});
	// Loops through the robots vector
	for (auto i = v.begin(); i != v.end(); i++)
	{
		// If the iterated robot's name and team are bigger or equal 0
		if (i->name() >= 0 && i->team() >= 0)
		{
			// Outputs the robot's name, team, x and y positions 
			cout << i->name() << ' ' << i->team() << ' ' << i->x_position() << ' ' << i->y_position() << '\n';
		}
	}
}

void game::travelled(vector<robot>& v)
{
	// Sorts the robots vector in increasing order of distance travelled. If two robots have travelled the same distance, orders them by robot's name.
	sort(v.begin(), v.end(), [](robot& lr, robot& rr) {
		if (lr.name() != rr.name())
		{
			if (lr.travelled() != rr.travelled())
			{
				return lr.travelled() < rr.travelled();
			}
			else {}
			return lr.name() < rr.name();
		}
		else {}
		});

	// Loops through the robots vector
	for (auto i = v.begin(); i != v.end(); i++)
	{
		// If the iterated robot's name and team are bigger or equal 0
		if (i->name() >= 0 && i->team() >= 0)
		{
			// Outputs the robot's name, team, x and y positions 
			cout << i->name() << ' ' << i->travelled() << '\n';
		}
	}
}

int game::within(vector<robot>& v, int& n)
{
	// Declarations of a counter and a distance
	int counter = 0;
	int distance;

	// Looping through the robots vector using ranged for-loop
	for (auto r = v.begin(); r != v.end(); ++r)
	{
		// Sets the distance to be equivalent to the Manhattan Metric by calculating the robot's absolute values of x, y
		distance = abs(r->x_position()) + abs(r->y_position());

		// If the distance is less than or equals n
		if (distance <= n)
		{
			// Increments the counter
			++counter;
		}
	}
	// Outputs the result
	return counter;
}

void game::turnleft(robot& r)
{
	// Calling the robot's public member function
	r.turnleft(r);
}

void game::turnright(robot& r)
{
	// Calling the robot's public member function
	r.turnrightt(r);
}

void game::read_start(vector<robot>& v)
{
	// Object of the fstream class to operate on the files
	fstream fs;
	// Opening the file
	fs.open("start.txt", fstream::in);

	/** Declaring four variables to represent the robots name, team, x and y positions 
	 n - the read robot's name  
	 t - the read robot's team
	 x - the read robot's x position
	 y - the read robot's y position
	*/
	int n, t, x, y;

	// Loops through the file reading the above variables
	while (fs >> n >> t >> x >> y)
	{
		//@param r - creating a new robot object with the read values from the file
		robot r(n, t, x, y);
		// If the n value and t value are biggar or equal 0
		if (n >= 0 && t >= 0)
		{
			// Push the robot to the vector of robots
			v.push_back(r);
		}
		else
		{
			// Destroy the robot if the read values for n and t are negative
			r.~robot();
		}
	}
	fs.close();
}

void game::move(vector<robot>& v, int& n)
{ 
	auto is_name = [n](robot& r) { return r.name() == n; };
	// Check if the robot's name is equivalent to the read integer n
	auto robot = find_if(v.begin(), v.end(), is_name);
	int new_position = 0;
	int new_travelled = robot->travelled() + 1;

	// Case where the robot's are from the same team
	for (auto p = v.cbegin(); p != v.cend(); ++p)
	{
		// Switch for the facing direction of the robot
		switch (robot->face())
		{
		case robot::_Facing::North:
			// If the target location is already occupied by a robot on the same team, no move is possible, and the robot stays where it was.
			if (p->team() == robot->team() && p->y_position() == robot->y_position() + 1 && p->x_position() == robot->x_position()) { return; }
			break;
		case robot::_Facing::South:
			// If the target location is already occupied by a robot on the same team, no move is possible, and the robot stays where it was.
			if (p->team() == robot->team() && p->y_position() == robot->y_position() - 1 && p->x_position() == robot->x_position()) { return; }
			break;
		case robot::_Facing::East:
			// If the target location is already occupied by a robot on the same team, no move is possible, and the robot stays where it was.
			if (p->team() == robot->team() && p->y_position() == robot->y_position() && p->x_position() == robot->x_position() + 1) { return; }
			break;
		case robot::_Facing::West:
			// If the target location is already occupied by a robot on the same team, no move is possible, and the robot stays where it was.
			if (p->team() == robot->team() && p->y_position() == robot->y_position() && p->x_position() == robot->x_position() - 1) { return; }
			break;
		default:
			break;
		}
	}
	// Case where the robot's are from different teams
	for (auto p = v.begin(); p != v.end(); ++p)
	{
		// Switch for the facing direction of the robot
		switch (robot->face())
		{
		case robot::_Facing::North:
			// Attempt to move robot r one step in the direction it is facing
			if (p->team() != robot->team() && p->y_position() == robot->y_position() + 1 && p->x_position() == robot->x_position())
			{
				// Incrementing the robot's position by one step
				new_position = robot->y_position() + 1;
				// Erasing the robot that's on the way
				v.erase(p);
				
				for (auto& r : v)
				{
					if (r.name() == n)
					{
						// Set the new position of the robot
						r.set_y_position(new_position);
						// Set the travelled data member;
						r.set_travelled(new_travelled);
					}
				}
				return;
			}
			break;
		case robot::_Facing::South:
			// Attempt to move robot r one step in the direction it is facing
			if (p->team() != robot->team() && p->y_position() == robot->y_position() - 1 && p->x_position() == robot->x_position())
			{
				// Incrementing the robot's position by one step
				new_position = robot->y_position() - 1;
				// Erasing the robot that's on the way
				v.erase(p);

				for (auto& r : v)
				{

					if (r.name() == n)
					{
						// Set the new position of the robot
						r.set_y_position(new_position);
						// Set the travelled data member;
						r.set_travelled(new_travelled);
					}
				}
				return;
			}
			break;
		case robot::_Facing::East:
			// Attempt to move robot r one step in the direction it is facing
			if (p->team() != robot->team() && p->y_position() == robot->y_position() && p->x_position() == robot->x_position() + 1)
			{
				// Incrementing the robot's position by one step
				new_position = robot->x_position() + 1;
				// Erasing the robot that's on the way
				v.erase(p);
	
				for (auto& r : v)
				{
				
					if (r.name() == n)
					{
						// Set the new position of the robot
						r.set_x_position(new_position);
						// Set the travelled data member;
						r.set_travelled(new_travelled);
					}
				}
				return;
			}
			break;
		case robot::_Facing::West:
			// Attempt to move robot r one step in the direction it is facing
			if (p->team() != robot->team() && p->y_position() == robot->y_position() && p->x_position() == robot->x_position() - 1)
			{
				// Incrementing the robot's position by one step
				new_position = robot->x_position() - 1;
				// Erasing the robot that's on the way
				v.erase(p);
				
				for (auto& r : v)
				{
					
					if (r.name() == n)
					{
						// Set the new position of the robot
						r.set_x_position(new_position);
						// Set the travelled data member of the robot;
						r.set_travelled(new_travelled);
					}
				}
				return;
			}
			break;
		default:
			break;
		}
	}
	// Switching the facing direction of the robot and moving it one step in the direction that it's facing
	switch (robot->face())
	{
	case robot::_Facing::North:
		// Incrementing the robot's position by one step
		new_position = robot->y_position() + 1;
		// Set the new position of the robot
		robot->set_y_position(new_position);
		// Set the travelled data member of the robot;
		robot->set_travelled(new_travelled);
		return;
		break;
	case robot::_Facing::South:
		// Incrementing the robot's position by one step
		new_position = robot->y_position() - 1;
		// Set the new position of the robot
		robot->set_y_position(new_position);
		// Set the travelled data member of the robot;
		robot->set_travelled(new_travelled);
		return;
		break;
	case robot::_Facing::East:
		// Incrementing the robot's position by one step
		new_position = robot->x_position() + 1;
		// Set the new position of the robot
		robot->set_x_position(new_position);
		// Set the travelled data member of the robot;
		robot->set_travelled(new_travelled);
		return;
		break;
	case robot::_Facing::West:
		// Incrementing the robot's position by one step
		new_position = robot->x_position() - 1;
		// Seting the new position of the robot
		robot->set_x_position(new_position);
		// Seting the travelled data member of the robot;
		robot->set_travelled(new_travelled);
		return;
		break;
	default:
		break;
	}

}

void game::read_commands(vector<robot>& v)
{
	// Declaring a new filestream
	fstream fs;
	// Open the file
	fs.open("commands.txt", fstream::in);
	// Declaring a variable to represent the read command
	string command;
	// Declaring a variable to represent the read number
	int n = {};

	// Loops through the file reading the commands
	while (fs >> command)
	{
		if (command == "show") { show(v); }
		else if (command == "travelled") { travelled(v); }
		else if (command == "within") { fs >> n; cout << within(v, n) << '\n'; }
		else if (command == "turnleft")
		{
			// Read the robot's name
			fs >> n;
			// Look at each robot inside the vector
			for (robot& r : v)
			{
				// If the robot's name matches the read value from the file
				if (r.name() == n)
				{
					// Turn the robot left
					turnleft(r);
				}
			}
		}
		else if (command == "turnright")
		{
			// Read the robot's name
			fs >> n;
			// Look at each robot inside the vector
			for (robot& r : v)
			{
				// If the robot's name matches the read value from the file
				if (r.name() == n)
				{
					// Turn the robot right
					turnright(r);
				}
			}
		}
		else if (command == "move")
		{
			// Read the robot's name
			fs >> n;
			// Look at each robot inside the vector
			for (robot& r : v)
			{
				// If the robot's name matches the read value from the file
				if (r.name() == n)
				{
					// Turn the robot right
					move(v, n);
				}
			}
		}
	}
	// Close the file
	fs.close();
}