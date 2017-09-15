// LAB01.cpp
// James Mock 
// COSC 2030
// 2017-09-11
// Lab01

#include<fstream>
#include<iostream>
#include<string>

using std::ifstream;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
	int count = 0;
	double numBuf, num1, num2, num3, num4;
	string inBuf;
	ifstream inFile;
	do
	{
		cout << "Please enter a filename to read from: "; // prompt user for filename
		cin >> inBuf;
		inFile.open(inBuf); // open file
		
	
		if (!inFile.is_open()) // Check if file is open
		{
			cerr << "\nCould not open: " << inBuf << endl << endl; // prompt user if the file could not be opened
			inFile.clear();
		}
	} while (!inFile.is_open());

	// loop to get an count of the numbers
	inFile >> numBuf; // read in first value
	while (!inFile.fail()) // fail check
	{
		count++;
		inFile >> numBuf;
	}

	inFile.clear(); // clear error state
	inFile.seekg (inFile.beg); //set back to the first char of the file

	int index = 0; // counter for the second loop
	inFile >> numBuf; // read in first value
	while (!inFile.fail()) // fail check
	{
		index++;
		if (index == 1) // save first number
		{
			num1 = numBuf;
		}
		if (index == 2) // save second number
		{
			num2 = numBuf;
		}
		if (index == count - 1) // save second to last number
		{
			num3 = numBuf;
		}
		if (index == count) // save last number
		{
			num4 = numBuf;
		}
		inFile >> numBuf;
	}

	cout << "There are "<< count << " numbers in the file." << endl; // output data
	cout << "The first number is " << num1 << "." << endl;
	cout << "The second number is " << num2 << "." << endl;
	cout << "The second to last number is " << num3 << "." << endl;
	cout << "The last number is " << num4 << "." << endl;

	inFile.close(); // close file
	return 0;
}
