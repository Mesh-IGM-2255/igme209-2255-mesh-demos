#include "Player.h"

#include <iostream>
using namespace std;

Player::Player(int _item1, int _item2, int _item3)
{
	cout << "Player() - " << _item1 << ", " << _item2 << ", " << _item3 << endl;
	invSize = 3;
	inventory = new int[invSize] { _item1, _item2, _item3 };
}


void Player::printInventory()
{
	cout << "Inventory: ";
	for (unsigned int i = 0; i < invSize; i++)
	{
		cout << inventory[i] << " ";
	}
	cout << "which is at " << inventory << endl;
}

void Player::SwapItem(unsigned int _slot, int _newItem)
{
	if (_slot < 0 || _slot >= invSize)
	{
		cout << "Invalid slot" << endl;
		return;
	}
	inventory[_slot] = _newItem;
}

Player::~Player()
{
	cout << "~Player()" << endl;
	delete[] inventory;
}

Player::Player(const Player& other)
{
	cout << "Player(other)" << endl;

	// Default SHALLOW copy
	invSize = other.invSize;
	//inventory = other.inventory; // this is the default SHALLOW behavior!

	// DEEP copy all external data
	inventory = new int[invSize];
	for (unsigned int i = 0; i < invSize; i++)
	{
		inventory[i] = other.inventory[i];
	}
}

Player& Player::operator=(const Player& other)
{
	cout << "operator=" << endl;

	if (this == &other)
	{
		cout << "Self-assignment!" << endl;
		return *this;
	}

	invSize = other.invSize;
	delete[] inventory;
	inventory = new int[invSize];
	for (unsigned int i = 0; i < invSize; i++)
	{
		inventory[i] = other.inventory[i];
	}

	return *this;
}
