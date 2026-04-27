#pragma once
class Stuff
{
public:
	Stuff();

	// 1
	~Stuff();

	// 2
	Stuff(Stuff& other);

	// 3
	Stuff& operator=(Stuff& other);


private:
	int thing1;
	int thing2;
	int* thingPtr;
};

