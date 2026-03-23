// Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <vector>
#include <string>

#include "TemplateEx.h"

int main()
{
	std::vector<int> nums;

	TemplateEx<int> ex1 = TemplateEx<int>(12);
	TemplateEx<std::string> ex2 = TemplateEx<std::string>("Pax");

}
