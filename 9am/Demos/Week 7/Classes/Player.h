#pragma once

#include <string>

class Player
{
	//int thing2; // private by default

private:
	char* name;
	unsigned short numScores;
	short* scores;
	std::string nickname;

public:
	//int thing;
	Player();
	Player(const char* name, unsigned short numScores);
	void print();

	~Player();

};

