#include "myheader.h"

void PrintReportToFile(string accName[],
					             int accId[],
                       float accBalance[],
                       int accInfo,
                       ofstream& outFile,
                       bool headers,
                       bool printAve,
                       double balAverage
                       )
{


	/*After the first run headers is
	 *true so this only prints once*/
	if (!headers)
	{
		//Creates the headers for the output file
		outFile << "ID #" << setw(9)
				<< "NAME"<< setw(32)
				<< "BALANCE DUE" << endl;

		outFile <<"----" << setw(25)
				<< "--------------------" << setw(16)
				<< "-----------" << endl;
	}

	//When the average is being printed this won't print
	if(!printAve)
	{
		//accId, accName, and accBalance are printed to output file
		outFile << left << setw(9)
				<< accId[accInfo]  << setw(25)
				<< accName[accInfo] << "$"
				<< right << setw(10)
				<< fixed << setprecision(2)
				<< accBalance[accInfo] << endl;
	}


	if (printAve)
	{
		//The Average balance is printed
		outFile << endl << setw(35);
		outFile <<"Average Balance Due: $" << setw(10)
				<< balAverage;
	}



}
