#include "OutputManager.h"

namespace KWaySort
{
	void saveArrayToFile(ArrayToSort& kWayToSort, ostream& out)
	{
		int* arrayToPrint = kWayToSort.getArray();
		int size = kWayToSort.getSize();
		//char newLine = '\n';

		for (int i = 0; i < size; i++)
		{
			out << arrayToPrint[i] << endl;
		}
	}
}
