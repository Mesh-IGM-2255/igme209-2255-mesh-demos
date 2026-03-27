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
	delete inventory;
}

Player::Player(const Player& other)
{
	cout << "Player(other)" << endl;

	// SHALLOW by default
	invSize = other.invSize;
	//inventory = other.inventory; // NOT what we want

	// Need a DEEP copy of all data
	inventory = new int[invSize];

	/*
	for (unsigned int i = 0; i < invSize; i++)
	{
		inventory[i] = other.inventory[i];
		// inventory[i] --- *(inventory + i)
	}
	*/

	// slight more performant
	std::copy(
		other.inventory, // source start addr
		other.inventory + invSize, // source end addr
		inventory
	);


}

Player& Player::operator=(const Player& other)
{
	cout << "Player=" << endl;

	if (this == &other)
	{
		cout << "Self assignment!" << endl;
		return *this;
	}

	// clean up old external memory before the deep copy!
	if (inventory != nullptr)
	{
		delete[] inventory;
	}

	invSize = other.invSize;
	inventory = new int[invSize];
	std::copy(
		other.inventory, // source start addr
		other.inventory + invSize, // source end addr
		inventory
	);

	return *this;
}
