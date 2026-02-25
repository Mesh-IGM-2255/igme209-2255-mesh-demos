// To ensure the autograder can compile with gcc, use the NON _s 
// versions of cstring functions(e.g.strlen, strncpy, etc.).
#define _CRT_SECURE_NO_WARNINGS

#include "Point.h"

#include <iostream>
#include <cmath>
using namespace std;

Point::Point(const char* _name, int _x, int _y)
{
	cout << "+Point(x,y)" << endl;
	int nameLength = strlen(_name) + 1;
	this->name = new char[nameLength];
	strncpy(name, _name, nameLength);
	x = _x;
	y = _y;
}

Point::~Point()
{
	cout << "~Point()" << endl;
	delete[] name;
}

void Point::print()
{
	cout << name << " (" << x << ", " << y << ")";
}

void Point::distance(Point& p1, Point& p2)
{
	int dx = p2.x - p1.x;
	int dy = p2.y - p1.y;
	float dist = sqrt(dx * dx + dy * dy);
	p1.print();
	std::cout << " to ";
	p2.print();
	std::cout << " = " << dist << std::endl;
}
