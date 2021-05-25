#include "ArrayToSort.h"
#include "Heap.h"

namespace KWaySort
{
	ArrayToSort::ArrayToSort(int n, int k, int* array)
	{
		this->_arrayToSort = new int[n];
		this->_heapPointers = new int* [k];
		_size = n;
		_k = k;
		_heapCounter = 0;

		for (int i = 0; i < _size; i++)
		{
			_arrayToSort[i] = array[i];
		}
	}

	void ArrayToSort::KWaySort()
	{
		KWaySortRec(_arrayToSort, _size);
	}

	void ArrayToSort::KWaySortRec(int* arrayToSort, int  n)
	{

		if (n < _k)
		{
			QuickSort(arrayToSort, 0, n-1);
			return;
		}

		int remainSubArrs = n % _k;
		int** subArr = new int* [_k];
		int* sizesArray = new int[_k];
		for (int i = 0; i < _k - remainSubArrs; i++)
		{
			subArr[i] = arrayToSort + i * (n / _k) ;
			sizesArray[i] = n / _k;
			KWaySortRec(subArr[i], n / _k);
		}

		for (int j = 0; j < remainSubArrs; j++) 
		{
			subArr[_k- remainSubArrs + j] = arrayToSort + n - ((j + 1) * ((n / _k) + 1));
			sizesArray[_k - remainSubArrs + j] = n / _k + 1;
			KWaySortRec(subArr[_k - remainSubArrs + j], (n / _k) + 1);
		}

		int* sorted = mergeKArrays(subArr, sizesArray, _k, n);

		for (int i = 0; i < n; i++)
		{
			arrayToSort[i] = sorted[i];
		}

		delete[] sorted;
	}

	int* ArrayToSort::mergeKArrays(int** arr, int* sizes, int k, int totalCount)
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


	void ArrayToSort::QuickSort(int* arrayToSort, int left, int right)
	{
		if (left < right)
		{
			int pivot = Partition(arrayToSort, left, right);
			QuickSort(arrayToSort, left, pivot - 1);
			QuickSort(arrayToSort, pivot + 1, right);
		}
	}

	int ArrayToSort::Partition(int* array, int left, int right)
	{
		int pivot = array[right];
		int i = (left - 1);
		for (int j = left; j < right; j++)
		{
			if (array[j] <= pivot)
			{
				i++;
				swap(array[i], array[j]);
			}
		}
		swap(array[i + 1], array[right]);
		return i + 1;
	}

	void swap(int& num1, int& num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}

}