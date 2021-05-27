#include "ArrayToSort.h"
#include "Heap.h"

namespace KWaySort
{
	ArrayToSort::ArrayToSort(int n, int k, int* array)
	{
		this->_arrayToSort = new int[n];
		_size = n;
		_k = k;

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

		int** subArr = new int* [_k];
		int* sizesArray = new int[_k];
		int remainSubArrs = n % _k;

		// recursively sort all n\k sub arrays 
		for (int i = 0; i < _k - remainSubArrs; i++)
		{
			subArr[i] = arrayToSort + i * (n / _k) ;
			sizesArray[i] = n / _k;
			KWaySortRec(subArr[i], n / _k);
		}

		// recursively sort all n\k+1 sub arrays 
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
		// output array of the merged arrays
		int* output = new int[totalCount];

		// Build a minimum heap with k nodes, every node has first number of an array
		Node* heapArr = new Node[k];
		for (int i = 0; i < k; i++)
		{
			// init the heap
			heapArr[i].data = arr[i][0];
			heapArr[i].array_index = i;
			heapArr[i].item_index = 1; 
		}

		Heap heap(heapArr, k);

		for (int count = 0; count < totalCount; count++)
		{
			// Get the minimum number from the heap and store it in output
			Node item_to_insert = heap.min();
			output[count] = item_to_insert.data;

			// Find the next number from the same array as the current root.
			if (item_to_insert.item_index < sizes[item_to_insert.array_index]) 
			{
				item_to_insert.data = arr[item_to_insert.array_index][item_to_insert.item_index];
				item_to_insert.item_index += 1;
			}
			// If root was the last number of its array, mark it was "infinity"    
			else item_to_insert.data = INT_MAX;

			// Replace root with next element of array
			heap.replaceMin(item_to_insert);
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