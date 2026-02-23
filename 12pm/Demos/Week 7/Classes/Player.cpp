// To ensure the autograder can compile with gcc, use the NON _s 
// versions of cstring functions(e.g.strlen, strncpy, etc.).
#define _CRT_SECURE_NO_WARNINGS

#include "Player.h"

#include <iostream>
using namespace std;

typedef unsigned short ushort;

Player::Player()
	: Player("Shiro", 4)
{
	cout << "+Player()" << endl;
	
	/*
	name = new char[6] {"Shiro"};
	nickname = "Binky";
	numScores = 4;
	scores = new short[numScores];
	for (int i = 0; i < numScores; i++)
	{
		scores[i] = rand() % 100;
	}*/
}

Player::Player(const char* name, unsigned short numScores)
{
	cout << "+Player(name,numScores)" << endl;
	int nameLength = strlen(name) + 1;
	this->name = new char[nameLength];
	strncpy(this->name, name, nameLength);
	nickname = "Binky";

	this->numScores = numScores;
	scores = new short[numScores];

	for (ushort i = 0; i < numScores; i++)
	{
		scores[i] = rand() % 100;
	}
}

Player::~Player()
{
	cout << "~Player()" << endl;
	delete[] scores;
	delete[] name;
}

void Player::print()
{
	cout << this->name << " (" << nickname << "): ";
	for (ushort i = 0; i < numScores; i++)
	{
		cout << scores[i] << " ";
	}
	cout << endl;
}