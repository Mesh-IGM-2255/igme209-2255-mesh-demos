#pragma once

struct Point
{
	char* name;
	int x;
	int y;
	Point(const char* _name, int _x, int _y);
	~Point();
	void print();

	static void distance(Point& p1, Point& p2);
};

