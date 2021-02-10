#include "Robot.h"
#include <iostream>

using namespace std;

void robot::turnleft(robot& r)
{
	switch (_face)
	{
	case _Facing::North:	_face = _Facing::West; // std::cout << '\n'; std::cout << "The robot: " << r.name() << " has turned left and is now facing West!" << '\n';
		break;
	case _Facing::East:		_face = _Facing::North;// std::cout << '\n'; std::cout << "The robot: " << r.name() << " has turned left and is now facing North!" << '\n';
		break;
	case _Facing::South:	_face = _Facing::East;// std::cout << '\n'; std::cout << "The robot: " << r.name() << " has turned left and is now facing East!" << '\n';
		break;
	case _Facing::West:		_face = _Facing::South; // std::cout << '\n'; std::cout << "The robot: " << r.name() << " has turned left and is now facing South!" << '\n';
		break;
	default:
		break;
	}
}

void robot::turnrightt(robot& r)
{
	switch (_face)
	{
	case _Facing::North:_face = _Facing::East;// std::cout << '\n'; std::cout << "The robot: " << r.name() << " has turned right and is now facing East!" << '\n';
		break;
	case _Facing::East:	_face = _Facing::South;// std::cout << '\n'; std::cout << "The robot: " << r.name() << " has turned right and is now facing South!" << '\n';
		break;
	case _Facing::South:_face = _Facing::West;// std::cout << '\n'; std::cout << "The robot: " << r.name() << " has turned right and is now facing West!" << '\n';
		break;
	case _Facing::West:	_face = _Facing::North;// std::cout << '\n'; std::cout << "The robot: " << r.name() << " has turned right and is now facing North!" << '\n';
		break;
	default:
		break;
	}
}

void robot::move(robot &r)
{
	switch (_face)
	{
	case _Facing::North:_y_position += 1;// std::cout << '\n'; std::cout << "The robot: " << r.name() << " has moved North " << "The robot position is: " << "(" << _position.first << "," << _position.second << ")" << '\n';
		break;
	case _Facing::East:	_x_position += 1;// std::cout << '\n'; std::cout << "The robot: " << r.name() << " has moved East " << "The robot position is: " << "(" << _position.first << "," << _position.second << ")" << '\n';
		break;
	case _Facing::South:_y_position -= 1;// std::cout << '\n'; std::cout << "The robot: " << r.name() << " has moved South " << "The robot position is: " << "(" << _position.first << "," << _position.second << ")" << '\n';
		break;
	case _Facing::West:	_x_position -= 1;// std::cout << '\n'; std::cout << "The robot has: " << r.name() << " moved West " << "The robot position is: " << "(" << _position.first << "," << _position.second << ")" << '\n';
		break;
	default:
		break;
	}
	_travelled += 1;
}
