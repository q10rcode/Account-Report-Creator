#include "myheader.h"


void PrintHeaderToFile(ofstream& outFile)
{
	outFile << left;
	outFile << "************************************************\n";
	outFile << "* PROGRAMMED BY : Quinten Ridley\n";
	outFile << "* CLASS         : CSC5\n";
	outFile << "* SECTION       : MW - 2:20PM-6:30PM\n";
	outFile << "* PROJECT #4    : Parallel Arrays\n";
	outFile << "************************************************\n";
	outFile << right;

	return;
}
