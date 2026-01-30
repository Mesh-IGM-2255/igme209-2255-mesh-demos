// BitwiseOps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
	// *************************************************************************************
	short test = 4;
	printOneShort("Testing", test);
	_div();

	short test2 = 11110000;
	printOneShort("Bad Init", test2);
	_div();

	// Define in binary -- 0b at the start
	short a = 0b11110000; // 240
	short b = 0b10101010; // 170
	printTwoShorts(a, b);
	_div();

	// *************************************************************************************

	// AND and OR

	// Boolean AND (&&)
	if (true && false) {}

	// Bitwise AND -- &
	// 1 1 1 1 0 0 0 0		- 240
	// 1 0 1 0 1 0 1 0		- 170
	// ~~~~~~~~~~~~~~~~~~~~~~~~
	// 1 0 1 0 0 0 0 0
	printTwoShorts(a, b);
	printOneShort("a & b", a & b);
	_div();

	// Bitwise OR -- |
	// 1 1 1 1 0 0 0 0		- 240
	// 1 0 1 0 1 0 1 0		- 170
	// ~~~~~~~~~~~~~~~~~~~~~~~~
	// 1 1 1 1 1 0 1 0
	printTwoShorts(a, b);
	printOneShort("a | b", a | b);
	_div();

	// Bitwise XOR -- ^
	// 1 1 1 1 0 0 0 0		- 240
	// 1 0 1 0 1 0 1 0		- 170
	// ~~~~~~~~~~~~~~~~~~~~~~~~
	// 0 1 0 1 1 0 1 0
	printTwoShorts(a, b);
	printOneShort("a ^ b", a ^ b);
	_div();


	short doors = 0b00000000;
	const short DOOR_1 = 0b00000001;
	doors = doors | DOOR_1;

	// *************************************************************************************

	// left shift - <<
	// 00000000 1 1 1 1 0 0 0 0		- 240
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 00000001 1 1 1 0 0 0 0 0* 
	printOneShort("a", a);
	printOneShort("a << 1", a << 1);
	printOneShort("a << 2", a << 2);
	_div();


	// right shift - >>
	// 00000000 1 1 1 1 0 0 0 0		- 240
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 00000000 0 1 1 1 1 0 0 0
	printOneShort("a", a);
	printOneShort("a >> 1", a >> 1);
	printOneShort("a >> 2", a >> 2);
	_div();

	// Effectively multiplies by 2 for each space moved.
	// Consider how in base 10 we multiply by 10 for each place moved.
	short c = 0b100;
	printOneShort("c", c);
	for (int i = 1; i < 5; i++)
	{
		char label[8] = "";
		sprintf_s(label, "c << %d", i);
		printOneShort(label, c << i);
	}
	_div();


	// complement -- ~
	// 1 1 1 1 0 0 0 0
	// ~~~~~~~~~~~~~~~~~
	// 0 0 0 0 1 1 1 1
	printOneShort("a", a);
	printOneShort("~a", ~a);
	_div();

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	short v1 = 0b11110000; // 240
	short v2 = 0b10101010; // 170

	// with a tmp
	/*
	short tmp = v1;
	v2 = v1;
	v1 = tmp;
	*/

	// Swap the values in c & d without using an extra variable

	// XOR swap

	printOneShort("\tv1", v1);
	printOneShort("\tv2", v2);
	v1 = v1 ^ v2;
	printOneShort("\nv1 = v1 ^ v2", v1);

	// v1 is now not v1 or v2 -- it's a map between them
	v2 = v1 ^ v2;
	printOneShort("\nv2 = v1 ^ v2", v2);

	v1 = v1 ^ v2;
	printOneShort("\nv1 = v1 ^ v2", v1);
	_div();
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// Could define our layers as strings or enums, have all objects have a layer, and compare
	// layers on all objects as we check collisions.
	char playerLayerStr[] = "Layer1";
	// { "Layer1", "Layer2", "Layer3", "Layer4" };
	// tedious and SLOW

	// Instead, we can use bit packing to store the layers in a single variable.
	//           W  B  P
	// Players   x  x  x
	// Bullets      x  -
	// Walls        -  -

	// Be consistent about which layer is which bit.

	//                    -WBP
	short playerLayer = 0b0001;
	short bulletLayer = 0b0010;
	short   wallLayer = 0b0100;

	// Masks to allow us check for things we collide with
	//                   -WBP
	short playerMask = 0b0111; // player collides with everything
	short bulletMask = 0b0011; // bullets collide with other bullets and players
	short   wallMask = 0b0001; // walls collide with players

	// cout checking all possible collision combinations
	cout << "Player vs Player: " << resolveCollision(playerLayer, playerMask) << endl;
	cout << "Player vs Bullet: " << resolveCollision(playerLayer, bulletMask) << endl;
	cout << "Player vs Wall: " << resolveCollision(playerLayer, wallMask) << endl;

	cout << "Bullet vs Player: " << resolveCollision(bulletLayer, playerMask) << endl;
	cout << "Bullet vs Bullet: " << resolveCollision(bulletLayer, bulletMask) << endl;
	cout << "Bullet vs Wall: " << resolveCollision(bulletLayer, wallMask) << endl;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	_div();

	unsigned short lcv = 1;
	for (; lcv > 0; lcv++)
	{
		cout << ".";
	}
	cout << endl << lcv << endl;
}
