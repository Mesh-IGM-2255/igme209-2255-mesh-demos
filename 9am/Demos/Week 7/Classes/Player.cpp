// To ensure the autograder can compile with gcc, use the NON _s 
// versions of cstring functions(e.g.strlen, strncpy, etc.).
#define _CRT_SECURE_NO_WARNINGS

#include "Player.h"
#include <iostream>

typedef unsigned short ushort;

using namespace std;
#include <cstring>

Player::Player()
	: Player("Shiro", 4)
{
	cout << "+Player()" << endl;
	/*
	nickname = "Binky";

	name = new char[6] {"Shiro"};
	numScores = 4;
	scores = new short[numScores];

	for (int i = 0; i < numScores; i++)
	{
		scores[i] = rand() % 100;
	}
	*/
}

Player::Player(const char* name, ushort numScores)
{
	cout << "+Player(name, numScores)" << endl;
	nickname = "Binky";

	int nameLen = strlen(name);
	this->name = new char[nameLen + 1];
	strncpy(this->name, name, nameLen + 1);

	this->numScores = numScores;
	scores = new short[numScores];

	for (int i = 0; i < numScores; i++)
	{
		scores[i] = rand() % 100;
	}
}

Player::~Player()
{
	cout << "~Player()" << endl;
	delete[] name;
	delete[] scores;
}

void Player::print()
{
	cout << name << " (" << nickname << "): ";
	for (int i = 0; i < numScores; i++)
	{
		cout << scores[i] << " ";
	}
	cout << endl;
}