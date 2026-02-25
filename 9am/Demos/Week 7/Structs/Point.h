#pragma once

struct Point
{
	char* name;
	int x;
	int y;
	void print();
	Point(const char* _name, int _x, int _y);
	~Point();

	//void distance(Point& p2);
	static void distance(Point& p1, Point& p2);
};



