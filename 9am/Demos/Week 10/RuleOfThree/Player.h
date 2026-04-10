#pragma once

// Comment these out to turn on/off support for different aspects of the Rule of Three
#define R1
#define R2
#define R3

#include <string>

class Player
{
private:
	int* inventory;
	unsigned int invSize;
	std::string name; // to make it more clear when we have multiple players in the demo

public:
	// Base setup for the demo
	Player(std::string _name, int _item1, int _item2, int _item3);
	void printInventory();
	void SwapItem(unsigned int _slot, int _newItem);

	// ** Rule of Three ** 
	// Things we need to pretty much always do in a 
	// class that manages external memory

#ifdef R1
	// ** Part 1: Custom Destructor **
	// all classes have a default destructor, but we need to write our 
	// own because we have memory that isn't part of the object
	~Player();
#endif 


#ifdef R2
	// ** Part 2: Copy Constructor **
	// By default, C++ will make a shallow copy of our object
	// I.e., an EXACT copy of all memory, including all pointer addresses
	Player(const Player& _other);
#endif


#ifdef R3
	// ** Part 3: Assignment Operator **
	// By default, C++ will make a shallow copy of our object with an =
	Player& operator=(const Player& _other);
#endif
};

