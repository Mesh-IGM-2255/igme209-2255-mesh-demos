#include "Player.h"

#include <iostream>
using namespace std;

Player::Player(string _name, int _item1, int _item2, int _item3)
{
	cout << "Player("<< _name <<") - " << _item1 << ", " << _item2 << ", " << _item3 << endl;
	invSize = 3;
	name = _name;
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

#ifdef R1
Player::~Player()
{
	cout << "~Player(" << name << ")" << endl;
	delete[] inventory;
}
#endif


#ifdef R2
Player::Player(const Player& _other)
{
	cout << "Player(other.name="<< _other.name<<")" << endl;
	invSize = _other.invSize;

	// SHALLOW copy that happens implicitly
	// NOT what we want!!
	//inventory = _other.inventory;

	// DEEP copy of the inventory instead of
	inventory = new int[invSize];

	// Simple for loop to copy it
	/*
	for (unsigned int i = 0; i < invSize; i++)
	{
		inventory[i] = _other.inventory[i];
	}
	*/

	// Slightly more perforant way to copy it
	std::copy(
		_other.inventory,						// source start addr
		_other.inventory + _other.invSize,		// source end addr
		inventory								// dest addr start
	);
}
#endif


#ifdef R3
Player& Player::operator=(const Player& _other)
{
	cout << "Player operator = other.name=" << _other.name << ")" << endl;

	// Check for self-assignment
	if (this == &_other)
	{
		cout << "Self-assignment!" << endl;
		return *this;
	}

	// Clean up old memory before allocating new memory!
	if (inventory != nullptr)
	{
		delete[] inventory;
	}

	// THEN do our deep copy!
	invSize = _other.invSize;
	inventory = new int[invSize];
	std::copy(
		_other.inventory,						// source start addr
		_other.inventory + _other.invSize,		// source end addr
		inventory								// dest addr start
	);

	// operators need to return a reference to the object in case we chain them together
	return *this;
}
#endif

