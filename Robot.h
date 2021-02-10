#ifndef ROBOT_H
#define ROBOR_H

class robot
{
	/**
	* Data member that represents the robot's name
	*/
	int _name = 0;
	/**
	*  Data member that represents the robot's team
	*/
	int _team = 0;
	/**
	*  Data member that represents the robot's original x position
	*/
	int _x_position_origin = 0;
	/**
	*  Data member that represents the robot's original y position
	*/
	int _y_position_origin = 0;
	/**
	*  Data member that represents the robot's x position
	*/
	int _x_position = 0;
	/**
	*  Data member that represents the robot's y position
	*/
	int _y_position = 0;
	/**
	* The distance the respective robot has tavelled stored in a private data member of type integer.
	*/
	int _travelled = 0;
public:
	/**
	* Constructor for the robot object
	*/
	explicit robot(const int& n, const int& t, int& x, int& y)
		: _name(n), _team(t), _x_position(x), _y_position(y) {
		_face = _Facing::North;
		_travelled = 0;
		_x_position_origin = _x_position;
		_y_position_origin = _y_position;
	}
	/**
	*  The robot facing directions in a public data member of type enum
	*/
	enum class _Facing { North, East, South, West };
	/**
	* The robot current facing direction
	*/
	_Facing _face{};
	/**
	* Trivial accessor member function that returns the robot's name
	*/
	const int name() const { return _name; }
	/**
	* Trivial accessor member function that returns the robot's team
	*/
	const int team() const { return _team; }
	/**
	* Trivial accessor member function that returns the robot's current facing direction;
	*/
	const _Facing face() const { return _face; }
	/**
	* Trivial accessor member function that returns the robot's x position
	*/
	const int  x_position() const { return _x_position; }
	/**
	* Trivial accessor member function that returns the robot's y position
	*/
	const int y_position() const { return _y_position; }
	/**
	* Trivial mutator member function that sets the value of the private data member _x_position to x
	*/
	void set_x_position(int& x) { this->_x_position = x; }
	/**
	* Trivial mutator member function that sets the value of the private data member _y_position
	*/
	void set_y_position(int& y) { this->_y_position = y; }
	/**
	* Trivial accessor member function that returns the robot's original x position
	*/
	const int x_position_origin() const { return _x_position_origin; }
	/**
	* Trivial accessor member function that returns the robot's original y position
	*/
	const int y_position_origin() const { return _y_position_origin; }
	/**
	* Trivial accessor member fuction that returns the distance the robot's has travelled
	*/
	const int travelled() const { return _travelled; }
	/**
	* Trivial amutator member fuction that returns the distance the robot's has travelled
	*/
	void set_travelled(int& n) { _travelled = n; }
	/**
	* Member fuction to make a robot r turn to the left, e.g. if it is facing north, it turns it to face west.
	*/
	void turnleft(robot& r);
	/**
	* Member fuction to make robot r turn to the right, e.g. if it is facing north, it turns it to face east.
	*/
	void turnrightt(robot& r);
	/**
	* Member fuction to move a robot r one step in the direction it is facing.
	*If the target location is already occupied by a robot on the same team, no move is initialized, and the robot stays where it is.
	*If the target location is occupied by a robot of another team, that robot is removed from the system, after which the respective robot moves.
	*/
	void move(robot& r);
};

#endif