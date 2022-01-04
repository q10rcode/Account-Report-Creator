/******************************************************************
* PROGRAMMED BY : Quinten Ridley
* PROJECT 04	: Parallel Arrays
* CLASS			: CSC5
* SECTION		: MW 2:20PM-5:30PM
* DUE DATE		: 12/6/21
******************************************************************/

#include "myheader.h"

/******************************************************************
 *
 * CREATE ACCOUNT REPORTS
 * ________________________________________________________________
 * This program begins by asking users what input file they would
 * like to use in the LoadArraysFromFile function. The program
 * will then load the data from the file into three parallel arrays.
 * The program will then ask the user for an output file. Users are
 * then prompted to search for names in a while loop which are
 * passed into the SearchForMatch function. The SearchForMatch
 * function returns the subscript of the name which is then passed
 * into PrintReportFunction which displays the account's ID, name,
 * and balance in the output file. When the user enters "done" as
 * the program asks for a name a bool variable is set to true and
 * then the PrintReportToFile prints the average for all the
 * accounts searched.
 * ________________________________________________________________
 * INPUT
 *   accounts			: The amount of accounts on the file
 *   accId				: Array holding the account IDs
 *   accBalance			: Array holding the account balances
 *   accName			: Array holding the names of the accounts
 *   searchName			: Names entered by user
 *   outFileName		: The name of the output file being used
 *   inFileName			: The name of the input file being used
 *   inFile				: Variable holding the file
 *
 * OUTPUT
 *   outFile			: Variable for the output file
 *   accInfo			: Subscript to link arrays
 *   headers			: Controls when headers print
 *   printAve			: Controls when the average balance prints
 *   balAverage			: The average balance of the accounts
 *   searched			: The amount of names searched successfully
 *****************************************************************/


int main ()
{
	int accounts;			//INPUT - Number of accounts on file
	int accId[100];			//INPUT - Account ID numbers
	float accBalance[100];	//INPUT - Account balances
	string accName[100];	//INPUT - Names of account owners
	string searchName;		//INPUT - The name being searched
	string outFileName;		//INPUT - Name of the output file
	ofstream outFile;		//OUTPUT - Variable for output file
	int accInfo;			//OUTPUT - Subscript to link arrays
	bool headers;			//OUTPUT - Controls printing headers
	bool printAve;			//OUTPUT - Controls when average prints
	double balAverage;		//OUTPUT - Average balance of accounts
	float searched;			//OUTPUT - Amount of names searched

	headers = false;
	printAve = false;
	balAverage = 0;

	cout << left;
	cout << "************************************************\n";
	cout << "* PROGRAMMED BY : Quinten Ridley\n";
	cout << "* CLASS         : CSC5\n";
	cout << "* SECTION       : MW - 2:20PM-6:30PM\n";
	cout << "* PROJECT #4    : Parallel Arrays\n";
	cout << "************************************************\n";
	cout << right;


	//Loads data from file into arrays
	LoadArraysFromFile(accName, accId, accBalance, accounts);

	//Creates an output file
	cout << "What output file would you like to use? ";
	getline(cin, outFileName);
	cout << endl;

	outFile.open(outFileName);

	//Prints class header to top of output file
	PrintHeaderToFile(outFile);

	//Program will ask for names until "done" is entered
	while (searchName != "done")
	{
		cout << "Who do you want to search for (enter done "
			 	"to exit): ";

		getline(cin, searchName);

		//There is no search if users enter "done"
		if (searchName != "done")
		{
			//accInfo gets the value returned from the function
			accInfo = SearchForMatch(searchName, accName, accounts);

			/*-1 is the default value returned from the function
			if what was entered for searchName is not found */
			if (accInfo == -1)
			{
				cout << searchName << " was not found.\n\n";
			} else
			{
				cout << "Found.\n\n";
				//The accounts information is printed
				PrintReportToFile(accName,
								  accId,
								  accBalance,
								  accInfo,outFile,
								  headers,
								  printAve,
								  balAverage);
				headers = true;
				//The accounts balance is added to balAverage
				balAverage += accBalance[accInfo];
				searched++;
			}
		} else
		{
			//balAverage is set equal to balAverage
			balAverage = balAverage / searched;
			printAve = true;
			PrintReportToFile(accName,
							  accId,
							  accBalance,
							  accInfo,
							  outFile,
							  headers,
							  printAve,
							  balAverage);
		}

	}

	cout << "\nThank you for using my program.";

	outFile.close();

	return 0;
}
