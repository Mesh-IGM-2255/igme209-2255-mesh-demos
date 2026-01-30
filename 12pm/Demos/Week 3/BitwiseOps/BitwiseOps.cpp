// BitwiseOps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
	short test = 10;
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

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// boolean operators -- && !!
	if (true && false) {} // --> false
	if (0 && 12) {} // --> false (false && true)

	// Bitwise AND -- &
	// 1 1 1 1 0 0 0 0
	// 1 0 1 0 1 0 1 0
	// ~~~~~~~~~~~~~~~~~
	// 1 0 1 0 0 0 0 0 
	printTwoShorts(a, b);
	printOneShort("a & b", a & b);
	_div();

	// Bitwise OR -- |
	// 1 1 1 1 0 0 0 0
	// 1 0 1 0 1 0 1 0
	// ~~~~~~~~~~~~~~~~~
	// 1 1 1 1 1 0 1 0
	printTwoShorts(a, b);
	printOneShort("a | b", a | b);
	_div();

	// Bitwise XOR -- ^
	// 1 1 1 1 0 0 0 0
	// 1 0 1 0 1 0 1 0
	// ~~~~~~~~~~~~~~~~~
	// 0 1 0 1 1 0 1 0
	printTwoShorts(a, b);
	printOneShort("a ^ b", a ^ b);
	_div();


	short openDoors = 0;
	const short DOOR_1 = 0b0001;
	const short DOOR_2 = 0b0010;
	const short DOOR_3 = 0b0100;
	const short DOOR_4 = 0b1000;

	openDoors = openDoors | DOOR_1;
	if (openDoors & DOOR_4) {} // --> 0

	if (openDoors) {} // at least 1 open

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// complement - ~
	// 1 1 1 1 0 0 0 0
	// ~~~~~~~~~~~~~~~~~~~~~
	// 0 0 0 0 1 1 1 1
	printOneShort("a", a);
	printOneShort("~a", ~a);
	_div();

	// 00000000 1 1 1 1 0 0 0 0
	// ~~~~~~~~~~~~~~~~~~~~~
	// 00000001 1 1 1 0 0 0 0 0
	printOneShort("a", a);
	printOneShort("a << 1", a << 1);
	printOneShort("a << 2", a << 2);
	printOneShort("a << 3", a << 3);
	_div();

	// 00000000 1 1 1 1 0 0 0 0
    // ~~~~~~~~~~~~~~~~~~~~~
	// 00000000 0 1 1 1 1 0 0 0
	printOneShort("a", a);
	printOneShort("a >> 1", a >> 1);
	printOneShort("a >> 2", a >> 2);
	printOneShort("a >> 3", a >> 3);
	_div();

	// What about odd numbers?
	short c = 0b111;
	printOneShort("c", c);
	for (int i = 1; i < 3; i++)
	{
		char label[8] = "";
		sprintf_s(label, "c >> %d", i);
		printOneShort(label, c >> i);
	}
	_div();

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	short v1 = 0b11110000; // 240
	short v2 = 0b10101010; // 170

	// swap the values between the variables
	/*short tmp = v1;
	v1 = v2;
	v2 = tmp;*/

	// do it with a 3rd variable

	// XOR swap
	printOneShort("\tv1", v1);
	printOneShort("\tv2", v2);

	v1 = v1 ^ v2;
	printOneShort("v1 = v1 ^ v2", v1);

	// Bitwise XOR -- ^
	// 1 1 1 1 0 0 0 0
	// 1 0 1 0 1 0 1 0
	// ~~~~~~~~~~~~~~~~~
	// 0 1 0 1 1 0 1 0 ----
	//   !   ! !   !

	v2 = v2 ^ v1; // apply conv map to original v2 to get original v1
	printOneShort("v2 = v2 ^ v1", v2);

	v1 = v2 ^ v1; // apply conv map to orig v1 to get orig v2 into new v1
	printOneShort("v1 = v2 ^ v1", v1);

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	char playerLayerStr[] = "Layer1";
	// { "Layer1", "Layer2", "Layer3", "Layer4" };


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
	short playerBullet = 0b0011;

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
}
