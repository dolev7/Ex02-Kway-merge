#include "MainHeader.h"
#include "InputManager.h"
#include "OutputManager.h"
using namespace KWaySort;

int main()
{
	string errorName;
	ifstream inFile;
	ofstream outFile;
	int n, k;
	string inputFileName, outputFileName;

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
		outFile.close();

	}

	catch(const string& error)
	{
		cout << "wrong input" << endl;
		inFile.close();
	}

	return 0;
}