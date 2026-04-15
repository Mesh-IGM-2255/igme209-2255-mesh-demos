// FileIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>



int main()
{
    int a;

    // console streams
    std::cout << "Enter a number: "; // output stream
    std::cin >> a; // input stream

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // file streams -- FSTREAM

    // output file stream
    std::ofstream outFile = std::ofstream("test.txt", std::ios::app);

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

    inFile.clear();
    inFile.seekg(5);
    inFile.read(fileContent, 200);
    std::cout << fileContent << std::endl << std::endl;

    // ~~~~~~~~~~~
    inFile.clear(); // clear state (eg EOF)
    inFile.seekg(0);

    std::string fileAsString = 
        std::string(
            std::istreambuf_iterator<char>(inFile), // where to start getting data
            std::istreambuf_iterator<char>() // where to stop -- default is EOF
            // EOF == end of file flag
        );
    inFile.close();
    std::cout << fileAsString << std::endl;


    // ~~~~~~~~~~~~~~~~~~~
    std::string saveData = "5,10,14,3"; // lives, pos_x, pos_y, level
    outFile.open("saveData.txt");
    if (outFile.is_open())
    {
        outFile << saveData;
    }
    outFile.close();

    const int OBFUSCATION_KEY = 94523957;
    std::string myObfText = saveData;
    for (int i = 0; i < myObfText.length(); i++)
    {
        myObfText[i] ^= OBFUSCATION_KEY;
    }
    outFile.open("obfData.txt", std::ios::binary);
    if (outFile.is_open())
    {
        outFile << myObfText;
    }
    outFile.close();

    inFile.open("obfData.txt", std::ios::binary);
    fileAsString = std::string(
        std::istreambuf_iterator<char>(inFile), // where to start getting data
        std::istreambuf_iterator<char>() // where to stop -- default is EOF
        // EOF == end of file flag
    );
    inFile.close();
    std::cout << fileAsString << std::endl;

    for (int i = 0; i < fileAsString.length(); i++)
    {
        // xor is a reversible operation!
        fileAsString[i] ^= OBFUSCATION_KEY;
    }

    std::cout << fileAsString << std::endl;

    // --------------------------
    std::string line;
    std::ifstream mapFileIn("level1.map");
    int i = 0;
    while (mapFileIn.good())
    {
        std::getline(mapFileIn, line);
        std::cout << i << ": " << line << std::endl;
        i++;
    }
    mapFileIn.close();

}
