// FileIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

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

	inFile.clear();
	inFile.seekg(5);
	char fileContentA[200] = "";
	inFile.read(fileContentA, 200);
	cout << fileContentA << endl << endl;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Move the file pointer to a specific location
	inFile.clear();
	inFile.seekg(5);
	inFile.read(fileContent, 200); // reads starting wherever the file pointer is
	cout << fileContent << endl << endl;
	// prints out extra b/c of the 1st read. And even ignoring that, fileContent is way bigger than we need.

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// better if we read into something we don't need to worry about the size of.

	// get us back to the start of the file stream
	inFile.clear(); // clears the flags for EOF, etc.
	inFile.seekg(0); // move us back to the start of the file

	// string(buf,buf) creates a string based on the range of the iterators
	//		Essentally we loop from the start of the file to the end of the file.
	//string tmp = string("Sdffsdf");
	string fileAsString = string(
		// START
		istreambuf_iterator<char>(inFile), // istreambuf_iterator<char>(inFile) is an iterator that starts at the beginning of inFile

		// STOP
		istreambuf_iterator<char>() // istreambuf_iterator<char>() is an iterator that defaults to the "end of file"
		// "EOF" is a special state of the stream that indicates we've reached the end of the file. 
		// It's not a "null terminator" in the stream itself
	);
	inFile.close();
	cout << fileAsString << endl << endl;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Play with simple ways to obscure data in a save file. 
	// This is NOT encryption, just a way to make it less obvious to the user.
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	string saveData = "5,10,14,3";
	outFile.open("saveData.txt"); // reuse the ofstream object - fine since it closed earlier
	if (outFile.is_open())
	{
		outFile << saveData;
	}
	outFile.close();

	// Nothing stopping the user from editing the file. We could save a hashcode of all the data
	// and then compare when loading to detect corrupted data.
	//    - Still have to store the hash some where. Local == still vulnerable. Online == Performance hit.

	// Instead, we can obfuscate the data. Make it harder to read/edit.
	// Deters casual "hackers", but won't stop anyone who is determined to edit the file.
	// This is NOT encryption!
	const int OBFUSCATION_KEY = 234234;

	string myObfuscatedText = saveData;
	for (int i = 0; i < myObfuscatedText.length(); i++)
	{
		// each character is a # under the hood, so xor to change the value just a bit
		// easy to undo, hard to read
		myObfuscatedText[i] ^= OBFUSCATION_KEY;
	}
	outFile.open("obfuscated.txt", std::ios::binary); // binary mode prevents conversion of line endings and other characters
	if (outFile.is_open())
	{
		outFile << myObfuscatedText;
	}
	outFile.close();

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	inFile.open("obfuscated.txt", std::ios::binary);
	fileAsString = string(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>());
	inFile.close();

	for (int i = 0; i < fileAsString.length(); i++)
	{
		// xor is a reversible operation!
		fileAsString[i] ^= OBFUSCATION_KEY;
	}

	cout << fileAsString << endl << endl;
	
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Binary mode prevents conversion of line endings and other characters
	// By default, ifStream will convert all new lines to \r\n (Carriage Return, Line Feed).
	// In ios::binary, it will not convert these line endings
	// You’ll need to create this text file in the correct directory
	ifstream mapFileIn = ifstream("level1.map", ios::binary);

	// While the streams status is "good" (aka haven't made it to the end)

	string line;

	int i = 0;
	while (mapFileIn.good())
	{
		getline(mapFileIn, line);
		cout << i << ": "<<line << endl;
		i++;
	}

	mapFileIn.close();
	
}
