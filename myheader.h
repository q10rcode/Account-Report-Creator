#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

/***************************************************************
 * LoadArraysFromFile
 * _____________________________________________________________
 * This function asks the user what input file they want to use
 * and then it opens the file to read the amount of accounts
 * are in it and then closes it. The number of accounts is
 * stored in the variable accounts so that loops throughout the
 * program do not have to cycle through the entire array. The
 * program then reopens the array and the data is put into
 * the arrays accName, accId, and accBalance.
 * _____________________________________________________________
 * INPUT
 * accName			: Enters the function empty
 * accId			: Enters the function empty
 * accBalance		: Enters the function empty
 * accounts			: Enters the function empty
 *
 * OUTPUT
 * accName			: Contains names from input file
 * accId			: Contains IDs from input file
 * accBalance		: Contains balances from input file
 * accounts			: Contains the amount of accounts in the file
 ***************************************************************/
void LoadArraysFromFile(string accName[],
						int accId[],
						float accBalance[],
						int& accounts);

/***************************************************************
 * SearchForMatch
 * _____________________________________________________________
 * This function uses the variable searchName in a linear
 * search to see if there are any matches in the array accName.
 * Accounts is used to limit the for loop so that it does not
 * waste time looking through the empty arrays. At the end of
 * the function the variable position is returned. Position is
 * set to -1 by default but will be changed to the subscript of
 * the array that matches searchName if there is one.
 * _____________________________________________________________
 * INPUT
 * searchName		: Name entered by user
 * accName			: Array holding all names on the file
 * accounts			: The amount of accounts on the file
 *
 * OUTPUT
 * position			: Subscript of array that matches searchName
 ***************************************************************/
int SearchForMatch(string searchName,
				   string accName[],
				   int accounts);

/***************************************************************
 * PrintHeaderToFile
 * _____________________________________________________________
 * This function the output file created in main and it prints
 * the class header to the output file.
 * _____________________________________________________________
 * INPUT
 * outFile			: Variable containing output file
 *
 * OUTPUT
 * outFile			: Class header written in output file
 ***************************************************************/
void PrintHeaderToFile(ofstream& outFile);

/***************************************************************
 * PrintReportToFile
 * _____________________________________________________________
 * This function takes all three arrays and uses accInfo for the
 * subscript for each array and outputs the information into
 * the output file. If the bool headers is false then the
 * headers ID, Name, and Balance due appear. If the bool
 * printAve is true then the average balance will be displayed.
 * The values in the arrays only display if printAve is false.
 * _____________________________________________________________
 * INPUT
 * accName			: Contains names from input file
 * accId			: Contains IDs from input file
 * accBalance		: Contains balances from input file
 * accInfo			: Subscript to link arrays
 * headers			: Controls when headers print
 * printAve			: Controls when the average balance prints
 *
 * OUTPUT
 * outFile			: Have average balance, account information,
 * 					  and average balance printed
 * balAverage		:Average balance of accounts
 ***************************************************************/
void PrintReportToFile(string accName[],
					   int accId[],
					   float accBalance[],
				       int accInfo,
					   ofstream& outFile,
					   bool headers,
					   bool printAve,
					   double balAverage);
