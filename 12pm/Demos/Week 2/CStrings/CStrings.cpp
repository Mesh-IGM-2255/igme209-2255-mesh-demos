// CStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS // disable deprecation warnings for 
								// cstring functions in MS compilers

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char name[6] = "Shiro";
	cout << name << endl;

	char stuff[2] = { 'a','b' };
	cout << stuff << endl;

	char firstName[6] = "Shiro";
	cout << firstName << endl;
	//firstName[5] = '!'; // BAD IDEA -- overwrites the null term.
	//cout << firstName << endl;

	char lastName[6] = " Mesh";

	char fullName[50] = "?";
	// fullName = firstName;  // can't reassign cstrings
	// fullName = firstName + lastName; // can't concatenate cstrings
	// fullName += lastName; // can't concatenate cstrings

	// "_s" versions are MS only - https://cplusplus.com/forum/beginner/118771/
	// You can use them, but PE autotests will replace with the gcc versions (non _s)
	// so make sure you're using memory safely!
	// To compile in VS without _s versions, defines _CRT_SECURE_NO_WARNINGS 
	// as a preprocessor directive (see top of file)
	// https://learn.microsoft.com/en-us/cpp/c-runtime-library/security-features-in-the-crt?view=msvc-170
	strcpy(fullName, firstName);
	strcat(fullName, lastName);
	cout << fullName << endl;

	// other cstring functions: strlen, strchr
	if (strchr(fullName, 'h'))
	{
		// found it and return WHERE it found it -- as a pointer!
		cout << strchr(fullName, 'h') << endl << endl;
	}

	// Other helpful functions like strlen & strchr -- you can read up on them and use them, 
	// but also just use array calcs.
	cout << strlen(fullName) << endl;

	if (strchr(fullName, 'S'))
	{
		cout << "Found the letter S" << endl;
		cout << strchr(fullName, 'S') << endl;
	}

	// *** INPUT ***
	char username[100];
	cout << "Enter your name: ";
	cin.getline(username, 100);
	cout << "hello " << username << endl;

	char input;
	cout << "Enter a letter: ";
	cin >> input;
	cout << "Your letter: " << input << endl;

	cin >> input;
	cout << "Your letter: " << input << endl;

	cin >> input;
	cout << "Your letter: " << input << endl;

	// See HW1 writeup for how to only get ONE char and ignore others until
	// the next newline

}
