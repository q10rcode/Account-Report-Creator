
#include "myheader.h"

void LoadArraysFromFile(string accName[],
						int accId[],
						float accBalance[],
						int& accounts)
{

	string inFileName;	//INPUT - Name of the input file
	string lines;		//OUTPUT - Number of lines in the file
	ifstream inFile;	//INPUT - Variable to hold file

	accounts = 0;

	cout <<"What input file would you like to use?  ";
	getline(cin, inFileName);

	//This loop will read the amount of lines in the file
	inFile.open(inFileName);
	while (getline(inFile, lines))
	{
		accounts++;
	}
	//Each account has two lines in the file
	accounts = accounts / 2;
	inFile.close();

	//This loop reads the data from the file into parallel arrays
	inFile.open(inFileName);
	for(int i = 0; i < accounts; i++)
	{
		getline(inFile, accName[i]);
		inFile >> accId[i];
		inFile >> accBalance[i];
		inFile.ignore();
	}

	inFile.close();


}
