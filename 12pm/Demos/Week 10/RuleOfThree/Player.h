#pragma once

class Player
{
private:
	int* inventory;
	unsigned int invSize;

public:
	// Base setup for the demo
	Player(int _item1, int _item2, int _item3);
	void printInventory();
	void SwapItem(unsigned int _slot, int _newItem);

	// #1 - need to delete external data
	~Player();

	// #2 - need a DEEP copy constructor
	Player(const Player& other);

	// #3 -- DEEP copy = that ALSO detects self-assignment & clean ups old external data
	Player& operator=(const Player& other);
};