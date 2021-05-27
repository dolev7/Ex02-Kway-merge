#include "MainHeader.h"
#include "InputManager.h"
#include "OutputManager.h"
using namespace KWaySort;

int main()
{
	string errorName;
	ifstream inFile;
	ofstream outFile;
	string inputFileName, outputFileName;
	int n, k;

	try
	{
		getNumbersAndFilesNames(n, k, inputFileName, outputFileName);
		inFile.open(inputFileName, ios::binary | ios::in);
		if (!inFile.is_open())
		{
			throw (errorName = "Input file wasn't found");
		}

		outFile.open(outputFileName, ios::binary | ios::out);
		int* arrayToSort = new int[n];
		loadArrayFromFile(arrayToSort, n, inFile);
		inFile.close();

		ArrayToSort kWayToSort(n, k, arrayToSort);
		kWayToSort.KWaySort();
		saveArrayToFile(kWayToSort, outFile);

	}

	catch (const string& error)
	{
		//the string "error" is only for debugging use, in any case the error displayed to the user is "wrong output"
		cout << "wrong input" << endl;
		inFile.close();
	}

	return 0;
}


