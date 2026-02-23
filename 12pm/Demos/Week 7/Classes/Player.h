#pragma once

#include <string>

class Player
{
	//int thing;

private:
	char* name;
	short* scores;
	unsigned short numScores;
	std::string nickname;

public:
	//int thing2;
	Player();
	Player(const char* name, unsigned short numScores);

	~Player();

	void print();

};

