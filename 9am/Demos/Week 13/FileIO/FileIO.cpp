// FileIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

int main()
{
    int a;

    // console streams
    std::cout << "Enter a number: "; // output stream
    std::cin >> a; // input stream

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // file streams -- FSTREAM

    // output file stream
    std::ofstream outFile = std::ofstream("test.txt");

    if (outFile.is_open())
    {
        outFile << "Hello test file!" << std::endl;
        outFile << "My number is " << a << std::endl;
    }

    // close when done!
    outFile.close();

    // -----------

    std::ifstream inFile("myData.txt");

    char fileContent[200] = "";
    inFile.read(fileContent, 200);
    std::cout << fileContent << std::endl << std::endl;

}
