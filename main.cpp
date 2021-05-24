#include "MainHeader.h"
#include "InputManager.h"
#include "OutputManager.h"
#include "Heap.h"
using namespace KWaySort;

int* mergeKArrays(int** arr, int* sizes, int k, int totalCount)
{
	// To store output array
	int* output = new int[totalCount];

	// Create a min heap with k heap nodes.
	// Every heap node has first element of an array
	Node* harr = new Node[k];
	for (int i = 0; i < k; i++)
	{

		// Store the first element
		harr[i].data = arr[i][0];

		// index of array
		harr[i].array_index = i;

		// Index of next element to be stored from the array
		harr[i].item_index = 1; //todo
	}

	// Create the heap
	Heap hp(harr, k);

	// Now one by one get the minimum element from min
	// heap and replace it with next element of its array
	for (int count = 0; count < totalCount; count++)
	{
		// Get the minimum element and store it in output
		Node item_to_insert = hp.min();
		output[count] = item_to_insert.data;

		// Find the next elelement that will replace current
		// root of heap. The next element belongs to same
		// array as the current root.
		if (item_to_insert.item_index < sizes[item_to_insert.array_index]) //todo
		{
			item_to_insert.data = arr[item_to_insert.array_index][item_to_insert.item_index];
			item_to_insert.item_index += 1;
		}
		// If root was the last element of its array
// INT_MAX is for infinite       
		else item_to_insert.data = INT_MAX;

		// Replace root with next element of array
		//hp.deleteMin();
		//hp.Insert(item_to_insert);
		//hp.fixHeap(0);
		hp.replaceMin(item_to_insert);
	}

	return output;
}

int main()
{
	string errorName;
	ifstream inFile;
	ofstream outFile;
	int n, k;
	string inputFileName, outputFileName;

	try
	{
		/*getNumbersAndFilesNames(n, k, inputFileName, outputFileName);
		inFile.open(inputFileName, ios::binary | ios::in);
		if (!inFile.is_open())
		{
			throw (errorName = "Input file wasn't found");
		}

		outFile.open(outputFileName, ios::binary | ios::out);
		int* arrayToSort = new int[n];
		loadArrayFromFile(arrayToSort, n, inFile);
		inFile.close();*/

		//	ArrayToSort kWayToSort(n, k, arrayToSort);

			//kWayToSort.KWaySort();

		//	saveArrayToFile(kWayToSort, outFile);

		int** arr = new int* [2];
		arr[0] = new int[1];
		arr[1] = new int[1];

		arr[0][0] = 7;
		arr[1][0] = 4;

		int* sizes = new int[2];
		sizes[0] = 1;
		sizes[2] = 1;
		mergeKArrays(arr, sizes, 2, 2);
	}

	catch(const string& error)
	{
		cout << "wrong input" << endl;
		inFile.close();
	}

	return 0;
}


