// FileIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // console stream
    int a;
    std::cout << "Enter a number: "; // output
    std::cin >> a; // input stream

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // file streams --- FSTREAM

    std::ofstream outFile = ofstream("test.txt", std::ios::app);

    if (outFile.is_open())
    {
        outFile << "My number is ";
        outFile << a << endl;
    }

    outFile.close();

    // -------------------
    ifstream inFile("myData.txt");

    char fileContent[200] = "";
    inFile.read(fileContent, 200);
    cout << fileContent << endl << endl;


}
