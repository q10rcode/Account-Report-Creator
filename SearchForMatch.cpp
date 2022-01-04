#include "myheader.h"

int SearchForMatch(string searchName,
                   string accName[],
				           int accounts
				           )
{

	int index = 0;		//INPUT - Index of the array
	int position = -1;	//OUTPUT - Subscript of array
	bool found = false;	//OUTPUT - Tells loop if searchName was found

	//Linear search algorithm
	while (index < accounts && !found)
	{
		if(accName[index] == searchName)
		{
			found = true;
			position = index;
		}
		index++;
	}

	return position;
}
