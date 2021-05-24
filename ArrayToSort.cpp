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
		//HeapKWayMerge();
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
		for (int i = 0; i < _k - remainSubArrs; i++)
		{
			subArr[i] = arrayToSort + i * (n / _k) ;
			KWaySortRec(subArr[i], n / _k);
		}

		for (int j = 0; j < remainSubArrs; j++) 
		{
			subArr[_k- remainSubArrs + j] = arrayToSort + n - ((j + 1) * ((n / _k) + 1));
			KWaySortRec(subArr[_k - remainSubArrs + j], (n / _k) + 1);
		}
		print(subArr);
		
	}

	void ArrayToSort::print(int** subArr)
	{
		for (int i = 0; i < _k; i++)
		{
			cout << *subArr[i] << endl;
		}
	}

	void ArrayToSort::HeapKWayMerge()
	{
		for (int i = 0; i < _size / _k; i++)
		{
			// Heap(*_heapPointers, _size / _k)
		}
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