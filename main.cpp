#include "MainHeader.h"
#include "InputManager.h"
#include "OutputManager.h"
#include "Heap.h"
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

		//int** arr = new int* [2];
		//arr[0] = new int[3];
		//arr[1] = new int[3];

		////arr0
		//arr[0][0] = 7;
		//arr[0][1] = 8;
		//arr[0][2] = 70;
		////arr1
		//arr[1][0] = 4;
		//arr[1][1] = 40;
		//arr[1][2] = 60;

		//int* sizes = new int[2];
		//sizes[0] = 3;
		//sizes[1] = 3;
		//int* res = mergeKArrays(arr, sizes, 2, 6);
		//cout << "the array is:" << endl;
		//for (int i = 0; i < 6; i++)
		//{
		//	cout << res[i] <<endl;
		//}
	}

	catch(const string& error)
	{
		cout << "wrong input" << endl;
		inFile.close();
	}

	return 0;
}


