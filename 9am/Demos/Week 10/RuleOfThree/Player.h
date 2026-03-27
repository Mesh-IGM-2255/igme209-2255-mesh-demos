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

	// #1 - destructor for external memory
	~Player();

	// #2 -- DEEP copy constructor
	Player(const Player& other);

	// #3 (b/c) - assignment
	Player& operator=(const Player& other);
};

